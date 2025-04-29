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

#ifndef LOOP_FLOW_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define LOOP_FLOW_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The break loop flow logic cybol name. */
static wchar_t* BREAK_LOOP_FLOW_LOGIC_CYBOL_NAME = L"break";
static int* BREAK_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The collection loop flow logic cybol name. */
static wchar_t* COLLECTION_LOOP_FLOW_LOGIC_CYBOL_NAME = L"collection";
static int* COLLECTION_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The end loop flow logic cybol name. */
static wchar_t* END_LOOP_FLOW_LOGIC_CYBOL_NAME = L"end";
static int* END_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The index loop flow logic cybol name. */
static wchar_t* INDEX_LOOP_FLOW_LOGIC_CYBOL_NAME = L"index";
static int* INDEX_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The times loop flow logic cybol name. */
static wchar_t* TIMES_LOOP_FLOW_LOGIC_CYBOL_NAME = L"times";
static int* TIMES_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The model loop flow logic cybol name. */
static wchar_t* MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME = L"model";
static int* MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The start loop flow logic cybol name. */
static wchar_t* START_LOOP_FLOW_LOGIC_CYBOL_NAME = L"start";
static int* START_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The step loop flow logic cybol name. */
static wchar_t* STEP_LOOP_FLOW_LOGIC_CYBOL_NAME = L"step";
static int* STEP_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOOP_FLOW_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
