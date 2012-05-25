/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOG_SETTING_SOURCE
#define LOG_SETTING_SOURCE

#include <stdio.h>

//
// The global variables.
//
// CAUTION! This is just the variable definition, specifying a size.
// Initialisation happens in directory "controller/globaliser/".
//

/** The log level. */
static int LOG_LEVEL_ARRAY[1];
static int* LOG_LEVEL = LOG_LEVEL_ARRAY;

/** The log message. */
static wchar_t LOG_MESSAGE_ARRAY[1000];
static wchar_t* LOG_MESSAGE = LOG_MESSAGE_ARRAY;

static int LOG_MESSAGE_COUNT_ARRAY[1];
static int* LOG_MESSAGE_COUNT = LOG_MESSAGE_COUNT_ARRAY;

static int LOG_MESSAGE_SIZE_ARRAY[1];
static int* LOG_MESSAGE_SIZE = LOG_MESSAGE_SIZE_ARRAY;

/** The log output. */
static void* LOG_OUTPUT_ARRAY[1];
static void** LOG_OUTPUT = LOG_OUTPUT_ARRAY;

/* LOG_SETTING_SOURCE */
#endif
