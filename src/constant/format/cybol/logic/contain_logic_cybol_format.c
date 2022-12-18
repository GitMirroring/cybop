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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CONTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Contain
//
// IANA media type: not defined
// Self-defined media type: contain
// This media type is a CYBOL extension.
//

/**
 * The contain/any logic cybol format.
 *
 * Description:
 *
 * Compares if the bounded area contains the value.
 *
 * NOT IMPLEMENTED YET! See Java methods "startsWith" and "endsWith".
 *
 * Examples:
 *
 * <node>
 *     <node name="description" channel="inline" format="text/plain" model="TODO"/>
 *     <node name="example" channel="file" format="text/plain" model="api-generator/spec/logic/TODO/TODO/example.txt"/>
 *     <node name="properties" channel="file" format="element/part" model="api-generator/spec/logic/TODO/TODO/properties.cybol"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean result.
 * - value (required) [text/cybol-path]: The value to be searched.
 * - left (required) [text/cybol-path]: The left bound.
 * - right (required) [text/cybol-path]: The right bound.
 */
static wchar_t* ANY_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/any";
static int* ANY_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contain/left logic cybol format.
 *
 * Compare if bounded area contains value.
 *
 * Description:
 *
Compare if bounded area contains value.
 *
 * Examples:
 *
<node>
 *     <node name="description" channel="inline" format="text/plain" model="TODO"/>
 *     <node name="example" channel="file" format="text/plain" model="api-generator/spec/logic/TODO/TODO/example.txt"/>
 *     <node name="properties" channel="file" format="element/part" model="api-generator/spec/logic/TODO/TODO/properties.cybol"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result    the knowledge model, in which the result is stored    true    path/* | logicvalue/boolean
left    the left part    true    path/* | number/* | text/plain
right    the right part    true    path/* | number/* | text/plain
 */
static wchar_t* LEFT_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/left";
static int* LEFT_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contain/right logic cybol format.
 *
 * Compare if bounded area contains value.
 *
 * Description:
 *
Compare if bounded area contains value.
 *
 * Examples:
 *
<node>
 *     <node name="description" channel="inline" format="text/plain" model="TODO"/>
 *     <node name="example" channel="file" format="text/plain" model="api-generator/spec/logic/TODO/TODO/example.txt"/>
 *     <node name="properties" channel="file" format="element/part" model="api-generator/spec/logic/TODO/TODO/properties.cybol"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
result    the knowledge model, in which the result is stored    true    path/* | logicvalue/boolean
left    the left part    true    path/* | number/* | text/plain
right    the right part    true    path/* | number/* | text/plain
 */
static wchar_t* RIGHT_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/right";
static int* RIGHT_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CONTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
