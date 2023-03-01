/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BSD_SOCKET_INITIALISER_SOURCE
#define BSD_SOCKET_INITIALISER_SOURCE

#include <netinet/tcp.h> // SOL_TCP, TCP_NODELAY
#include <sys/socket.h> // setsockopt
#include <errno.h> // errno

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Initialises the bsd socket device.
 *
 * @param p0 the socket
 */
void initialise_bsd_socket(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p0;

        // The socket options data, size.
        void* od = (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
        socklen_t os = (socklen_t) sizeof(od);
        // The return value.
        int r = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        //
        // CAUTION! The socket is BLOCKING by default.
        // There is NO need to assign an option for this.
        //

        //
        // Initialise error number.
        //
        // It is a global variable and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Disable nagle algorithm delay.
        //
        // SOL_TCP:
        // - constant handed over to indicate tcp-level options
        //
        // TCP_NODELAY:
        // - specifies whether or not to use the nagle algorithm (delay)
        //   for deciding when to send data
        // - only supported by stream sockets (tcp)
        // - should be used for applications using the request/response paradigm
        // - a non-zero value sets the option forcing tcp to always
        //   send data immediately (disabled nagle algorithm)
        //
        // https://stackoverflow.com/questions/1525050/non-blocking-socket
        // https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_72/apis/ssocko.htm
        //
        r = setsockopt(*s, SOL_TCP, TCP_NODELAY, od, os);

        if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise bsd socket. An error occured.");
            fwprintf(stdout, L"Error: Could not initialise bsd socket. An error occured. %i\n", r);
            log_errno((void*) &errno);
        }

        //
        // Initialise error number.
        //
        // It is a global variable and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Set socket reusable after execution.
        //
        // SOL_SOCKET:
        // - constant handed over to indicate socket-level options
        //
        // SO_REUSEADDR:
        // - avoid error message "address already in use"
        // - should always be set for a tcp server before it calls "bind"
        //
        r = setsockopt(*s, SOL_SOCKET, SO_REUSEADDR, od, os);

        if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise bsd socket. An error occured.");
            fwprintf(stdout, L"Error: Could not initialise bsd socket. An error occured. %i\n", r);
            log_errno((void*) &errno);
        }

        //
        // The SO_KEEPALIVE option may be used for sending
        // "heartbeats" through a persistent connection.
        //
        // It has two end purposes:
        // - back-end application: detect an absent client,
        //   so as to drop a connection and release the associated resources
        // - client: prevent connection resources stored within intermediate nodes
        //   (such as a nat router) being released, so as to keep the connection alive
        //
        // https://holmeshe.me/network-essentials-setsockopt-SO_KEEPALIVE/
        //
        // Neither of these two is needed in cyboi,
        // which is why the SO_KEEPALIVE option is NOT set here.
        //

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise bsd socket. The socket is null.");
    }
}

/* BSD_SOCKET_INITIALISER_SOURCE */
#endif
