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

#ifndef STARTER_SOURCE
#define STARTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/maintainer/starter/terminal_starter.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Starts up the given service.
 *
 * CAUTION! Do NOT rename this function to "startup",
 * since it should be consistent with "shutdown_service",
 * which cannot be renamed to "shutdown",
 * as that name is already used by low-level socket functionality
 * (/usr/include/i386-linux-gnu/sys/socket.h:232:12).
 *
 * @param p0 the internal memory data
 * @param p1 the channel
 */
void startup_service(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The internal memory index.
//??    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The server socket internal.
//??    int** s = (int**) NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TERMINAL_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            startup_terminal(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            startup_x_window_system(p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) WWW_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

/*??
            // Get server socket internal.
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            get((void*) &s, p3, (void*) &i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            if (*s == *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Startup server socket if it does not already exist.
                startup_socket(p3, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) TCP_WWW_SERVICE_PORT_MODEL, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME, p2, p3, p4);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply startup. The www service is already running.");
            }
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CYBOI_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

/*??
            // Get server socket internal.
            i = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            get((void*) &s, p3, (void*) &i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            if (*s == *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Startup server socket if it does not already exist.
                startup_socket(p3, *nm, *nmc, *stm, *stmc, *am, *amc, (void*) TCP_CYBOI_SERVICE_PORT_MODEL, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME, p2, p3, p4);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply startup. The cyboi service is already running.");
            }
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup. The channel is unknown.");
    }
}

/* STARTER_SOURCE */
#endif
