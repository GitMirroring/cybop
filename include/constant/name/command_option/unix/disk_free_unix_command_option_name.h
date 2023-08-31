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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DISK_FREE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define DISK_FREE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The all disk free unix command option name. */
static wchar_t* ALL_DISK_FREE_UNIX_COMMAND_OPTION_NAME = L"-a";
static int* ALL_DISK_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The human disk free unix command option name. */
static wchar_t* HUMAN_DISK_FREE_UNIX_COMMAND_OPTION_NAME = L"-h";
static int* HUMAN_DISK_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kilobytes disk free unix command option name. */
static wchar_t* KILOBYTES_DISK_FREE_UNIX_COMMAND_OPTION_NAME = L"-k";
static int* KILOBYTES_DISK_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The local disk free unix command option name. */
static wchar_t* LOCAL_DISK_FREE_UNIX_COMMAND_OPTION_NAME = L"-l";
static int* LOCAL_DISK_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The megabytes disk free unix command option name. */
static wchar_t* MEGABYTES_DISK_FREE_UNIX_COMMAND_OPTION_NAME = L"-m";
static int* MEGABYTES_DISK_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print type disk free unix command option name. */
static wchar_t* TYPE_DISK_FREE_UNIX_COMMAND_OPTION_NAME = L"-T";
static int* TYPE_DISK_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DISK_FREE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
