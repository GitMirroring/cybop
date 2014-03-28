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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_CONSTANT_SOURCE
#define TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The add to archive tape archiver command option name. */
static wchar_t ADD_TO_ARCHIVE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'a'};
static wchar_t* ADD_TO_ARCHIVE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = ADD_TO_ARCHIVE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* ADD_TO_ARCHIVE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination tape archiver command option name. */
static wchar_t DESTINATION_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'o'};
static wchar_t* DESTINATION_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = DESTINATION_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* DESTINATION_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The force archiver command option name. */
static wchar_t FORCE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'y'};
static wchar_t* FORCE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = FORCE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* FORCE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gzip format tape archiver command option name. */
static wchar_t GZIP_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L't', L'g', L'z', L'i', L'p'};
static wchar_t* GZIP_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = GZIP_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* GZIP_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tar format tape archiver command option name. */
static wchar_t TAR_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L't', L't', L'a', L'r'};
static wchar_t* TAR_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = TAR_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* TAR_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unpack tape archiver command option name. */
static wchar_t UNPACK_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'x'};
static wchar_t* UNPACK_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = UNPACK_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* UNPACK_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_CONSTANT_SOURCE */
#endif