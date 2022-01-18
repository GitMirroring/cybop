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

#ifndef BSD_SOCKET_OPENER_SOURCE
#define BSD_SOCKET_OPENER_SOURCE

#include <sys/socket.h>
#include <errno.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Connects with a server via bsd socket.
 *
 * @param p0 the socket
 * @param p1 the socket address data
 * @param p2 the socket address size
 */
void open_bsd_socket(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open bsd socket.");

                // Cast int to socklen_t.
                socklen_t sl = (socklen_t) *as;

                //
                // Initialise error number.
                //
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                //
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                //
                // CAUTION! The "select" function was NOT used to make
                // this socket non-blocking, because it has some overhead
                // in that other sockets need to be considered and
                // their file descriptors handed over as argument.
                // If nonblocking mode is necessary, then using a worker thread
                // is considered to be a more simple and clean solution here.
                //

                //?? fwprintf(stdout, L"Debug: Open bsd socket. *as: %i\n", *as);
                //?? fwprintf(stdout, L"Debug: Open bsd socket. ad: %i\n", ad);
                //?? fwprintf(stdout, L"Debug: Open bsd socket. *s: %i\n", *s);

                //
                // Make connexion with server.
                //
                // This function call waits until the server responds
                // to the request before it returns.
                //
                int r = connect(*s, ad, sl);

                //?? fwprintf(stdout, L"Debug: Open bsd socket. r: %i\n", r);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open bsd socket. success");
                    //?? fwprintf(stdout, L"Debug: Open bsd socket. success r: %i\n", r);

                } else {

                    //
                    // An error occured.
                    //

                    if (errno == EBADF) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The argument socket is not a valid file descriptor.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error EBADF: %i\n", errno);

                    } else if (errno == ENOTSOCK) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The argument socket is not a socket.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error ENOTSOCK: %i\n", errno);

                    } else if (errno == EADDRNOTAVAIL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The specified address is not available on the remote machine.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error EADDRNOTAVAIL: %i\n", errno);

                    } else if (errno == EAFNOSUPPORT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The namespace of the address is not supported by this socket.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error EAFNOSUPPORT: %i\n", errno);

                    } else if (errno == EISCONN) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The socket is already connected.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error EISCONN: %i\n", errno);

                    } else if (errno == ETIMEDOUT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The attempt to establish the connexion timed out.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error ETIMEDOUT: %i\n", errno);

                    } else if (errno == ECONNREFUSED) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The server has actively refused to establish the connexion.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error ECONNREFUSED: %i\n", errno);

                    } else if (errno == ENETUNREACH) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The network of the given address is not reachable from this host.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error ENETUNREACH: %i\n", errno);

                    } else if (errno == EADDRINUSE) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The socket address of the given address is already in use.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error EADDRINUSE: %i\n", errno);

                    } else if (errno == EINPROGRESS) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The socket is non-blocking and the connexion could not be established immediately. You can determine when the connexion is completely established with select; see Waiting for I/O. Another connect call on the same socket, before the connexion is completely established, will fail with EALREADY.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error EINPROGRESS: %i\n", errno);

                    } else if (errno == EALREADY) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The socket is non-blocking and already has a pending connexion in progress (see EINPROGRESS above).");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error EALREADY: %i\n", errno);

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. An unknown error occured while connecting the socket.");
                        fwprintf(stdout, L"Debug: Could not open bsd socket. error UNKNOWN: %i\n", errno);
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The address size is null.");
    }
}

/* BSD_SOCKET_OPENER_SOURCE */
#endif
