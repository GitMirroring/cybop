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

#ifndef DATE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define DATE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The ISO date format unix command option name. */
static wchar_t* ISO_DATE_UNIX_COMMAND_OPTION_NAME = L"-I";
static int* ISO_DATE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RFC date format unix command option name. */
static wchar_t* RFC_DATE_UNIX_COMMAND_OPTION_NAME = L"-R";
static int* RFC_DATE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The UTC date format unix command option name. */
static wchar_t* UTC_DATE_UNIX_COMMAND_OPTION_NAME = L"-u";
static int* UTC_DATE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DATE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
