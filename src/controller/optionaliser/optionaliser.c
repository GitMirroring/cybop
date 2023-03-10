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

#ifndef OPTIONALISER_SOURCE
#define OPTIONALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../controller/optionaliser/log_file_optionaliser.c"
#include "../../executor/representer/deserialiser/command_line/command_line_deserialiser.c"
#include "../../logger/logger.c"

/**
 * Optionalises the given command line argument options.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the test unit
 * @param p4 the log file stream (pointer reference)
 * @param p5 the arguments data (pointer reference)
 * @param p6 the arguments count
 */
void optionalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    //
    // log_write((void*) stdout, L"Information: Optionalise.\n");
    //
    //?? fwprintf(stdout, L"Debug: Optionalise. p2: %i\n", p2);

    // The terminated log file name item as multibyte character data.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate terminated log file name item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! Do NOT use a wide character array here!
    // The glibc file stream functions below expect standard (multibyte) character arrays.
    //
    allocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Get command line options, among others the file name data, count.
    deserialise_command_line(p0, p1, p2, p3, f, p5, p6);

    // Optionalise log file handing over terminated log file name item.
    optionalise_log_file(p4, f);

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Begin log.");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"(See file 'optionaliser.c' for this message.)");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");

    // Deallocate terminated log file name item.
    deallocate_item((void*) &f, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* OPTIONALISER_SOURCE */
#endif
