/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef REQUEST_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER
#define REQUEST_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// The constants defined here are copies of the standard constants
// that may be found in files of this same directory.
//
// The difference is that these constants are of type "wchar_t"
// and are prefixed with "CYBOI_".
//
// This duplication of constants is necessary, because names or models
// of standard formats like HTTP or xDT are not always intuitive,
// so that CYBOI uses its own speaking names internally.
//
// Examples:
// - HTTP header names start with a capital letter, but CYBOI uses lower-case names only
// - xDT fields are represented by numbers, but CYBOI uses speaking names (text) only
//

/** The accept request header http cyboi name. */
static wchar_t* ACCEPT_REQUEST_HEADER_HTTP_CYBOI_NAME = L"accept";
static int* ACCEPT_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accept-charset request header http cyboi name. */
static wchar_t* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_CYBOI_NAME = L"accept-charset";
static int* ACCEPT_CHARSET_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accept-encoding request header http cyboi name. */
static wchar_t* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_CYBOI_NAME = L"accept-encoding";
static int* ACCEPT_ENCODING_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The accept-language request header http cyboi name. */
static wchar_t* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_CYBOI_NAME = L"accept-language";
static int* ACCEPT_LANGUAGE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The authorization request header http cyboi name. */
static wchar_t* AUTHORIZATION_REQUEST_HEADER_HTTP_CYBOI_NAME = L"authorization";
static int* AUTHORIZATION_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The expect request header http cyboi name. */
static wchar_t* EXPECT_REQUEST_HEADER_HTTP_CYBOI_NAME = L"expect";
static int* EXPECT_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The from request header http cyboi name. */
static wchar_t* FROM_REQUEST_HEADER_HTTP_CYBOI_NAME = L"from";
static int* FROM_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The host request header http cyboi name. */
static wchar_t* HOST_REQUEST_HEADER_HTTP_CYBOI_NAME = L"host";
static int* HOST_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The if-match request header http cyboi name. */
static wchar_t* IF_MATCH_REQUEST_HEADER_HTTP_CYBOI_NAME = L"if-match";
static int* IF_MATCH_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The if-modified-since request header http cyboi name. */
static wchar_t* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_CYBOI_NAME = L"if-modified-since";
static int* IF_MODIFIED_SINCE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The if-none-match request header http cyboi name. */
static wchar_t* IF_NONE_MATCH_REQUEST_HEADER_HTTP_CYBOI_NAME = L"if-none-match";
static int* IF_NONE_MATCH_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The if-range request header http cyboi name. */
static wchar_t* IF_RANGE_REQUEST_HEADER_HTTP_CYBOI_NAME = L"if-range";
static int* IF_RANGE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The if-unmodified-since request header http cyboi name. */
static wchar_t* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_CYBOI_NAME = L"if-unmodified-since";
static int* IF_UNMODIFIED_SINCE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The max-forwards request header http cyboi name. */
static wchar_t* MAX_FORWARDS_REQUEST_HEADER_HTTP_CYBOI_NAME = L"max-forwards";
static int* MAX_FORWARDS_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The proxy-authorization request header http cyboi name. */
static wchar_t* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_CYBOI_NAME = L"proxy-authorization";
static int* PROXY_AUTHORIZATION_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The range request header http cyboi name. */
static wchar_t* RANGE_REQUEST_HEADER_HTTP_CYBOI_NAME = L"range";
static int* RANGE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The referer request header http cyboi name. */
static wchar_t* REFERER_REQUEST_HEADER_HTTP_CYBOI_NAME = L"referer";
static int* REFERER_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The te request header http cyboi name. */
static wchar_t* TE_REQUEST_HEADER_HTTP_CYBOI_NAME = L"te";
static int* TE_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The user-agent request header http cyboi name. */
static wchar_t* USER_AGENT_REQUEST_HEADER_HTTP_CYBOI_NAME = L"user-agent";
static int* USER_AGENT_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vary request header http cyboi name. */
static wchar_t* VARY_REQUEST_HEADER_HTTP_CYBOI_NAME = L"vary";
static int* VARY_REQUEST_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REQUEST_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER */
#endif
