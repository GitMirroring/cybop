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

#ifndef FRAGMENT_SOCKET_SENSOR_SOURCE
#define FRAGMENT_SOCKET_SENSOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/dispatcher/closer/socket/socket_closer.c"
#include "../../../executor/sensor/socket/server_socket_sensor.c"
#include "../../../executor/streamer/reader/basic/basic_reader.c"
#include "../../../logger/logger.c"

//
// Maximum Size of Transferable Data:
//
// 1 Stream sockets:
//
// One can send (by definition) an unlimited amount of data.
// If it cannot all be buffered or sent at once or if the
// receiver cannot receive it all at once, the send will:
//
// - for blocking sockets: block or return a partial count of bytes written
// - for nonblocking sockets: return the EAGAIN error
//
// 2 Datagram sockets:
//
// - UDPv4: supports only 65536 bytes per datagram
// - UDPv6: supports much more
// - UNIX domain sockets: probably support still more
//
// https://unix.stackexchange.com/questions/38043/size-of-data-that-can-be-written-to-read-from-sockets
//

//
// CAUTION! Considering byte order conversion from/to network byte order
// is NOT necessary here, since the message data already have been
// serialised properly into single characters before.
//

/**
 * Senses a socket message fragment.
 *
 * @param p0 the destination item
 * @param p1 the source file descriptor (client socket number)
 * @param p2 the character buffer data
 * @param p3 the character buffer size
 * @param p4 the destination item mutex
 * @param p5 the exit flag
 * @param p6 the client mode (true if reading as client from server socket; false otherwise)
 */
void sense_socket_fragment(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket fragment.");
    fwprintf(stdout, L"Debug: Sense socket fragment. p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Sense socket fragment. *p1: %i\n", *((int*) p1));

    // The close flag.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Read data from socket.
    read_basic(p0, p1, p2, p3, p4, p5, (void*) &c);

    if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The close flag was set.
        //

        // Cleanup resources.
        //?? close_client(p0, p1, p2, p3, p4, p5, p6, p7, p8);

        //
        // Close the client socket on this server side,
        // since the client side has closed its connexion.
        //
        close_socket(p1);

        // Set client thread exit flag if server socket.
        sense_socket_server(p5, p6);
    }
}

/* FRAGMENT_SOCKET_SENSOR_SOURCE */
#endif
