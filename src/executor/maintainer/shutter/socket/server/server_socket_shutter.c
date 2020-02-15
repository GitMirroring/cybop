/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SERVER_SOCKET_SHUTTER_SOURCE
#define SERVER_SOCKET_SHUTTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../../executor/maintainer/shutter/socket/server/list_server_socket_shutter.c"
#include "../../../../../executor/maintainer/shutter/socket/close_socket_shutter.c"
#include "../../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../../executor/copier/array_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Shuts down the server socket.
 *
 * @param p0 the input/output entry
 * @param p1 the port
 */
void shutdown_socket_server(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket server.");

    // The socket.
    int s = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Get socket from io entry.
    //
    // CAUTION! Do NOT use "overwrite_array" function here,
    // since it adapts the array count and size.
    // But the array's count and size are CONSTANT.
    get_io_entry_element((void*) &s, p0, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

    //?? TODO
    // Shutdown client list.
//??    shutdown_socket_server_list(cl);

    // Close server socket.
    shutdown_socket_close((void*) &s);
}

/* SERVER_SOCKET_SHUTTER_SOURCE */
#endif
