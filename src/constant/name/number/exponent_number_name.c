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

#ifndef EXPONENT_NUMBER_NAME_CONSTANT_SOURCE
#define EXPONENT_NUMBER_NAME_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The abbreviation begin exp( exponent number name. */
static wchar_t* ABBREVIATION_BEGIN_EXPONENT_NUMBER_NAME = L"exp(";
static int* ABBREVIATION_BEGIN_EXPONENT_NUMBER_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The end ) exponent number name. */
static wchar_t* END_EXPONENT_NUMBER_NAME = L")";
static int* END_EXPONENT_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The letter begin E( exponent number name. */
static wchar_t* LETTER_BEGIN_EXPONENT_NUMBER_NAME = L"E(";
static int* LETTER_BEGIN_EXPONENT_NUMBER_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The multiplication abbreviation begin *exp( exponent number name. */
static wchar_t* MULTIPLICATION_ABBREVIATION_BEGIN_EXPONENT_NUMBER_NAME = L"*exp(";
static int* MULTIPLICATION_ABBREVIATION_BEGIN_EXPONENT_NUMBER_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The multiplication letter begin *E( exponent number name. */
static wchar_t* MULTIPLICATION_LETTER_BEGIN_EXPONENT_NUMBER_NAME = L"*E(";
static int* MULTIPLICATION_LETTER_BEGIN_EXPONENT_NUMBER_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* EXPONENT_NUMBER_NAME_CONSTANT_SOURCE */
#endif
