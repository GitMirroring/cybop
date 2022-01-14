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

#ifndef ELEMENT_SERVER_SOCKET_SHUTTER_SOURCE
#define ELEMENT_SERVER_SOCKET_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/dispatcher/closer/socket/socket_closer.c"
#include "../../../../executor/modifier/remove_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the client socket at the given index.
 *
 * @param p0 the client list data (pointer reference)
 * @param p1 the client list count
 * @param p2 the client list size
 * @param p3 the accepttime list data (pointer reference)
 * @param p4 the accepttime list count
 * @param p5 the accepttime list size
 * @param p6 the list index
 */
void shutdown_socket_server_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket server element.");

        // The client socket.
        int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // Get client socket at the given index.
        copy_array_forward((void*) &c, *d, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

        // Remove element from client list.
        modify_remove(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p6, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        // Remove element from accepttime list.
        modify_remove(p3, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p6, p4, p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        // Close client socket.
        close_socket((void*) &c);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket server element. The client list data is null.");
    }
}

/* ELEMENT_SERVER_SOCKET_SHUTTER_SOURCE */
#endif
