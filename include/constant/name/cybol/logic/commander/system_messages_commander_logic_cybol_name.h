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

#ifndef SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The human option for the system messages logic in cybol. */
static wchar_t* HUMAN_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME = L"human";
static int* HUMAN_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The time-stamp option for the system messages logic in cybol. */
static wchar_t* CTIME_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME = L"ctime";
static int* CTIME_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The show kernel messages option for the system messages logic in cybol. */
static wchar_t* KERNEL_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME = L"kernel";
static int* KERNEL_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The colorize option for the system messages logic in cybol. */
static wchar_t* COLOR_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME = L"color";
static int* COLOR_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The userspace option for the system messages logic in cybol. */
static wchar_t* USERSPACE_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME = L"userspace";
static int* USERSPACE_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
