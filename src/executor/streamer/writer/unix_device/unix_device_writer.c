/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <sys/ioctl.h> // ioctl
#include <errno.h> // errno
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Sends a command to the unix device given by the file descriptor.
 *
 * @param p0 the destination device file descriptor
 * @param p1 the source command (device-dependent request code)
 * @param p2 the argument (either a single number or a pointer to a structure, depending upon the command used)
 */
void write_unix_device(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* c = (int*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* d = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write unix device.");
                fwprintf(stdout, L"Debug: Write unix device. d: %i\n", d);
                fwprintf(stdout, L"Debug: Write unix device. *d: %i\n", *d);
                fwprintf(stdout, L"Debug: Write unix device. c: %i\n", c);
                fwprintf(stdout, L"Debug: Write unix device. *c: %i\n", *c);

                //
                // Initialise error number.
                //
                // It is a global variable and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                //
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

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
                // Alternative function:
                // Some sources recommend to replace "ioctl" with "fcntl":
                // https://stackoverflow.com/questions/1150635/unix-nonblocking-i-o-o-nonblock-vs-fionbio
                // However, the glibc documentation only mentions the following possibilities of "fcntl":
                // - duplicating file descriptors
                // - manipulating flags
                // - implementing locking
                // - asynchronous signal for interrupt input via SIGIO signals
                // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Control-Operations
                // Generic i/o control operations, on the other hand, are offered via "ioctl":
                // - changing the character font used on a terminal
                // - telling a magnetic tape system to rewind or fast forward
                // - ejecting a disk from a drive
                // - playing an audio track from a CD-ROM drive
                // - maintaining routing tables for a network
                // https://www.gnu.org/software/libc/manual/html_mono/libc.html#IOCTLs
                // However, most ioctl operations are operating system-specific and not part of glibc.
                //
                int r = ioctl(*d, *c, p2);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    fwprintf(stdout, L"Debug: Write unix device. success r: %i\n", r);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write unix device. An error occured.");
                    fwprintf(stdout, L"Error: Could not write unix device. An error occured. %i\n", r);
                    log_error((void*) &errno);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write unix device. The destination device file descriptor is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write unix device. The source command is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write unix device. The argument is null.");
    }
}
