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

#ifndef UNIX_COMMAND_MODEL_CONSTANT_HEADER
#define UNIX_COMMAND_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The shell unix command model. */
static wchar_t* SHELL_UNIX_COMMAND_MODEL = L"/bin/sh";
static int* SHELL_UNIX_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The change directory unix command model. */
static wchar_t* CHANGE_DIRECTORY_UNIX_COMMAND_MODEL = L"cd";
static int* CHANGE_DIRECTORY_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The change permission unix command model. */
static wchar_t* CHANGE_PERMISSION_UNIX_COMMAND_MODEL = L"chmod";
static int* CHANGE_PERMISSION_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clear screen unix command model. */
static wchar_t* CLEAR_SCREEN_UNIX_COMMAND_MODEL = L"clear";
static int* CLEAR_SCREEN_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compare two files unix command model. */
static wchar_t* COMPARE_FILES_UNIX_COMMAND_MODEL = L"cmp";
static int* COMPARE_FILES_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Configuration of a network adapter */
static wchar_t* CONFIG_NETWORK_UNIX_COMMAND_MODEL = L"ip";
static int* CONFIG_NETWORK_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy file unix command model. */
static wchar_t* COPY_FILE_UNIX_COMMAND_MODEL = L"cp";
static int* COPY_FILE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The create directory unix command model. */
static wchar_t* CREATE_DIRECTORY_UNIX_COMMAND_MODEL = L"mkdir";
static int* CREATE_DIRECTORY_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print date unix command model. */
static wchar_t* DATE_UNIX_COMMAND_MODEL = L"date";
static int* DATE_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sleep unix command model. */
static wchar_t* DELAY_UNIX_COMMAND_MODEL = L"sleep";
static int* DELAY_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The diff unix command model. */
static wchar_t* DIFF_UNIX_COMMAND_MODEL = L"diff";
static int* DIFF_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The disk free unix command model. */
static wchar_t* DISK_FREE_UNIX_COMMAND_MODEL = L"df";
static int* DISK_FREE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The disk usage command model. */
static wchar_t* DISK_USAGE_UNIX_COMMAND_MODEL = L"du";
static int* DISK_USAGE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display content command model. */
static wchar_t* DISPLAY_CONTENT_UNIX_COMMAND_MODEL = L"cat";
static int* DISPLAY_CONTENT_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo message unix command model. */
static wchar_t* ECHO_MESSAGE_UNIX_COMMAND_MODEL = L"echo";
static int* ECHO_MESSAGE_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The find command unix command model. */
static wchar_t* FIND_COMMAND_UNIX_COMMAND_MODEL = L"whereis";
static int* FIND_COMMAND_UNIX_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The find file unix command model. */
static wchar_t* FIND_FILE_UNIX_COMMAND_MODEL = L"find";
static int* FIND_FILE_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The grep unix command model. */
static wchar_t* GREP_UNIX_COMMAND_MODEL = L"grep";
static int* GREP_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The help unix command model. */
static wchar_t* HELP_UNIX_COMMAND_MODEL = L"man";
static int* HELP_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hostname unix command model. */
static wchar_t* HOSTNAME_UNIX_COMMAND_MODEL = L"hostname";
static int* HOSTNAME_UNIX_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The id unix command model. */
static wchar_t* ID_UNIX_COMMAND_MODEL = L"id";
static int* ID_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ifconfig unix command model. */
static wchar_t* IFCONFIG_UNIX_COMMAND_MODEL = L"ifconfig";
static int* IFCONFIG_UNIX_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ifup unix command model. */
static wchar_t* IFUP_UNIX_COMMAND_MODEL = L"ifup";
static int* IFUP_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kill unix command model. */
static wchar_t* KILL_UNIX_COMMAND_MODEL = L"kill";
static int* KILL_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list directory contents unix command model. */
static wchar_t* LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL = L"ls";
static int* LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list open files command model. */
static wchar_t* LIST_OPEN_FILES_UNIX_COMMAND_MODEL = L"lsof";
static int* LIST_OPEN_FILES_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list tasks command model. */
static wchar_t* LIST_TASKS_UNIX_COMMAND_MODEL = L"ps";
static int* LIST_TASKS_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list tasks command model. */
static wchar_t* MEMORY_FREE_UNIX_COMMAND_MODEL = L"free";
static int* MEMORY_FREE_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move file unix command model. */
static wchar_t* MOVE_FILE_UNIX_COMMAND_MODEL = L"mv";
static int* MOVE_FILE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The netstat unix command model. */
static wchar_t* NETSTAT_UNIX_COMMAND_MODEL = L"netstat";
static int* NETSTAT_UNIX_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ping unix command model. */
static wchar_t* PING_UNIX_COMMAND_MODEL = L"ping";
static int* PING_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The present working directory command model. */
static wchar_t* PWD_UNIX_COMMAND_MODEL = L"pwd";
static int* PWD_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove file unix command model. */
static wchar_t* REMOVE_FILE_UNIX_COMMAND_MODEL = L"rm";
static int* REMOVE_FILE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort unix command model. */
static wchar_t* SORT_UNIX_COMMAND_MODEL = L"sort";
static int* SORT_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The spellcheck unix command model. */
static wchar_t* SPELLCHECK_UNIX_COMMAND_MODEL = L"aspell check";
static int* SPELLCHECK_UNIX_COMMAND_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The system messages command model. */
static wchar_t* SYSTEM_MESSAGES_UNIX_COMMAND_MODEL = L"dmesg";
static int* SYSTEM_MESSAGES_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tape archiver unix command model. */
static wchar_t* TAPE_ARCHIVER_UNIX_COMMAND_MODEL = L"tar";
static int* TAPE_ARCHIVER_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The top unix command model. */
static wchar_t* TOP_UNIX_COMMAND_MODEL = L"top";
static int* TOP_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The touch unix command model. */
static wchar_t* TOUCH_UNIX_COMMAND_MODEL = L"touch";
static int* TOUCH_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The traceroute unix command model. */
static wchar_t* TRACEROUTE_UNIX_COMMAND_MODEL = L"traceroute";
static int* TRACEROUTE_UNIX_COMMAND_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The userlog unix command model. */
static wchar_t* USERLOG_UNIX_COMMAND_MODEL = L"w";
static int* USERLOG_UNIX_COMMAND_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The whoami unix command model. */
static wchar_t* WHO_AM_I_UNIX_COMMAND_MODEL = L"whoami";
static int* WHO_AM_I_UNIX_COMMAND_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The who unix command model. */
static wchar_t* WHO_UNIX_COMMAND_MODEL = L"who";
static int* WHO_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The word count unix command model. */
static wchar_t* WORD_COUNT_UNIX_COMMAND_MODEL = L"wc";
static int* WORD_COUNT_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* UNIX_COMMAND_MODEL_CONSTANT_HEADER */
#endif
