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

#ifndef COUNT_ACCESS_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define COUNT_ACCESS_LOGIC_CYBOL_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The count count access logic cybol name. */
static wchar_t* COUNT_COUNT_ACCESS_LOGIC_CYBOL_NAME = L"count";
static int* COUNT_COUNT_ACCESS_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The part count access logic cybol name. */
static wchar_t* PART_COUNT_ACCESS_LOGIC_CYBOL_NAME = L"part";
static int* PART_COUNT_ACCESS_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The selection count access logic cybol name. */
static wchar_t* SELECTION_COUNT_ACCESS_LOGIC_CYBOL_NAME = L"selection";
static int* SELECTION_COUNT_ACCESS_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The filter count access logic cybol name. */
static wchar_t* FILTER_COUNT_ACCESS_LOGIC_CYBOL_NAME = L"filter";
static int* FILTER_COUNT_ACCESS_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COUNT_ACCESS_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
