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

#ifndef SUSPEND_FEELING_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define SUSPEND_FEELING_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The channel suspend feeling logic cybol name. */
static wchar_t* CHANNEL_SUSPEND_FEELING_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_SUSPEND_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port suspend feeling logic cybol name. */
static wchar_t* PORT_SUSPEND_FEELING_LOGIC_CYBOL_NAME = L"port";
static int* PORT_SUSPEND_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sender suspend feeling logic cybol name. */
static wchar_t* SENDER_SUSPEND_FEELING_LOGIC_CYBOL_NAME = L"sender";
static int* SENDER_SUSPEND_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server suspend feeling logic cybol name. */
static wchar_t* SERVER_SUSPEND_FEELING_LOGIC_CYBOL_NAME = L"server";
static int* SERVER_SUSPEND_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SUSPEND_FEELING_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
