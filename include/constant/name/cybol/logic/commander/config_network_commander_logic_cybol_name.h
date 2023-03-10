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

#ifndef CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

/** Windows specific option to show full config info*/
static wchar_t* ALL_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME = L"/all";
static int* ALL_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** Linux specific option for system resolver*/
static wchar_t* RESOLVE_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME = L"resolve";
static int* RESOLVE_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** Linux specific option to print statistics*/
static wchar_t* STATISTICS_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME = L"statistics";
static int* STATISTICS_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** Linux specific option to print version*/
static wchar_t* VERSION_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME = L"version";
static int* VERSION_CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CONFIG_NETWORK_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
