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

#ifndef RESPONSE_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER
#define RESPONSE_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER

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

/** The accept-ranges response header http cyboi name. */
static wchar_t* ACCEPT_RANGES_RESPONSE_HEADER_HTTP_CYBOI_NAME = L"accept-ranges";
static int* ACCEPT_RANGES_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The age response header http cyboi name. */
static wchar_t* AGE_RESPONSE_HEADER_HTTP_CYBOI_NAME = L"age";
static int* AGE_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The etag response header http cyboi name. */
static wchar_t* ETAG_RESPONSE_HEADER_HTTP_CYBOI_NAME = L"etag";
static int* ETAG_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The location response header http cyboi name. */
static wchar_t* LOCATION_RESPONSE_HEADER_HTTP_CYBOI_NAME = L"location";
static int* LOCATION_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The proxy-authenticate response header http cyboi name. */
static wchar_t* PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_CYBOI_NAME = L"proxy-authenticate";
static int* PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The retry-after response header http cyboi name. */
static wchar_t* RETRY_AFTER_RESPONSE_HEADER_HTTP_CYBOI_NAME = L"retry-after";
static int* RETRY_AFTER_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server response header http cyboi name. */
static wchar_t* SERVER_RESPONSE_HEADER_HTTP_CYBOI_NAME = L"server";
static int* SERVER_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The www-authenticate response header http cyboi name. */
static wchar_t* WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_CYBOI_NAME = L"www-authenticate";
static int* WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RESPONSE_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER */
#endif
