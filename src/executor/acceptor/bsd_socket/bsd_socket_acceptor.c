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

#ifndef BSD_SOCKET_ACCEPTOR_SOURCE
#define BSD_SOCKET_ACCEPTOR_SOURCE

#include <sys/socket.h>
#include <errno.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Accepts data on the given bsd socket.
 *
 * @param p0 the sender client socket
 * @param p1 the receiver server socket
 */
void accept_bsd_socket(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p1;

        //
        // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
        // Otherwise, it would produce huge log files filled up with useless entries.
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept bsd socket.");

//??        fwprintf(stdout, L"TEST: Accept bsd socket *s: %i \n", *s);

        //
        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the procedure that might cause an error.
        //
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
        // Therefore, the following source code is NOT necessary:
        //     struct sockaddr_in ad;
        //     socklen_t as = sizeof(ad);
        //     *c = accept(*s, (struct sockaddr*) &ad, &as);
        //
        // CAUTION! The socket was made non-blocking at startup.
        //
        int c = accept(*s, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

//??        fwprintf(stdout, L"TEST: Accept bsd socket. client socket c: %i \n", c);

        if (c >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept bsd socket successful.");

            fwprintf(stdout, L"TEST: Accept bsd socket successful. client socket c: %i \n", c);

            copy_integer(p0, (void*) &c);

        } else {

            //
            // An error occured.
            //

            if (errno == EBADF) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept bsd socket. The socket argument is not a valid file descriptor.");

                fwprintf(stdout, L"TEST: sense bsd socket accept error EBADF: %i \n", errno);

            } else if (errno == ENOTSOCK) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept bsd socket. The descriptor socket argument is not a socket.");

                fwprintf(stdout, L"TEST: sense bsd socket accept error ENOTSOCK: %i \n", errno);

            } else if (errno == EOPNOTSUPP) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept bsd socket. The descriptor socket does not support this operation.");

                fwprintf(stdout, L"TEST: sense bsd socket accept error EOPNOTSUPP: %i \n", errno);

            } else if (errno == EWOULDBLOCK) {

                //
                // CAUTION! Do NOT log the following error!
                // The reason is that the socket is non-blocking,
                // so that the "accept" procedure returns always,
                // even if no connexion was established.
                //
                // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
                // Otherwise, it would produce huge log files filled up with useless entries.
                //
                // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept bsd socket. The socket has nonblocking mode set, and there are no pending connexions immediately available.");

//??                fwprintf(stdout, L"TEST: Accept bsd socket. error EWOULDBLOCK: %i \n", errno);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept bsd socket. An unknown error occured.");

                fwprintf(stdout, L"TEST: sense bsd socket accept error UNKNOWN: %i \n", errno);
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept bsd socket. The server socket is null.");
    }
}

/* BSD_SOCKET_ACCEPTOR_SOURCE */
#endif
