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

#ifndef SPECIFIC_SHUTTER_SOURCE
#define SPECIFIC_SHUTTER_SOURCE

#include "../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/maintainer/shutter/display/display_shutter.c"
#include "../../../executor/maintainer/shutter/serial_port/serial_port_shutter.c"
#include "../../../executor/maintainer/shutter/socket/socket_shutter.c"
#include "../../../executor/maintainer/shutter/terminal/terminal_shutter.c"
#include "../../../logger/logger.c"

/**
 * Calls functions specific to the given service.
 *
 * @param p0 the input/output entry
 * @param p1 the channel
 */
void shutdown_specific(void* p0, void* p1) {

    //
    // CAUTION! Do NOT log messages here, since this function is called 65,536 times
    // for socket channels in a loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown specific.");
    //?? fwprintf(stdout, L"Debug: Shutdown specific. p1: %i\n", p1);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            shutdown_display(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? shutdown_serial_port(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            shutdown_socket(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            shutdown_terminal(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown specific. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not shutdown specific. The channel is unknown. p1: %i\n", p1);
        fwprintf(stdout, L"Warning: Could not shutdown specific. The channel is unknown. *p1: %i\n", *((int*) p1));
    }
}

/* SPECIFIC_SHUTTER_SOURCE */
#endif
