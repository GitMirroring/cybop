/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
* The host for the ping logic cybol name.
*
* It indicates the IP or the host name of the host to ping.
*/
static wchar_t* HOST_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"host";
static int* HOST_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The count for the ping logic cybol name.
*
* It indicates the count of packets to send.
*/
static wchar_t* COUNT_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"count";
static int* COUNT_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The interface for the ping logic cybol name.
*
* It indicates the interface to send on.
*/
static wchar_t* INTERFACE_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"interface";
static int* INTERFACE_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
