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

#ifndef REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The force remove file win32 command option name. */
static wchar_t* FORCE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME = L"/F";
static int* FORCE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactvie remove file win32 command option name. */
static wchar_t* INTERACTIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME = L"/S";
static int* INTERACTIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursvie remove file win32 command option name. */
static wchar_t* RECURSIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME = L"/P";
static int* RECURSIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
