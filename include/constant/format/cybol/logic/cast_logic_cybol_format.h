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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CAST_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define CAST_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Cast
//
// IANA media type: not defined
// Self-defined media type: cast
// This media type is a CYBOL extension.
//

/**
 * The cast/byte logic cybol format.
 *
 * Description:
 *
 * Casts a value to type "byte".
 *
 * Examples:
 *
 * <node name="cast_value" channel="inline" format="cast/byte" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".value"/>
 *     <node name="source" channel="inline" format="number/integer" model="123"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination value with the desired type to cast to.
 * - source (required) [text/cybol-path | number/any]: The source value to cast from.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be casted. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from where to start writing values to. If null, the default is zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from where to start reading values from. If null, the default is zero.
 */
static wchar_t* BYTE_CAST_LOGIC_CYBOL_FORMAT = L"cast/byte";
static int* BYTE_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/character logic cybol format.
 *
 * Description:
 *
 * Casts a value to type "character".
 *
 * Examples:
 *
 * <node name="cast_value" channel="inline" format="cast/character" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".value"/>
 *     <node name="source" channel="inline" format="number/integer" model="54"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination value with the desired type to cast to.
 * - source (required) [text/cybol-path | number/any]: The source value to cast from.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be casted. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from where to start writing values to. If null, the default is zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from where to start reading values from. If null, the default is zero.
 */
static wchar_t* CHARACTER_CAST_LOGIC_CYBOL_FORMAT = L"cast/character";
static int* CHARACTER_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/double logic cybol format.
 *
 * Description:
 *
 * Casts a value to type "double".
 *
 * Examples:
 *
 * <node name="cast_value" channel="inline" format="cast/double" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".value"/>
 *     <node name="source" channel="inline" format="number/integer" model="123"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination value with the desired type to cast to.
 * - source (required) [text/cybol-path | number/any]: The source value to cast from.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be casted. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from where to start writing values to. If null, the default is zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from where to start reading values from. If null, the default is zero.
 */
static wchar_t* DOUBLE_CAST_LOGIC_CYBOL_FORMAT = L"cast/double";
static int* DOUBLE_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/integer logic cybol format.
 *
 * Description:
 *
 * Casts a value to type "integer".
 *
 * Examples:
 *
 * <node name="cast_value" channel="inline" format="cast/integer" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".value"/>
 *     <node name="source" channel="inline" format="number/float" model="123.45"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination value with the desired type to cast to.
 * - source (required) [text/cybol-path | number/any]: The source value to cast from.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be casted. This is relevant only for arrays with more than one element. If null, the default is the lesser of left and right operand count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from where to start writing values to. If null, the default is zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from where to start reading values from. If null, the default is zero.
 */
static wchar_t* INTEGER_CAST_LOGIC_CYBOL_FORMAT = L"cast/integer";
static int* INTEGER_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CAST_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
