/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DETAILS_SHUTTER_SOURCE
#define DETAILS_SHUTTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/maintainer/shutter/display/display_shutter.c"
#include "../../executor/maintainer/shutter/serial_port/serial_port_shutter.c"
#include "../../executor/maintainer/shutter/socket/socket_shutter.c"
#include "../../executor/maintainer/shutter/terminal/terminal_shutter.c"
#include "../../logger/logger.c"

/**
 * Shuts down the service details.
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (e.g. socket port)
 * @param p2 the socket client socket
 * @param p3 the socket mode data
 * @param p4 the socket mode count
 * @param p5 the socket network service data
 * @param p6 the socket network service count
 * @param p7 the channel
 * @param p8 the input/output entry
 */
void shutdown_details(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown details.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            shutdown_display(p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Change from p0 into p8 as soon as shutter gets adapted to new io entry.
            shutdown_serial_port(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            shutdown_socket(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            shutdown_terminal(p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown details. The channel is unknown.");
    }
}

/* DETAILS_SHUTTER_SOURCE */
#endif
