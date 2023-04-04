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

#ifndef WORD_COUNT_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define WORD_COUNT_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The byte word count unix command option name. */
static wchar_t* BYTE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = L"--bytes";
static int* BYTE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The char word count unix command option name. */
static wchar_t* CHAR_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = L"--chars";
static int* CHAR_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The line word count unix command option name. */
static wchar_t* LINE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = L"--lines";
static int* LINE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The max line length word count unix command option name. */
static wchar_t* MAX_LINE_LENGTH_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = L"--max-line-length";
static int* MAX_LINE_LENGTH_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The word word count unix command option name. */
static wchar_t* WORD_WORD_COUNT_UNIX_COMMAND_OPTION_NAME = L"--words";
static int* WORD_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WORD_COUNT_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
