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

#ifndef COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Compare
//
// IANA media type: not defined
// Self-defined media type: compare
// This media type is a CYBOL extension.
//

/**
 * The compare/equal logic cybol format.
 *
 * Description:
 *
 * Compares if left and right value are equal.
 *
 * Commonly used operator in other programming languages: ==
 *
 * Left and right operand as well as the boolean result are treated as vector. That is, one boolean result value is returned per each operand vector element. When comparing single elements, the vectors contain just one single value.
 *
 * Numbers may be given as vectors, for example the integer sequence "1,2,3". If using text operands, for example "Hello, World!", then the single characters are compared, one by one.
 *
 * Example with many elements:
 *
 * - operation: equal
 * - left: 10,2,3
 * - right: 1,2,3
 * - result: 0,1,1 (which corresponds to "false,true,true")
 *
 * Example with one single element:
 *
 * - operation: equal
 * - left: 33
 * - right: 3
 * - result: 0 (which corresponds to "false")
 *
 * Examples:
 *
 * <node name="compare_one" channel="inline" format="compare/equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="2"/>
 *     <node name="right" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * <node name="compare_many" channel="inline" format="compare/equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 * </node>
 *
 * <node name="compare_literal_and_path" channel="inline" format="compare/equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="3"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_via_paths" channel="inline" format="compare/equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".left"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_with_index" channel="inline" format="compare/equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 *     <node name="count" channel="inline" format="number/integer" model="1"/>
 *     <node name="left_index" channel="inline" format="number/integer" model="1"/>
 *     <node name="right_index" channel="inline" format="number/integer" model="0"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean value vector resulting from comparison.
 * - left (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The left operand vector.
 * - right (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The right operand vector.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be compared. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - left_index (optional) [text/cybol-path | number/integer]: The left index from where to start the comparison from. If null, the default is zero.
 * - right_index (optional) [text/cybol-path | number/integer]: The right index from where to start the comparison from. If null, the default is zero.
 */
static wchar_t* EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/equal";
static int* EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/greater logic cybol format.
 *
 * Description:
 *
 * Compares if the left value is greater than the right value.
 *
 * Commonly used operator in other programming languages: >
 *
 * Left and right operand as well as the boolean result are treated as vector. That is, one boolean result value is returned per each operand vector element. When comparing single elements, the vectors contain just one single value.
 *
 * Numbers may be given as vectors, for example the integer sequence "1,2,3". If using text operands, for example "Hello, World!", then the single characters are compared, one by one.
 *
 * Example with many elements:
 *
 * - operation: greater
 * - left: 10,2,3
 * - right: 1,2,3
 * - result: 0,1,1 (which corresponds to "false,true,true")
 *
 * Example with one single element:
 *
 * - operation: greater
 * - left: 33
 * - right: 3
 * - result: 0 (which corresponds to "false")
 *
 * Examples:
 *
 * <node name="compare_one" channel="inline" format="compare/greater" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="2"/>
 *     <node name="right" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * <node name="compare_many" channel="inline" format="compare/greater" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 * </node>
 *
 * <node name="compare_literal_and_path" channel="inline" format="compare/greater" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="3"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_via_paths" channel="inline" format="compare/greater" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".left"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_with_index" channel="inline" format="compare/greater" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 *     <node name="count" channel="inline" format="number/integer" model="1"/>
 *     <node name="left_index" channel="inline" format="number/integer" model="1"/>
 *     <node name="right_index" channel="inline" format="number/integer" model="0"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean value vector resulting from comparison.
 * - left (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The left operand vector.
 * - right (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The right operand vector.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be compared. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - left_index (optional) [text/cybol-path | number/integer]: The left index from where to start the comparison from. If null, the default is zero.
 * - right_index (optional) [text/cybol-path | number/integer]: The right index from where to start the comparison from. If null, the default is zero.
 */
static wchar_t* GREATER_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/greater";
static int* GREATER_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/greater-or-equal logic cybol format.
 *
 * Description:
 *
 * Compares if the left value is greater than the right value or both are equal.
 *
 * Commonly used operator in other programming languages: >=
 *
 * Left and right operand as well as the boolean result are treated as vector. That is, one boolean result value is returned per each operand vector element. When comparing single elements, the vectors contain just one single value.
 *
 * Numbers may be given as vectors, for example the integer sequence "1,2,3". If using text operands, for example "Hello, World!", then the single characters are compared, one by one.
 *
 * Example with many elements:
 *
 * - operation: greater-or-equal
 * - left: 10,2,3
 * - right: 1,2,3
 * - result: 0,1,1 (which corresponds to "false,true,true")
 *
 * Example with one single element:
 *
 * - operation: greater-or-equal
 * - left: 33
 * - right: 3
 * - result: 0 (which corresponds to "false")
 *
 * Examples:
 *
 * <node name="compare_one" channel="inline" format="compare/greater-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="2"/>
 *     <node name="right" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * <node name="compare_many" channel="inline" format="compare/greater-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 * </node>
 *
 * <node name="compare_literal_and_path" channel="inline" format="compare/greater-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="3"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_via_paths" channel="inline" format="compare/greater-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".left"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_with_index" channel="inline" format="compare/greater-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 *     <node name="count" channel="inline" format="number/integer" model="1"/>
 *     <node name="left_index" channel="inline" format="number/integer" model="1"/>
 *     <node name="right_index" channel="inline" format="number/integer" model="0"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean value vector resulting from comparison.
 * - left (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The left operand vector.
 * - right (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The right operand vector.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be compared. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - left_index (optional) [text/cybol-path | number/integer]: The left index from where to start the comparison from. If null, the default is zero.
 * - right_index (optional) [text/cybol-path | number/integer]: The right index from where to start the comparison from. If null, the default is zero.
 */
static wchar_t* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/greater-or-equal";
static int* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/less logic cybol format.
 *
 * Description:
 *
 * Compares if the left value is lesser than the right value.
 *
 * Commonly used operator in other programming languages: <
 *
 * Left and right operand as well as the boolean result are treated as vector. That is, one boolean result value is returned per each operand vector element. When comparing single elements, the vectors contain just one single value.
 *
 * Numbers may be given as vectors, for example the integer sequence "1,2,3". If using text operands, for example "Hello, World!", then the single characters are compared, one by one.
 *
 * Example with many elements:
 *
 * - operation: less
 * - left: 10,2,3
 * - right: 1,2,3
 * - result: 0,1,1 (which corresponds to "false,true,true")
 *
 * Example with one single element:
 *
 * - operation: less
 * - left: 33
 * - right: 3
 * - result: 0 (which corresponds to "false")
 *
 * Examples:
 *
 * <node name="compare_one" channel="inline" format="compare/less" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="2"/>
 *     <node name="right" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * <node name="compare_many" channel="inline" format="compare/less" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 * </node>
 *
 * <node name="compare_literal_and_path" channel="inline" format="compare/less" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="3"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_via_paths" channel="inline" format="compare/less" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".left"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_with_index" channel="inline" format="compare/less" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 *     <node name="count" channel="inline" format="number/integer" model="1"/>
 *     <node name="left_index" channel="inline" format="number/integer" model="1"/>
 *     <node name="right_index" channel="inline" format="number/integer" model="0"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean value vector resulting from comparison.
 * - left (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The left operand vector.
 * - right (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The right operand vector.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be compared. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - left_index (optional) [text/cybol-path | number/integer]: The left index from where to start the comparison from. If null, the default is zero.
 * - right_index (optional) [text/cybol-path | number/integer]: The right index from where to start the comparison from. If null, the default is zero.
 */
static wchar_t* LESS_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/less";
static int* LESS_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/less-or-equal logic cybol format.
 *
 * Description:
 *
 * Compares if the left value is lesser than the right value or both are equal.
 *
 * Commonly used operator in other programming languages: <=
 *
 * Left and right operand as well as the boolean result are treated as vector. That is, one boolean result value is returned per each operand vector element. When comparing single elements, the vectors contain just one single value.
 *
 * Numbers may be given as vectors, for example the integer sequence "1,2,3". If using text operands, for example "Hello, World!", then the single characters are compared, one by one.
 *
 * Example with many elements:
 *
 * - operation: less-or-equal
 * - left: 10,2,3
 * - right: 1,2,3
 * - result: 0,1,1 (which corresponds to "false,true,true")
 *
 * Example with one single element:
 *
 * - operation: less-or-equal
 * - left: 33
 * - right: 3
 * - result: 0 (which corresponds to "false")
 *
 * Examples:
 *
 * <node name="compare_one" channel="inline" format="compare/less-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="2"/>
 *     <node name="right" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * <node name="compare_many" channel="inline" format="compare/less-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 * </node>
 *
 * <node name="compare_literal_and_path" channel="inline" format="compare/less-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="3"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_via_paths" channel="inline" format="compare/less-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".left"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_with_index" channel="inline" format="compare/less-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 *     <node name="count" channel="inline" format="number/integer" model="1"/>
 *     <node name="left_index" channel="inline" format="number/integer" model="1"/>
 *     <node name="right_index" channel="inline" format="number/integer" model="0"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean value vector resulting from comparison.
 * - left (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The left operand vector.
 * - right (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The right operand vector.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be compared. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - left_index (optional) [text/cybol-path | number/integer]: The left index from where to start the comparison from. If null, the default is zero.
 * - right_index (optional) [text/cybol-path | number/integer]: The right index from where to start the comparison from. If null, the default is zero.
 */
static wchar_t* LESS_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/less-or-equal";
static int* LESS_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/unequal logic cybol format.
 *
 * Description:
 *
 * Compares if left and right value are unequal.
 *
 * Commonly used operators in other programming languages: != <>
 *
 * Left and right operand as well as the boolean result are treated as vector. That is, one boolean result value is returned per each operand vector element. When comparing single elements, the vectors contain just one single value.
 *
 * Numbers may be given as vectors, for example the integer sequence "1,2,3". If using text operands, for example "Hello, World!", then the single characters are compared, one by one.
 *
 * Example with many elements:
 *
 * - operation: unequal
 * - left: 10,2,3
 * - right: 1,2,3
 * - result: 0,1,1 (which corresponds to "false,true,true")
 *
 * Example with one single element:
 *
 * - operation: unequal
 * - left: 33
 * - right: 3
 * - result: 0 (which corresponds to "false")
 *
 * Examples:
 *
 * <node name="compare_one" channel="inline" format="compare/unequal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="2"/>
 *     <node name="right" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * <node name="compare_many" channel="inline" format="compare/unequal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 * </node>
 *
 * <node name="compare_literal_and_path" channel="inline" format="compare/unequal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="3"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_via_paths" channel="inline" format="compare/unequal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".left"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".right"/>
 * </node>
 *
 * <node name="compare_with_index" channel="inline" format="compare/unequal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="right" channel="inline" format="number/integer" model="2,3,4"/>
 *     <node name="count" channel="inline" format="number/integer" model="1"/>
 *     <node name="left_index" channel="inline" format="number/integer" model="1"/>
 *     <node name="right_index" channel="inline" format="number/integer" model="0"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean value vector resulting from comparison.
 * - left (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The left operand vector.
 * - right (required) [text/cybol-path | number/any | text/plain | element/part | element/property]: The right operand vector.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be compared. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - left_index (optional) [text/cybol-path | number/integer]: The left index from where to start the comparison from. If null, the default is zero.
 * - right_index (optional) [text/cybol-path | number/integer]: The right index from where to start the comparison from. If null, the default is zero.
 */
static wchar_t* UNEQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/unequal";
static int* UNEQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
