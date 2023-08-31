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

#ifndef TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The create new archive tape archiver unix command option name. */
static wchar_t* CREATE_NEW_ARCHIVE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = L"-c";
static int* CREATE_NEW_ARCHIVE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination tape archiver unix command option name. */
static wchar_t* DESTINATION_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = L"-C";
static int* DESTINATION_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The force archiver unix command option name. */
static wchar_t* FORCE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = L"--overwrite";
static int* FORCE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gzip tape archiver unix command option name. */
static wchar_t* GZIP_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = L"-z";
static int* GZIP_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unpack tape archiver unix command option name. */
static wchar_t* UNPACK_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = L"-x";
static int* UNPACK_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The use file tape archiver unix command option name. */
static wchar_t* USE_FILE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = L"-f";
static int* USE_FILE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The verbal tape archiver unix command option name. */
static wchar_t* VERBAL_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = L"-v";
static int* VERBAL_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
