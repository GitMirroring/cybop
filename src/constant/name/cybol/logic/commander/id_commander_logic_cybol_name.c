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

#ifndef ID_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define ID_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** print only the security context of the process*/
static wchar_t* CONTEXT_ID_COMMANDER_LOGIC_CYBOL_NAME = L"context";
static int* CONTEXT_ID_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**print only the effective group ID */
static wchar_t* GROUP_ID_COMMANDER_LOGIC_CYBOL_NAME = L"group";
static int* GROUP_ID_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**print all group IDs */
static wchar_t* GROUPS_ID_COMMANDER_LOGIC_CYBOL_NAME = L"groups";
static int* GROUPS_ID_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** print a name instead of a number, for -ugG*/
static wchar_t* NAME_ID_COMMANDER_LOGIC_CYBOL_NAME = L"name";
static int* NAME_ID_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**print only the effective user ID */
static wchar_t* USER_ID_COMMANDER_LOGIC_CYBOL_NAME = L"user";
static int* USER_ID_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ID_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
