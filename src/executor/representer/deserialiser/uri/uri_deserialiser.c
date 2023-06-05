/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

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

//
// The request uri identifies the resource upon which to apply a request.
// There are four options to specify a request uri:
//
// Request-URI = "*" | absoluteURI | abs_path | authority
//
// (1) No resource
//
// The asterisk "*" means that the request does not apply to a particular
// resource, but to the server itself, and is only allowed when the method
// used does not necessarily apply to a resource. Example:
//
// OPTIONS * HTTP/1.1
//
// (2) Absolute URI
//
// The absoluteURI form IS REQUIRED when the request is being made to
// a proxy. The proxy is requested to forward the request or service it
// from a valid cache, and return the response. Note that the proxy MAY
// forward the request on to another proxy or directly to the server
// specified by the absoluteURI. Example:
//
// GET http://www.w3.org/pub/WWW/TheProject.html HTTP/1.1
//
// (3) Authority Form
//
// The authority form is only used by the CONNECT method. If a client
// connects to a proxy using the CONNECT method, it has to specify
// the hostname and, separated by a colon, the port number. Both of them
// have to be specified. The host:port part is followed by a space and
// a string specifying the HTTP version number. Example:
//
// CONNECT home.netscape.com:443 HTTP/1.0
// User-agent: Mozilla/1.1N
// Proxy-authorization: basic aGVsbG86d29ybGQ=
//
// (4) Absolute Path
//
// The most common form is that used to identify a resource on an
// origin server or gateway. In this case, the absolute path of the
// uri MUST be transmitted as the request uri, and the network location
// of the uri (authority) MUST be transmitted in a Host header field.
// For example, a client wishing to retrieve the resource above directly
// from the origin server would create a TCP connection to port 80 of
// the host "www.w3.org" and send the lines:
//
// GET /pub/WWW/TheProject.html HTTP/1.1
// Host: www.w3.org
//
// followed by the remainder of the request.
// Note that the absolute path CANNOT be empty; if none is present
// in the original URI, it MUST be given as "/" (the server root).
//

/**
 * Deserialises the wide character uri into a model and properties.
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
void deserialise_uri(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise uri.");

    // The no resource source data position and source count remaining.
    void* nord = *NULL_POINTER_STATE_CYBOI_MODEL;
    int norc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The absolute uri source data position and source count remaining.
    void* abud = *NULL_POINTER_STATE_CYBOI_MODEL;
    int abuc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The authority form source data position and source count remaining.
    void* aufd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int aufc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The absolute path source data position and source count remaining.
    void* abpd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int abpc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy no resource source data position and source count remaining.
    copy_pointer((void*) &nord, (void*) &p2);
    copy_integer((void*) &norc, p3);
    // Copy absolute uri source data position and source count remaining.
    copy_pointer((void*) &abud, (void*) &p2);
    copy_integer((void*) &abuc, p3);
    // Copy authority form source data position and source count remaining.
    copy_pointer((void*) &aufd, (void*) &p2);
    copy_integer((void*) &aufc, p3);
    // Copy absolute path source data position and source count remaining.
    copy_pointer((void*) &abpd, (void*) &p2);
    copy_integer((void*) &abpc, p3);

    //
    // CAUTION! Do comparisons below IN PARALLEL, because:
    // - the uri types do not depend on each other
    // - each detection has to start with the first character
    //
    // CAUTION! The ORDER of the following comparisons is IMPORTANT!
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        deserialise_no_resource_http_request_uri(p0, p1, (void*) &nord, (void*) &norc, (void*) &r);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Do nothing, since the http request uri is empty "*",
            // which means that it points to nowhere, i.e. no resource is given.
            //
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        deserialise_absolute_uri_http_request_uri(p0, p1, (void*) &abud, (void*) &abuc, (void*) &r);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_uri_scheme(p0, p1, (void*) &abud, (void*) &abuc);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        deserialise_authority_form_http_request_uri(p0, p1, (void*) &aufd, (void*) &aufc, (void*) &r);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Add scheme as full text string.
            //
            // The scheme is handed over as http request "protocol" header.
            // Add scheme as uri part here, because the authority does not contain one.
            //
            deserialise_http_request_append(p0, (void*) SCHEME_URI_CYBOI_NAME, (void*) SCHEME_URI_CYBOI_NAME_COUNT, (void*) HTTP_SCHEME_URI_MODEL, (void*) HTTP_SCHEME_URI_MODEL_COUNT);

            deserialise_http_uri_authority_content(p0, (void*) &aufd, (void*) &aufc);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        deserialise_absolute_path_http_request_uri(p0, p1, (void*) &abpd, (void*) &abpc, (void*) &r);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Add scheme as full text string.
            //
            // The scheme is handed over as http request "protocol" header.
            // Add scheme as uri part here, because the path does not contain one.
            //
            deserialise_http_request_append(p0, (void*) SCHEME_URI_CYBOI_NAME, (void*) SCHEME_URI_CYBOI_NAME_COUNT, (void*) HTTP_SCHEME_URI_MODEL, (void*) HTTP_SCHEME_URI_MODEL_COUNT);

            deserialise_http_uri_path(p0, p1, (void*) &abpd, (void*) &abpc);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise uri. The uri is invalid.");
        fwprintf(stdout, L"Warning: Could not deserialise uri. The uri is invalid.\n");
    }
}
