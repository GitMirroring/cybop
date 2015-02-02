/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SET_STATUS_BSD_SOCKET_STARTER_SOURCE
#define SET_STATUS_BSD_SOCKET_STARTER_SOURCE

#include <errno.h>
#include <fcntl.h> // fcntl function

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Set socket status flags.
 *
 * In this case, only the "nonblocking" mode is set.
 *
 * @param p0 the socket
 * @param p1 the status flags
 * @param p2 the blocking flag
 */
void startup_bsd_socket_status_set(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* s = (int*) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket status set.");

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_unequal((void*) &r, p2, FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Set BLOCKING status by clearing non-blocking flag (bit).
                (*f) &= ~O_NONBLOCK;
    fwprintf(stdout, L"TEST startup bsd socket status set blocking *f: %i\n", *f);

            } else {

                // Set NON-BLOCKING status by setting non-blocking flag (bit).
                //
                // CAUTION! If the O_NONBLOCK flag (a bit) is set,
                // read/write requests on the socket (file) can return
                // immediately with a failure status, instead of blocking,
                // in case no data are immediately available.
                (*f) |= O_NONBLOCK;
    fwprintf(stdout, L"TEST startup bsd socket status set non-blocking *f: %i\n", *f);
            }

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling
            // the function that might cause an error.
            errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            //
            // Set status flags.
            //
            // CAUTION! The second argument is the command,
            // in this case "F_SETFL".
            //
            // CAUTION! This command requires a third
            // integer argument to specify the new flags.
            //
            // CAUTION! Prior to standardization there was:
            //     ioctl(...FIONBIO...)
            //     fcntl(...O_NDELAY...)
            // But these behaved inconsistently between systems,
            // and even within the same system.
            // New programs should use the function standardised by POSIX:
            //     fcntl(...O_NONBLOCK...)
            //
            // https://stackoverflow.com/questions/1150635/unix-nonblocking-i-o-o-nonblock-vs-fionbio
            //
            int e = fcntl(*s, F_SETFL, *f);

            // The normal return value from fcntl with F_SETFL is an
            // unspecified value OTHER THAN -1, which indicates an error.
            if (e != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

    fwprintf(stdout, L"TEST: startup bsd socket status set success *f: %i \n", *f);

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket status set success.");

            } else {

                // An error occured.

                if (errno == EBADF) {

    fwprintf(stdout, L"TEST: startup bsd socket status set error EBADF: %i \n", errno);

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket status set. The filedes argument is invalid. ");

                } else {

    fwprintf(stdout, L"TEST: startup bsd socket status set error UNKNOWN: %i \n", errno);

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket status set. An unknown error occured.");
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket status set. The socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket status set. The status flags is null.");
    }
}

/* SET_STATUS_BSD_SOCKET_STARTER_SOURCE */
#endif
