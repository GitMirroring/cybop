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

#ifndef SEPARATOR_KNOWLEDGE_CYBOI_NAME_CONSTANT_SOURCE
#define SEPARATOR_KNOWLEDGE_CYBOI_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The begin index separator knowledge cyboi name.
 *
 * Example:
 * .app.wui.[.path.to.index].data
 */
static wchar_t* BEGIN_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"[";
static int* BEGIN_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The begin name separator knowledge cyboi name.
 *
 * Example:
 * .app.wui.(.path.to.name).data
 */
static wchar_t* BEGIN_NAME_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"(";
static int* BEGIN_NAME_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The begin reference separator knowledge cyboi name.
 *
 * Examples:
 * {.app.var.path}
 * .app.adr.[{{.app.var.index}}].phone
 */
static wchar_t* BEGIN_REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"{";
static int* BEGIN_REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The end index separator knowledge cyboi name.
 *
 * Example:
 * .app.wui.[.path.to.index].data
 */
static wchar_t* END_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"]";
static int* END_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The end name separator knowledge cyboi name.
 *
 * Example:
 * .app.wui.(.path.to.name).data
 */
static wchar_t* END_NAME_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L")";
static int* END_NAME_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The end reference separator knowledge cyboi name.
 *
 * Examples:
 * {.app.var.path}
 * .app.adr.[{{.app.var.index}}].phone
 */
static wchar_t* END_REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"}";
static int* END_REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The model separator knowledge cyboi name.
 *
 * Examples:
 * .app.gui.menubar.file.exit
 * .app
 */
static wchar_t* MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L".";
static int* MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The property separator knowledge cyboi name.
 *
 * Example:
 * .app.gui.menubar:colour
 * :colour
 */
static wchar_t* PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L":";
static int* PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The stack separator knowledge cyboi name.
 *
 * Examples:
 * #variable
 * #variable.part:property
 * #variable:property.part
 */
static wchar_t* STACK_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"#";
static int* STACK_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The operation parametre separator knowledge cyboi name.
 *
 * Example:
 * <node name="menu" channel="file" format="text/cybol" model="menu/window.cybol">
 *     <node name="size" channel="inline" type="number/integer" model="300,200"/>
 * </node>
 */
static wchar_t* VALUE_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L",";
static int* VALUE_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_KNOWLEDGE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
