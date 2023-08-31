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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef STATUS_CODE_HTTP_MODEL_CONSTANT_HEADER
#define STATUS_CODE_HTTP_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// These constants represent http 1.1 status codes (server response codes),
// which are sent from a server back to the client that had sent the request.
//

//
// 1xx - informational
//
// This class of status code indicates a provisional response, consisting only of
// the Status-Line and optional headers, and is terminated by an empty line.
// There are no required headers for this class of status code. Since HTTP/1.0
// did not define any 1xx status codes, servers must not send a 1xx response to an
// HTTP/1.0 client except under experimental conditions.
//
// A client must be prepared to accept one or more 1xx status responses prior to a
// regular response, even if the client does not expect a 100 (Continue) status message.
// Unexpected 1xx status responses may be ignored by a user agent.
//
// Proxies must forward 1xx responses, unless the connection between the proxy and its client
// has been closed, or unless the proxy itself requested the generation of the 1xx response.
// (For example, if a proxy adds a "Expect: 100-continue" field when it forwards a request,
// then it need not forward the corresponding 100 (Continue) response(s).)
//

/** The continue 100 status code http model. */
static unsigned char* CONTINUE_100_STATUS_CODE_HTTP_MODEL = "100 Continue";
static int* CONTINUE_100_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The switching protocols 101 status code http model. */
static unsigned char* SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL = "101 Switching Protocols";
static int* SWITCHING_PROTOCOLS_101_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The processing 102 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static unsigned char* PROCESSING_102_STATUS_CODE_HTTP_MODEL = "102 Processing";
static int* PROCESSING_102_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

//
// 2xx - successful
//
// This class of status code indicates that the client's request was successfully
// received, understood, and accepted.
//

/** The ok 200 status code http model. */
static unsigned char* OK_200_STATUS_CODE_HTTP_MODEL = "200 OK";
static int* OK_200_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The created 201 status code http model. */
static unsigned char* CREATED_201_STATUS_CODE_HTTP_MODEL = "201 Created";
static int* CREATED_201_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accepted 202 status code http model. */
static unsigned char* ACCEPTED_202_STATUS_CODE_HTTP_MODEL = "202 Accepted";
static int* ACCEPTED_202_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The non-authoritative information 203 status code http model. */
static unsigned char* NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL = "203 Non-Authoritative Information";
static int* NON_AUTHORITATIVE_203_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The no content 204 status code http model. */
static unsigned char* NO_CONTENT_204_STATUS_CODE_HTTP_MODEL = "204 No Content";
static int* NO_CONTENT_204_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reset content 205 status code http model. */
static unsigned char* RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL = "205 Reset Content";
static int* RESET_CONTENT_205_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The partial content 206 status code http model. */
static unsigned char* PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL = "206 Partial Content";
static int* PARTIAL_CONTENT_206_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multi-status 207 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static unsigned char* MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL = "207 Multi-Status";
static int* MULTI_STATUS_207_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

//
// 3xx - redirection
//
// This class of status code indicates that further action needs to be taken by the
// user agent in order to fulfill the request. The action required may be carried
// out by the user agent without interaction with the user if and only if the method
// used in the second request is GET or HEAD. A client should detect infinite
// redirection loops, since such loops generate network traffic for each redirection.
//
// Note: previous versions of this specification recommended a maximum of five
// redirections. Content developers should be aware that there might be clients
// that implement such a fixed limitation.
//

/** The multiple choices 300 status code http model. */
static unsigned char* MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL = "300 Multiple Choices";
static int* MULTIPLE_CHOICES_300_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The moved permanently 301 status code http model. */
static unsigned char* MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL = "301 Moved Permanently";
static int* MOVED_PERMANENTLY_301_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The found 302 status code http model. */
static unsigned char* FOUND_302_STATUS_CODE_HTTP_MODEL = "302 Found";
static int* FOUND_302_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The see other 303 status code http model. */
static unsigned char* SEE_OTHER_303_STATUS_CODE_HTTP_MODEL = "303 See Other";
static int* SEE_OTHER_303_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not modified 304 status code http model. */
static unsigned char* NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL = "304 Not Modified";
static int* NOT_MODIFIED_304_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The use proxy 305 status code http model. */
static unsigned char* USE_PROXY_305_STATUS_CODE_HTTP_MODEL = "305 Use Proxy";
static int* USE_PROXY_305_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The switch proxy 306 status code http model.
 *
 * This status code is reserved but NOT used anymore in HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static unsigned char* SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL = "306 Switch Proxy";
static int* SWITCH_PROXY_306_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/** The temporary redirect (moved temporarily) 307 status code http model. */
static unsigned char* TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL = "307 Temporary Redirect";
static int* TEMPORARY_REDIRECT_307_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// 4xx - client error
//
// The 4xx class of status code is intended for cases in which the client seems to have erred.
// Except when responding to a HEAD request, the server should include an entity containing an
// explanation of the error situation, and whether it is a temporary or permanent condition.
// These status codes are applicable to any request method. User agents should display any
// included entity to the user.
//
// If the client is sending data, a server implementation using TCP should be careful to
// ensure that the client acknowledges receipt of the packet(s) containing the response,
// before the server closes the input connection. If the client continues sending data
// to the server after the close, the server's TCP stack will send a reset packet to the
// client, which may erase the client's unacknowledged input buffers before they can be
// read and interpreted by the HTTP application.
//

/** The bad request 400 status code http model. */
static unsigned char* BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL = "400 Bad Request";
static int* BAD_REQUEST_400_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unauthorized 401 status code http model. */
static unsigned char* UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL = "401 Unauthorized";
static int* UNAUTHORIZED_401_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The payment required 402 status code http model. */
static unsigned char* PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL = "402 Payment Required";
static int* PAYMENT_REQUIRED_402_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The forbidden 403 status code http model. */
static unsigned char* FORBIDDEN_403_STATUS_CODE_HTTP_MODEL = "403 Forbidden";
static int* FORBIDDEN_403_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not found 404 status code http model. */
static unsigned char* NOT_FOUND_404_STATUS_CODE_HTTP_MODEL = "404 Not Found";
static int* NOT_FOUND_404_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The method not allowed 405 status code http model. */
static unsigned char* METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL = "405 Method Not Allowed";
static int* METHOD_NOT_ALLOWED_405_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not acceptable 406 status code http model. */
static unsigned char* NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL = "406 Not Acceptable";
static int* NOT_ACCEPTABLE_406_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The proxy authentication required 407 status code http model. */
static unsigned char* PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL = "407 Proxy Authentication Required";
static int* PROXY_AUTHENTICATION_REQUIRED_407_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The request timeout 408 status code http model. */
static unsigned char* REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL = "408 Request Timeout";
static int* REQUEST_TIMEOUT_408_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The conflict 409 status code http model. */
static unsigned char* CONFLICT_409_STATUS_CODE_HTTP_MODEL = "409 Conflict";
static int* CONFLICT_409_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gone 410 status code http model. */
static unsigned char* GONE_410_STATUS_CODE_HTTP_MODEL = "410 Gone";
static int* GONE_410_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The length required 411 status code http model. */
static unsigned char* LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL = "411 Length Required";
static int* LENGTH_REQUIRED_411_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The precondition failed 412 status code http model. */
static unsigned char* PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL = "412 Precondition Failed";
static int* PRECONDITION_FAILED_412_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The request entity too large 413 status code http model. */
static unsigned char* REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL = "413 Request Entity Too Large";
static int* REQUEST_ENTITY_TOO_LARGE_413_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The request-uri too long 414 status code http model. */
static unsigned char* REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL = "414 Request-URI Too Long";
static int* REQUEST_URI_TOO_LARGE_414_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unsupported media type 415 status code http model. */
static unsigned char* UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL = "415 Unsupported Media Type";
static int* UNSUPPORTED_MEDIA_TYPE_415_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The requested range not satisfiable 416 status code http model. */
static unsigned char* REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL = "416 Requested Range Not Satisfiable";
static int* REQUESTED_RANGE_NOT_SATISFIABLE_416_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The expectation failed 417 status code http model. */
static unsigned char* EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL = "417 Expectation Failed";
static int* EXPECTATION_FAILED_417_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The unprocessable entity 422 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static unsigned char* UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL = "422 Unprocessable Entity";
static int* UNPROCESSABLE_ENTITY_422_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/**
 * The locked 423 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static unsigned char* LOCKED_423_STATUS_CODE_HTTP_MODEL = "423 Locked";
static int* LOCKED_423_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/**
 * The failed dependency (site too ugly) 424 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static unsigned char* FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL = "424 Failed Dependency";
static int* FAILED_DEPENDENCY_424_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

//
// 5xx - server error
//
// Response status codes beginning with the digit "5" indicate cases in which the server is
// aware that it has erred or is incapable of performing the request. Except when responding
// to a HEAD request, the server should include an entity containing an explanation of the
// error situation, and whether it is a temporary or permanent condition. User agents should
// display any included entity to the user. These response codes are applicable to any request method.
//

/** The internal server error 500 status code http model. */
static unsigned char* INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL = "500 Internal Server Error";
static int* INTERNAL_SERVER_ERROR_500_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not implemented 501 status code http model. */
static unsigned char* NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL = "501 Not Implemented";
static int* NOT_IMPLEMENTED_501_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bad gateway 502 status code http model. */
static unsigned char* BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL = "502 Bad Gateway";
static int* BAD_GATEWAY_502_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The service unavailable 503 status code http model. */
static unsigned char* SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL = "503 Service Unavailable";
static int* SERVICE_UNAVAILABLE_503_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gateway timeout 504 status code http model. */
static unsigned char* GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL = "504 Gateway Timeout";
static int* GATEWAY_TIMEOUT_504_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http version not supported 505 status code http model. */
static unsigned char* HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL = "505 HTTP Version Not Supported";
static int* HTTP_VERSION_NOT_SUPPORTED_505_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The insufficient storage 507 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static unsigned char* INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL = "507 Insufficient Storage";
static int* INSUFFICIENT_STORAGE_507_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/**
 * The bandwidth limit exceeded 509 status code http model.
 *
 * Not part of the "Hypertext Transfer Protocol -- HTTP/1.1" as found at:
 * http://www.w3.org/Protocols/HTTP/1.1/rfc2616bis/draft-lafon-rfc2616bis-03.html
 */
/*??
static unsigned char* BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL = "509 Bandwidth Limit Exceeded";
static int* BANDWIDTH_LIMIT_EXCEEDED_509_STATUS_CODE_HTTP_MODEL_COUNT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/* STATUS_CODE_HTTP_MODEL_CONSTANT_HEADER */
#endif
