/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NO_RESOURCE_HTTP_REQUEST_URI_SELECTOR_SOURCE
#define NO_RESOURCE_HTTP_REQUEST_URI_SELECTOR_SOURCE

#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/uri/scheme_uri_model.c"
#include "../../../../constant/name/http_request_uri/http_request_uri_name.c"
#include "../../../../executor/representer/deserialiser/uri/http_uri_deserialiser.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

/**
 * Selects no resource http request uri.
 *
 * The request uri identifies the resource upon which to apply a request.
 * There are four options to specify a request uri:
 *
 * Request-URI = "*" | absoluteURI | abs_path | authority
 *
 * (1) No resource
 *
 * The asterisk "*" means that the request does not apply to a particular
 * resource, but to the server itself, and is only allowed when the method
 * used does not necessarily apply to a resource. Example:
 *
 * OPTIONS * HTTP/1.1
 *
 * (2) Absolute URI
 *
 * The absoluteURI form is REQUIRED when the request is being made to
 * a proxy. The proxy is requested to forward the request or service it
 * from a valid cache, and return the response. Note that the proxy MAY
 * forward the request on to another proxy or directly to the server
 * specified by the absoluteURI. Example:
 *
 * GET http://www.w3.org/pub/WWW/TheProject.html HTTP/1.1
 *
 * (3) Authority Form
 *
 * The authority form is only used by the CONNECT method. If a client
 * connects to a proxy using the CONNECT method, it has to specify
 * the hostname and, separated by a colon, the port number. Both of them
 * have to be specified. The host:port part is followed by a space and
 * a string specifying the HTTP version number. Example:
 *
 * CONNECT home.netscape.com:443 HTTP/1.0
 * User-agent: Mozilla/1.1N
 * Proxy-authorization: basic aGVsbG86d29ybGQ=
 *
 * (4) Absolute Path
 *
 * The most common form is that used to identify a resource on an
 * origin server or gateway. In this case, the absolute path of the
 * uri MUST be transmitted as the request uri, and the network location
 * of the uri (authority) MUST be transmitted in a Host header field.
 * For example, a client wishing to retrieve the resource above directly
 * from the origin server would create a TCP connection to port 80 of
 * the host "www.w3.org" and send the lines:
 *
 * GET /pub/WWW/TheProject.html HTTP/1.1
 * Host: www.w3.org
 *
 * followed by the remainder of the request.
 * Note that the absolute path cannot be empty; if none is present
 * in the original URI, it MUST be given as "/" (the server root).
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the break flag
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void select_no_resource_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select no resource http request uri.");

    //
    // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) NO_RESOURCE_HTTP_REQUEST_URI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NO_RESOURCE_HTTP_REQUEST_URI_NAME_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        move_position(p3, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* NO_RESOURCE_HTTP_REQUEST_URI_SELECTOR_SOURCE */
#endif
