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

#ifndef SOCKET_READER_SOURCE
#define SOCKET_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/streamer/reader/socket/client_socket_reader.c"
#include "../../../../executor/streamer/reader/socket/server_socket_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads from either client- or server socket, depending on the given mode.
 *
 * @param p0 the destination item
 * @param p1 the source socket number (server or client)
 * @param p2 the internal memory data
 * @param p3 the socket port
 * @param p4 the client mode (true if reading as client from server socket; false otherwise)
 */
void read_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read socket.");
    fwprintf(stdout, L"Debug: Read socket. p2: %i\n", p2);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The reading is done in SERVER mode.
        // That is, this system reads as server from one of its (remote) client sockets.
        //

        read_socket_server(p0, p1, p2, p3);

    } else {

        //
        // The reading is done in CLIENT mode.
        // That is, this system reads as client from some (remote) server socket.
        //

        read_socket_client(p0, p1);
    }
}

/* SOCKET_READER_SOURCE */
#endif
