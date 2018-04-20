/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ATTRIBUTES_UNIX_TERMINAL_SHUTTER_SOURCE
#define ATTRIBUTES_UNIX_TERMINAL_SHUTTER_SOURCE

#include <termios.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Resets unix terminal attributes.
 *
 * @param p0 the file descriptor data
 * @param p1 the internal memory data
 */
void shutdown_unix_terminal_attributes(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown unix terminal attributes.");

        // The original attributes.
        void* o = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get original attributes.
        copy_array_forward((void*) &o, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ORIGINAL_ATTRIBUTES_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        if (o != *NULL_POINTER_STATE_CYBOI_MODEL) {

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
            int e = tcsetattr(*d, TCSANOW, (struct termios*) o);

            if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal attributes. The termios settings could not be set.");

                if (errno == EBADF) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal attributes. The filedes argument is not a valid file descriptor.");

                } else if (errno == ENOTTY) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal attributes. The filedes is not associated with a terminal.");

                } else if (errno == EINVAL) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal attributes. Either the value of the second argument is not valid, or there is something wrong with the data in the third argument.");

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal attributes. An unknown error occured.");
                }
            }

            // Deallocate original attributes.
            free(o);

            // Reset original attributes.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            copy_array_forward(p1, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ORIGINAL_ATTRIBUTES_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal attributes. The original attributes is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal attributes. The file descriptor data is null.");
    }
}

/* ATTRIBUTES_UNIX_TERMINAL_SHUTTER_SOURCE */
#endif
