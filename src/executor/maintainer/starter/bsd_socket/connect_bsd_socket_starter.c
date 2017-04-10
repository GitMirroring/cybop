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

#ifndef CONNECT_BSD_SOCKET_STARTER_SOURCE
#define CONNECT_BSD_SOCKET_STARTER_SOURCE

#include <sys/socket.h>
#include <errno.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Connects a bsd socket.
 *
 * @param p0 the socket
 * @param p1 the socket address data
 * @param p2 the socket address size
 */
void startup_bsd_socket_connect(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket connect.");

                // Cast int to socklen_t.
                socklen_t sl = (socklen_t) *as;

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                // CAUTION! The "select" function was NOT used to make
                // this socket non-blocking, because it has some overhead
                // in that other sockets need to be considered and
                // their file descriptors handed over as argument.
                // If nonblocking mode is necessary, then using a thread
                // is considered to be a more simple and clean solution here.

//?? fwprintf(stdout, L"TEST: startup bsd socket connect *as: %i \n", *as);
//?? fwprintf(stdout, L"TEST: startup bsd socket connect ad: %i \n", ad);
//?? fwprintf(stdout, L"TEST: startup bsd socket connect *s: %i \n", *s);

                // Make connexion with server.
                //
                // This function call waits until the server responds
                // to the request before it returns.
                int r = connect(*s, ad, sl);

//?? fwprintf(stdout, L"TEST: startup bsd socket connect r: %i \n", r);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST: startup bsd socket connect successful r: %i \n", r);

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully startup bsd socket connect.");

                } else {

                    // An error occured.

    fwprintf(stdout, L"TEST: startup bsd socket connect error errorno: %i \n", errno);

                    if (errno == EBADF) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error EBADF: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The argument socket is not a valid file descriptor.");

                    } else if (errno == ENOTSOCK) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error ENOTSOCK: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The argument socket is not a socket.");

                    } else if (errno == EADDRNOTAVAIL) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error EADDRNOTAVAIL: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The specified address is not available on the remote machine.");

                    } else if (errno == EAFNOSUPPORT) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error EAFNOSUPPORT: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The namespace of the address is not supported by this socket.");

                    } else if (errno == EISCONN) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error EISCONN: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The socket is already connected.");

                    } else if (errno == ETIMEDOUT) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error ETIMEDOUT: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The attempt to establish the connexion timed out.");

                    } else if (errno == ECONNREFUSED) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error ECONNREFUSED: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The server has actively refused to establish the connexion.");

                    } else if (errno == ENETUNREACH) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error ENETUNREACH: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The network of the given address is not reachable from this host.");

                    } else if (errno == EADDRINUSE) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error EADDRINUSE: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The socket address of the given address is already in use.");

                    } else if (errno == EINPROGRESS) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error EINPROGRESS: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The socket is non-blocking and the connexion could not be established immediately. You can determine when the connexion is completely established with select; see Waiting for I/O. Another connect call on the same socket, before the connexion is completely established, will fail with EALREADY.");

                    } else if (errno == EALREADY) {

    fwprintf(stdout, L"TEST: startup bsd socket connect error EALREADY: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The socket is non-blocking and already has a pending connexion in progress (see EINPROGRESS above).");

                    } else {

    fwprintf(stdout, L"TEST: startup bsd socket connect error UNKNOWN: %i \n", errno);

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. An unknown error occured while connecting the socket.");
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket connect. The address size is null.");
    }
}

/* CONNECT_BSD_SOCKET_STARTER_SOURCE */
#endif
