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

#ifndef COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

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
 * Compare for equality: ==
 *
 * Left and right operand as well as the boolean result are treated as vector,
 * i.e. ONE boolean result value is returned PER EACH operand vector ELEMENT.
 *
 * When comparing single elements, the vectors contain just one single value.
 *
 * Most operand types may be used. For instance, numbers may be given as vectors,
 * e.g. the integer sequence "1,2,3". If using text operands, e.g. "Hello, World!",
 * then the single characters are compared, one by one.
 *
 * Example with many elements:
 *
 * operation: equal
 * left operand: 10,2,3
 * right operand: 1,2,3
 * result vector: 0,1,1 (which corresponds to "false,true,true")
 *
 * Example with one single element:
 *
 * operation: equal
 * left operand: 33
 * right operand: 3
 * result value: 0 (which corresponds to "false")
 *
 * Description:
 *
Compares left and right parametre.
 *
 * Examples:
 *
 * <node name="compare_equal" channel="inline" format="compare/equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".model.result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".model.left"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".model.right"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/complex-cartesian"/>
 *     <node name="selection" channel="inline" format="text/plain" model="all"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	the knowledge model, in which the result is stored (of type boolean)	true	path/* | logicvalue/boolean
left	the left operand	true	path/* | number/* | text/plain
right	the right operand	true	path/* | number/* | text/plain
type	the operand type which is equal for both operands	true	path/* | meta/type
selection	the area of two strings or number vectors to be compared	true	path/* | meta/type
 *
 * Expected parametres:
 * - result (required): the knowledge model, in which the result is stored (of type boolean)
 * - left (required): the left operand
 * - right (required): the right operand
 * - count (optional): the number of elements to be compared (NOT relevant for lexicographical comparison, where left and right count are used and are allowed to differ)
 * - left index (optional): the left index from where to start the comparison from (NOT relevant for lexicographical comparison)
 * - right index (optional): the right index from where to start the comparison from (NOT relevant for lexicographical comparison)
 */
static wchar_t* EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/equal";
static int* EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/greater logic cybol format.
 *
 * Compare for greaterness: >
 *
 * Description:
 *
Compares left and right parametre.
 *
 * Examples:
 *
 * <node name="compare_loop_count" channel="inline" format="compare/greater" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".counter.break"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".counter.count"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".counter.maximum"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 *     <node name="selection" channel="inline" format="text/plain" model="all"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	the knowledge model, in which the result is stored (of type boolean)	true	path/* | logicvalue/boolean
left	the left operand	true	path/* | number/* | text/plain
right	the right operand	true	path/* | number/* | text/plain
type	the operand type which is equal for both operands	true	path/* | meta/type
selection	the area of two strings or number vectors to be compared	true	path/* | meta/type
 */
static wchar_t* GREATER_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/greater";
static int* GREATER_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/greater-or-equal logic cybol format.
 *
 * Compare for greaterness or equality: >=
 *
 * Description:
 *
Compares left and right parametre.
 *
 * Examples:
 *
 * <node name="compare_loop_count" channel="inline" format="compare/greater-or-equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".domain.break"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".domain.count"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".domain.maximum"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 *     <node name="selection" channel="inline" format="text/plain" model="all"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	the knowledge model, in which the result is stored (of type boolean)	true	path/* | logicvalue/boolean
left	the left operand	true	path/* | number/* | text/plain
right	the right operand	true	path/* | number/* | text/plain
type	the operand type which is equal for both operands	true	path/* | meta/type
selection	the area of two strings or number vectors to be compared	true	path/* | meta/type
 */
static wchar_t* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/greater-or-equal";
static int* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/less logic cybol format.
 *
 * Compare for lessness: <
 *
 * Description:
 *
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* LESS_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/less";
static int* LESS_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/less-or-equal logic cybol format.
 *
 * Compare for lessness or equality: <=
 *
 * Description:
 *
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* LESS_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/less-or-equal";
static int* LESS_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/unequal logic cybol format.
 *
 * Compare for unequality: !=
 *
 * Description:
 *
Compares left and right parametre.
 *
 * Examples:
 *
 * <node name="compare_unequal" channel="inline" format="compare/unequal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".model.result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".model.left"/>
 *     <node name="right" channel="inline" format="text/cybol-path" model=".model.right"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/complex-cartesian"/>
 *     <node name="selection" channel="inline" format="text/plain" model="all"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result	the knowledge model, in which the result is stored (of type boolean)	true	path/* | logicvalue/boolean
left	the left operand	true	path/* | number/* | text/plain
right	the right operand	true	path/* | number/* | text/plain
type	the operand type which is equal for both operands	true	path/* | meta/type
selection	the area of two strings or number vectors to be compared	true	path/* | meta/type
 */
static wchar_t* UNEQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/unequal";
static int* UNEQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
