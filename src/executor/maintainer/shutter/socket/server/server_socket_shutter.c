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

#ifndef SERVER_SOCKET_SHUTTER_SOURCE
#define SERVER_SOCKET_SHUTTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../../executor/maintainer/shutter/socket/server/list_server_socket_shutter.c"
#include "../../../../../executor/maintainer/shutter/socket/close_socket_shutter.c"
#include "../../../../../logger/logger.c"

/**
 * Shuts down the server socket.
 *
 * @param p0 the input/output entry
 */
void shutdown_socket_server(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket server.");

    // The socket.
    int s = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The client list item.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The accepttime list item.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get socket from input/output entry.
    get_io_entry_element((void*) &s, p0, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get client list item from input/output entry.
    get_io_entry_element((void*) &c, p0, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get accepttime list item from input/output entry.
    get_io_entry_element((void*) &a, p0, (void*) ACCEPTTIME_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Shutdown client list.
    shutdown_socket_server_list(c, a);

    // Close server socket.
    shutdown_socket_close((void*) &s);
}

/* SERVER_SOCKET_SHUTTER_SOURCE */
#endif
