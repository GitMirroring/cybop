/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
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

/** The copy file unix command model. */
static wchar_t COPY_FILE_UNIX_COMMAND_MODEL_ARRAY[] = {L'c', L'p'};
static wchar_t* COPY_FILE_UNIX_COMMAND_MODEL = COPY_FILE_UNIX_COMMAND_MODEL_ARRAY;
static int* COPY_FILE_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo message unix command model. */
static wchar_t ECHO_MESSAGE_UNIX_COMMAND_MODEL_ARRAY[] = {L'e', L'c', L'h', L'o'};
static wchar_t* ECHO_MESSAGE_UNIX_COMMAND_MODEL = ECHO_MESSAGE_UNIX_COMMAND_MODEL_ARRAY;
static int* ECHO_MESSAGE_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list directory contents unix command model. */
static wchar_t LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ARRAY[] = {L'l', L's'};
static wchar_t* LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL = LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

/** The word count unix command model. */
static wchar_t WORD_COUNT_UNIX_COMMAND_MODEL_ARRAY[] = {L'w', L'c'};
static wchar_t* WORD_COUNT_UNIX_COMMAND_MODEL = WORD_COUNT_UNIX_COMMAND_MODEL_ARRAY;
static int* WORD_COUNT_UNIX_COMMAND_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The create folder unix command model. */
static wchar_t CREATE_FOLDER_UNIX_COMMAND_MODEL_ARRAY[] = {L'm', L'k', L'd', L'i', L'r'};
static wchar_t* CREATE_FOLDER_UNIX_COMMAND_MODEL = CREATE_FOLDER_UNIX_COMMAND_MODEL_ARRAY;
static int* CREATE_FOLDER_UNIX_COMMAND_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ping unix command model. */
static wchar_t PING_UNIX_COMMAND_MODEL_ARRAY[] = {L'p', L'i', L'n', L'g'};
static wchar_t* PING_UNIX_COMMAND_MODEL = PING_UNIX_COMMAND_MODEL_ARRAY;
static int* PING_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The grep unix command model. */
static wchar_t GREP_UNIX_COMMAND_MODEL_ARRAY[] = {L'g', L'r', L'e', L'p'};
static wchar_t* GREP_UNIX_COMMAND_MODEL = GREP_UNIX_COMMAND_MODEL_ARRAY;
static int* GREP_UNIX_COMMAND_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* UNIX_COMMAND_MODEL_CONSTANT_SOURCE */
#endif
