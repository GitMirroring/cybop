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

#ifndef COMPARE_FILES_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE
#define COMPARE_FILES_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The print differing chars compare files unix command option name. */
static wchar_t* PRINT_DIFFERING_CHARS_COMPARE_FILES_UNIX_COMMAND_OPTION_NAME = L"-c";
static int* PRINT_DIFFERING_CHARS_COMPARE_FILES_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print offset compare files unix command option name. */
static wchar_t* PRINT_OFFSET_COMPARE_FILES_UNIX_COMMAND_OPTION_NAME = L"-l";
static int* PRINT_OFFSET_COMPARE_FILES_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The silent compare files unix command option name. */
static wchar_t* SILENT_COMPARE_FILES_UNIX_COMMAND_OPTION_NAME = L"-s";
static int* SILENT_COMPARE_FILES_UNIX_COMMAND_OPTION_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMPARE_FILES_UNIX_COMMAND_OPTION_NAME_CONSTANT_SOURCE */
#endif
