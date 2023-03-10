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

#ifndef REQUEST_METHOD_HTTP_MODEL_CONSTANT_HEADER
#define REQUEST_METHOD_HTTP_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The connect request method http model. Connects via ssl tunnel on proxy server. */
static unsigned char* CONNECT_REQUEST_METHOD_HTTP_MODEL = "CONNECT";
static int* CONNECT_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The delete request method http model. Deletes the specified file on the webserver. */
static unsigned char* DELETE_REQUEST_METHOD_HTTP_MODEL = "DELETE";
static int* DELETE_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The get request method http model. Transfers content from server as arguments in uri. */
static unsigned char* GET_REQUEST_METHOD_HTTP_MODEL = "GET";
static int* GET_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The head request method http model. Sends GET or POST request header, but not content. */
static unsigned char* HEAD_REQUEST_METHOD_HTTP_MODEL = "HEAD";
static int* HEAD_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The options request method http model. Returns a list of methods and features supported by the webserver. */
static unsigned char* OPTIONS_REQUEST_METHOD_HTTP_MODEL = "OPTIONS";
static int* OPTIONS_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The post request method http model. Transfers content from server in an additional data block consisting of name-value pairs. */
static unsigned char* POST_REQUEST_METHOD_HTTP_MODEL = "POST";
static int* POST_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The put request method http model. Uploads data to webserver via given uri. */
static unsigned char* PUT_REQUEST_METHOD_HTTP_MODEL = "PUT";
static int* PUT_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The trace request method http model. Returns the request as the webserver received it. */
static unsigned char* TRACE_REQUEST_METHOD_HTTP_MODEL = "TRACE";
static int* TRACE_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REQUEST_METHOD_HTTP_MODEL_CONSTANT_HEADER */
#endif
