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
 * The calculate/add-many logic cybol format.
 *
 * Description:
 *
 * Adds the many numbers contained in a separate operand node to the result.
 *
 * sum = summand_1 + summand_2 + summand_3 (etc.)
 *
 * This is similar to functional programming using many operands like for example in clojure:
 * (+ 24 4 3 2)
 *
 * Caution! Do not mix this up with vector addition "calculate/add" where the operand
 * represents an array of numbers like for example "4,3,2" given in just one node.
 *
 * Examples:
 *
 * <node name="add_operands_loaded_from_file" channel="inline" format="calculate/add-many" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".sum"/>
 *     <node name="operand" channel="file" format="element/part" model="addition/many/summands.cybol"/>
 * </node>
 *
 * <node name="add_operands_contained_as_children_in_tree_node" channel="inline" format="calculate/add-many" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".sum"/>
 *     <node name="operand" channel="inline" format="text/cybol-path" model=".list-of-numbers"/>
 * </node>
 *
 * The list of numbers could be defined as follows:
 *
 * <node>
 *     <node name="number_1" channel="inline" format="number/integer" model="4"/>
 *     <node name="number_2" channel="inline" format="number/integer" model="3"/>
 *     <node name="number_3" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The sum resulting from the addition. It initially represents the first summand.
 * - operand (required) [text/cybol-path | element/part]: The list of summands given as separate node containing the actual numbers.
 */
static wchar_t* ADD_MANY_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/add-many";
static int* ADD_MANY_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
 * The calculate/divide-many logic cybol format.
 *
 * Description:
 *
 * Divides the result by the many numbers contained in a separate operand node.
 *
 * quotient = dividend / divisor_1 / divisor_2 / divisor_3 (etc.)
 *
 * This is similar to functional programming using many operands like for example in clojure:
 * (/ 24 4 3 2)
 *
 * Caution! Do not mix this up with vector division "calculate/divide" where the operand
 * represents an array of numbers like for example "4,3,2" given in just one node.
 *
 * Examples:
 *
 * <node name="divide_by_operands_loaded_from_file" channel="inline" format="calculate/divide-many" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".quotient"/>
 *     <node name="operand" channel="file" format="element/part" model="division/many/divisors.cybol"/>
 * </node>
 *
 * <node name="divide_by_operands_contained_as_children_in_tree_node" channel="inline" format="calculate/divide-many" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".quotient"/>
 *     <node name="operand" channel="inline" format="text/cybol-path" model=".list-of-numbers"/>
 * </node>
 *
 * The list of numbers could be defined as follows:
 *
 * <node>
 *     <node name="number_1" channel="inline" format="number/integer" model="4"/>
 *     <node name="number_2" channel="inline" format="number/integer" model="3"/>
 *     <node name="number_3" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The quotient resulting from the division. It initially represents the dividend.
 * - operand (required) [text/cybol-path | element/part]: The list of divisors given as separate node containing the actual numbers.
 */
static wchar_t* DIVIDE_MANY_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/divide-many";
static int* DIVIDE_MANY_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
 * The calculate/multiply-many logic cybol format.
 *
 * Description:
 *
 * Multiplies the result with the many numbers contained in a separate operand node.
 *
 * product = factor_1 * factor_2 * factor_3 (etc.)
 *
 * This is similar to functional programming using many operands like for example in clojure:
 * (* 24 4 3 2)
 *
 * Caution! Do not mix this up with vector multiplication "calculate/multiply" where the operand
 * represents an array of numbers like for example "4,3,2" given in just one node.
 *
 * Examples:
 *
 * <node name="multiply_with_operands_loaded_from_file" channel="inline" format="calculate/multiply-many" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".product"/>
 *     <node name="operand" channel="file" format="element/part" model="multiplication/many/factors.cybol"/>
 * </node>
 *
 * <node name="multiply_with_operands_contained_as_children_in_tree_node" channel="inline" format="calculate/multiply-many" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".product"/>
 *     <node name="operand" channel="inline" format="text/cybol-path" model=".list-of-numbers"/>
 * </node>
 *
 * The list of numbers could be defined as follows:
 *
 * <node>
 *     <node name="number_1" channel="inline" format="number/integer" model="4"/>
 *     <node name="number_2" channel="inline" format="number/integer" model="3"/>
 *     <node name="number_3" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The product resulting from the multiplication. It initially represents the first factor.
 * - operand (required) [text/cybol-path | element/part]: The list of factors given as separate node containing the actual numbers.
 */
static wchar_t* MULTIPLY_MANY_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/multiply-many";
static int* MULTIPLY_MANY_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

/**
 * The calculate/subtract-many logic cybol format.
 *
 * Description:
 *
 * Subtracts the many numbers contained in a separate operand node from the result.
 *
 * difference = minuend - subtrahend_1 - subtrahend_2 - subtrahend_3 (etc.)
 *
 * This is similar to functional programming using many operands like for example in clojure:
 * (- 24 4 3 2)
 *
 * Caution! Do not mix this up with vector subtraction "calculate/subtract" where the operand
 * represents an array of numbers like for example "4,3,2" given in just one node.
 *
 * Examples:
 *
 * <node name="subtract_operands_loaded_from_file" channel="inline" format="calculate/subtract-many" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".difference"/>
 *     <node name="operand" channel="file" format="element/part" model="subtraction/many/subtrahends.cybol"/>
 * </node>
 *
 * <node name="subtract_operands_contained_as_children_in_tree_node" channel="inline" format="calculate/subtract-many" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".difference"/>
 *     <node name="operand" channel="inline" format="text/cybol-path" model=".list-of-numbers"/>
 * </node>
 *
 * The list of numbers could be defined as follows:
 *
 * <node>
 *     <node name="number_1" channel="inline" format="number/integer" model="4"/>
 *     <node name="number_2" channel="inline" format="number/integer" model="3"/>
 *     <node name="number_3" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The difference resulting from the subtraction. It initially represents the minuend.
 * - operand (required) [text/cybol-path | element/part]: The list of subtrahends given as separate node containing the actual numbers.
 */
static wchar_t* SUBTRACT_MANY_CALCULATE_LOGIC_CYBOL_FORMAT = L"calculate/subtract-many";
static int* SUBTRACT_MANY_CALCULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CALCULATE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
