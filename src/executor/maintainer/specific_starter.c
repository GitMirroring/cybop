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

#ifndef SPECIFIC_STARTER_SOURCE
#define SPECIFIC_STARTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/maintainer/starter/display/display_starter.c"
#include "../../executor/maintainer/starter/serial_port/serial_port_starter.c"
#include "../../executor/maintainer/starter/socket/socket_starter.c"
#include "../../executor/maintainer/starter/terminal/terminal_starter.c"
#include "../../executor/maintainer/editor.c"
#include "../../logger/logger.c"

/**
 * Calls functions specific to the given service.
 *
 * @param p0 the input/output entry
 * @param p1 the serial filename data
 * @param p2 the serial filename count
 * @param p3 the serial baudrate
 * @param p4 the socket family data (namespace)
 * @param p5 the socket family count
 * @param p6 the socket style data (communication type)
 * @param p7 the socket style count
 * @param p8 the socket protocol data
 * @param p9 the socket protocol count
 * @param p10 the socket filename data
 * @param p11 the socket filename count
 * @param p12 the socket host address data
 * @param p13 the socket host address count
 * @param p14 the socket port (service identification)
 * @param p15 the socket connexions (number of possible pending client requests)
 * @param p16 the socket timeout
 * @param p17 the channel
 */
void startup_specific(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup specific.");
    fwprintf(stdout, L"Debug: Startup specific. p17: %i\n", p17);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p17, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            startup_display(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p17, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? startup_serial_port(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p17, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            startup_socket(p0, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p17, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            startup_terminal(p0);

            // Configure service.
            edit_service(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TERMINAL_CYBOI_CHANNEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup specific. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not startup specific. The channel is unknown. p17: %i\n", p17);
        fwprintf(stdout, L"Warning: Could not startup specific. The channel is unknown. *p17: %i\n", *((int*) p17));
    }
}

/* SPECIFIC_STARTER_SOURCE */
#endif
