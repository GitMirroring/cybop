/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BIND_BSD_SOCKET_STARTER_SOURCE
#define BIND_BSD_SOCKET_STARTER_SOURCE

#include <sys/socket.h>
#include <errno.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Binds the address to the bsd socket.
 *
 * @param p0 the socket
 * @param p1 the address data
 * @param p2 the address size
 */
void startup_bsd_socket_bind(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket bind.");

                // Cast int to socklen_t.
                socklen_t sl = (socklen_t) *as;

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                int r = bind(*s, ad, sl);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

//??     fwprintf(stdout, L"TEST: startup bsd socket bind success r: %i \n", r);

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully startup bsd socket bind.");

                } else {

                    // An error occured.

                    if (errno == EBADF) {

    fwprintf(stdout, L"TEST: startup bsd socket bind error EBADF: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The socket argument is not a valid file descriptor.");

                    } else if (errno == ENOTSOCK) {

    fwprintf(stdout, L"TEST: startup bsd socket bind error ENOTSOCK: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The descriptor socket is not a socket.");

                    } else if (errno == EADDRNOTAVAIL) {

    fwprintf(stdout, L"TEST: startup bsd socket bind error EADDRNOTAVAIL: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The specified address is not available on this machine.");

                    } else if (errno == EADDRINUSE) {

    fwprintf(stdout, L"TEST: startup bsd socket bind error EADDRINUSE: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The specified address is already used by some other socket.");

                    } else if (errno == EINVAL) {

    fwprintf(stdout, L"TEST: startup bsd socket bind error EINVAL: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The socket socket already has an address.");

                    } else if (errno == EACCES) {

    fwprintf(stdout, L"TEST: startup bsd socket bind error EACCES: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The permission to access the requested address is missing. (In the internet domain, only the super-user is allowed to specify a port number in the range 0 through IPPORT_RESERVED minus one; see the section called 'Internet Ports'.");

                    } else {

    fwprintf(stdout, L"TEST: startup bsd socket bind error UNKNOWN: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. An unknown error occured while binding the socket to the address.");
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The address size is null.");
    }
}

/* BIND_BSD_SOCKET_STARTER_SOURCE */
#endif
