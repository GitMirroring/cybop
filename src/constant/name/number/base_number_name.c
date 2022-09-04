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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BASE_NUMBER_NAME_CONSTANT_SOURCE
#define BASE_NUMBER_NAME_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The capital hexadecimal 0X base number name. */
static wchar_t* CAPITAL_HEXADECIMAL_BASE_NUMBER_NAME = L"0X";
static int* CAPITAL_HEXADECIMAL_BASE_NUMBER_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The octal 0 base number name. */
static wchar_t* OCTAL_BASE_NUMBER_NAME = DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* OCTAL_BASE_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The small hexadecimal 0x base number name. */
static wchar_t* SMALL_HEXADECIMAL_BASE_NUMBER_NAME = L"0x";
static int* SMALL_HEXADECIMAL_BASE_NUMBER_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BASE_NUMBER_NAME_CONSTANT_SOURCE */
#endif
