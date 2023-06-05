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

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"
#include "variable.h"

/**
 * Initialises log global variables.
 */
void globalise_log() {

    //?? fwprintf(stdout, L"Debug: Globalise log.\n");

    *LOG_LEVEL = *OFF_LEVEL_LOG_CYBOI_MODEL;

    //
    // CAUTION! The LOG_MESSAGE variable array was already allocated.
    // It does not receive an initial value and remains empty here.
    // It gets only filled later, by the logger.
    //
    // CAUTION! Do NOT assign a null pointer here, since then,
    // the allocated array would be lost!
    //
    *LOG_MESSAGE_COUNT = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    *LOG_MESSAGE_SIZE = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! This variable HAS TO BE INITIALISED with null!
    // Otherwise, strange log errors will appear at runtime,
    // since some functions call the logger before it is setup.
    // The LOG_OUTPUT variable is tested for a defined null there.
    //
    // CAUTION! Do NOT try to initialise the log output of type FILE!
    //
    // FILE objects are allocated and managed internally by the input/ output
    // library functions. The library creates objects of type FILE.
    // Programs should deal only with pointers to these objects (FILE* values),
    // rather than the objects themselves.
    //
    // Hence, the following line would NOT have sense and is FORBIDDEN:
    // LOG_OUTPUT = (FILE*) malloc(sizeof (FILE));
    //
    // The LOG_OUTPUT variable does not receive an initial value
    // and remains empty here. It gets only filled later,
    // in file "optionaliser.c", which cares about log file creation.
    //
    LOG_OUTPUT = *NULL_POINTER_STATE_CYBOI_MODEL;
}
