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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The add to archive tape archiver win32 command option name. */
static wchar_t* ADD_TO_ARCHIVE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = L"a";
static int* ADD_TO_ARCHIVE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination tape archiver win32 command option name. */
static wchar_t* DESTINATION_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = L"-o";
static int* DESTINATION_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The force archiver win32 command option name. */
static wchar_t* FORCE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = L"-y";
static int* FORCE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gzip format tape archiver win32 command option name. */
static wchar_t* GZIP_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = L"-tgzip";
static int* GZIP_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tar format tape archiver win32 command option name. */
static wchar_t* TAR_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = L"-ttar";
static int* TAR_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unpack tape archiver win32 command option name. */
static wchar_t* UNPACK_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME = L"x";
static int* UNPACK_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
