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

#ifndef MEMORY_FREE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define MEMORY_FREE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The human memory free unix command option name. */
static wchar_t* HUMAN_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME = L"-h";
static int* HUMAN_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kilobytes memory free unix command option name. */
static wchar_t* KILOBYTES_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME = L"-k";
static int* KILOBYTES_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The megabytes memory free unix command option name. */
static wchar_t* MEGABYTES_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME = L"-m";
static int* MEGABYTES_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gigabytes memory free unix command option name. */
static wchar_t* GIGABYTES_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME = L"-g";
static int* GIGABYTES_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The total memory free unix command option name. */
static wchar_t* TOTAL_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME = L"-t";
static int* TOTAL_MEMORY_FREE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MEMORY_FREE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
