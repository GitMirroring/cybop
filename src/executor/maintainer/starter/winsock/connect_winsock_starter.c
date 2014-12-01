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

#ifndef CONNECT_WINSOCK_STARTER_SOURCE
#define CONNECT_WINSOCK_STARTER_SOURCE

#include <winsock2.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Connects with a server via socket.
 *
 * @param p0 the socket
 * @param p1 the socket address data
 * @param p2 the socket address size
 */
void startup_winsock_connect(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        socklen_t* as = (socklen_t*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock connect.");

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling the procedure
                // that might cause an error.
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                // Make connexion with server.
                //
                // This function call WAITS until the server responds
                // to the request before it returns.
                int r = connect(*s, ad, *as);

fwprintf(stdout, L"TEST: startup winsock connect s: %i \n", *s);
sleep(2);

                if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    if (errno == EBADF) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The argument socket is not a valid file descriptor.");

                    } else if (errno == ENOTSOCK) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The argument socket is not a socket.");

                    } else if (errno == EADDRNOTAVAIL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The specified address is not available on the remote machine.");

                    } else if (errno == EAFNOSUPPORT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The namespace of the address is not supported by this socket.");

                    } else if (errno == EISCONN) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket is already connected.");

                    } else if (errno == ETIMEDOUT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The attempt to establish the connexion timed out.");

                    } else if (errno == ECONNREFUSED) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The server has actively refused to establish the connexion.");

                    } else if (errno == ENETUNREACH) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The network of the given address is not reachable from this host.");

                    } else if (errno == EADDRINUSE) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket address of the given address is already in use.");

                    } else if (errno == EINPROGRESS) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket is non-blocking and the connexion could not be established immediately. You can determine when the connexion is completely established with select; see Waiting for I/O. Another connect call on the same socket, before the connexion is completely established, will fail with EALREADY.");

                    } else if (errno == EALREADY) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket is non-blocking and already has a pending connexion in progress (see EINPROGRESS above).");

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. An unknown error occured while connecting the socket.");
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The address size is null.");
    }
}

/* CONNECT_WINSOCK_STARTER_SOURCE */
#endif
