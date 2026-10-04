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

#ifndef NETSTAT_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define NETSTAT_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The routingtable Netstat unix command option name. */
static wchar_t* ROUTINGTABLE_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-r";
static int* ROUTINGTABLE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interface Netstat unix command option name. */
static wchar_t* INTERFACE_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-i";
static int* INTERFACE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The groups Netstat unix command option name. */
static wchar_t* GROUPS_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-g";
static int* GROUPS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The statistics Netstat unix command option name. */
static wchar_t* STATISTICS_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-s";
static int* STATISTICS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The masquerade Netstat unix command option name. */
static wchar_t* MASQUERADE_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-M";
static int* MASQUERADE_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The long Netstat unix command option name. */
static wchar_t* LONG_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-v";
static int* LONG_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nohostname Netstat unix command option name. */
static wchar_t* NOHOST_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-n";
static int* NOHOST_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The extended Netstat unix command option name. */
static wchar_t* EXTENDED_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-e";
static int* EXTENDED_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The program names Netstat unix command option name. */
static wchar_t* PROGNAMES_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-p";
static int* PROGNAMES_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The listening sockets Netstat unix command option name. */
static wchar_t* LISTENSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-l";
static int* LISTENSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The all sockets Netstat unix command option name. */
static wchar_t* ALLSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-a";
static int* ALLSOCKETS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The timers Netstat unix command option name. */
static wchar_t* TIMERS_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-o";
static int* TIMERS_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The active connections Netstat unix command option name. */
static wchar_t* ACTIVECONN_NETSTAT_UNIX_COMMAND_OPTION_NAME = L"-t";
static int* ACTIVECONN_NETSTAT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* USERLOG_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
