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

#ifndef CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The use system's name resolver unix command option name. */
static wchar_t* RESOLVE_CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME = L"-r";
static int* RESOLVE_CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ouput more info unix command option name. */
static wchar_t* STATISTICS_CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME = L"-s";
static int* STATISTICS_CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print version unix command option name. */
static wchar_t* VERSION_CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME = L"-V";
static int* VERSION_CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CONFIG_NETWORK_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
