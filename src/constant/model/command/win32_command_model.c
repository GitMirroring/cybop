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

#ifndef WIN32_COMMAND_MODEL_CONSTANT_SOURCE
#define WIN32_COMMAND_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The change directory win32 command model. */
static wchar_t CHANGE_DIRECTORY_WIN32_COMMAND_MODEL_ARRAY[] = {L'c', L'd'};
static wchar_t* CHANGE_DIRECTORY_WIN32_COMMAND_MODEL = CHANGE_DIRECTORY_WIN32_COMMAND_MODEL_ARRAY;
static int* CHANGE_DIRECTORY_WIN32_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy win32 command model. */
static wchar_t XCOPY_WIN32_COMMAND_MODEL_ARRAY[] = {L'x', L'c', L'o', L'p', L'y'};
static wchar_t* XCOPY_WIN32_COMMAND_MODEL = XCOPY_WIN32_COMMAND_MODEL_ARRAY;
static int* XCOPY_WIN32_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clear screen win32 command model. */
static wchar_t CLEAR_SCREEN_WIN32_COMMAND_MODEL_ARRAY[] = {L'c', L'l', L's'};
static wchar_t* CLEAR_SCREEN_WIN32_COMMAND_MODEL = CLEAR_SCREEN_WIN32_COMMAND_MODEL_ARRAY;
static int* CLEAR_SCREEN_WIN32_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print date win32 command model. */
static wchar_t DATE_WIN32_COMMAND_MODEL_ARRAY[] = {L'd', L'a', L't', L'e'};
static wchar_t* DATE_WIN32_COMMAND_MODEL = DATE_WIN32_COMMAND_MODEL_ARRAY;
static int* DATE_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The delete win32 command model. */
static wchar_t DEL_WIN32_COMMAND_MODEL_ARRAY[] = {L'd', L'e', L'l'};
static wchar_t* DEL_WIN32_COMMAND_MODEL = DEL_WIN32_COMMAND_MODEL_ARRAY;
static int* DEL_WIN32_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The kill win32 command model. */
static wchar_t KILL_WIN32_COMMAND_MODEL_ARRAY[] = {L't', L's', L'k', L'i', L'l', L'l'};
static wchar_t* KILL_WIN32_COMMAND_MODEL = KILL_WIN32_COMMAND_MODEL_ARRAY;
static int* KILL_WIN32_COMMAND_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list directory contents win32 command model. */
static wchar_t DIR_WIN32_COMMAND_MODEL_ARRAY[] = {L'd', L'i', L'r'};
static wchar_t* DIR_WIN32_COMMAND_MODEL = DIR_WIN32_COMMAND_MODEL_ARRAY;
static int* DIR_WIN32_COMMAND_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo win32 command model. */
static wchar_t ECHO_WIN32_COMMAND_MODEL_ARRAY[] = {L'e', L'c', L'h', L'o'};
static wchar_t* ECHO_WIN32_COMMAND_MODEL = ECHO_WIN32_COMMAND_MODEL_ARRAY;
static int* ECHO_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The help win32 command model. */
static wchar_t HELP_WIN32_COMMAND_MODEL_ARRAY[] = {L'h', L'e', L'l', L'p'};
static wchar_t* HELP_WIN32_COMMAND_MODEL = HELP_WIN32_COMMAND_MODEL_ARRAY;
static int* HELP_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move win32 command model. */
static wchar_t MOVE_WIN32_COMMAND_MODEL_ARRAY[] = {L'm', L'o', L'v', L'e'};
static wchar_t* MOVE_WIN32_COMMAND_MODEL = MOVE_WIN32_COMMAND_MODEL_ARRAY;
static int* MOVE_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tape archiver win32 command model. */
static wchar_t SEVEN_ZIP_WIN32_COMMAND_MODEL_ARRAY[] = {L'7', L'z', L'.', L'e', L'x', L'e'};
static wchar_t* SEVEN_ZIP_WIN32_COMMAND_MODEL = SEVEN_ZIP_WIN32_COMMAND_MODEL_ARRAY;
static int* SEVEN_ZIP_WIN32_COMMAND_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ping win32 command model. */
static wchar_t PING_WIN32_COMMAND_MODEL_ARRAY[] = {L'p', L'i', L'n', L'g'};
static wchar_t* PING_WIN32_COMMAND_MODEL = PING_WIN32_COMMAND_MODEL_ARRAY;
static int* PING_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** Configuration of a network adapter. */
static wchar_t CONFIG_NETWORK_WIN32_COMMAND_MODEL_ARRAY[] = {L'i', L'p', L'c', L'o', L'n', L'f', L'i', L'g'};
static wchar_t* CONFIG_NETWORK_WIN32_COMMAND_MODEL = CONFIG_NETWORK_WIN32_COMMAND_MODEL_ARRAY;
static int* CONFIG_NETWORK_WIN32_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The grep win32 command model. */
static wchar_t FIND_WIN32_COMMAND_MODEL_ARRAY[] = {L'f', L'i', L'n', L'd'};
static wchar_t* FIND_WIN32_COMMAND_MODEL = FIND_WIN32_COMMAND_MODEL_ARRAY;
static int* FIND_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The traceroute win32 command model. */
static wchar_t TRACERT_WIN32_COMMAND_MODEL_ARRAY[] = {L't', L'r', L'a', L'c', L'e', L'r', L't'};
static wchar_t* TRACERT_WIN32_COMMAND_MODEL = TRACERT_WIN32_COMMAND_MODEL_ARRAY;
static int* TRACERT_WIN32_COMMAND_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The diff win32 command model. */
static wchar_t FC_WIN32_COMMAND_MODEL_ARRAY[] = {L'f', L'c'};
static wchar_t* FC_WIN32_COMMAND_MODEL = FC_WIN32_COMMAND_MODEL_ARRAY;
static int* FC_WIN32_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort win32 command model. */
static wchar_t SORT_WIN32_COMMAND_MODEL_ARRAY[] = {L's', L'o', L'r', L't'};
static wchar_t* SORT_WIN32_COMMAND_MODEL = SORT_WIN32_COMMAND_MODEL_ARRAY;
static int* SORT_WIN32_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list tasks win32 command model. */
static wchar_t LIST_TASKS_WIN32_COMMAND_MODEL_ARRAY[] = {L't', L'a', L's', L'k', L'l', L'i', L's', L't'};
static wchar_t* LIST_TASKS_WIN32_COMMAND_MODEL = LIST_TASKS_WIN32_COMMAND_MODEL_ARRAY;
static int* LIST_TASKS_WIN32_COMMAND_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WIN32_COMMAND_MODEL_CONSTANT_SOURCE */
#endif