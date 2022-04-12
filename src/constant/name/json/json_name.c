/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef JSON_NAME_CONSTANT_SOURCE
#define JSON_NAME_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The array begin [ json name. */
static wchar_t* ARRAY_BEGIN_JSON_NAME = LEFT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ARRAY_BEGIN_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The array end ] json name. */
static wchar_t* ARRAY_END_JSON_NAME = RIGHT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ARRAY_END_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The array value separation , json name. */
static wchar_t* ARRAY_VALUE_SEPARATION_JSON_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ARRAY_VALUE_SEPARATION_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The object begin { json name. */
static wchar_t* OBJECT_BEGIN_JSON_NAME = LEFT_CURLY_BRACKET_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* OBJECT_BEGIN_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The object end } json name. */
static wchar_t* OBJECT_END_JSON_NAME = RIGHT_CURLY_BRACKET_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* OBJECT_END_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The object name-value separation : json name. */
static wchar_t* OBJECT_NAME_VALUE_SEPARATION_JSON_NAME = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* OBJECT_NAME_VALUE_SEPARATION_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The object pair separation , json name. */
static wchar_t* OBJECT_PAIR_SEPARATION_JSON_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* OBJECT_PAIR_SEPARATION_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The string begin end " json name. */
static wchar_t* STRING_BEGIN_END_JSON_NAME = QUOTATION_MARK_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* STRING_BEGIN_END_JSON_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* JSON_NAME_CONSTANT_SOURCE */
#endif
