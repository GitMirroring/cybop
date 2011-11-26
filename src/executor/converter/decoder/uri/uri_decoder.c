/*
 * Copyright (C) 1999-2012. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI. If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef URI_DECODER_SOURCE
#define URI_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/converter/decoder/http_request_uri/absolute_path_http_request_uri_decoder.c"
#include "../../../../executor/converter/decoder/http_request_uri/absolute_uri_http_request_uri_decoder.c"
#include "../../../../executor/converter/decoder/http_request_uri/authority_form_http_request_uri_decoder.c"
#include "../../../../executor/converter/decoder/http_request_uri/no_resource_http_request_uri_decoder.c"
#include "../../../../executor/converter/decoder/uri/http/authority_http_uri_decoder.c"
#include "../../../../executor/converter/decoder/uri/http/path_http_uri_decoder.c"
#include "../../../../executor/converter/decoder/uri/scheme_uri_decoder.c"
#include "../../../../executor/modifier/appender/part_allocator_item_appender.c"
#include "../../../../logger/logger.c"

//
// The generic URI syntax consists of a hierarchical sequence of components:
//
// URI          = scheme ":" hier-part [ "?" query ] [ "#" fragment ]
//
// hier-part    = "//" authority path-abempty
//                / path-absolute
//                / path-rootless
//                / path-empty
//
// One can have a scheme ":" with path-absolute, path-rootless
// or path-empty and no "//" after the scheme ":".
//
// - path-empty is 0<pchar>, no slashes in sight, next stop "?"
// - path-absolute is "/" segment-nz etc.; segment-nz is 1*pchar;
//   there is precisely one slash after the scheme ":"
// - path-rootless starts with segment-nz, no "/" after the scheme ":"
//
// That leaves "//" authority path-abempty to get an interesting
// number of slashes after the scheme ":".
// Ignoring optional parts, <authority> is at least a <host>
// and <host> is IP-literal / IPv4addrss / reg-name.
// They shouldn't be empty, but <reg-name> can be empty.
//
// - path-abempty is zero or more "/" segment
// - segment is zero or more pchar
//
// So one can have three slashes like:
// file:///etc
// and in theory also more slashes if the segments are "empty".
// In practice, however, file: is the only URI scheme known to
// allow an empty reg-name (in that case instead of localhost).
//
// Example URI and its component parts:
//
// foo://username:password@example.com:8042/over/there/index.dtb?type=animal&name=ferret#nose
// \__/\__________________/\_________/\___/\__________/\___/\__/\__________/\__________/\___/
//  |            |              |       |      |         |    |          |       |        |
//  |         userinfo      hostname  port    dir  filename extension   parametre(s)      |
//  |  \__________________________________/\___________________/\______________________/  |
//  |                    |                            |                     |             |
//  |                authority                       path                   |             |
//  |  \_______________________________________________________/            |             |
//  |                                     |                                 |             |
// scheme                             hierarchy                           query       fragment
//
// The scheme is required.
// The authority component is required, but may be empty only prefixed
// with two slash characters ("//").
// The hostname may be given in IPv4, IPv6 or FQDN format.
// The path may be empty.
// The path must either be empty or begin with a slash ("/") character.
// When authority is not present, the path cannot begin with two slash characters ("//").
//
// In cyboi, the uri parts are translated into the following compound hierarchy:
//
// root (destination compound that was handed over)
// +-scheme
// +-authority
// | +-username
// | +-password
// | +-hostname
// | +-port
// +-path
// +-query
// | +-param1
// | +-param2
// | +-...
// +-fragment
//
// The url path specified by the client is relative to the
// server's root directory. Consider the following url as it
// would be requested by a client:
// http://www.example.com/path/file.html
// The client's web browser will translate it into a connection
// to www.example.com with the following http 1.1 request:
// GET /path/file.html HTTP/1.1
// host: www.example.com
// The Web server on www.example.com will append the given path
// to the path of its root directory. On Unix machines, this is
// commonly /var/www/htdocs.
// The result is the local file system resource:
// /var/www/htdocs/path/file.html
// The Web server will then read the file, if it exists, and
// send a response to the client's web browser. The response
// will describe the content of the file and contain the file itself.
//
// Although not defined by IETF's uri specification rfc3986, it has become
// usual to use the characters ";" and "&" as parametre separators in a uri.
// These are commonly found in both, the "path" and "query" component part.
// For cyboi, however, it is defined that parametres may only be given in the
// "query" component part, and that parametres are separated by ampersand "&".
//
// Examples:
//
// http://localhost:1971/?exit
// http://127.0.0.1:1971?name=close&channel=inline&type=knowledge&model=.residenz.logic.exit_program
// http://de.wikipedia.org/w/index.php?title=Uniform_Resource_Locator&action=edit
//
// There are a number of reserved characters, to which belong:
// ! # $ % & ' ( )// + , / : ; = ? @ [ ]
// The following url contains the reserved # character:
// http://www.example.net/index.html?session=A54C6FE2#info
// which should be encoded as %23 like:
// http://www.example.net/index.html?session=A54C6FE2%23info
//
// See:
// http://tools.ietf.org/html/rfc1630
// http://tools.ietf.org/html/rfc3986
//

/**
 * Decodes the wide character uri into a model and properties.
 *
 * CAUTION! The source character array MUST NOT be given
 * as percent-encoded octets. In other words, it has to
 * have been DECODED BEFORE being handed over to this function.
 *
 * CAUTION! The source character array HAS TO BE given
 * as sequence of WIDE characters.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 */
void decode_uri(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode uri.");

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p2);
    // Copy source count remaining.
    copy_integer((void*) &c, p3);

    //
    // CAUTION! Do comparisons below IN PARALLEL, because:
    // - the uri types do not depend on each other
    // - each detection has to start with the first character
    //
    // CAUTION! The order of the comparisons is IMPORTANT!
    // Do NOT change it easily!
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        decode_no_resource_http_request_uri(p0, p1, (void*) &r, (void*) &d, (void*) &c);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Do nothing, since the http request uri is empty "*",
            // which means that it points to nowhere, i.e. no resource is given.
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        decode_absolute_uri_http_request_uri(p0, p1, (void*) &r, (void*) &d, (void*) &c);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_uri_scheme(p0, p1, (void*) &d, (void*) &c);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        decode_authority_form_http_request_uri(p0, p1, (void*) &r, (void*) &d, (void*) &c);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Add scheme as full text string.
            // The scheme is handed over as http request "protocol" header.
            // Add scheme as uri part here, because the authority does not contain one.
            append_item_allocate_part(p0, (void*) SCHEME_URI_CYBOI_NAME, (void*) SCHEME_URI_CYBOI_NAME_COUNT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT,
                (void*) HTTP_SCHEME_URI_MODEL, (void*) HTTP_SCHEME_URI_MODEL_COUNT,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

            decode_http_uri_authority_content(p0, (void*) &d, (void*) &c);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        decode_absolute_path_http_request_uri(p0, p1, (void*) &r, (void*) &d, (void*) &c);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Add scheme as full text string.
            // The scheme is handed over as http request "protocol" header.
            // Add scheme as uri part here, because the path does not contain one.
            append_item_allocate_part(p0, (void*) SCHEME_URI_CYBOI_NAME, (void*) SCHEME_URI_CYBOI_NAME_COUNT,
                (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT,
                (void*) HTTP_SCHEME_URI_MODEL, (void*) HTTP_SCHEME_URI_MODEL_COUNT,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

            decode_http_uri_path(p0, p1, (void*) &d, (void*) &c);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode uri. The uri is invalid.");
    }
}

/* URI_DECODER_SOURCE */
#endif
