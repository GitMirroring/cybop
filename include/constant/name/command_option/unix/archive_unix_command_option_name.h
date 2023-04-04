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

#ifndef ARCHIVE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define ARCHIVE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The create archive unix command option name. */
static wchar_t* CREATE_ARCHIVE_UNIX_COMMAND_OPTION_NAME = L"create";
static int* CREATE_ARCHIVE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The update archive unix command option name. */
static wchar_t* UPDATE_ARCHIVE_UNIX_COMMAND_OPTION_NAME = L"update";
static int* UPDATE_ARCHIVE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bzip2 archive unix command option name. */
static wchar_t* BZIP2_ARCHIVE_UNIX_COMMAND_OPTION_NAME = L"bzip2";
static int* BZIP2_ARCHIVE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ARCHIVE_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
