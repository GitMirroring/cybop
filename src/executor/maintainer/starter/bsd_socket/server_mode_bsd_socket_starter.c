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

#ifndef SERVER_MODE_BSD_SOCKET_STARTER_SOURCE
#define SERVER_MODE_BSD_SOCKET_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Starts up bsd socket in server mode.
 *
 * @param p0 the socket
 * @param p1 the socket address data
 * @param p2 the socket address size
 * @param p3 the communication style
 * @param p4 the connexions
 */
void startup_bsd_socket_mode_server(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket mode server.");

    // The error flag.
    int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Bind address to socket.
    startup_bsd_socket_bind((void*) &e, p0, p1, p2);

    if (e == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_equal((void*) &r, p3, (void*) &SOCK_STREAM);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // This is a stream socket.
            //
            // CAUTION! Datagram sockets do NOT have connexions,
            // which is why the "listen" function is ONLY called
            // for stream sockets here.

            // Listen for client requests.
            //
            // The second argument specifies the length
            // of the queue for pending connexions.
            // When the queue fills, new clients attempting to connect
            // fail with ECONNREFUSED until the server calls accept
            // to accept a connexion from the queue.
            startup_bsd_socket_listen(p0, p4);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket mode server. The address binding failed.");
    }
}

/* SERVER_MODE_BSD_SOCKET_STARTER_SOURCE */
#endif
