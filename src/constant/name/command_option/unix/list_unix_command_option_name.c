/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIST_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE
#define LIST_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The all list unix command option name. */
static wchar_t ALL_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'a', L'l', L'l'};
static wchar_t* ALL_LIST_UNIX_COMMAND_OPTION_NAME = ALL_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* ALL_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The long list unix command option name. */
static wchar_t LONG_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'l'};
static wchar_t* LONG_LIST_UNIX_COMMAND_OPTION_NAME = LONG_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* LONG_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The one row per entry list unix command option name. */
static wchar_t ONE_ROW_PER_ENTRY_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'1'};
static wchar_t* ONE_ROW_PER_ENTRY_LIST_UNIX_COMMAND_OPTION_NAME = ONE_ROW_PER_ENTRY_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* ONE_ROW_PER_ENTRY_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursive list unix command option name. */
static wchar_t RECURSIVE_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'R'};
static wchar_t* RECURSIVE_LIST_UNIX_COMMAND_OPTION_NAME = RECURSIVE_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* RECURSIVE_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort by file size list unix command option name. */
static wchar_t SORT_BY_FILE_SIZE_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'S'};
static wchar_t* SORT_BY_FILE_SIZE_LIST_UNIX_COMMAND_OPTION_NAME = SORT_BY_FILE_SIZE_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* SORT_BY_FILE_SIZE_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort by modification time list unix command option name. */
static wchar_t SORT_BY_MODIFICATION_TIME_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L't'};
static wchar_t* SORT_BY_MODIFICATION_TIME_LIST_UNIX_COMMAND_OPTION_NAME = SORT_BY_MODIFICATION_TIME_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* SORT_BY_MODIFICATION_TIME_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sort by file extension list unix command option name. */
static wchar_t SORT_BY_FILE_EXTENSION_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'X'};
static wchar_t* SORT_BY_FILE_EXTENSION_LIST_UNIX_COMMAND_OPTION_NAME = SORT_BY_FILE_EXTENSION_LIST_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* SORT_BY_FILE_EXTENSION_LIST_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LIST_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE */
#endif
