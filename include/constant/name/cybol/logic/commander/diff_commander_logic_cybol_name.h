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

#ifndef DIFF_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define DIFF_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

/**
* The first file for the grep logic cybol name.
*
* It is the path to the first file
*/
static wchar_t* FILE1_DIFF_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"file1";
static int* FILE1_DIFF_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The second file for the grep logic cybol name.
*
* It is the path to the second file
*/
static wchar_t* FILE2_DIFF_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"file2";
static int* FILE2_DIFF_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DIFF_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
