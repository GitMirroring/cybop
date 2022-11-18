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

#ifndef CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Calculate
//
// IANA media type: not defined
// Self-defined media type: calculate
// This media type is a CYBOL extension.
//

/**
 * The calculate/absolute logic cybol format.
 *
 * Description:
 *
 * Determines the absolute value of a number.
 *
 * Examples:
 *
 * <node name="absolute" channel="inline" format="calculate/absolute" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="-2,+4"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The absolute value of the given number.
 * - operand (required) [text/cybol-path | number/any]: The source number.
 */
static wchar_t* ABSOLUTE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/absolute";
static int* ABSOLUTE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/add logic cybol format.
 *
 * Description:
 *
 * Adds the operand to the result.
 *
 * Caution! Do not use this operation for characters (strings)!
 * They may be concatenated by using the "modify/append" operation.
 *
 * Examples:
 *
 * <node name="add_integer" channel="inline" format="calculate/add" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * <node name="add_arrays_with_equal_size" channel="inline" format="calculate/add" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="1,2,3"/>
 * </node>
 *
 * <node name="add_summand_to_sum" channel="inline" format="calculate/add" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".sum"/>
 *     <node name="operand" channel="inline" format="text/cybol-path" model=".summand"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The sum resulting from the addition. It initially represents the first summand.
 * - operand (required) [text/cybol-path | number/any]: The second summand.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from which to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from which to start calculating. If null, the default is zero.
 */
static wchar_t* ADD_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/add";
static int* ADD_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/divide logic cybol format.
 *
 * Divide a number by another.
 *
 * Description:
 *
Divides two numbers of the given format
 *
 * Examples:
 *
 * <node name="divide" channel="inline" format="calculate/divide" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	The quotient resulting from the divison. It initially contains the dividend.	true	path/*
operand	The divisor for the division.	true	path/* | number/*
type	The number type. It has to be identical for all parametres.	true	path/* | meta/type
 *
 * quotient = dividend / divisor
 */
static wchar_t* DIVIDE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/divide";
static int* DIVIDE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/maximum logic cybol format.
 *
 * Determine the lesser of two values.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * maximum = (x > y) ? x : y
 */
static wchar_t* MAXIMUM_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/maximum";
static int* MAXIMUM_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/minimum logic cybol format.
 *
 * Determine the lesser of two values.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * minimum = (x < y) ? x : y
 */
static wchar_t* MINIMUM_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/minimum";
static int* MINIMUM_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/modulo logic cybol format.
 *
 * Calculate the remainder of an integer division.
 *
 * Description:
 *
Calculate the module of a given value.
 *
 * Examples:
 *
 * <node name="modulo" channel="inline" format="calculate/modulo" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="2"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	The result of the modulo operation.	true	path/*
operand	The factor for the modulo.	true	path/* | number/*
type	The number type. It has to be identical for all parametres.	true	path/* | meta/type
 *
 * remainder = dividend % divisor
 */
static wchar_t* MODULO_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/modulo";
static int* MODULO_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/multiply logic cybol format.
 *
 * Multiply two numbers.
 *
 * Description:
 *
Multiplies two numbers of the given format.
 *
 * Examples:
 *
 * <node name="multiply" channel="inline" format="calculate/multiply" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	The product resulting from the multiplication. It initially contains the first factor.	true	path/*
operand	The second factor for the multiplication.	true	path/* | number/*
type	The number type. It has to be identical for all parametres.	true	path/* | meta/type
 *
 * product = factor_1 * factor_2
 */
static wchar_t* MULTIPLY_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/multiply";
static int* MULTIPLY_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/negate logic cybol format.
 *
 * Negate a number (altering the sign).
 *
 * Description:
 *
Negates a given number.
 *
 * Examples:
 *
 * <node name="negate" channel="inline" format="calculate/negate" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	The output resulting from the negation.	true	path/*
operand	The number which is to negate.	true	path/* | number/*
type	The number type. It has to be identical for all parametres.	true	path/* | meta/type
 *
 * result = - number
 */
static wchar_t* NEGATE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/negate";
static int* NEGATE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/reduce logic cybol format.
 *
 * Reduce a fraction to the lowest common denominator.
 *
 * Description:
 *
Not implemented yet.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Example: lowest common denominator of 12 / 4 and 5 / 3 is 12
 */
static wchar_t* REDUCE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/reduce";
static int* REDUCE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/subtract logic cybol format.
 *
 * Subtract a number from another.
 *
 * Description:
 *
Subtracts two numbers of the given format.
 *
 * Examples:
 *
 * <node name="subtract" channel="inline" format="calculate/subtract" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	The difference resulting from the subtraction. It initially contains the minuend.	true	path/*
operand	The subtrahend for the subtraction.	true	path/* | number/*
type	The number type. It has to be identical for all parametres.	true	path/* | meta/type
 *
 * difference = minuend - subtrahend
 */
static wchar_t* SUBTRACT_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/subtract";
static int* SUBTRACT_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
