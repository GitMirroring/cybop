/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Calculate (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: calculate
// This media type is a CYBOL extension.
//

/**
 * The calculate/absolute logic cybol format.
 *
 * Determine the absolute value of a number.
 *
 * absolute = | number |
 *
 * This is a CYBOL extension.
 */
static wchar_t* ABSOLUTE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/absolute";
static int* ABSOLUTE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/add logic cybol format.
 *
 * Add two numbers.
 *
 * sum = summand_1 + summand_2
 *
 * This is a CYBOL extension.
 */
static wchar_t* ADD_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/add";
static int* ADD_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/divide logic cybol format.
 *
 * Divide a number by another.
 *
 * quotient = dividend / divisor
 *
 * This is a CYBOL extension.
 */
static wchar_t* DIVIDE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/divide";
static int* DIVIDE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/modulo logic cybol format.
 *
 * Calculate the remainder of an integer division.
 *
 * remainder = dividend % divisor
 *
 * This is a CYBOL extension.
 */
static wchar_t* MODULO_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/modulo";
static int* MODULO_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/multiply logic cybol format.
 *
 * Multiply two numbers.
 *
 * product = factor_1 * factor_2
 *
 * This is a CYBOL extension.
 */
static wchar_t* MULTIPLY_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/multiply";
static int* MULTIPLY_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/negate logic cybol format.
 *
 * Negate a number (altering the sign).
 *
 * result = - number
 *
 * This is a CYBOL extension.
 */
static wchar_t* NEGATE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/negate";
static int* NEGATE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/reduce logic cybol format.
 *
 * Reduce a fraction to the lowest common denominator.
 *
 * Example: lowest common denominator of 12 / 4 and 5 / 3 is 12
 *
 * This is a CYBOL extension.
 */
static wchar_t* REDUCE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/reduce";
static int* REDUCE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/subtract logic cybol format.
 *
 * Subtract a number from another.
 *
 * difference = minuend - subtrahend
 *
 * This is a CYBOL extension.
 */
static wchar_t* SUBTRACT_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/subtract";
static int* SUBTRACT_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
