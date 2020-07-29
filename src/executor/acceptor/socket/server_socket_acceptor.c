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

#ifndef SERVER_SOCKET_ACCEPTOR_SOURCE
#define SERVER_SOCKET_ACCEPTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../executor/acceptor/socket/socket_acceptor.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../logger/logger.c"

/**
 * Accepts a new client request waiting on the server socket.
 *
 * @param p0 the sender client socket
 * @param p1 the input/output entry
 */
void accept_socket_server(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept socket.");

    // The receiver server socket.
    int s = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Get receiver server socket from io entry.
    get_io_entry_element((void*) &s, p1, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Sense new client requests on server socket.
    accept_socket(p0, (void*) &s);
}

/* SERVER_SOCKET_ACCEPTOR_SOURCE */
#endif
