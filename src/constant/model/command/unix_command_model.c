/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_COMMAND_MODEL_CONSTANT_SOURCE
#define UNIX_COMMAND_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The shell unix command model. */
static wchar_t SHELL_UNIX_COMMAND_MODEL_ARRAY[] = {L'/', L'b', L'i', L'n', L'/', L's', L'h'};
static wchar_t* SHELL_UNIX_COMMAND_MODEL = SHELL_UNIX_COMMAND_MODEL_ARRAY;
static int* SHELL_UNIX_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tape archiver unix command model. */
static wchar_t TAPE_ARCHIVER_UNIX_COMMAND_MODEL_ARRAY[] = {L't', L'a', L'r'};
static wchar_t* TAPE_ARCHIVER_UNIX_COMMAND_MODEL = TAPE_ARCHIVER_UNIX_COMMAND_MODEL_ARRAY;
static int* TAPE_ARCHIVER_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The change directory unix command model. */
static wchar_t CHANGE_DIRECTORY_UNIX_COMMAND_MODEL_ARRAY[] = {L'c', L'd'};
static wchar_t* CHANGE_DIRECTORY_UNIX_COMMAND_MODEL = CHANGE_DIRECTORY_UNIX_COMMAND_MODEL_ARRAY;
static int* CHANGE_DIRECTORY_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clear screen unix command model. */
static wchar_t CLEAR_SCREEN_UNIX_COMMAND_MODEL_ARRAY[] = {L'c', L'l', L'e', L'a', L'r'};
static wchar_t* CLEAR_SCREEN_UNIX_COMMAND_MODEL = CLEAR_SCREEN_UNIX_COMMAND_MODEL_ARRAY;
static int* CLEAR_SCREEN_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compare two files unix command model. */
static wchar_t COMPARE_FILES_UNIX_COMMAND_MODEL_ARRAY[] = {L'c', L'm', L'p'};
static wchar_t* COMPARE_FILES_UNIX_COMMAND_MODEL = COMPARE_FILES_UNIX_COMMAND_MODEL_ARRAY;
static int* COMPARE_FILES_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy file unix command model. */
static wchar_t COPY_FILE_UNIX_COMMAND_MODEL_ARRAY[] = {L'c', L'p'};
static wchar_t* COPY_FILE_UNIX_COMMAND_MODEL = COPY_FILE_UNIX_COMMAND_MODEL_ARRAY;
static int* COPY_FILE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print date unix command model. */
static wchar_t DATE_UNIX_COMMAND_MODEL_ARRAY[] = {L'd', L'a', L't', L'e'};
static wchar_t* DATE_UNIX_COMMAND_MODEL = DATE_UNIX_COMMAND_MODEL_ARRAY;
static int* DATE_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The disk free unix command model. */
static wchar_t DISK_FREE_UNIX_COMMAND_MODEL_ARRAY[] = {L'd', L'f'};
static wchar_t* DISK_FREE_UNIX_COMMAND_MODEL = DISK_FREE_UNIX_COMMAND_MODEL_ARRAY;
static int* DISK_FREE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display text file unix command model. */
static wchar_t DISPLAY_CONTENT_UNIX_COMMAND_MODEL_ARRAY[] = {L'c', L'a', L't'};
static wchar_t* DISPLAY_CONTENT_UNIX_COMMAND_MODEL = DISPLAY_CONTENT_UNIX_COMMAND_MODEL_ARRAY;
static int* DISPLAY_CONTENT_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo message unix command model. */
static wchar_t ECHO_MESSAGE_UNIX_COMMAND_MODEL_ARRAY[] = {L'e', L'c', L'h', L'o'};
static wchar_t* ECHO_MESSAGE_UNIX_COMMAND_MODEL = ECHO_MESSAGE_UNIX_COMMAND_MODEL_ARRAY;
static int* ECHO_MESSAGE_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The find command unix command model. */
static wchar_t FIND_COMMAND_UNIX_COMMAND_MODEL_ARRAY[] = {L'w', L'h', L'e', L'r', L'e', L'i', L's'};
static wchar_t* FIND_COMMAND_UNIX_COMMAND_MODEL = FIND_COMMAND_UNIX_COMMAND_MODEL_ARRAY;
static int* FIND_COMMAND_UNIX_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list directory contents unix command model. */
static wchar_t LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ARRAY[] = {L'l', L's'};
static wchar_t* LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL = LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kill unix command model. */
static wchar_t KILL_UNIX_COMMAND_MODEL_ARRAY[] = {L'k', L'i', L'l', L'l'};
static wchar_t* KILL_UNIX_COMMAND_MODEL = KILL_UNIX_COMMAND_MODEL_ARRAY;
static int* KILL_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move file unix command model. */
static wchar_t MOVE_FILE_UNIX_COMMAND_MODEL_ARRAY[] = {L'm', L'v'};
static wchar_t* MOVE_FILE_UNIX_COMMAND_MODEL = MOVE_FILE_UNIX_COMMAND_MODEL_ARRAY;
static int* MOVE_FILE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove file unix command model. */
static wchar_t REMOVE_FILE_UNIX_COMMAND_MODEL_ARRAY[] = {L'r', L'm'};
static wchar_t* REMOVE_FILE_UNIX_COMMAND_MODEL = REMOVE_FILE_UNIX_COMMAND_MODEL_ARRAY;
static int* REMOVE_FILE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The change permission unix command model. */
static wchar_t CHANGE_PERMISSION_UNIX_COMMAND_MODEL_ARRAY[] = {L'c', L'h', L'm', L'o', L'd'};
static wchar_t* CHANGE_PERMISSION_UNIX_COMMAND_MODEL = CHANGE_PERMISSION_UNIX_COMMAND_MODEL_ARRAY;
static int* CHANGE_PERMISSION_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** Configuration of a network adapter */
static wchar_t CONFIG_NETWORK_UNIX_COMMAND_MODEL_ARRAY[] = {L'i', L'p'};
static wchar_t* CONFIG_NETWORK_UNIX_COMMAND_MODEL = CONFIG_NETWORK_UNIX_COMMAND_MODEL_ARRAY;
static int* CONFIG_NETWORK_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The word count unix command model. */
static wchar_t WORD_COUNT_UNIX_COMMAND_MODEL_ARRAY[] = {L'w', L'c'};
static wchar_t* WORD_COUNT_UNIX_COMMAND_MODEL = WORD_COUNT_UNIX_COMMAND_MODEL_ARRAY;
static int* WORD_COUNT_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The create folder unix command model. */
static wchar_t CREATE_FOLDER_UNIX_COMMAND_MODEL_ARRAY[] = {L'm', L'k', L'd', L'i', L'r'};
static wchar_t* CREATE_FOLDER_UNIX_COMMAND_MODEL = CREATE_FOLDER_UNIX_COMMAND_MODEL_ARRAY;
static int* CREATE_FOLDER_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The help unix command model. */
static wchar_t HELP_UNIX_COMMAND_MODEL_ARRAY[] = {L'm', L'a', L'n'};
static wchar_t* HELP_UNIX_COMMAND_MODEL = HELP_UNIX_COMMAND_MODEL_ARRAY;
static int* HELP_UNIX_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ping unix command model. */
static wchar_t PING_UNIX_COMMAND_MODEL_ARRAY[] = {L'p', L'i', L'n', L'g'};
static wchar_t* PING_UNIX_COMMAND_MODEL = PING_UNIX_COMMAND_MODEL_ARRAY;
static int* PING_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The grep unix command model. */
static wchar_t GREP_UNIX_COMMAND_MODEL_ARRAY[] = {L'g', L'r', L'e', L'p'};
static wchar_t* GREP_UNIX_COMMAND_MODEL = GREP_UNIX_COMMAND_MODEL_ARRAY;
static int* GREP_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The traceroute unix command model. */
static wchar_t TRACEROUTE_UNIX_COMMAND_MODEL_ARRAY[] = {L't', L'r', L'a', L'c', L'e', L'r', L'o', L'u', L't', L'e'};
static wchar_t* TRACEROUTE_UNIX_COMMAND_MODEL = TRACEROUTE_UNIX_COMMAND_MODEL_ARRAY;
static int* TRACEROUTE_UNIX_COMMAND_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The diff unix command model. */
static wchar_t DIFF_UNIX_COMMAND_MODEL_ARRAY[] = {L'd', L'i', L'f', L'f'};
static wchar_t* DIFF_UNIX_COMMAND_MODEL = DIFF_UNIX_COMMAND_MODEL_ARRAY;
static int* DIFF_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort unix command model. */
static wchar_t SORT_UNIX_COMMAND_MODEL_ARRAY[] = {L's', L'o', L'r', L't'};
static wchar_t* SORT_UNIX_COMMAND_MODEL = SORT_UNIX_COMMAND_MODEL_ARRAY;
static int* SORT_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list tasks command model. */
static wchar_t LIST_TASKS_UNIX_COMMAND_MODEL_ARRAY[] = {L'p', L's'};
static wchar_t* LIST_TASKS_UNIX_COMMAND_MODEL = LIST_TASKS_UNIX_COMMAND_MODEL_ARRAY;
static int* LIST_TASKS_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* UNIX_COMMAND_MODEL_CONSTANT_SOURCE */
#endif