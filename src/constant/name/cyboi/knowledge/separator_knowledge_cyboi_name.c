/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEPARATOR_KNOWLEDGE_CYBOI_NAME_CONSTANT_SOURCE
#define SEPARATOR_KNOWLEDGE_CYBOI_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The begin index separator knowledge cyboi name.
 *
 * Example:
 * .app.wui.index.body.table.row.[2].data
 */
static wchar_t* BEGIN_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"[";
static int* BEGIN_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The begin path separator knowledge cyboi name.
 *
 * Example:
 * .app.wui.(.app.var.page_name).body.table.row
 */
static wchar_t* BEGIN_PATH_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"(";
static int* BEGIN_PATH_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The end index separator knowledge cyboi name.
 *
 * Example:
 * .app.wui.index.body.table.row.[2].data
 */
static wchar_t* END_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"]";
static int* END_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The end path separator knowledge cyboi name.
 *
 * Example:
 * .app.wui.(.app.var.page_name).body.table.row
 */
static wchar_t* END_PATH_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L")";
static int* END_PATH_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
 * The reference separator knowledge cyboi name.
 *
 * Examples:
 * *.app.var.path
 * .app.adr.[**.app.var.index].phone
 */
static wchar_t* REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L"*";
static int* REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The operation parametre separator knowledge cyboi name.
 *
 * Example:
 * <part name="menu" channel="file" type="text/cybol" model="menu/window.cybol">
 *     <property name="size" channel="inline" type="number/integer" model="20,50,300,200">
 * </part>
 */
static wchar_t* VALUE_SEPARATOR_KNOWLEDGE_CYBOI_NAME = L",";
static int* VALUE_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_KNOWLEDGE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
