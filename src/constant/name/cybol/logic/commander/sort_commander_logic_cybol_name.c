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

#ifndef SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
* The file for the sort logic cybol name.
*
* It is the path to the file, that should be sorted.
*/
static wchar_t* FILE_SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"file";
static int* FILE_SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The output for the sort logic cybol name.
*
* It is the path to the output file.
*/
static wchar_t* OUTPUT_SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"output";
static int* OUTPUT_SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The reverse for the sort logic cybol name.
*
* Sort will be reversed, when set.
*/
static wchar_t* REVERSED_SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"reversed";
static int* REVERSED_SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SORT_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
