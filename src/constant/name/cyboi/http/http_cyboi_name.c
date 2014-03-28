/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HTTP_NAME_CONSTANT_SOURCE
#define HTTP_NAME_CONSTANT_SOURCE

#include <stddef.h>
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

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

/** The arguments http cyboi name. */
/*??
static wchar_t ARGUMENTS_HTTP_CYBOI_NAME_ARRAY[] = {L'a', L'r', L'g', L'u', L'm', L'e', L'n', L't', L's'};
static wchar_t* ARGUMENTS_HTTP_CYBOI_NAME = ARGUMENTS_HTTP_CYBOI_NAME_ARRAY;
static int* ARGUMENTS_HTTP_CYBOI_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The body http cyboi name. */
/*??
static wchar_t BODY_HTTP_CYBOI_NAME_ARRAY[] = {L'b', L'o', L'd', L'y'};
static wchar_t* BODY_HTTP_CYBOI_NAME = BODY_HTTP_CYBOI_NAME_ARRAY;
static int* BODY_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The connection http cyboi name. */
/*??
static wchar_t CONNECTION_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L'n', L'e', L'c', L't', L'i', L'o', L'n'};
static wchar_t* CONNECTION_HTTP_CYBOI_NAME = CONNECTION_HTTP_CYBOI_NAME_ARRAY;
static int* CONNECTION_HTTP_CYBOI_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content_language http cyboi name. */
/*??
static wchar_t CONTENT_LANGUAGE_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* CONTENT_LANGUAGE_HTTP_CYBOI_NAME = CONTENT_LANGUAGE_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_LANGUAGE_HTTP_CYBOI_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content_length http cyboi name. */
/*??
static wchar_t CONTENT_LENGTH_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L'l', L'e', L'n', L'g', L't', L'h'};
static wchar_t* CONTENT_LENGTH_HTTP_CYBOI_NAME = CONTENT_LENGTH_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_LENGTH_HTTP_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content_type http cyboi name. */
/*??
static wchar_t CONTENT_TYPE_HTTP_CYBOI_NAME_ARRAY[] = {L'c', L'o', L'n', L't', L'e', L'n', L't', L'_', L't', L'y', L'p', L'e'};
static wchar_t* CONTENT_TYPE_HTTP_CYBOI_NAME = CONTENT_TYPE_HTTP_CYBOI_NAME_ARRAY;
static int* CONTENT_TYPE_HTTP_CYBOI_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The date http cyboi name. */
/*??
static wchar_t DATE_HTTP_CYBOI_NAME_ARRAY[] = {L'd', L'a', L't', L'e'};
static wchar_t* DATE_HTTP_CYBOI_NAME = DATE_HTTP_CYBOI_NAME_ARRAY;
static int* DATE_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The host http cyboi name. */
/*??
static wchar_t HOST_HTTP_CYBOI_NAME_ARRAY[] = {L'h', L'o', L's', L't'};
static wchar_t* HOST_HTTP_CYBOI_NAME = HOST_HTTP_CYBOI_NAME_ARRAY;
static int* HOST_HTTP_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The last_modified http cyboi name. */
/*??
static wchar_t LAST_MODIFIED_HTTP_CYBOI_NAME_ARRAY[] = {L'l', L'a', L's', L't', L'_', L'm', L'o', L'd', L'i', L'f', L'i', L'e', L'd'};
static wchar_t* LAST_MODIFIED_HTTP_CYBOI_NAME = LAST_MODIFIED_HTTP_CYBOI_NAME_ARRAY;
static int* LAST_MODIFIED_HTTP_CYBOI_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The location http cyboi name. */
/*??
static wchar_t LOCATION_HTTP_CYBOI_NAME_ARRAY[] = {L'l', L'o', L'c', L'a', L't', L'i', L'o', L'n'};
static wchar_t* LOCATION_HTTP_CYBOI_NAME = LOCATION_HTTP_CYBOI_NAME_ARRAY;
static int* LOCATION_HTTP_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The method http cyboi name. */
static wchar_t METHOD_HTTP_CYBOI_NAME_ARRAY[] = {L'm', L'e', L't', L'h', L'o', L'd'};
static wchar_t* METHOD_HTTP_CYBOI_NAME = METHOD_HTTP_CYBOI_NAME_ARRAY;
static int* METHOD_HTTP_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The protocol http cyboi name. */
static wchar_t PROTOCOL_HTTP_CYBOI_NAME_ARRAY[] = {L'p', L'r', L'o', L't', L'o', L'c', L'o', L'l'};
static wchar_t* PROTOCOL_HTTP_CYBOI_NAME = PROTOCOL_HTTP_CYBOI_NAME_ARRAY;
static int* PROTOCOL_HTTP_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server http cyboi name. */
/*??
static wchar_t SERVER_HTTP_CYBOI_NAME_ARRAY[] = {L's', L'e', L'r', L'v', L'e', L'r'};
static wchar_t* SERVER_HTTP_CYBOI_NAME = SERVER_HTTP_CYBOI_NAME_ARRAY;
static int* SERVER_HTTP_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The status_code http cyboi name. */
/*??
static wchar_t STATUS_CODE_HTTP_CYBOI_NAME_ARRAY[] = {L's', L't', L'a', L't', L'u', L's', L'_', L'c', L'o', L'd', L'e'};
static wchar_t* STATUS_CODE_HTTP_CYBOI_NAME = STATUS_CODE_HTTP_CYBOI_NAME_ARRAY;
static int* STATUS_CODE_HTTP_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/**
 * The uri http name.
 *
 * URI - Uniform Resource Identifier
 */
static wchar_t URI_HTTP_CYBOI_NAME_ARRAY[] = {L'u', L'r', L'i'};
static wchar_t* URI_HTTP_CYBOI_NAME = URI_HTTP_CYBOI_NAME_ARRAY;
static int* URI_HTTP_CYBOI_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The uri-text http name.
 *
 * URI - Uniform Resource Identifier
 */
static wchar_t URI_TEXT_HTTP_CYBOI_NAME_ARRAY[] = {L'u', L'r', L'i', L'-', L't', L'e', L'x', L't'};
static wchar_t* URI_TEXT_HTTP_CYBOI_NAME = URI_TEXT_HTTP_CYBOI_NAME_ARRAY;
static int* URI_TEXT_HTTP_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* HTTP_NAME_CONSTANT_SOURCE */
#endif
