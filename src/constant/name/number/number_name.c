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

#ifndef NUMBER_NAME_CONSTANT_SOURCE
#define NUMBER_NAME_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The begin exponent abbreviation  exp( number name. */
static wchar_t* BEGIN_EXPONENT_ABBREVIATION_NUMBER_NAME = L"exp(";
static int* BEGIN_EXPONENT_ABBREVIATION_NUMBER_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The begin exponent letter E( number name. */
static wchar_t* BEGIN_EXPONENT_LETTER_NUMBER_NAME = L"E(";
static int* BEGIN_EXPONENT_LETTER_NUMBER_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The begin exponent multiplication abbreviation *exp( number name. */
static wchar_t* BEGIN_EXPONENT_MULTIPLICATION_ABBREVIATION_NUMBER_NAME = L"*exp(";
static int* BEGIN_EXPONENT_MULTIPLICATION_ABBREVIATION_NUMBER_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The begin exponent multiplication letter *E( number name. */
static wchar_t* BEGIN_EXPONENT_MULTIPLICATION_LETTER_NUMBER_NAME = L"*E(";
static int* BEGIN_EXPONENT_MULTIPLICATION_LETTER_NUMBER_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The capital exponent character E number name. */
static wchar_t* CAPITAL_EXPONENT_CHARACTER_NUMBER_NAME = LATIN_CAPITAL_LETTER_E_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* CAPITAL_EXPONENT_CHARACTER_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The decimal separator . number name. */
static wchar_t* DECIMAL_SEPARATOR_NUMBER_NAME = FULL_STOP_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* DECIMAL_SEPARATOR_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The end exponent ) number name. */
static wchar_t* END_EXPONENT_NUMBER_NAME = L")";
static int* END_EXPONENT_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction bar / number name. */
static wchar_t* FRACTION_BAR_NUMBER_NAME = SOLIDUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* FRACTION_BAR_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hexadecimal prefix 0x number name. */
static wchar_t HEXADECIMAL_PREFIX_NUMBER_NAME_ARRAY[] = {0x0030, 0x0078};
static wchar_t* HEXADECIMAL_PREFIX_NUMBER_NAME = HEXADECIMAL_PREFIX_NUMBER_NAME_ARRAY;
static int* HEXADECIMAL_PREFIX_NUMBER_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The minus sign - number name. */
static wchar_t* MINUS_SIGN_NUMBER_NAME = HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* MINUS_SIGN_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The multiplication sign * number name. */
static wchar_t* MULTIPLICATION_SIGN_NUMBER_NAME = MULTIPLICATION_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* MULTIPLICATION_SIGN_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The octal prefix 0 number name. */
static wchar_t* OCTAL_PREFIX_NUMBER_NAME = DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* OCTAL_PREFIX_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The plus sign + number name. */
static wchar_t* PLUS_SIGN_NUMBER_NAME = PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PLUS_SIGN_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The small exponent character e number name. */
static wchar_t* SMALL_EXPONENT_CHARACTER_NUMBER_NAME = LATIN_SMALL_LETTER_E_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SMALL_EXPONENT_CHARACTER_NUMBER_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* NUMBER_NAME_CONSTANT_SOURCE */
#endif
