/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GENERAL_HEADER_HTTP_CYBOI_NAME_CONSTANT_SOURCE
#define GENERAL_HEADER_HTTP_CYBOI_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/memory/integer_memory_model.c"

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
static wchar_t CACHE_CONTROL_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'a', L'c', L'h', L'e', L'-', L'c', L'o', L'n', L't', L'r', L'o', L'l'};
static wchar_t* CACHE_CONTROL_GENERAL_HEADER_HTTP_CYBOI_NAME = CACHE_CONTROL_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CACHE_CONTROL_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The connection general header http cyboi name. */
static wchar_t CONNECTION_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L'n', L'e', L'c', L't', L'i', L'o', L'n'};
static wchar_t* CONNECTION_GENERAL_HEADER_HTTP_CYBOI_NAME = CONNECTION_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CONNECTION_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The date general header http cyboi name. */
static wchar_t DATE_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'e'};
static wchar_t* DATE_GENERAL_HEADER_HTTP_CYBOI_NAME = DATE_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* DATE_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The pragma general header http cyboi name. */
static wchar_t PRAGMA_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'p', L'r', L'a', L'g', L'm', L'a'};
static wchar_t* PRAGMA_GENERAL_HEADER_HTTP_CYBOI_NAME = PRAGMA_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* PRAGMA_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The trailer general header http cyboi name. */
static wchar_t TRAILER_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L't', L'r', L'a', L'i', L'l', L'e', L'r'};
static wchar_t* TRAILER_GENERAL_HEADER_HTTP_CYBOI_NAME = TRAILER_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* TRAILER_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The transfer-encoding general header http cyboi name. */
static wchar_t TRANSFER_ENCODING_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L't', L'r', L'a', L'n', L's', L'f', L'e', L'r', L'-', L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* TRANSFER_ENCODING_GENERAL_HEADER_HTTP_CYBOI_NAME = TRANSFER_ENCODING_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* TRANSFER_ENCODING_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_17_INTEGER_MEMORY_MODEL_ARRAY;

/** The upgrade general header http cyboi name. */
static wchar_t UPGRADE_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'u', L'p', L'g', L'r', L'a', L'd', L'e'};
static wchar_t* UPGRADE_GENERAL_HEADER_HTTP_CYBOI_NAME = UPGRADE_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* UPGRADE_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The via general header http cyboi name. */
static wchar_t VIA_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'v', L'i', L'a'};
static wchar_t* VIA_GENERAL_HEADER_HTTP_CYBOI_NAME = VIA_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* VIA_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The warning general header http cyboi name. */
static wchar_t WARNING_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'w', L'a', L'r', L'n', L'i', L'n', L'g'};
static wchar_t* WARNING_GENERAL_HEADER_HTTP_CYBOI_NAME = WARNING_GENERAL_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* WARNING_GENERAL_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/* GENERAL_HEADER_HTTP_CYBOI_NAME_CONSTANT_SOURCE */
#endif
