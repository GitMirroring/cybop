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

#ifndef ACCEPT_BSD_SOCKET_SENSOR_SOURCE
#define ACCEPT_BSD_SOCKET_SENSOR_SOURCE

#include <sys/socket.h>
#include <errno.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Accepts data on the given bsd socket.
 *
 * @param p0 the interrupt request
 * @param p1 the sender client socket
 * @param p2 the server socket
 */
void sense_bsd_socket_accept(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* c = (int*) p1;

            // CAUTION! DO NOT log this function call!
            // The function runs in an endless loop
            // that would produce huge log files.
            // log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense bsd socket accept.");

    fwprintf(stdout, L"TEST: sense bsd socket accept *s: %i \n", *((int*) p2));

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling
            // the procedure that might cause an error.
            errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            //
            // Accept request and store client socket.
            //
            // Accepting a connexion does NOT make the original server socket
            // part of the connexion. Instead, it creates a new client socket
            // which becomes connected. The normal return value of
            // "accept" is the file descriptor for the new client socket.
            //
            // After "accept", the original server socket remains open and
            // unconnected, and continues listening until it gets closed.
            // One can accept further connexions with the original
            // server socket by calling "accept" again.
            //
            // CAUTION! If addr (second argument) and/or addrlen (third argument)
            // are equal to NULL, then no information about the remote address
            // of the accepted client socket is returned.
            //
            // CAUTION! The socket was made non-blocking at startup.
            //
            *c = accept(*s, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

            if (*c >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense bsd socket accept successful.");

    fwprintf(stdout, L"TEST: sense bsd socket accept c: %i \n", *c);

                // Set interrupt request.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            } else {

                // An error occured.

    fwprintf(stdout, L"TEST: sense bsd socket accept error: %i \n", *c);

                if (errno == EBADF) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense bsd socket accept. The socket argument is not a valid file descriptor.");

                } else if (errno == ENOTSOCK) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense bsd socket accept. The descriptor socket argument is not a socket.");

                } else if (errno == EOPNOTSUPP) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense bsd socket accept. The descriptor socket does not support this operation.");

                } else if (errno == EWOULDBLOCK) {

    fwprintf(stdout, L"TEST: sense bsd socket accept error EWOULDBLOCK: %i \n", *c);

                    // CAUTION! Do NOT log the following error!
                    // The reason is that the socket is non-blocking,
                    // so that the "accept" procedure returns always,
                    // even if no connexion was established,
                    // which would unnecessarily fill up the log file.
                    // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense bsd socket accept. The socket has nonblocking mode set, and there are no pending connexions immediately available.");

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense bsd socket accept. An unknown error occured.");
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense bsd socket accept. The sender client socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense bsd socket accept. The server socket is null.");
    }
}

/* ACCEPT_BSD_SOCKET_SENSOR_SOURCE */
#endif
