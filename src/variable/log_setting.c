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

#ifndef LOG_SETTING_SOURCE
#define LOG_SETTING_SOURCE

#include <stdio.h>

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

/** The log level. */
static int LOG_LEVEL_ARRAY[1];
static int* LOG_LEVEL = LOG_LEVEL_ARRAY;

/**
 * The log message.
 *
 * It may have a maximum count of 1000 wide characters.
 * This is just to have a defined size and avoid steady reallocation.
 *
 * In addition to the actual message, there has to be place for:
 * - log level (the longest of is "information"): 11 Byte
 * - colon: 1 Byte
 * - space: 1 Byte
 * - line feed: 1 Byte
 * - null termination: 1 Byte
 *
 * Sum: 15 Byte
 *
 * Therefore, 1015 is used here instead of just 1000.
 */
static wchar_t LOG_MESSAGE_ARRAY[1015];
static wchar_t* LOG_MESSAGE = LOG_MESSAGE_ARRAY;

static int LOG_MESSAGE_COUNT_ARRAY[1];
static int* LOG_MESSAGE_COUNT = LOG_MESSAGE_COUNT_ARRAY;

static int LOG_MESSAGE_SIZE_ARRAY[1];
static int* LOG_MESSAGE_SIZE = LOG_MESSAGE_SIZE_ARRAY;

/** The log output. */
//?? static FILE LOG_OUTPUT_ARRAY[1];
//?? static FILE* LOG_OUTPUT = LOG_OUTPUT_ARRAY;
static FILE* LOG_OUTPUT;

/**
 * The debug flag.
 *
 * CAUTION! It does actually NOT belong to the logger.
 * However, since the logger is included in almost every file,
 * it is just convenient to define the debug flag here WITHOUT
 * having to include a separate file into all source code using it.
 */
static int DEBUG_CYBOP = 0;

/* LOG_SETTING_SOURCE */
#endif
