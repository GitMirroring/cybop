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

#ifndef COMPARISON_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define COMPARISON_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The result comparison logic cybol name. */
static wchar_t* RESULT_COMPARISON_LOGIC_CYBOL_NAME = L"result";
static int* RESULT_COMPARISON_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left comparison logic cybol name. */
static wchar_t* LEFT_COMPARISON_LOGIC_CYBOL_NAME = L"left";
static int* LEFT_COMPARISON_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The right comparison logic cybol name. */
static wchar_t* RIGHT_COMPARISON_LOGIC_CYBOL_NAME = L"right";
static int* RIGHT_COMPARISON_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The count comparison logic cybol name. */
static wchar_t* COUNT_COMPARISON_LOGIC_CYBOL_NAME = L"count";
static int* COUNT_COMPARISON_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left index comparison logic cybol name. */
static wchar_t* LEFT_INDEX_COMPARISON_LOGIC_CYBOL_NAME = L"left_index";
static int* LEFT_INDEX_COMPARISON_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The right index comparison logic cybol name. */
static wchar_t* RIGHT_INDEX_COMPARISON_LOGIC_CYBOL_NAME = L"right_index";
static int* RIGHT_INDEX_COMPARISON_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMPARISON_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
