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

#ifndef ENTITY_HEADER_HTTP_CYBOI_NAME_CONSTANT_SOURCE
#define ENTITY_HEADER_HTTP_CYBOI_NAME_CONSTANT_SOURCE

#include <stddef.h>
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

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
static wchar_t ALLOW_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'a', L'l', L'l', L'o', L'w'};
static wchar_t* ALLOW_ENTITY_HEADER_HTTP_CYBOI_NAME = ALLOW_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* ALLOW_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-encoding entity header http cyboi name. */
static wchar_t CONTENT_ENCODING_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* CONTENT_ENCODING_ENTITY_HEADER_HTTP_CYBOI_NAME = CONTENT_ENCODING_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_ENCODING_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-language entity header http cyboi name. */
static wchar_t CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_CYBOI_NAME = CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-length entity header http cyboi name. */
static wchar_t CONTENT_LENGTH_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'e', L'n', L'g', L't', L'h'};
static wchar_t* CONTENT_LENGTH_ENTITY_HEADER_HTTP_CYBOI_NAME = CONTENT_LENGTH_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_LENGTH_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-location entity header http cyboi name. */
static wchar_t CONTENT_LOCATION_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'l', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* CONTENT_LOCATION_ENTITY_HEADER_HTTP_CYBOI_NAME = CONTENT_LOCATION_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_LOCATION_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-md5 entity header http cyboi name. */
static wchar_t CONTENT_MD5_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'm', L'd', L'5'};
static wchar_t* CONTENT_MD5_ENTITY_HEADER_HTTP_CYBOI_NAME = CONTENT_MD5_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_MD5_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-range entity header http cyboi name. */
static wchar_t CONTENT_RANGE_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L'r', L'a', L'n', L'g', L'e'};
static wchar_t* CONTENT_RANGE_ENTITY_HEADER_HTTP_CYBOI_NAME = CONTENT_RANGE_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_RANGE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content-type entity header http cyboi name. */
static wchar_t CONTENT_TYPE_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'-', L't', L'y', L'p', L'e'};
static wchar_t* CONTENT_TYPE_ENTITY_HEADER_HTTP_CYBOI_NAME = CONTENT_TYPE_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_TYPE_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The expires entity header http cyboi name. */
static wchar_t EXPIRES_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'e', L'x', L'p', L'i', L'r', L'e', L's'};
static wchar_t* EXPIRES_ENTITY_HEADER_HTTP_CYBOI_NAME = EXPIRES_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* EXPIRES_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The last-modified entity header http cyboi name. */
static wchar_t LAST_MODIFIED_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY[] = {L'l', L'a', L's', L't', L'-', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* LAST_MODIFIED_ENTITY_HEADER_HTTP_CYBOI_NAME = LAST_MODIFIED_ENTITY_HEADER_HTTP_CYBOI_NAME_ARRAY;
static int* LAST_MODIFIED_ENTITY_HEADER_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ENTITY_HEADER_HTTP_CYBOI_NAME_CONSTANT_SOURCE */
#endif
