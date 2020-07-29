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

#ifndef TERMINAL_SHUTTER_SOURCE
#define TERMINAL_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../executor/maintainer/shutter/terminal/mode_terminal_shutter.c"
#include "../../../../executor/maintainer/starter/terminal/get_file_number_terminal_starter.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the terminal.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the input/output entry
 */
void shutdown_terminal(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown terminal.");

    // The terminal output- and input file streams.
    // CAUTION! The standard input/output streams "stdin"
    // and "stdout" exist on posix as well as on win32.
    void* os = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* is = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal output- and input file descriptors.
    int od = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    int id = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

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
    get_io_entry_element((void*) &os, p0, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    get_io_entry_element((void*) &is, p0, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Get terminal output- and input file descriptors from file streams.
    startup_terminal_file_number_get((void*) &od, os);
    startup_terminal_file_number_get((void*) &id, is);

    //
    // Restore original terminal mode.
    //
    // CAUTION! The order of function calls IS IMPORTANT (first input, then output).
    // For some unknown reason, the terminal mode is not restored properly
    // (enter | return key does not break the line but adds prompt to the end of a line),
    // when restoring the output first and the input only afterwards.
    // However, restoring the output only (not the input) is NOT a viable solution,
    // since the win32 console expects different modes for input and output.
    //
    shutdown_terminal_mode((void*) &id, p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    shutdown_terminal_mode((void*) &od, p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // CAUTION! A "close" function is NOT called here,
    // since standard terminal output- and input file descriptors
    // were used at startup and MUST NOT be closed.
    // This is the case on all operating systems.
    //
}

/* TERMINAL_SHUTTER_SOURCE */
#endif
