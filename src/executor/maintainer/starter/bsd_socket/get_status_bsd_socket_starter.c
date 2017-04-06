/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GET_STATUS_BSD_SOCKET_STARTER_SOURCE
#define GET_STATUS_BSD_SOCKET_STARTER_SOURCE

#include <errno.h>
#include <fcntl.h> // fcntl function

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/maintainer/starter/bsd_socket/set_status_bsd_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Get socket status flags.
 *
 * @param p0 the socket
 * @param p1 the blocking flag
 */
void startup_bsd_socket_status_get(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket status get.");

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Get status flags.
        //
        // CAUTION! The second argument is the command,
        // in this case "F_GETFL".
        //
        // CAUTION! The return value can be interpreted
        // as the bitwise OR of the individual flags.
        //
        // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Getting-File-Status-Flags
        int f = fcntl(*s, F_GETFL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (f >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST: startup bsd socket status get success f: %i \n", f);

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket status get success.");

            startup_bsd_socket_status_set(p0, (void*) &f, p1);

        } else {

            // An error occured.

            if (errno == EBADF) {

fwprintf(stdout, L"TEST: startup bsd socket status get error EBADF: %i \n", errno);

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket status get. The filedes argument is invalid. ");

            } else {

fwprintf(stdout, L"TEST: startup bsd socket status get error UNKNOWN: %i \n", errno);

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket status get. An unknown error occured.");
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket status get. The socket is null.");
    }
}

/* GET_STATUS_BSD_SOCKET_STARTER_SOURCE */
#endif
