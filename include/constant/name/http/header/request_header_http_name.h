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

#ifndef REQUEST_HEADER_HTTP_NAME_CONSTANT_HEADER
#define REQUEST_HEADER_HTTP_NAME_CONSTANT_HEADER

#include <stddef.h>
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

//
// The following constants are taken from the HTTP 1.1 RFC 2616 specification:
// http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14
// They are sorted alphabetically here.
//

/** The Accept request header http name. */
static unsigned char* ACCEPT_REQUEST_HEADER_HTTP_NAME = "Accept";
static int* ACCEPT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Accept-Charset request header http name. */
static unsigned char* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME = "Accept-Charset";
static int* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Accept-Encoding request header http name. */
static unsigned char* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME = "Accept-Encoding";
static int* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Accept-Language request header http name. */
static unsigned char* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME = "Accept-Language";
static int* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Authorization request header http name. */
static unsigned char* AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = "Authorization";
static int* AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Expect request header http name. */
static unsigned char* EXPECT_REQUEST_HEADER_HTTP_NAME = "Expect";
static int* EXPECT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The From request header http name. */
static unsigned char* FROM_REQUEST_HEADER_HTTP_NAME = "From";
static int* FROM_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Host request header http name. */
static unsigned char* HOST_REQUEST_HEADER_HTTP_NAME = "Host";
static int* HOST_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The If-Match request header http name. */
static unsigned char* IF_MATCH_REQUEST_HEADER_HTTP_NAME = "If-Match";
static int* IF_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The If-Modified-Since request header http name. */
static unsigned char* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = "If-Modified-Since";
static int* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The If-None-Match request header http name. */
static unsigned char* IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME = "If-None-Match";
static int* IF_NONE_MATCH_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The If-Range request header http name. */
static unsigned char* IF_RANGE_REQUEST_HEADER_HTTP_NAME = "If-Range";
static int* IF_RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The If-Unmodified-since request header http name. */
static unsigned char* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME = "If-Unmodified-since";
static int* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Max-Forwards request header http name. */
static unsigned char* MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME = "Max-Forwards";
static int* MAX_FORWARDS_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Proxy-Authorization request header http name. */
static unsigned char* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME = "Proxy-Authorization";
static int* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Range request header http name. */
static unsigned char* RANGE_REQUEST_HEADER_HTTP_NAME = "Range";
static int* RANGE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Referer request header http name. */
static unsigned char* REFERER_REQUEST_HEADER_HTTP_NAME = "Referer";
static int* REFERER_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The TE request header http name. */
static unsigned char* TE_REQUEST_HEADER_HTTP_NAME = "TE";
static int* TE_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The User-Agent request header http name. */
static unsigned char* USER_AGENT_REQUEST_HEADER_HTTP_NAME = "User-Agent";
static int* USER_AGENT_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Vary request header http name. */
static unsigned char* VARY_REQUEST_HEADER_HTTP_NAME = "Vary";
static int* VARY_REQUEST_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REQUEST_HEADER_HTTP_NAME_CONSTANT_HEADER */
#endif
