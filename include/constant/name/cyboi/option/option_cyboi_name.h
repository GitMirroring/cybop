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

#ifndef OPTION_CYBOI_NAME_CONSTANT_HEADER
#define OPTION_CYBOI_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

/** The "--help" option cyboi name. */
static wchar_t* HELP_OPTION_CYBOI_NAME = L"--help";
static int* HELP_OPTION_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--knowledge" option cyboi name. */
static wchar_t* KNOWLEDGE_OPTION_CYBOI_NAME = L"--knowledge";
static int* KNOWLEDGE_OPTION_CYBOI_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--logfile" option cyboi name. */
static wchar_t* LOG_FILE_OPTION_CYBOI_NAME = L"--logfile";
static int* LOG_FILE_OPTION_CYBOI_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--loglevel" option cyboi name. */
static wchar_t* LOG_LEVEL_OPTION_CYBOI_NAME = L"--loglevel";
static int* LOG_LEVEL_OPTION_CYBOI_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "--version" option cyboi name. */
static wchar_t* VERSION_OPTION_CYBOI_NAME = L"--version";
static int* VERSION_OPTION_CYBOI_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* OPTION_CYBOI_NAME_CONSTANT_HEADER */
#endif
