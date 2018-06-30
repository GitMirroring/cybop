/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ATTRIBUTES_SERIAL_PORT_SHUTTER_SOURCE
#define ATTRIBUTES_SERIAL_PORT_SHUTTER_SOURCE

#include <errno.h>
#include <stdio.h>

#if defined(__linux__) || defined(__unix__)
    #include <termios.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <termios.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    //?? No import required?
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Resets the serial port attributes.
 *
 * @param p0 the file descriptor data
 * @param p1 the internal memory data
 */
void shutdown_serial_port_attributes(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown serial port attributes.");

        // The original attributes.
        void* o = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get original attributes.
        copy_array_forward((void*) &o, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ORIGINAL_ATTRIBUTES_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        if (o != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling
            // the function that might cause an error.
            errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // The error return value.
            int e = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Reset serial port to original attributes.
            //
            // The second argument specifies how to deal with
            // input and output already queued.
            // It can be one of the following values:
            // TCSANOW - Make the change immediately.
            // TCSADRAIN - Make the change after waiting until all queued output has been written. You should usually use this option when changing parameters that affect output.
            // TCSAFLUSH - This is like TCSADRAIN, but also discards any queued input.
            // TCSASOFT - This is a flag bit that you can add to any of the above alternatives.
            //            Its meaning is to inhibit alteration of the state of the serial port hardware.
            //            It is a BSD extension; it is only supported on BSD systems and the GNU system.
            //            Using TCSASOFT is exactly the same as setting the CIGNORE bit in the c_cflag member of the structure termios-p points to.
#if defined(__linux__) || defined(__unix__)
            e = tcsetattr(*d, TCSANOW, (struct termios*) o);
#elif defined(__APPLE__) && defined(__MACH__)
            e = tcsetattr(*d, TCSANOW, (struct termios*) o);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            //?? WIN Support required?
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

            if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The termios settings could not be set.");

                if (errno == EBADF) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The filedes argument is not a valid file descriptor.");

                } else if (errno == ENOTTY) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The filedes is not associated with a serial port.");

                } else if (errno == EINVAL) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. Either the value of the second argument is not valid, or there is something wrong with the data in the third argument.");

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. An unknown error occured.");
                }
            }

            // Deallocate original attributes.
            free(o);

            // Reset original attributes.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            copy_array_forward(p1, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ORIGINAL_ATTRIBUTES_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The original attributes is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port attributes. The serial port file descriptor data is null.");
    }
}

/* ATTRIBUTES_SERIAL_PORT_SHUTTER_SOURCE */
#endif
