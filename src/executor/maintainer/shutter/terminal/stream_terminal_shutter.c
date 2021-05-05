/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef STREAM_TERMINAL_SHUTTER_SOURCE
#define STREAM_TERMINAL_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../executor/maintainer/shutter/terminal/mode_terminal_shutter.c"
#include "../../../../executor/maintainer/starter/terminal/get_file_number_terminal_starter.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the terminal stream.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the input/output entry
 * @param p1 the flag indicating input (true) or output (false)
 * @param p2 the input/output entry source index
 */
void shutdown_terminal_stream(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown terminal stream.");

    //
    // The terminal file stream.
    //
    // CAUTION! The standard input/output streams "stdin"
    // and "stdout" exist on posix as well as on win32.
    //
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal file descriptor.
    int d = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Retrieve terminal file streams from input/output entry.
    //
    // CAUTION! Do NOT use "overwrite_array" function here,
    // since it adapts the array count and size.
    // But the array's count and size are CONSTANT.
    //
    // CAUTION! Hand over values as pointer REFERENCE.
    //
    // CAUTION! Do NOT hand over input/output entry as pointer reference.
    //
    get_io_entry_element((void*) &s, p0, p2);

    // Get terminal file descriptor from file stream.
    //??
    //?? TODO: Commented out, since stdout cannot be stored
    //?? in input/output entry successfully.
    //?? Therefore, stdout of type FILE* is handed over
    //?? directly here. Investigate this later.
    //?? startup_terminal_file_number_get((void*) &d, s);
    //??
    startup_terminal_file_number_get((void*) &d, (void*) stdout);

    // Restore original terminal mode.
    shutdown_terminal_mode((void*) &d, p0, p1);

    //
    // CAUTION! A "close" function is NOT called here,
    // since STANDARD terminal output- and input file descriptors
    // were used at startup and MUST NOT be closed.
    // This is the case on all operating systems.
    //
}

/* STREAM_TERMINAL_SHUTTER_SOURCE */
#endif
