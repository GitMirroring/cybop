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

#ifndef COPY_FILE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define COPY_FILE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The force copy file unix command option name. */
static wchar_t* FORCE_COPY_FILE_UNIX_COMMAND_OPTION_NAME = L"-f";
static int* FORCE_COPY_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactive copy file unix command option name. */
static wchar_t* INTERACTIVE_COPY_FILE_UNIX_COMMAND_OPTION_NAME = L"-i";
static int* INTERACTIVE_COPY_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The preserve all attributes copy file unix command option name. */
static wchar_t* PRESERVE_ALL_ATTRIBUTES_COPY_FILE_UNIX_COMMAND_OPTION_NAME = L"-a";
static int* PRESERVE_ALL_ATTRIBUTES_COPY_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The preserve links copy file unix command option name. */
static wchar_t* PRESERVE_LINKS_COPY_FILE_UNIX_COMMAND_OPTION_NAME = L"-d";
static int* PRESERVE_LINKS_COPY_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursive copy file unix command option name. */
static wchar_t* RECURSIVE_COPY_FILE_UNIX_COMMAND_OPTION_NAME = L"-r";
static int* RECURSIVE_COPY_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The update copy file unix command option name. */
static wchar_t* UPDATE_COPY_FILE_UNIX_COMMAND_OPTION_NAME = L"-u";
static int* UPDATE_COPY_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The verbal copy file unix command option name. */
static wchar_t* VERBAL_COPY_FILE_UNIX_COMMAND_OPTION_NAME = L"-v";
static int* VERBAL_COPY_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COPY_FILE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
