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

#ifndef LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
* List keyword options (Unix only)
*/
static wchar_t KEYWORD_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'k', L'e', L'y', L'w', L'o', L'r', L'd'};
static wchar_t* KEYWORD_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME = KEYWORD_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* KEYWORD_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* List all processes (Unix only)
*/
static wchar_t ALL_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'a', L'l', L'l'};
static wchar_t* ALL_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME = ALL_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* ALL_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* Print stuff in verbose mode (Win32 only)
*/
static wchar_t VERBOSE_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'v', L'e', L'r', L'b', L'o', L's', L'e'};
static wchar_t* VERBOSE_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME = VERBOSE_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* VERBOSE_LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LIST_TASKS_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif

