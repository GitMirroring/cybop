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

#ifndef SERIAL_PORT_SHUTTER_SOURCE
#define SERIAL_PORT_SHUTTER_SOURCE

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
 * Shuts down the serial port.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_serial_port(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown serial port.");

    // The serial port file descriptor.
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get serial port file descriptor.
    copy_array_forward((void*) &sp, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_DESCRIPTOR_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only deallocate serial port resources if existent.
    if (sp != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* spi = (int*) sp;

        // Interrupt serial port service thread.
        interrupt_thread(p1, p2);

        if (*spi >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // The original attributes.
            void* o = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get original attributes.
            copy_array_forward((void*) &o, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ORIGINAL_ATTRIBUTES_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

            if (o != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

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
                int e = tcsetattr(*spi, TCSANOW, (struct termios*) o);

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
                copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ORIGINAL_ATTRIBUTES_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The original attributes is null.");
            }

            // Close file descriptor.
            int e = close(*spi);

            // The normal return value from "close" is zero;
            // a value of minus one is returned in case of failure.
            if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                if (errno == EBADF) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The filedes argument is not a valid file descriptor.");

                } else if (errno == EINTR) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The close call was interrupted by a signal.");

                } else if (errno == ENOSPC) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. ENOSPC.");

                } else if (errno == EIO) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. EIO.");

                } else if (errno == EDQUOT) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. When the file is accessed by NFS, these errors from write can sometimes not be detected until close.");

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. An unknown error occured.");
                }
            }

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The serial port file descriptor is zero or negative.");
        }

        // Deallocate serial port file descriptor.
        int spc = *PRIMITIVE_STATE_CYBOI_MODEL_COUNT;
        int sps = *PRIMITIVE_STATE_CYBOI_MODEL_COUNT;
        deallocate_array((void*) &sp, (void*) &spc, (void*) &sps, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Reset serial port file descriptor.
        // CAUTION! Assign NULL to the internal memory.
        // It is ESSENTIAL, since cyboi tests for null pointers.
        // Otherwise, wild pointers would lead to memory corruption.
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FILE_DESCRIPTOR_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. There is no serial port running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* SERIAL_PORT_SHUTTER_SOURCE */
#endif
