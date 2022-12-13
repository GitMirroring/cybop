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

#ifndef CHECK_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CHECK_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Check
//
// IANA media type: not defined
// Self-defined media type: check
// This media type is a CYBOL extension.
//

/**
 * The check/equal logic cybol format.
 *
 * Description:
 *
 * Checks lexicographically if left and right parametre are equal.
 *
 * Lexicographical comparison is usually applied to text, but can be used for vectors of other types as well.
 *
 * Even though both operands are vectors, there is always just one boolean result value altogether.
 *
 * Internally, the lexicographical flag is set to true also for deep comparison of compound parts of type "element/part", so that only one result value gets returned.
 *
 * Examples:
 *
 * <node name="check_equal" channel="inline" format="check/equal" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="left" channel="inline" format="text/cybol-path" model=".some_string"/>
 *     <node name="right" channel="inline" format="text/plain" model="Hello"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean value resulting from lexicographical comparison.
 * - left (required) [text/cybol-path | text/plain]: The left operand.
 * - right (required) [text/cybol-path | text/plain]: The right operand.
 */
static wchar_t* EQUAL_CHECK_LOGIC_CYBOL_FORMAT = L"check/equal";
static int* EQUAL_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/greater logic cybol format.
 *
 * Check lexicographically for greaterness: >
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
static wchar_t* GREATER_CHECK_LOGIC_CYBOL_FORMAT = L"check/greater";
static int* GREATER_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/greater-or-equal logic cybol format.
 *
 * Check lexicographically for greaterness or equality: >=
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
static wchar_t* GREATER_OR_EQUAL_CHECK_LOGIC_CYBOL_FORMAT = L"check/greater-or-equal";
static int* GREATER_OR_EQUAL_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/less logic cybol format.
 *
 * Check lexicographically for lessness: <
 *
 * Description:
 *
Compares left and right parametre.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* LESS_CHECK_LOGIC_CYBOL_FORMAT = L"check/less";
static int* LESS_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/less-or-equal logic cybol format.
 *
 * Check lexicographically for lessness or equality: <=
 *
 * Description:
 *
Compares left and right parametre.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* LESS_OR_EQUAL_CHECK_LOGIC_CYBOL_FORMAT = L"check/less-or-equal";
static int* LESS_OR_EQUAL_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/unequal logic cybol format.
 *
 * Check lexicographically for unequality: !=
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
static wchar_t* UNEQUAL_CHECK_LOGIC_CYBOL_FORMAT = L"check/unequal";
static int* UNEQUAL_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CHECK_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
