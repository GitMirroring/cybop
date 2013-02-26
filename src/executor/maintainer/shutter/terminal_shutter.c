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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_SHUTTER_SOURCE
#define TERMINAL_SHUTTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <termios.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../logger/logger.c"

/**
 * Shuts down the terminal.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_terminal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown terminal.");

    // The terminal input- and output stream.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get terminal input- and output stream.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_STREAM_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_STREAM_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only deallocate terminal resources if AT LEAST ONE,
    // the input- OR output stream internal is NOT null.
    if ((ip != *NULL_POINTER_STATE_CYBOI_MODEL) || (op != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Interrupt terminal service thread.
        interrupt_thread(p1, p2);

        // The original termios settings.
        void* to = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get terminal internals.
        copy_array_forward((void*) &to, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ORIGINAL_ATTRIBUTES_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        // Get file descriptor for file stream.
        // CAUTION! The stream "stdin" must be used instead of "stdout" here!
        int d = fileno((FILE*) ip);

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        // Reset terminal to original attributes.
        //
        // The second argument specifies how to deal with
        // input and output already queued.
        // It can be one of the following values:
        // TCSANOW - Make the change immediately.
        // TCSADRAIN - Make the change after waiting until all queued output has been written. You should usually use this option when changing parameters that affect output.
        // TCSAFLUSH - This is like TCSADRAIN, but also discards any queued input.
        // TCSASOFT - This is a flag bit that you can add to any of the above alternatives.
        //            Its meaning is to inhibit alteration of the state of the terminal hardware.
        //            It is a BSD extension; it is only supported on BSD systems and the GNU system.
        //            Using TCSASOFT is exactly the same as setting the CIGNORE bit in the c_cflag member of the structure termios-p points to.
        int e = tcsetattr(d, TCSANOW, (struct termios*) to);

        if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. The termios settings could not be set.");

            if (errno == EBADF) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. The filedes argument is not a valid file descriptor.");

            } else if (errno == ENOTTY) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. The filedes is not associated with a terminal.");

            } else if (errno == EINVAL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. Either the value of the second argument is not valid, or there is something wrong with the data in the third argument.");

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. An unknown error occured.");
            }
        }

fwprintf(stdout, L"TEST to free: %i\n", to);

        // Deallocate termios settings.
        free(to);

fwprintf(stdout, L"TEST to after free: %i\n", to);

        // CAUTION! DO NOT deallocate ip and op because they refer to stdin and stdout of the system!
        // This might be changed at a (much) later point in CYBOI development.

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. There is no terminal running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* TERMINAL_SHUTTER_SOURCE */
#endif
