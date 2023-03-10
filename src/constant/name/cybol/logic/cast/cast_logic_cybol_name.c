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

#ifndef CAST_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define CAST_LOGIC_CYBOL_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The destination cast logic cybol name. */
static wchar_t* DESTINATION_CAST_LOGIC_CYBOL_NAME = L"destination";
static int* DESTINATION_CAST_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The source cast logic cybol name. */
static wchar_t* SOURCE_CAST_LOGIC_CYBOL_NAME = L"source";
static int* SOURCE_CAST_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The count cast logic cybol name. */
static wchar_t* COUNT_CAST_LOGIC_CYBOL_NAME = L"count";
static int* COUNT_CAST_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination index cast logic cybol name. */
static wchar_t* DESTINATION_INDEX_CAST_LOGIC_CYBOL_NAME = L"destination_index";
static int* DESTINATION_INDEX_CAST_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The source index cast logic cybol name. */
static wchar_t* SOURCE_INDEX_CAST_LOGIC_CYBOL_NAME = L"source_index";
static int* SOURCE_INDEX_CAST_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CAST_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
