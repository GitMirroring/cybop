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

#ifndef BASE_NUMERAL_NAME_CONSTANT_SOURCE
#define BASE_NUMERAL_NAME_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The capital binary 0B base numeral name. */
static wchar_t* CAPITAL_BINARY_BASE_NUMERAL_NAME = L"0B";
static int* CAPITAL_BINARY_BASE_NUMERAL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The capital hexadecimal 0X base numeral name. */
static wchar_t* CAPITAL_HEXADECIMAL_BASE_NUMERAL_NAME = L"0X";
static int* CAPITAL_HEXADECIMAL_BASE_NUMERAL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The capital octal 0O base numeral name. */
static wchar_t* CAPITAL_OCTAL_BASE_NUMERAL_NAME = L"0O";
static int* CAPITAL_OCTAL_BASE_NUMERAL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The octal 0 base numeral name. */
static wchar_t* OCTAL_BASE_NUMERAL_NAME = DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* OCTAL_BASE_NUMERAL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The small binary 0b base numeral name. */
static wchar_t* SMALL_BINARY_BASE_NUMERAL_NAME = L"0b";
static int* SMALL_BINARY_BASE_NUMERAL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The small hexadecimal 0x base numeral name. */
static wchar_t* SMALL_HEXADECIMAL_BASE_NUMERAL_NAME = L"0x";
static int* SMALL_HEXADECIMAL_BASE_NUMERAL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The small octal 0o base numeral name. */
static wchar_t* SMALL_OCTAL_BASE_NUMERAL_NAME = L"0o";
static int* SMALL_OCTAL_BASE_NUMERAL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BASE_NUMERAL_NAME_CONSTANT_SOURCE */
#endif
