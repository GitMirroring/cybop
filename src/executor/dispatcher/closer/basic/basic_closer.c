/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <errno.h> // errno
#include <unistd.h> // close
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Closes the file descriptor.
 *
 * CAUTION! Do NOT rename this function to "close",
 * as that name is already used by low-level glibc functionality.
 *
 * @param p0 the file descriptor, e.g. a file, serial port, terminal, socket
 */
void close_basic(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close basic.");
        //?? fwprintf(stdout, L"Debug: Close basic. f: %i\n", f);
        //?? fwprintf(stdout, L"Debug: Close basic. *f: %i\n", *((int*) f));

        //
        // Initialise error number.
        //
        // It is a global variable and other functions
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Close file descriptor.
        //
        // Closing a file descriptor has the following consequences:
        // - The file descriptor is deallocated.
        // - Any record locks owned by the process on the file are unlocked.
        // - When all file descriptors associated with a pipe or fifo
        //   have been closed, any unread data is closed.
        //
        // If there is still data waiting to be transmitted over the
        // connexion, normally close tries to complete this transmission.
        // One can control this behaviour using the SO_LINGER socket option
        // to specify a timeout period.
        //
        int r = close(*f);

        if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close basic. Success.");
            //?? fwprintf(stdout, L"Debug: Close basic. success r: %i\n", r);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close basic. An error occured.");
            fwprintf(stdout, L"Error: Could not close basic. An error occured. %i\n", r);
            log_error((void*) &errno);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close basic. The basic descriptor is null.");
        fwprintf(stdout, L"Error: Could not close basic. The basic descriptor is null. p0: %i\n", p0);
    }
}
