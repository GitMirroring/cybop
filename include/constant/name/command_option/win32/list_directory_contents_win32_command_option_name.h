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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The all list directory contents win32 command option name. */
static wchar_t* ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME = L"/A";
static int* ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The long list directory contents win32 command option name. */
static wchar_t* LONG_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME = L"/Q/N";
static int* LONG_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The one row per entry list directory contents win32 command option name. */
static wchar_t* ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME = L"/B";
static int* ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursive list directory contents win32 command option name. */
static wchar_t* RECURSIVE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME = L"/S";
static int* RECURSIVE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The short list directory contents win32 command option name. */
static wchar_t* SHORT_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME = L"/W";
static int* SHORT_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort by file size list directory contents win32 command option name. */
static wchar_t* SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME = L"/OS";
static int* SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort by modification time list directory contents win32 command option name. */
static wchar_t* SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME = L"/OD";
static int* SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort by file extension list directory contents win32 command option name. */
static wchar_t* SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME = L"/OE";
static int* SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
