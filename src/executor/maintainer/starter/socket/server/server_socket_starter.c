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
#include "../../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../../executor/maintainer/starter/socket/server/lifecycle_server_socket_starter.c"
#include "../../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../../executor/modifier/copier/array_copier.c"
#include "../../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Starts up server socket.
 *
 * @param p0 the internal memory data
 * @param p1 the family data (namespace)
 * @param p2 the family count
 * @param p3 the style data (communication type)
 * @param p4 the style count
 * @param p5 the protocol data
 * @param p6 the protocol count
 * @param p7 the blocking flag
 * @param p8 the filename data
 * @param p9 the filename count
 * @param p10 the host address data
 * @param p11 the host address count
 * @param p12 the port
 * @param p13 the connexions (number of possible pending client requests)
 */
void startup_socket_server(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket server.");

    // The internal memory index.
    int i = *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;

    fwprintf(stdout, L"TEST: startup socket server io index: %i \n", i);
    fwprintf(stdout, L"TEST: startup socket server port p12: %i \n", *((int*) p12));

    // Calculate internal memory index using given port.
    calculate_integer_add((void*) &i, p12);

    if (i > *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME) {

        // The given port is valid.

        // The socket io entry.
        void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"TEST: startup socket server io index with port: %i \n", i);

        // Get socket io entry.
        copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (io == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The socket.
            int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The client list item.
            void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate io entry.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            allocate_array((void*) &io, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);
            // Startup server socket.
            startup_socket_server_lifecycle((void*) &s, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
            // Allocate client list item.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            allocate_item((void*) &cl, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"TEST: startup socket server after lifecycle s: %i \n", s);
    fwprintf(stdout, L"TEST: startup socket server after lifecycle cl: %i \n", cl);

            // Store socket in io entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            set_io_entry_element((void*) &io, (void*) &s, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);
            // Store client list item in io entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            set_io_entry_element((void*) &io, (void*) &cl, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

            // Store io entry in internal memory.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the internal array's count and size are CONSTANT.
            copy_array_forward(p0, (void*) &io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket server. The socket already exists in internal memory.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket server. The internal memory base is wrong, due to an invalid port.");
    }
}

/* SERVER_SOCKET_STARTER_SOURCE */
#endif
