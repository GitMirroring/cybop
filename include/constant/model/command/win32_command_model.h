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

#ifndef WIN32_COMMAND_MODEL_CONSTANT_HEADER
#define WIN32_COMMAND_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The change directory win32 command model. */
static wchar_t* CHANGE_DIRECTORY_WIN32_COMMAND_MODEL = L"cd";
static int* CHANGE_DIRECTORY_WIN32_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compare two files win32 command model. */
static wchar_t* COMPARE_FILES_WIN32_COMMAND_MODEL = L"fc";
static int* COMPARE_FILES_WIN32_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy win32 command model. */
static wchar_t* XCOPY_WIN32_COMMAND_MODEL = L"xcopy";
static int* XCOPY_WIN32_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clear screen win32 command model. */
static wchar_t* CLEAR_SCREEN_WIN32_COMMAND_MODEL = L"cls";
static int* CLEAR_SCREEN_WIN32_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print date win32 command model. */
static wchar_t* DATE_WIN32_COMMAND_MODEL = L"date";
static int* DATE_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The delete win32 command model. */
static wchar_t* DEL_WIN32_COMMAND_MODEL = L"del";
static int* DEL_WIN32_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display text file win32 command model. */
static wchar_t* DISPLAY_CONTENT_WIN32_COMMAND_MODEL = L"more";
static int* DISPLAY_CONTENT_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list directory contents win32 command model. */
static wchar_t* DIR_WIN32_COMMAND_MODEL = L"dir";
static int* DIR_WIN32_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo win32 command model. */
static wchar_t* ECHO_WIN32_COMMAND_MODEL = L"echo";
static int* ECHO_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The find file win32 command model. */
static wchar_t* FIND_FILE_WIN32_COMMAND_MODEL = L"WHERE";
static int* FIND_FILE_WIN32_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The help win32 command model. */
static wchar_t* HELP_WIN32_COMMAND_MODEL = L"help";
static int* HELP_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kill win32 command model. */
static wchar_t* KILL_WIN32_COMMAND_MODEL = L"kill";
static int* KILL_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move win32 command model. */
static wchar_t* MOVE_WIN32_COMMAND_MODEL = L"move";
static int* MOVE_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tape archiver win32 command model. */
static wchar_t* SEVEN_ZIP_WIN32_COMMAND_MODEL = L"7z.exe";
static int* SEVEN_ZIP_WIN32_COMMAND_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ping win32 command model. */
static wchar_t* PING_WIN32_COMMAND_MODEL = L"ping";
static int* PING_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sleep win32 command model. */
static wchar_t* DELAY_WIN32_COMMAND_MODEL = L"timeout";
static int* DELAY_WIN32_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** Configuration of a network adapter. */
static wchar_t* CONFIG_NETWORK_WIN32_COMMAND_MODEL = L"ipconfig";
static int* CONFIG_NETWORK_WIN32_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The grep win32 command model. */
static wchar_t* FIND_WIN32_COMMAND_MODEL = L"find";
static int* FIND_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The traceroute win32 command model. */
static wchar_t* TRACERT_WIN32_COMMAND_MODEL = L"tracert";
static int* TRACERT_WIN32_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The diff win32 command model. */
static wchar_t* FC_WIN32_COMMAND_MODEL = L"fc";
static int* FC_WIN32_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort win32 command model. */
static wchar_t* SORT_WIN32_COMMAND_MODEL = L"sort";
static int* SORT_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list tasks win32 command model. */
static wchar_t* LIST_TASKS_WIN32_COMMAND_MODEL = L"tasklist";
static int* LIST_TASKS_WIN32_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The memory free win32 command model. */
static wchar_t* MEMORY_FREE_WIN32_COMMAND_MODEL = L"wmic OS get TotalVisibleMemorySize /Value";
static int* MEMORY_FREE_WIN32_COMMAND_MODEL_COUNT = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The who am i win32 command model. */
static wchar_t* WHO_AM_I_WIN32_COMMAND_MODEL = L"whoami";
static int* WHO_AM_I_WIN32_COMMAND_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The top win32 command model. */
static wchar_t* TOP_WIN32_COMMAND_MODEL = L"tasklist";
static int* TOP_WIN32_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ifconfi win32 command model. */
static wchar_t* IFCONFIG_WIN32_COMMAND_MODEL = L"ipconfig";
static int* IFCONFIG_WIN32_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ifconfi win32 command model. */
static wchar_t* W_WIN32_COMMAND_MODEL = L"net user";
static int* W_WIN32_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WIN32_COMMAND_MODEL_CONSTANT_HEADER */
#endif
