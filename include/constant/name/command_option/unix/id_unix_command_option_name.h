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

#ifndef ID_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define ID_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The CONTEXT id format unix command option name. */
static wchar_t* CONTEXT_ID_UNIX_COMMAND_OPTION_NAME = L"-Z";
static int* CONTEXT_ID_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The GROUP id format unix command option name. */
static wchar_t* GROUP_ID_UNIX_COMMAND_OPTION_NAME = L"-g";
static int* GROUP_ID_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The GROUPS id format unix command option name. */
static wchar_t* GROUPS_ID_UNIX_COMMAND_OPTION_NAME = L"-G";
static int* GROUPS_ID_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The NAME id format unix command option name. */
static wchar_t* NAME_ID_UNIX_COMMAND_OPTION_NAME = L"-n";
static int* NAME_ID_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The USER id format unix command option name. */
static wchar_t* USER_ID_UNIX_COMMAND_OPTION_NAME = L"-u";
static int* USER_ID_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;
/* ID_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
