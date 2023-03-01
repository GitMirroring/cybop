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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef HTTP_REQUEST_DESERIALISER_SOURCE
#define HTTP_REQUEST_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/http_request/method_http_request_deserialiser.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

//
// An http server request delivers message data in text format (like MIME 1.0),
// and consists of the following three parts:
// 1 request line containing request method, file path and protocol version
// 2 headers containing meta data, of which some have the form of variables
// 3 body containing optional user data (such as an encoded/serialised xhtml page)
//
// CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
// This is defined so by the Hypertext Transfer Protocol (HTTP).
// The end of the headers is demarcated by an empty line (CRLF without any space).
//
// HTTP request and response messages use a generic message format for transferring
// entities (the payload of the message). Both types of message consist of a:
// - start-line
// - zero or more header fields (also known as "headers")
// - an empty line (i.e., a line with nothing preceding the CRLF)
//   indicating the end of the header fields
// - possibly a message-body
//
// Example with GET method 1:
//
// GET /wiki/Spezial:Search?search=Katzen&go=Artikel HTTP/1.1
// host: de.wikipedia.org
//
// The value pairs (parametres) of the example are:
//
// -------------------------------------
// Argument         Value
// -------------------------------------
// search           Katzen
// go               Artikel
// -------------------------------------
//
// Example with GET method 2:
//
// GET /residenz/test.html HTTP/1.1
// user-agent: Mozilla/5.0 (compatible; Konqueror/3.5; Linux) KHTML/3.5.5 (like Gecko) (Debian)
// accept: text/html, image/jpeg, image/png, text/*, image/*,// /*
// accept-encoding: x-gzip, x-deflate, gzip, deflate
// accept-charset: utf-8, utf-8;q=0.5, *;q=0.5
// accept-language: en, de, pl
// host: 127.0.0.1:1971
// connection: Keep-Alive
//
// Example with GET method 3:
//
// GET /?action=index HTTP/1.1
// Host: localhost
// User-Agent: Mozilla/5.0 (X11; Linux i686; rv:31.0) Gecko/20100101 Firefox/31.0 Iceweasel/31.4.0
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
// Accept-Language: de,en-US;q=0.7,en;q=0.3
// Accept-Encoding: gzip, deflate
// DNT: 1
// Connection: keep-alive
//
// Example with POST method:
//
// POST /wiki/Spezial:Search HTTP/1.1
// host: de.wikipedia.org
// content-type: application/x-www-form-urlencoded
// content-length: 24
//
// search=Katzen&go=Artikel
//

//
// Taken from:
// https://bugzilla.mozilla.org/show_bug.cgi?id=18643
//
// We cannot add a charset parametre to the Content-Type header for HTTP GET,
// because there is no Content-Type header in the case of GET (since there is no
// body following the headers). A *lot* of forms use GET.
//
// Since the charset of GET requests is always straight 7bit ASCII encoding
// standard ISO-Latin-1 text, I would have thought that that was pretty irrelevant.
//
// According to RFC1630:
// #     Where the local naming scheme uses ASCII characters which are not
// #     allowed in the URI, these may be represented in the URL by a
// #     percent sign "%" immediately followed by two hexadecimal digits
// #     (0-9, A-F) giving the ISO Latin 1 code for that character.
//                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// Does this not mean that URIs can only contain a single character encoding?
//
// Similarly in HTML4, section 17.13.1:
// #   Note. The "get" method restricts form data set values to ASCII
// #   characters. Only the "post" method (with
// #   enctype="multipart/form-data") is specified to cover the entire
// #   [ISO10646] character set.
//
// RFC1630 does attempt to restrict URIs to iso-8859-1, but it is a well
// known fact that HTML forms have been violating that rule for years.
// Similar comment for HTML4's 17.13.1.
//

//
// Since RFC 2822, conforming message header names
// and values should be ASCII characters;
// values that contain non-ASCII data should use
// the MIME encoded-word syntax (RFC 2047)
// instead of a literal string.
//
// https://en.wikipedia.org/wiki/MIME#Encoded-Word
//

/**
 * Deserialises the http request character data into a model and properties.
 *
 * An http message is expected to consist of a sequence of octets.
 * An octet labels eight Bits forming one Byte, e.g.: 01001100
 *
 * The http header octets are supposed to represent ASCII characters.
 * The http body, on the other hand, may be encoded by some mechanism,
 * on which the meaning of its bytes depends.
 *
 * One might get the idea to convert the http message header
 * AT ONCE from ASCII- to wide characters.
 * However, this might turn out to be problematic, since
 * the URI sent within the http message header uses a special
 * percent-encoding in order to escape reserved characters.
 *
 * Therefore, the http message has to be processed AS IS,
 * and only PIECES OF IT may be converted to wide characters,
 * e.g.: request method, protocol etc.
 *
 * The disadvantage is that for each conversion, a sub routine
 * has to be called (context switch) and local variables have
 * to be allocated and deallocated, which causes a delay.
 *
 * For the URI, octets have to be decoded from percent-encoding into
 * standard octets, which then get UTF-8-decoded into wide characters.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 */
void deserialise_http_request(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise http request.");

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p2);
    // Copy source count remaining.
    copy_integer((void*) &c, p3);

    //?? fwprintf(stdout, L"Debug: Deserialise http request. c: %i\n", c);
    //?? fwprintf(stdout, L"Debug: Deserialise http request. d: %s\n", (char*) d);

    //
    // CAUTION! A COPY of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    //
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    //
    deserialise_http_request_method(p0, p1, (void*) &d, (void*) &c);
}

/* HTTP_REQUEST_DESERIALISER_SOURCE */
#endif
