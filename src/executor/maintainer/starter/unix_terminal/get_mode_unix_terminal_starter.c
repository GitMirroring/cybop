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

#ifndef GET_MODE_UNIX_TERMINAL_STARTER_SOURCE
#define GET_MODE_UNIX_TERMINAL_STARTER_SOURCE

#include <errno.h> // errno
#include <termios.h> // struct termios

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Gets the unix terminal mode.
 *
 * @param p0 the terminal mode
 * @param p1 the file descriptor
 */
void startup_unix_terminal_mode_get(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct termios* m = (struct termios*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix terminal mode get.");

            //
            // Initialise error number.
            //
            // It is a global variable / function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling
            // the function that might cause an error.
            //
            copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            //
            // Get terminal mode (attributes).
            //
            int e = tcgetattr(*f, m);

            if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                fwprintf(stdout, L"Could not startup unix terminal mode get. An error occured within tcgetattr.\n");

                if (errno == EBADF) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal mode get. The filedes argument is not a valid file descriptor.");
                    fwprintf(stdout, L"Could not startup unix terminal mode get. The filedes argument is not a valid file descriptor. EBADF errno: %i\n", errno);

                } else if (errno == ENOTTY) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal mode get. The filedes is not associated with a serial port.");
                    fwprintf(stdout, L"Could not startup unix terminal mode get. The filedes is not associated with a serial port. ENOTTY errno: %i\n", errno);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal mode get. An unknown error occured.");
                    fwprintf(stdout, L"Could not startup unix terminal mode get. An unknown error occured. UNKNOWN errno: %i\n", errno);
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal mode get. The file descriptor is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal mode get. The terminal mode is null.");
    }
}

/* GET_MODE_UNIX_TERMINAL_STARTER_SOURCE */
#endif
