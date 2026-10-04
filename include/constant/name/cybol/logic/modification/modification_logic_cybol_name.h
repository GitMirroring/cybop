/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MODIFICATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define MODIFICATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The adjust modification logic cybol name. */
static wchar_t* ADJUST_MODIFICATION_LOGIC_CYBOL_NAME = L"adjust";
static int* ADJUST_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The count modification logic cybol name. */
static wchar_t* COUNT_MODIFICATION_LOGIC_CYBOL_NAME = L"count";
static int* COUNT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination_index modification logic cybol name. */
static wchar_t* DESTINATION_INDEX_MODIFICATION_LOGIC_CYBOL_NAME = L"destination_index";
static int* DESTINATION_INDEX_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination modification logic cybol name. */
static wchar_t* DESTINATION_MODIFICATION_LOGIC_CYBOL_NAME = L"destination";
static int* DESTINATION_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination properties modification logic cybol name. */
static wchar_t* DESTINATION_PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME = L"destination_properties";
static int* DESTINATION_PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move modification logic cybol name. */
static wchar_t* MOVE_MODIFICATION_LOGIC_CYBOL_NAME = L"move";
static int* MOVE_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The repetition modification logic cybol name. */
static wchar_t* REPETITION_MODIFICATION_LOGIC_CYBOL_NAME = L"repetition";
static int* REPETITION_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The searchterm modification logic cybol name. */
static wchar_t* SEARCHTERM_MODIFICATION_LOGIC_CYBOL_NAME = L"searchterm";
static int* SEARCHTERM_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The source_index modification logic cybol name. */
static wchar_t* SOURCE_INDEX_MODIFICATION_LOGIC_CYBOL_NAME = L"source_index";
static int* SOURCE_INDEX_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The source modification logic cybol name. */
static wchar_t* SOURCE_MODIFICATION_LOGIC_CYBOL_NAME = L"source";
static int* SOURCE_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The source properties modification logic cybol name. */
static wchar_t* SOURCE_PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME = L"source_properties";
static int* SOURCE_PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MODIFICATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
