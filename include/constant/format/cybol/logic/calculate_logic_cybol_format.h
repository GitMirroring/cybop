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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

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
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
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
 * sum = summand + summand
 *
 * Caution! Do not use this operation for adding characters (strings)!
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
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* ADD_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/add";
static int* ADD_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/decrement logic cybol format.
 *
 * Description:
 *
 * Decrements the number by one.
 *
 * Examples:
 *
 * <node name="decrement_number" channel="inline" format="calculate/decrement" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#number"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The decremented number. It initially represents the number before the operation.
 */
static wchar_t* DECREMENT_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/decrement";
static int* DECREMENT_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/divide logic cybol format.
 *
 * Description:
 *
 * Divides the result by the operand.
 *
 * quotient = dividend / divisor
 *
 * Examples:
 *
 * <node name="divide_by_two" channel="inline" format="calculate/divide" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The quotient resulting from the division. It initially represents the dividend.
 * - operand (required) [text/cybol-path | number/any]: The divisor.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* DIVIDE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/divide";
static int* DIVIDE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/increment logic cybol format.
 *
 * Description:
 *
 * Increments the number by one.
 *
 * Examples:
 *
 * <node name="increment_number" channel="inline" format="calculate/increment" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#number"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The incremented number. It initially represents the number before the operation.
 */
static wchar_t* INCREMENT_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/increment";
static int* INCREMENT_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/maximum logic cybol format.
 *
 * Description:
 *
 * Determines the greater of two values.
 *
 * Examples:
 *
 * <node name="determine_maximum" channel="inline" format="calculate/maximum" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".maximum"/>
 *     <node name="operand" channel="inline" format="number/integer" model=".value"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The greater of the two given values. It initially represents the first value.
 * - operand (required) [text/cybol-path | number/any]: The second value.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* MAXIMUM_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/maximum";
static int* MAXIMUM_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/minimum logic cybol format.
 *
 * Description:
 *
 * Determines the lesser of two values.
 *
 * Examples:
 *
 * <node name="determine_minimum" channel="inline" format="calculate/minimum" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".minimum"/>
 *     <node name="operand" channel="inline" format="number/integer" model=".value"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The lesser of the two given values. It initially represents the first value.
 * - operand (required) [text/cybol-path | number/any]: The second value.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* MINIMUM_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/minimum";
static int* MINIMUM_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/modulo logic cybol format.
 *
 * Description:
 *
 * Determines the remainder of the integer division.
 *
 * remainder = dividend % divisor
 *
 * Examples:
 *
 * <node name="determine_minimum" channel="inline" format="calculate/modulo" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="2"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The remainder of the integer division. It initially represents the dividend.
 * - operand (required) [text/cybol-path | number/any]: The divisor.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* MODULO_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/modulo";
static int* MODULO_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/multiply logic cybol format.
 *
 * Description:
 *
 * Multiplies the result with the operand.
 *
 * product = factor * factor
 *
 * Examples:
 *
 * <node name="multiply" channel="inline" format="calculate/multiply" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="3"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The product resulting from the multiplication. It initially represents the first factor.
 * - operand (required) [text/cybol-path | number/any]: The second factor.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* MULTIPLY_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/multiply";
static int* MULTIPLY_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/negate logic cybol format.
 *
 * Description:
 *
 * Negates a number by altering its sign.
 *
 * result = - operand
 *
 * Examples:
 *
 * <node name="negate_number" channel="inline" format="calculate/negate" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="-4"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The negated number.
 * - operand (required) [text/cybol-path | number/any]: The number to be negated.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* NEGATE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/negate";
static int* NEGATE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/reduce logic cybol format.
 *
 * Description:
 *
 * Reduces a vulgar fraction to the lowest possible denominator.
 *
 * Examples:
 *
 * <node name="reduce_fraction" channel="inline" format="calculate/reduce" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/fraction-vulgar" model="4/8"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The reduced vulgar fraction with lowest possible denominator.
 * - operand (required) [text/cybol-path | number/any]: The vulgar fraction to be reduced.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* REDUCE_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/reduce";
static int* REDUCE_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The calculate/subtract logic cybol format.
 *
 * Description:
 *
 * Subtracts the operand from the result.
 *
 * difference = minuend - subtrahend
 *
 * Examples:
 *
 * <node name="subtract_integer" channel="inline" format="calculate/subtract" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="operand" channel="inline" format="number/integer" model="5"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The difference resulting from the subtraction. It initially represents the minuend.
 * - operand (required) [text/cybol-path | number/any]: The subtrahend.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be calculated. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - result_index (optional) [text/cybol-path | number/integer]: The result index from where to start calculating. If null, the default is zero.
 * - operand_index (optional) [text/cybol-path | number/integer]: The operand index from where to start calculating. If null, the default is zero.
 */
static wchar_t* SUBTRACT_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/subtract";
static int* SUBTRACT_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
