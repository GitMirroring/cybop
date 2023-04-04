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

#ifndef COPY_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define COPY_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The force copy file win32 command option name. */
static wchar_t* FORCE_COPY_FILE_WIN32_COMMAND_OPTION_NAME = L"/Y";
static int* FORCE_COPY_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactive copy file win32 command option name. */
static wchar_t* INTERACTIVE_COPY_FILE_WIN32_COMMAND_OPTION_NAME = L"/P";
static int* INTERACTIVE_COPY_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The preserve all attributes copy file win32 command option name. */
static wchar_t* PRESERVE_ALL_ATTRIBUTES_COPY_FILE_WIN32_COMMAND_OPTION_NAME = L"/K/O";
static int* PRESERVE_ALL_ATTRIBUTES_COPY_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The preserve links copy file win32 command option name. */
static wchar_t* PRESERVE_LINKS_COPY_FILE_WIN32_COMMAND_OPTION_NAME = L"/B";
static int* PRESERVE_LINKS_COPY_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursive copy file win32 command option name. */
static wchar_t* RECURSIVE_COPY_FILE_WIN32_COMMAND_OPTION_NAME = L"/E";
static int* RECURSIVE_COPY_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The update copy file win32 command option name. */
static wchar_t* UPDATE_COPY_FILE_WIN32_COMMAND_OPTION_NAME = L"/D";
static int* UPDATE_COPY_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The verbal copy file win32 command option name. */
static wchar_t* VERBAL_COPY_FILE_WIN32_COMMAND_OPTION_NAME = L"/F";
static int* VERBAL_COPY_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The non-verbal copy file win32 command option name. */
static wchar_t* NON_VERBAL_COPY_FILE_WIN32_COMMAND_OPTION_NAME = L"/Q";
static int* NON_VERBAL_COPY_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COPY_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
