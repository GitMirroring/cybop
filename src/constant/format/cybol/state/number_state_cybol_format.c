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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NUMBER_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define NUMBER_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The CYBOL type constants' names and values have been adapted to follow
// the style of the Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//
// Since the MIME standard does not offer media types for certain data,
// CYBOL had to invent new languages (media types), e.g. for dates, numbers etc.
// This is not meant to pollute the MIME standard, just to fill a gap!
// In case IANA adopts these extensions one day -- fine.
// If, however, other media type values replacing ours are proposed,
// we are open to adapt the CYBOL language specification accordingly.
//

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
 * The number/complex-cartesian state cybol type.
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
static wchar_t COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_FORMAT_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'c', L'o', L'm', L'p', L'l', L'e', L'x', L'-', L'c', L'a', L'r', L't', L'e', L's', L'i', L'a', L'n'};
static wchar_t* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_FORMAT = COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_FORMAT_ARRAY;
static int* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/complex-polar state cybol type.
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
static wchar_t COMPLEX_POLAR_NUMBER_STATE_CYBOL_FORMAT_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'c', L'o', L'm', L'p', L'l', L'e', L'x', L'-', L'p', L'o', L'l', L'a', L'r'};
static wchar_t* COMPLEX_POLAR_NUMBER_STATE_CYBOL_FORMAT = COMPLEX_POLAR_NUMBER_STATE_CYBOL_FORMAT_ARRAY;
static int* COMPLEX_POLAR_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/fraction-decimal state cybol type.
 *
 * Decimal fraction number written as floating-point number.
 *
 * This is a CYBOL extension.
 *
 * Example:
 * 345.678038409
 */
static wchar_t FRACTION_DECIMAL_NUMBER_STATE_CYBOL_FORMAT_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'f', L'r', L'a', L'c', L't', L'i', L'o', L'n', L'-', L'd', L'e', L'c', L'i', L'm', L'a', L'l'};
static wchar_t* FRACTION_DECIMAL_NUMBER_STATE_CYBOL_FORMAT = FRACTION_DECIMAL_NUMBER_STATE_CYBOL_FORMAT_ARRAY;
static int* FRACTION_DECIMAL_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/fraction-vulgar state cybol type.
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
static wchar_t FRACTION_VULGAR_NUMBER_STATE_CYBOL_FORMAT_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'f', L'r', L'a', L'c', L't', L'i', L'o', L'n', L'-', L'v', L'u', L'l', L'g', L'a', L'r'};
static wchar_t* FRACTION_VULGAR_NUMBER_STATE_CYBOL_FORMAT = FRACTION_VULGAR_NUMBER_STATE_CYBOL_FORMAT_ARRAY;
static int* FRACTION_VULGAR_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The number/integer state cybol type.
 *
 * Integer number (integral data type).
 *
 * This is a CYBOL extension.
 */
static wchar_t INTEGER_NUMBER_STATE_CYBOL_FORMAT_ARRAY[] = {L'n', L'u', L'm', L'b', L'e', L'r', L'/', L'i', L'n', L't', L'e', L'g', L'e', L'r'};
static wchar_t* INTEGER_NUMBER_STATE_CYBOL_FORMAT = INTEGER_NUMBER_STATE_CYBOL_FORMAT_ARRAY;
static int* INTEGER_NUMBER_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* NUMBER_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
