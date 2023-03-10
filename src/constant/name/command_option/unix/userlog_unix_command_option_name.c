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

#ifndef USERLOG_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define USERLOG_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The noheader Userlog unix command option name. */
static wchar_t* NOHEADER_USERLOG_UNIX_COMMAND_OPTION_NAME = L"-h";
static int* NOHEADER_USERLOG_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nocurrent Userlog unix command option name. */
static wchar_t* NOCURRENT_USERLOG_UNIX_COMMAND_OPTION_NAME = L"-u";
static int* NOCURRENT_USERLOG_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The short Userlog unix command option name. */
static wchar_t* SHORT_USERLOG_UNIX_COMMAND_OPTION_NAME = L"-s";
static int* SHORT_USERLOG_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The old Userlog hostname unix command option name. */
static wchar_t* OLD_USERLOG_UNIX_COMMAND_OPTION_NAME = L"-o";
static int* OLD_USERLOG_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* USERLOG_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
