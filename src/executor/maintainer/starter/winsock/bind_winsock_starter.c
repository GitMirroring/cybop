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

#ifndef BIND_WINSOCK_STARTER_SOURCE
#define BIND_WINSOCK_STARTER_SOURCE

#include <winsock2.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Binds the address to the socket.
 *
 * @param p0 the error flag
 * @param p1 the socket
 * @param p2 the address data
 * @param p3 the address size
 */
void startup_winsock_bind(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        socklen_t* as = (socklen_t*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p1;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock bind.");

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling the procedure
                // that might cause an error.
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                int r = bind(*s, ad, *as);

fwprintf(stdout, L"TEST: startup winsock bind s: %i \n", *s);
sleep(2);

                if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // Set error flag.
                    // CAUTION! Only set flag if an error occured.
                    // CAUTION! Do NOT assign the returned error number,
                    // since it is different from the FALSE constant used below.
                    copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                    if (errno == EBADF) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The socket argument is not a valid file descriptor.");

                    } else if (errno == ENOTSOCK) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The descriptor socket is not a socket.");

                    } else if (errno == EADDRNOTAVAIL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The specified address is not available on this machine.");

                    } else if (errno == EADDRINUSE) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The specified address is already used by some other socket.");

                    } else if (errno == EINVAL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The socket socket already has an address.");

                    } else if (errno == EACCES) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The permission to access the requested address is missing. (In the internet domain, only the super-user is allowed to specify a port number in the range 0 through IPPORT_RESERVED minus one; see the section called 'Internet Ports'.");

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. An unknown error occured while binding the socket to the address.");
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The address size is null.");
    }
}

/* BIND_WINSOCK_STARTER_SOURCE */
#endif
