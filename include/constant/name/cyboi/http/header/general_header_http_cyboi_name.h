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

#ifndef GENERAL_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER
#define GENERAL_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER

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

/** The cache-control general header http cyboi name. */
static wchar_t* CACHE_CONTROL_GENERAL_HEADER_HTTP_CYBOI_NAME = L"cache-control";
static int* CACHE_CONTROL_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The connection general header http cyboi name. */
static wchar_t* CONNECTION_GENERAL_HEADER_HTTP_CYBOI_NAME = L"connection";
static int* CONNECTION_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The date general header http cyboi name. */
static wchar_t* DATE_GENERAL_HEADER_HTTP_CYBOI_NAME = L"date";
static int* DATE_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pragma general header http cyboi name. */
static wchar_t* PRAGMA_GENERAL_HEADER_HTTP_CYBOI_NAME = L"pragma";
static int* PRAGMA_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The trailer general header http cyboi name. */
static wchar_t* TRAILER_GENERAL_HEADER_HTTP_CYBOI_NAME = L"trailer";
static int* TRAILER_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The transfer-encoding general header http cyboi name. */
static wchar_t* TRANSFER_ENCODING_GENERAL_HEADER_HTTP_CYBOI_NAME = L"transfer-encoding";
static int* TRANSFER_ENCODING_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The upgrade general header http cyboi name. */
static wchar_t* UPGRADE_GENERAL_HEADER_HTTP_CYBOI_NAME = L"upgrade";
static int* UPGRADE_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The via general header http cyboi name. */
static wchar_t* VIA_GENERAL_HEADER_HTTP_CYBOI_NAME = L"via";
static int* VIA_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The warning general header http cyboi name. */
static wchar_t* WARNING_GENERAL_HEADER_HTTP_CYBOI_NAME = L"warning";
static int* WARNING_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* GENERAL_HEADER_HTTP_CYBOI_NAME_CONSTANT_HEADER */
#endif
