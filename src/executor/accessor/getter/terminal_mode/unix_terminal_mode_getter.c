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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef UNIX_TERMINAL_MODE_GETTER_SOURCE
#define UNIX_TERMINAL_MODE_GETTER_SOURCE

//
// System interface
//

#include <errno.h> // errno
#include <termios.h> // struct termios, tcgetattr
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Gets the unix terminal mode from the device pointed to by the file descriptor.
 *
 * @param p0 the destination terminal mode
 * @param p1 the source file descriptor
 */
void get_terminal_mode_unix(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct termios* m = (struct termios*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get terminal mode unix.");

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

            // Get terminal mode.
            int r = tcgetattr(*f, m);

            if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get terminal mode unix. An error occured.");
                fwprintf(stdout, L"Error: Could not get terminal mode unix. An error occured. r: %i\n", r);
                log_error((void*) &errno);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get terminal mode unix. The destination terminal mode is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get terminal mode unix. The source file descriptor is null.");
    }
}

/* UNIX_TERMINAL_MODE_GETTER_SOURCE */
#endif
