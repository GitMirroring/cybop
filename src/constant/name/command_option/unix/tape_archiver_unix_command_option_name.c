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

#ifndef TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE
#define TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The create new archive tape archiver command option name. */
static wchar_t CREATE_NEW_ARCHIVE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'c'};
static wchar_t* CREATE_NEW_ARCHIVE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = CREATE_NEW_ARCHIVE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* CREATE_NEW_ARCHIVE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination tape archiver command option name. */
static wchar_t DESTINATION_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'C'};
static wchar_t* DESTINATION_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = DESTINATION_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* DESTINATION_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The force archiver command option name. */
static wchar_t FORCE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'-', L'o', L'v', L'e', L'r', L'w', L'r', L'i', L't', L'e'};
static wchar_t* FORCE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = FORCE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* FORCE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gzip tape archiver command option name. */
static wchar_t GZIP_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'z'};
static wchar_t* GZIP_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = GZIP_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* GZIP_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unpack tape archiver command option name. */
static wchar_t UNPACK_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'x'};
static wchar_t* UNPACK_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = UNPACK_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* UNPACK_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The use file tape archiver command option name. */
static wchar_t USE_FILE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'f'};
static wchar_t* USE_FILE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = USE_FILE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* USE_FILE_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The verbal tape archiver command option name. */
static wchar_t VERBAL_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'v'};
static wchar_t* VERBAL_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME = VERBAL_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* VERBAL_TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TAPE_ARCHIVER_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE */
#endif