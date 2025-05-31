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

#ifndef JSON_NAME_CONSTANT_HEADER
#define JSON_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The begin array json name. */
static wchar_t* BEGIN_ARRAY_JSON_NAME = LEFT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* BEGIN_ARRAY_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The begin end string json name. */
static wchar_t* BEGIN_END_STRING_JSON_NAME = QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* BEGIN_END_STRING_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The begin object json name. */
static wchar_t* BEGIN_OBJECT_JSON_NAME = LEFT_CURLY_BRACKET_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* BEGIN_OBJECT_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The end array json name. */
static wchar_t* END_ARRAY_JSON_NAME = RIGHT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* END_ARRAY_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The end object json name. */
static wchar_t* END_OBJECT_JSON_NAME = RIGHT_CURLY_BRACKET_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* END_OBJECT_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The name-value separation json name. */
static wchar_t* NAME_VALUE_SEPARATION_JSON_NAME = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* NAME_VALUE_SEPARATION_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The separation json name. */
static wchar_t* SEPARATION_JSON_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATION_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* JSON_NAME_CONSTANT_HEADER */
#endif
