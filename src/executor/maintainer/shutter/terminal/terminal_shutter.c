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
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../executor/maintainer/shutter/terminal/stream_terminal_shutter.c"
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

    // The blocking mode.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The canonical mode.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The echo mode.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The character buffer data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* cc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The wide character buffer.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get blocking mode from input/output entry.
    copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BLOCKING_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get canonical mode from input/output entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CANONICAL_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get echo mode from input/output entry.
    copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ECHO_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get character buffer data, count from input/output entry.
    copy_array_forward((void*) &cd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHARACTER_BUFFER_DATA_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    copy_array_forward((void*) &cc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHARACTER_BUFFER_COUNT_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get wide character buffer from input/output entry.
    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BUFFER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

    //
    // CAUTION! Resetting the values is not necessary,
    // since the input/output entry gets deallocated anyway.
    //

    //
    // Deallocate blocking mode.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &b, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Deallocate canonical mode.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &c, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Deallocate echo mode.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &e, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    //
    // Deallocate character buffer data, count.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &cd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_64_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_array((void*) &cc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Deallocate wide character buffer item.
    deallocate_item((void*) &w, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // See comment in file "terminal_starter.c"!
    //
    // The output- and input stream were stored separately
    // in the input/output entry, since they are needed
    // for writing and reading data.
    //
    // However, both streams have identical terminal settings.
    // Shutting down both would cause the settings to be reset
    // to the original attributes TWICE and lead to errors like:
    //
    // Shutdown terminal mode.
    // Could not startup unix terminal mode set. An error occured within tcsetattr.
    // Could not startup unix terminal mode set. The filedes argument is not a valid file descriptor. EBADF errno: 9
    //
    // Therefore, ONLY the output stream is shut down below
    // but NOT the input stream.
    // Exception: In the windows operating system they are treated separately.
    //

#if defined(__linux__) || defined(__unix__)
    shutdown_terminal_stream(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
#elif defined(__APPLE__) && defined(__MACH__)
    shutdown_terminal_stream(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    shutdown_terminal_stream(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    shutdown_terminal_stream(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* TERMINAL_SHUTTER_SOURCE */
#endif
