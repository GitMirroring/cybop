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

#ifndef COMPARE_FILES_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define COMPARE_FILES_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The case insensitive win32 command option name. */
static wchar_t* CASE_INSENSITIVE_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME = L"/C";
static int* CASE_INSENSITIVE_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compare unicode win32 command option name. */
static wchar_t* UNICODE_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME = L"/U";
static int* UNICODE_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compare ascii win32 command option name. */
static wchar_t* ASCII_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME = L"/L";
static int* ASCII_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display line numbers win32 command option name. */
static wchar_t* LINE_NUMBERS_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME = L"/N";
static int* LINE_NUMBERS_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The squeeze win32 command option name. */
static wchar_t* SQUEEZE_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME = L"/W";
static int* SQUEEZE_COMPARE_FILES_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMPARE_FILES_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
