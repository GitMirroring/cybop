/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ENTITY_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER
#define ENTITY_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER

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

/** The allow entity header http cyboi name. */
static wchar_t* ALLOW_ENTITY_HEADER_HTTP_CYBOI_NAME = L"allow";
static int* ALLOW_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-encoding entity header http cyboi name. */
static wchar_t* CONTENT_ENCODING_ENTITY_HEADER_HTTP_CYBOI_NAME = L"content-encoding";
static int* CONTENT_ENCODING_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-language entity header http cyboi name. */
static wchar_t* CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_CYBOI_NAME = L"content-language";
static int* CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-length entity header http cyboi name. */
static wchar_t* CONTENT_LENGTH_ENTITY_HEADER_HTTP_CYBOI_NAME = L"content-length";
static int* CONTENT_LENGTH_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-location entity header http cyboi name. */
static wchar_t* CONTENT_LOCATION_ENTITY_HEADER_HTTP_CYBOI_NAME = L"content-location";
static int* CONTENT_LOCATION_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-md5 entity header http cyboi name. */
static wchar_t* CONTENT_MD5_ENTITY_HEADER_HTTP_CYBOI_NAME = L"content-md5";
static int* CONTENT_MD5_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-range entity header http cyboi name. */
static wchar_t* CONTENT_RANGE_ENTITY_HEADER_HTTP_CYBOI_NAME = L"content-range";
static int* CONTENT_RANGE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-type entity header http cyboi name. */
static wchar_t* CONTENT_TYPE_ENTITY_HEADER_HTTP_CYBOI_NAME = L"content-type";
static int* CONTENT_TYPE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The expires entity header http cyboi name. */
static wchar_t* EXPIRES_ENTITY_HEADER_HTTP_CYBOI_NAME = L"expires";
static int* EXPIRES_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The last-modified entity header http cyboi name. */
static wchar_t* LAST_MODIFIED_ENTITY_HEADER_HTTP_CYBOI_NAME = L"last-modified";
static int* LAST_MODIFIED_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ENTITY_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER */
#endif
