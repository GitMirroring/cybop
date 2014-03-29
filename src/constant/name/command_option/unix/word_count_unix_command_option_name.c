 
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

#ifndef WORD_COUNT_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE
#define WORD_COUNT_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The byte word count unix command option name. */
static wchar_t* BYTE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = L"--bytes";
static int* BYTE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The char word count unix command option name. */
static wchar_t CHAR_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'c', L'h', L'a', L'r', L's'};
static wchar_t* CHAR_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = CHAR_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* CHAR_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The line word count unix command option name. */
static wchar_t LINE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'l', L'i', L'n', L'e', L's'};
static wchar_t* LINE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = LINE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* LINE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The max line length word count unix command option name. */
static wchar_t MAX_LINE_LENGTH_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'm', L'a', L'x', L'-', L'l', L'i', L'n', L'e', L'-', L'l', L'e', L'n', L'g', L't', L'h'};
static wchar_t* MAX_LINE_LENGTH_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = MAX_LINE_LENGTH_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* MAX_LINE_LENGTH_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The word word count unix command option name. */
static wchar_t WORD_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'w', L'o', L'r', L'd', L's'};
static wchar_t* WORD_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = WORD_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* WORD_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WORD_COUNT_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE */
#endif
