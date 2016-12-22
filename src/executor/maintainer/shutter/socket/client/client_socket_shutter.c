/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CLIENT_SOCKET_SHUTTER_SOURCE
#define CLIENT_SOCKET_SHUTTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../../executor/maintainer/shutter/socket/client/list_client_socket_shutter.c"
#include "../../../../../executor/modifier/copier/array_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Shuts down the client socket.
 *
 * @param p0 the internal memory data (pointer reference)
 * @param p1 the port
 * @param p2 the client socket
 */
void shutdown_socket_client(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket client.");

    // The internal memory index.
    int i = *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;

    // Calculate internal memory index using given port.
    calculate_integer_add((void*) &i, p1);

//?? fwprintf(stdout, L"TEST: shutdown socket client i: %i \n", i);

    if (i > *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME) {

        // The given port is valid.

        // The socket io entry.
        void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get socket io entry.
        copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST shutdown socket client io: %i\n", io);

            // A socket service exists.

            // The client list item.
            void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get client list from io entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            get_io_entry_element((void*) &cl, (void*) &io, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

            // Search client in list.
            shutdown_socket_client_list(cl, p2);

        } else {

            // CAUTION! Do NOT log message for reasons of efficiency.
            // A socket service, for example, may exist for 65536 ports.
            // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket client. There is no socket running at the given base internal.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket client. The internal memory base is wrong, due to an invalid port.");
    }
}

/* CLIENT_SOCKET_SHUTTER_SOURCE */
#endif
