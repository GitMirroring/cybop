/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STARTUP_SOURCE
#define STARTUP_SOURCE

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../logger/logger.c"

/**
 * Starts up a service.
 *
 * Expected parametres:
 * - service (required): the service to be started up (terminal, tcp_socket, unix_socket, x_window_system, ...)
 * - namespace (optional, only if service is www, cyboi or similar): the namespace of the socket
 * - style (optional, only if service is www, cyboi or similar): the namespace of the socket
 * - style (optional, only if service is www, cyboi or similar): the address of hosts communicating with this system via socket
 *
 * @param p0 the parametres array (signal/ operation part properties with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory array
 */
void apply_startup(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply startup.");

    // The service part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The communication style part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The host address part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The service part model.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The service part model data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get service part.
    get_name_array((void*) &s, p0, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get socket namespace.
        (void*) NAMESPACE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) NAMESPACE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT,
    // Get communication style.
        (void*) STYLE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) STYLE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT,
    // Get host address.
        (void*) ADDRESS_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) ADDRESS_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT,

    // Get service part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get service part model data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The internal memory index.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The server socket internal.
    int** s = (int**) NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, smd, (void*) TERMINAL_CYBOL_CHANNEL);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            startup_terminal(p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, smd, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            startup_x_window_system(p3);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, smd, (void*) WWW_CYBOL_CHANNEL);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Get server socket internal.
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            get((void*) &s, p3, (void*) &i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_CYBOI_TYPE_COUNT);

            if (*s == *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Startup server socket if it does not already exist.
                startup_socket(p3, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) TCP_WWW_SERVICE_PORT_MODEL, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME, p2, p3, p4);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up service. The www service is already running.");
            }
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, smd, (void*) CYBOI_CYBOL_CHANNEL);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Get server socket internal.
            i = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            get((void*) &s, p3, (void*) &i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_CYBOI_TYPE_COUNT);

            if (*s == *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Startup server socket if it does not already exist.
                startup_socket(p3, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) TCP_CYBOI_SERVICE_PORT_MODEL, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME, p2, p3, p4);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not start up service. The cyboi service is already running.");
            }
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply startup. The service is unknown.");
    }
}

/* STARTUP_SOURCE */
#endif
