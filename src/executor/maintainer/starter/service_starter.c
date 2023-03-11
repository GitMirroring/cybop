/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SERVICE_STARTER_SOURCE
#define SERVICE_STARTER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/maintainer/starter/display/display_starter.c"
#include "../../../executor/maintainer/starter/socket/socket_starter.c"
#include "logger.h"

/**
 * Startup service on the given channel.
 *
 * @param p0 the server entry
 * @param p1 the port
 * @param p2 the host address data (network communication) OR filename data (local unix domain socket)
 * @param p3 the host address count (network communication) OR filename count (local unix domain socket)
 * @param p4 the family data (namespace)
 * @param p5 the family count
 * @param p6 the style data (communication type)
 * @param p7 the style count
 * @param p8 the protocol data
 * @param p9 the protocol count
 * @param p10 the connexions (number of possible pending client requests)
 * @param p11 the channel
 */
void startup_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup service.");
    //?? fwprintf(stdout, L"Debug: Startup service. p11: %i\n", p11);
    //?? fwprintf(stdout, L"Debug: Startup service. *p11: %i\n", *((int*) p11));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            startup_display(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            startup_socket(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup service. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not startup service. The channel is unknown. p11: %i\n", p11);
        fwprintf(stdout, L"Warning: Could not startup service. The channel is unknown. *p11: %i\n", *((int*) p11));
    }
}

/* SERVICE_STARTER_SOURCE */
#endif
