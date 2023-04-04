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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
* The routingtable Netstat logic cybol name.
*
*/
static wchar_t* ROUTINGTABLE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"routingtable";
static int* ROUTINGTABLE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The interface Netstat cybol name.
*
*/
static wchar_t* INTERFACE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"interface";
static int* INTERFACE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The groups Netstat logic cybol name.
*
*/
static wchar_t* GROUPS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"groups";
static int* GROUPS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The statistics Netstat logic cybol name.
*
*/
static wchar_t* STATISTICS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"statistics";
static int* STATISTICS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The masquerade Netstat logic cybol name.
*
*/
static wchar_t* MASQUERADE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"masquerade";
static int* MASQUERADE_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The long Netstat logic cybol name.
*
*/
static wchar_t* LONG_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"long";
static int* LONG_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The nohostname Netstat logic cybol name.
*
*/
static wchar_t* NOHOST_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"nohost";
static int* NOHOST_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The extended Netstat logic cybol name.
*
*/
static wchar_t* EXTENDED_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"extended";
static int* EXTENDED_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The programnames Netstat logic cybol name.
*
*/
static wchar_t* PROGNAMES_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"prognames";
static int* PROGNAMES_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The listening sockets Netstat logic cybol name.
*
*/
static wchar_t* LISTENSOCKETS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"listensockets";
static int* LISTENSOCKETS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The all sockets Netstat logic cybol name.
*
*/
static wchar_t* ALLSOCKETS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"allsockets";
static int* ALLSOCKETS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The timers Netstat logic cybol name.
*
*/
static wchar_t* TIMERS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"timers";
static int* TIMERS_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The active connection Netstat logic cybol name.
*
*/
static wchar_t* ACTIVECONN_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME = L"activeconn";
static int* ACTIVECONN_NETSTAT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* USERLOG_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
