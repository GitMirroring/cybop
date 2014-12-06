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

#ifndef SERVER_SOCKET_STARTER_SOURCE
#define SERVER_SOCKET_STARTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../../executor/maintainer/starter/socket/server/base_server_socket_starter.c"
#include "../../../../../executor/maintainer/starter/socket/server/lifecycle_server_socket_starter.c"
#include "../../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../../executor/modifier/copier/array_copier.c"
#include "../../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Starts up server socket.
 *
 * @param p0 the internal memory data (pointer reference)
 * @param p1 the family data (namespace)
 * @param p2 the family count
 * @param p3 the style data (communication type)
 * @param p4 the style count
 * @param p5 the protocol data
 * @param p6 the protocol count
 * @param p7 the filename data
 * @param p8 the filename count
 * @param p9 the host address data
 * @param p10 the host address count
 * @param p11 the port
 * @param p12 the connexions (number of possible pending client requests)
 */
void startup_socket_server(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket server.");

    // The internal memory base.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The socket.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get internal memory base from port.
    startup_socket_server_base((void*) &b, p11);
    // Calculate internal memory index.
    copy_integer((void*) &i, p13);
    calculate_integer_add((void*) &i, (void*) SOCKET_NUMBER_INDEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get socket.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    if (s == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Only create socket if not existent.

        // Allocate socket.
        allocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Startup server socket.
        startup_socket_server_lifecycle((void*) &s, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);

        // Store socket in internal memory.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the internal array's count and size are CONSTANT.
        copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket server existing. The socket already exists in internal memory.");
    }
}

/* SERVER_SOCKET_STARTER_SOURCE */
#endif
