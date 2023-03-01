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

#ifndef MEMORISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MEMORISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Memorise
//
// IANA media type: not defined
// Self-defined media type: memorise
// This media type is a CYBOL extension.
//

/**
 * The memorise/create logic cybol format.
 *
 * Description:
 *
 * Allocates an empty part in heap memory, consisting of name and type only.
 *
 * Each knowledge tree node has a double hierarchy with the main model branch representing
 * the whole-part-structure and a second branch representing additional (mostly flat) properties.
 * The "properties" property flag determines where to add the new part to.
 *
 * If the "whole" property is not given (null) and the "properties" flag set to true,
 * then the new part gets added to the knowledge memory root node's properties branch.
 *
 * Examples:
 *
 * <node name="create_fileid" channel="inline" format="memorise/create" model="">
 *     <node name="name" channel="inline" format="text/plain" model="id"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 * </node>
 *
 * <node name="create_summand" channel="inline" format="memorise/create" model="">
 *     <node name="name" channel="inline" format="text/plain" model="summand"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 *     <node name="whole" channel="inline" format="text/cybol-path" model=".addition_application"/>
 * </node>
 *
 * <node name="create_wui_song" channel="inline" format="memorise/create" model="">
 *     <node name="name" channel="inline" format="text/cybol-path" model="#song_name"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="whole" channel="inline" format="text/cybol-path" model=".wui.round.(#round_name).content"/>
 * </node>
 *
 * <node name="create_sub_node_in_root_property_properties" channel="inline" format="memorise/create" model="">
 *     <node name="name" channel="inline" format="text/plain" model="number"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 *     <node name="whole" channel="inline" format="text/cybol-path" model=":some_root_property"/>
 *     <node name="properties" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - name (required) [text/cybol-path | text/plain]: The name of the part to be created.
 * - format (required) [text/cybol-path | meta/format]: The format of the part to be created. The internal data type gets determined from it.
 * - whole (optional) [text/cybol-path]: The destination parent node to which to add the new part to. If null, the default is the knowledge memory root node.
 * - properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties branch as destination. If null, the default is false (model branch).
 */
static wchar_t* CREATE_MEMORISE_LOGIC_CYBOL_FORMAT = L"memorise/create";
static int* CREATE_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The memorise/destroy logic cybol format.
 *
 * Description:
 *
 * Deallocates the given part in heap memory.
 *
 * Caution! Do not destroy the whole knowledge tree when shutting down a system since otherwise,
 * the shutdown operation models of the corresponding cybol application being executed
 * get destroyed as well, so that the exit operation cannot be executed anymore.
 * The rubbish (garbage) collector cares about destruction evaluating references.
 * The exit operation is the last one to be called. It cleans up all memory internally.
 *
 * Examples:
 *
 * <node name="destroy_part" channel="inline" format="memorise/destroy" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".some.part"/>
 * </node>
 *
 * Properties:
 *
 * - part (required) [text/cybol-path]: The part to be destroyed.
 */
static wchar_t* DESTROY_MEMORISE_LOGIC_CYBOL_FORMAT = L"memorise/destroy";
static int* DESTROY_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The memorise/pop logic cybol format.
 */
static wchar_t* POP_MEMORISE_LOGIC_CYBOL_FORMAT = L"memorise/pop";
static int* POP_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The memorise/push logic cybol format.
 */
static wchar_t* PUSH_MEMORISE_LOGIC_CYBOL_FORMAT = L"memorise/push";
static int* PUSH_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MEMORISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
