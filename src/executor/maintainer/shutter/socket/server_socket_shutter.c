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

#ifndef SERVER_SOCKET_SHUTTER_SOURCE
#define SERVER_SOCKET_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../executor/maintainer/shutter/socket/close_socket_shutter.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the server socket.
 *
 * @param p0 the internal memory data (pointer reference)
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 * @param p3 the port
 */
void shutdown_socket_server(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket server.");

    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The socket.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    //?? TODO: "deserialise_socket_base" was removed; use ONE socket base instead!
    // Get internal memory base from port.
//??    deserialise_socket_base((void*) &i, p3);
//??    copy_integer(p0, (void*) SSH_BASE_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    if (i >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

/*??
        // Calculate internal memory index.
        calculate_integer_add((void*) &i, (void*) SOCKET_NUMBER_INDEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get socket.
        copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Only deallocate socket resources if a socket exists.

            // Interrupt terminal service thread.
            interrupt_thread(p1, p2);

            // Close server socket.
            shutdown_socket_close((void*) &s);

            // Deallocate socket.
            deallocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            // Reset values.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket server. There is no socket running at the given base internal.");
        }
*/

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket server. The internal memory base is zero.");
    }
}

/* SERVER_SOCKET_SHUTTER_SOURCE */
#endif
