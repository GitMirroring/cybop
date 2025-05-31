/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TOP_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER
#define TOP_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The BATCH top format unix command option name. */
static wchar_t* BATCH_TOP_UNIX_COMMAND_OPTION_NAME = L"-b";
static int* BATCH_TOP_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The COMMAND top format unix command option name. */
static wchar_t* COMMAND_TOP_UNIX_COMMAND_OPTION_NAME = L"-c";
static int* COMMAND_TOP_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The THREAD top format unix command option name. */
static wchar_t* THREAD_TOP_UNIX_COMMAND_OPTION_NAME = L"-h";
static int* THREAD_TOP_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The IDLE top format unix command option name. */
static wchar_t* IDLE_TOP_UNIX_COMMAND_OPTION_NAME = L"-i";
static int* IDLE_TOP_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The SECURE top format unix command option name. */
static wchar_t* SECURE_TOP_UNIX_COMMAND_OPTION_NAME = L"-s";
static int* SECURE_TOP_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TOP_UNIX_COMMAND_OPTION_NAME_CONSTANT_HEADER */
#endif
