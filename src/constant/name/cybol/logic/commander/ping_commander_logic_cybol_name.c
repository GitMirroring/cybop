/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
* The host for the ping logic cybol name.
*
* It indicates the IP or the host name of the host to ping.
*/
static wchar_t HOST_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'h', L'o', L's', L't'};
static wchar_t* HOST_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME = HOST_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* HOST_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The count for the ping logic cybol name.
*
* It indicates the count of packets to send.
*/
static wchar_t COUNT_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'c', L'o', L'u', L'n', L't'};
static wchar_t* COUNT_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME = COUNT_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* COUNT_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The interface for the ping logic cybol name.
*
* It indicates the interface to send on.
*/
static wchar_t INTERFACE_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_ARRAY[] = {L'i', L'n', L't', L'e', L'r', L'f', L'a', L'c', L'e'};
static wchar_t* INTERFACE_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME = INTERFACE_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_ARRAY;
static int* INTERFACE_PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PING_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif

