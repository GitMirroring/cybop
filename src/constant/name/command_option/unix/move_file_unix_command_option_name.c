/*
 * Copyright (C) 1999-2013. Christian Heller.
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

#ifndef MOVE_FILE_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE
#define MOVE_FILE_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The force move unix command option name. */
static wchar_t FORCE_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'f'};
static wchar_t* FORCE_MOVE_FILE_UNIX_COMMAND_OPTION_NAME = FORCE_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* FORCE_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactvie move unix command option name. */
static wchar_t INTERACTIVE_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'i'};
static wchar_t* INTERACTIVE_MOVE_FILE_UNIX_COMMAND_OPTION_NAME = INTERACTIVE_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* INTERACTIVE_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The verbal move unix command option name. */
static wchar_t VERBAL_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_ARRAY[] = {L'-', L'v'};
static wchar_t* VERBAL_MOVE_FILE_UNIX_COMMAND_OPTION_NAME = VERBAL_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_ARRAY;
static int* VERBAL_MOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MOVE_FILE_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE */
#endif