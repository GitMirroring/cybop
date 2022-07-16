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

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Number (quantity, the symbol representing a number is called a numeral)
//
// IANA media type: not defined
// Self-defined media type: number
// This media type is a CYBOL extension.
//

/**
 * The number/byte state cybol format.
 *
 * Description:
 *
 * An integer with a size of just one byte.
 *
 * The standard type used internally is unsigned char with 8 Bits.
 * It has a value range from 0 to 255.
 *
 * CAUTION! It is NOT to be mixed up with text/ascii representing
 * a text string of characters. Numbers in an array ARE separated by comma;
 * text characters of a string are NOT.
 *
 * Examples:
 *
 * <node name="x" channel="inline" format="number/byte" model="0"/>
 * <node name="y" channel="inline" format="number/byte" model="2"/>
 * <node name="array" channel="inline" format="number/byte" model="0,1,2,3,4"/>
 */
static wchar_t* BYTE_NUMBER_STATE_CYBOL_FORMAT = L"number/byte";
static int* BYTE_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/complex-cartesian state cybol format.
 *
 * Description:
 *
 * A complex number written in cartesian form as real and imaginary part,
 * separated by a (plus or minus) sign.
 *
 * CAUTION! The i (or j in electrical engineering) in the imaginary part
 * is NEGLECTED: 1+2i --> 1+2.
 *
 * CAUTION! Using fractions for real and imaginary part of a complex number
 * is NOT supported, e.g. -1/2+3/4.
 *
 * The complex number given in cartesian form:
 * 2 + 3i
 * which can also be written using a j instead of i:
 * 2 + 3j
 * would be written in CYBOL as:
 * 2+3
 *
 * Examples:
 *
 * <node name="standard" channel="inline" format="number/complex-cartesian" model="1+2"/>
 * <node name="negative_imaginary_part" channel="inline" format="number/complex-cartesian" model="2-7"/>
 * <node name="negative_real_part" channel="inline" format="number/complex-cartesian" model="-5+5"/>
 * <node name="both_parts_negative" channel="inline" format="number/complex-cartesian" model="-3-2"/>
 * <node name="decimal_fractions" channel="inline" format="number/complex-cartesian" model="-1.23+5.0"/>
 * <node name="scientific_notation" channel="inline" format="number/complex-cartesian" model="-1.23e12+.11e2"/>
 */
static wchar_t* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_FORMAT = L"number/complex-cartesian";
static int* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/complex-polar state cybol format.
 *
 * Description:
 *
 * A complex number written in polar form with absolute value and argument,
 * separated by a (plus or minus) sign.
 *
 * CAUTION! The i (or j in electrical engineering) in the exponent
 * is NEGLECTED: -2*exp(i45) --> -2*exp(45)
 *
 * The complex number given in trigonometric form:
 * 2 (cos 30° + i sin 30°)
 * which can also be written in exponential form, using Euler's formula:
 * 2 e ^(i 30)
 * would be written in CYBOL as:
 * 2*exp(30)
 *
 * CAUTION! The cybol parser is able to recognise many variants,
 * with sequence exp or capital letter E, with or without times sign,
 * as shown in the examples below. However, the RECOMMENDED FORM is as follows:
 *
 * -2*exp(-45)
 *
 * Examples:
 *
 * <node name="standard" channel="inline" format="number/complex-polar" model="-2*exp(-45)"/>
 * <node name="with_capital_letter_e" channel="inline" format="number/complex-polar" model="-2*E(-45)"/>
 * <node name="without_times_sign_1" channel="inline" format="number/complex-polar" model="-2exp(-45)"/>
 * <node name="without_times_sign_2" channel="inline" format="number/complex-polar" model="-2E(-45)"/>
 * <node name="decimal_fraction" channel="inline" format="number/complex-polar" model="-1.23*exp(-45)"/>
 * <node name="scientific_notation" channel="inline" format="number/complex-polar" model="-1.23E4E(-45)"/>
 */
static wchar_t* COMPLEX_POLAR_NUMBER_STATE_CYBOL_FORMAT = L"number/complex-polar";
static int* COMPLEX_POLAR_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/fraction-decimal state cybol format.
 *
 * Description:
 *
 * A decimal fraction number written as floating-point number.
 *
 * The standard type used internally is double with 64 Bits.
 * It has a value range from 2^−1022 to approximately 2^1024,
 * which is from 2 × 10^−308 to 2 × 10^308.
 *
 * CAUTION! The cybol parser is able to recognise many variants,
 * with small or capital letter E, with or without plus sign,
 * as shown in the examples below. However, the RECOMMENDED FORM is as follows:
 *
 * 1.23E+4
 *
 * The plus sign of the number is OPTIONAL.
 * The plus sign of the scientific notation exponent is MANDATORY.
 *
 * Examples:
 *
 * <node name="f1" channel="inline" format="fraction-decimal" model="0.12"/>
 * <node name="f2" channel="inline" format="fraction-decimal" model="24.68"/>
 * <node name="array" channel="inline" format="fraction-decimal" model="1.2,3.4,5.6"/>
 * <node name="scientific_notation" channel="inline" format="fraction-decimal" model="7E-3"/>
 * <node name="small_letter_possible" channel="inline" format="fraction-decimal" model="-1.23e12"/>
 * <node name="optional_plus_sign" channel="inline" format="fraction-decimal" model="-1.23e+4"/>
 * <node name="simple_example" channel="inline" format="fraction-decimal" model="11.0"/>
 * <node name="lacking_decimal_places" channel="inline" format="fraction-decimal" model="11."/>
 * <node name="scientific_notation_1" channel="inline" format="fraction-decimal" model=".11e2"/>
 * <node name="scientific_notation_2" channel="inline" format="fraction-decimal" model="11e0"/>
 * <node name="another_example" channel="inline" format="fraction-decimal" model="0.007"/>
 * <node name="scientific_notation_3" channel="inline" format="fraction-decimal" model="0.7e-2"/>
 * <node name="scientific_notation_4" channel="inline" format="fraction-decimal" model=".7E-2"/>
 */
static wchar_t* FRACTION_DECIMAL_NUMBER_STATE_CYBOL_FORMAT = L"number/fraction-decimal";
static int* FRACTION_DECIMAL_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/fraction-vulgar state cybol format.
 *
 * Description:
 *
 * A fraction number written as numerator and denominator,
 * separated by a bar (solidus, slash).
 *
 * Examples:
 *
 * <node name="f1" channel="inline" format="number/fraction-vulgar" model="1/2"/>
 * <node name="f2" channel="inline" format="number/fraction-vulgar" model="-2/3"/>
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
 *
 * The standard type used internally is int with 32 Bits.
 * It has a value range from −2,147,483,648 to 2,147,483,647,
 * which is from −(2^31) to 2^31 - 1.
 *
 * Examples:
 *
 * <node name="x" channel="inline" format="number/integer" model="2"/>
 * <node name="y" channel="inline" format="number/integer" model="4"/>
 * <node name="array" channel="inline" format="number/integer" model="1,2,3,4"/>
 * <node name="negative" channel="inline" format="number/integer" model="-24"/>
 * <node name="hexadecimal" channel="inline" format="number/integer" model="-0x18"/>
 * <node name="octal" channel="inline" format="number/integer" model="-030"/>
 */
static wchar_t* INTEGER_NUMBER_STATE_CYBOL_FORMAT = L"number/integer";
static int* INTEGER_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/line-speed state cybol format.
 *
 * Integer number (integral data type), prefixed with a B.
 * This represents a symbol as defined in the POSIX.1 standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t* LINE_SPEED_NUMBER_STATE_CYBOL_FORMAT = L"number/line-speed";
static int* LINE_SPEED_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* NUMBER_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
