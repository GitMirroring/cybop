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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ELEMENT_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define ELEMENT_STATE_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Element (in a knowledge tree accessed at runtime)
//
// IANA media type: not defined
// Self-defined media type: element
// This media type is a CYBOL extension.
//

/**
 * The element/part state cybol format.
 *
 * Description:
 *
 * A part node of the cyboi-internal knowledge tree.
 *
 * Each tree node (also called part) has a double hierarchy representing:
 * - model hierarchy: whole-part, container-element, macrocosm-microcosm, child parts
 * - properties hierarchy: metadata, constraints, parametres of a function, position and size of a graphical component
 *
 * Examples:
 *
 * <node name="empty_part_to_be_created" channel="inline" format="element/part" model=""/>
 * <node name="part_read_from_file" channel="file" format="element/part" model="path/to/file.cybol"/>
 *
 * <node name="initialise_choice_part" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".wui.index.body.choices.table.(#name)"/>
 * </node>
 * <node name="initialise_choice_properties" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/property"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".wui.index.body.choices.table.(#name)"/>
 * </node>
 */
static wchar_t* PART_ELEMENT_STATE_CYBOL_FORMAT = L"element/part";
static int* PART_ELEMENT_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element/property state cybol format.
 *
 * Description:
 *
 * A property node of the cyboi-internal knowledge tree.
 *
 * Each tree node (also called part) has a double hierarchy representing:
 * - model hierarchy: whole-part, container-element, macrocosm-microcosm, child parts
 * - properties hierarchy: metadata, constraints, parametres of a function, position and size of a graphical component
 *
 * Examples:
 *
 * <node name="empty_property_to_be_created" channel="inline" format="element/property" model=""/>
 * <node name="property_read_from_file" channel="file" format="element/property" model="path/to/file.cybol"/>
 *
 * <node name="initialise_choice_part" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".wui.index.body.choices.table.(#name)"/>
 * </node>
 * <node name="initialise_choice_properties" channel="inline" format="communicate/receive" model="">
 *     <node name="channel" channel="inline" format="meta/channel" model="file"/>
 *     <node name="sender" channel="inline" format="text/cybol-path" model=".id"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/property"/>
 *     <node name="message" channel="inline" format="text/cybol-path" model=".wui.index.body.choices.table.(#name)"/>
 * </node>
 */
static wchar_t* PROPERTY_ELEMENT_STATE_CYBOL_FORMAT = L"element/property";
static int* PROPERTY_ELEMENT_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The element/reference state cybol format.
 *
 * Description:
 *
 * A reference node of the cyboi-internal knowledge tree.
 * It represents a pointer to some knowledge tree node and was assigned as shallow copy.
 *
 * Examples:
 *
 * <node name="print_text" channel="inline" format="text/cybol-path" model=".print">
 *     <node name="extra_text" channel="inline" format="text/plain" model="This is EXTRA text handed over as runtime argument."/>
 * </node>
 *
 * <node name="field_model" channel="inline" format="text/cybol-path" model=".logic.translate.field">
 *     <node name="parent" channel="inline" format="element/reference" model="#parent.[#field_index]"/>
 * </node>
 */
static wchar_t* REFERENCE_ELEMENT_STATE_CYBOL_FORMAT = L"element/reference";
static int* REFERENCE_ELEMENT_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ELEMENT_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
