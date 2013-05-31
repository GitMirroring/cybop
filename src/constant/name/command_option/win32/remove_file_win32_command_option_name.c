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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_SOURCE
#define REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The force remove windows command option name. */
static wchar_t FORCE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'/', L'F'};
static wchar_t* FORCE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME = FORCE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* FORCE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactvie remove windows command option name. */
static wchar_t INTERACTIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'/', L'S'};
static wchar_t* INTERACTIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME = INTERACTIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* INTERACTIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursvie remove windows command option name. */
static wchar_t RECURSIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_ARRAY[] = {L'/', L'P'};
static wchar_t* RECURSIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME = RECURSIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_ARRAY;
static int* RECURSIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_CONSTANT_SOURCE */
#endif