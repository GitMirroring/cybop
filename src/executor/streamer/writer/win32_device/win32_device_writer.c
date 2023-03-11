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

#ifndef WIN32_DEVICE_WRITER_SOURCE
#define WIN32_DEVICE_WRITER_SOURCE

//?? #include <sys/ioctl.h>
#include <errno.h>

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/copier/integer_copier.c"
#include "logger.h"

/**
 * Sends a command to the win32 device given by the file descriptor.
 *
 * @param p0 the destination data
 * @param p1 the source device file descriptor (e.g. filename, socket number)
 * @param p2 the command (device-dependent request code)
 */
void write_win32_device(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* c = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* f = (int*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write win32 device.");

                //
                // The data to be returned.
                //
                // Their meaning depends upon the command used.
                // - in Linux: untyped pointer to memory
                //
                int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                fwprintf(stdout, L"Debug: Write win32 device. Command *c: %i\n", *c);
                fwprintf(stdout, L"Debug: Write win32 device. File descriptor *f: %i\n", *f);
                fwprintf(stdout, L"Debug: Write win32 device. errno: %i\n", errno);

                //
                // Perform a generic input/output operation on
                // the device determined by the file descriptor.
                //
                // First argument: the already open file descriptor
                //
                // Second argument: the command (device-dependent request code)
                //
                // Third argument: meaning depends upon the command used
                // - in Linux: untyped pointer to memory
                //
                // Returned value: meaning depends upon the command used
                // - in Linux: usually, on success zero is returned;
                //   sometimes also used as an output parameter;
                //   non-negative value on success;
                //   on error, -1 is returned, and errno is set appropriately
                //
                // Error codes: meaning depends upon the command used
                //
                //?? int r = ioctl(*f, *c, (void*) &d);

                fwprintf(stdout, L"Debug: Write win32 device. ioctl r: %i\n", r);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully write win32 device.");
                    fwprintf(stdout, L"Debug: Write win32 device. success r: %i\n", r);

                    // Copy destination data.
                    copy_integer(p0, (void*) &d);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open basic. An error occured.");
                    fwprintf(stdout, L"Error: Could not open basic. An error occured. %i\n", r);
                    log_error((void*) &errno);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write win32 device. The destination data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write win32 device. The source device file descriptor is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write win32 device. The command is null.");
    }
}

/* WIN32_DEVICE_WRITER_SOURCE */
#endif
