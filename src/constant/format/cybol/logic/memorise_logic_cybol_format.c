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
 * Create / allocate / reserve memory on heap.
 *
 * The model and properties may get filled with data using a
 * "deserialise" operation, which is called when a "receive"
 * logic operation is found in cybol.
 *
 * The new knowledge model gets added to either of:
 * - whole part's model hierarchy
 *   (or knowledge memory part's root, if no whole is given)
 * - whole part's properties hierarchy
 *   (or knowledge memory part's root, if no whole is given)
 *
 * Description:
 *
Creates an empty part consisting of name and type only.
 *
 * Examples:
 *
 * <node name="create_summand_2" channel="inline" format="memorise/create" model="">
 *     <node name="name" channel="inline" format="text/plain" model="summand_2"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 *     <node name="whole" channel="inline" format="text/cybol-path" model=".addition_application"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
name	the name of the part to be created	true	text/plain
format	the format of the part to be created, from which gets determined the type	true	meta/format
element	the kind of element to be created (part, property); a part element will be added to the whole model's part hierarchy; a property element to the whole model's properties hierarchy	true	text/plain
whole	If null, the new part will be added to the knowledge memory root. The compound to which to add to the new part.	false	element/part
 *
 * Expected parametres:
 * - name (required): the name of the part to be created
 * - format (required): the format of the part to be created, from which gets determined the type
 * - whole (optional; if null, the new part will be added to the knowledge memory root):
 *       the compound part to which to add the new part to
 * - whole_properties (optional; the default is "false"; if null, the MODEL container is used):
 *   the flag indicating whether the model- or properties container should be used;
 *   false = whole MODEL container;
 *   true = whole PROPERTIES container
 */
static wchar_t* CREATE_MEMORISE_LOGIC_CYBOL_FORMAT = L"memorise/create";
static int* CREATE_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The memorise/destroy logic cybol format.
 *
 * Destroy / deallocate / free memory on heap.
 *
 * Description:
 *
Destroys a part and removes it from the knowledge model.
 *
 * Examples:
 *
 * <node name="destroy_tui_control" channel="inline" format="memorise/destroy" model="">
 *     <node name="name" channel="inline" format="text/cybol-path" model=".tui_control"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
name	the part to be destroyed	true	text/cybol-path
 *
 * Parametres:
 * - part (required): the part to be destroyed
 */
static wchar_t* DESTROY_MEMORISE_LOGIC_CYBOL_FORMAT = L"memorise/destroy";
static int* DESTROY_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The memorise/pop logic cybol format.
 *
 * Destroy / deallocate / free memory on stack.
 *
 * Description:
 *
Pop an element from the stack.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* POP_MEMORISE_LOGIC_CYBOL_FORMAT = L"memorise/pop";
static int* POP_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The memorise/push logic cybol format.
 *
 * Create / allocate / reserve memory on stack.
 *
 * Description:
 *
Push an element on the stack.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* PUSH_MEMORISE_LOGIC_CYBOL_FORMAT = L"memorise/push";
static int* PUSH_MEMORISE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MEMORISE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
