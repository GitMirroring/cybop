/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define MOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The force move file win32 command option name. */
static wchar_t* FORCE_MOVE_FILE_WIN32_COMMAND_OPTION_NAME = L"/Y";
static int* FORCE_MOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactvie move file win32 command option name. */
static wchar_t* INTERACTIVE_MOVE_FILE_WIN32_COMMAND_OPTION_NAME = L"/-Y";
static int* INTERACTIVE_MOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
