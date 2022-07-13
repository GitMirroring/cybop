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

#ifndef NUMBER_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define NUMBER_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Number (quantity).
//
// The symbol which represents a number is called a numeral.
//
// IANA media type: not defined
// Self-defined media type: number
// This media type is a CYBOL extension.
//

/**
 * The number/byte state cybol format.
 *
 * Byte number (integral data type).
 *
 * This is a CYBOL extension.
 *
 * CAUTION! This format represents numbers in the range 0..255.
 * It is NOT to be mixed up with "text/ascii" representing
 * a text string of characters.
 * Numbers in an array ARE separated by comma;
 * text characters of a string are NOT.
 */
static wchar_t* BYTE_NUMBER_STATE_CYBOL_FORMAT = L"number/byte";
static int* BYTE_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/complex-cartesian state cybol format.
 *
 * Complex number written in cartesian form, that is as
 * comma-separated real part and imaginary part.
 *
 * This is a CYBOL extension.
 *
 * Example:
 * The complex number given in cartesian form:
 * 2 + 3i
 * which can also be written using a "j" instead of "i":
 * 2 + 3j
 * would be written in CYBOL as:
 * 2,3
 */
static wchar_t* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_FORMAT = L"number/complex-cartesian";
static int* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/complex-polar state cybol format.
 *
 * Complex number written in polar form, that is as
 * comma-separated absolute value (modulus) and argument (angle).
 *
 * This is a CYBOL extension.
 *
 * Example:
 * The complex number given in trigonometric form:
 * 2 (cos 30° + i sin 30°)
 * which can also be written in exponential form, using Euler's formula:
 * 2 e ^(i 30)
 * would be written in CYBOL as:
 * 2,30
 */
static wchar_t* COMPLEX_POLAR_NUMBER_STATE_CYBOL_FORMAT = L"number/complex-polar";
static int* COMPLEX_POLAR_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/fraction-decimal state cybol format.
 *
 * Decimal fraction number written as floating-point number.
 *
 * This is a CYBOL extension.
 *
 * Example:
 * 345.678038409
 */
static wchar_t* FRACTION_DECIMAL_NUMBER_STATE_CYBOL_FORMAT = L"number/fraction-decimal";
static int* FRACTION_DECIMAL_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/fraction-vulgar state cybol format.
 *
 * Vulgar fraction number written as comma-separated numerator and denominator.
 *
 * This is a CYBOL extension.
 *
 * Example:
 * The fraction given in vulgar form:
 * 2/3
 * would be written in CYBOL as:
 * 2,3
 */
static wchar_t* FRACTION_VULGAR_NUMBER_STATE_CYBOL_FORMAT = L"number/fraction-vulgar";
static int* FRACTION_VULGAR_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/integer state cybol format.
 *
 * Description:
 *
 * An integer is a datum of integral data type, a data type
 * that represents some range of mathematical integers.
 * It is allowed to contain negative values.
 * The standard type used internally is "int" with 32 Bits.
 * It has a value range from −2,147,483,648 to 2,147,483,647,
 * which is from −(2^31) to 2^31 - 1.
 *
 * Examples:
 *
 * <node name="x" channel="inline" format="number/integer" model="2"/>
 * <node name="y" channel="inline" format="number/integer" model="4"/>
 * <node name="array" channel="inline" format="number/integer" model="1,2,3,4"/>
 */
static wchar_t* INTEGER_NUMBER_STATE_CYBOL_FORMAT = L"number/integer";
static int* INTEGER_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/line-speed state cybol format.
 *
 * Integer number (integral data type), prefixed with a "B".
 * This represents a symbol as defined in the POSIX.1 standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t* LINE_SPEED_NUMBER_STATE_CYBOL_FORMAT = L"number/line-speed";
static int* LINE_SPEED_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* NUMBER_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
