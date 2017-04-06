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

#ifndef ELEMENT_CLIENT_SOCKET_SHUTTER_SOURCE
#define ELEMENT_CLIENT_SOCKET_SHUTTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../../executor/maintainer/shutter/socket/close_socket_shutter.c"
#include "../../../../../executor/copier/array_copier.c"
#include "../../../../../executor/modifier/remove_modifier.c"
#include "../../../../../logger/logger.c"

/**
 * Shuts down one client.
 *
 * @param p0 the client list data (pointer reference)
 * @param p1 the client list count
 * @param p2 the client list size
 * @param p3 the client socket
 * @param p4 the client list element index
 */
void shutdown_socket_client_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket client element.");

        // The client.
        int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Get client at the given index.
        copy_array_forward((void*) &c, *d, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p4);

//??    fwprintf(stdout, L"TEST: shutdown socket client element c: %i \n", c);
//??    fwprintf(stdout, L"TEST: shutdown socket client element *p3: %i \n", *((int*) p3));

        // Compare client with client socket handed over.
        compare_integer_equal((void*) &r, (void*) &c, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The client was found in the list.

            // Remove entry from client list.
            modify_remove(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p4, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Close client socket.
            shutdown_socket_close((void*) &c);
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket client element. The client list data is null.");
    }
}

/* ELEMENT_CLIENT_SOCKET_SHUTTER_SOURCE */
#endif
