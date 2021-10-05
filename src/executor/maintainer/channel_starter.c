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

#ifndef CHANNEL_STARTER_SOURCE
#define CHANNEL_STARTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../executor/acceptor/socket/socket_acceptor.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/copier/pointer_copier.c"
#include "../../executor/sensor/serial_port/serial_port_sensor.c"
//?? #include "../../executor/sensor/socket/socket_sensor.c"
#include "../../executor/sensor/unix_terminal/unix_terminal_sensor.c"
#include "../../executor/sensor/xcb/xcb_sensor.c"
#include "../../logger/logger.c"

/**
 * Determines values specific to the given service.
 *
 * @param p0 the input/output base
 * @param p1 the thread function (pointer reference)
 * @param p2 the channel
 */
void startup_channel(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup channel.");
    fwprintf(stdout, L"Debug: Startup channel. p2: %i\n", p2);

    //
    // CAUTION! The function pointer to the thread function can be
    // determined in TWO WAYS, with or without address operator.
    // Both are resulting in the SAME pointer (address).
    //
    // Example:
    // void* f = (void*) sense_unix_terminal;
    // void* f = (void*) &sense_unix_terminal;
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            void* f = (void*) &sense_xcb;

            copy_integer(p0, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_pointer(p1, (void*) &f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            void* f = (void*) &sense_serial_port;

            copy_integer(p0, (void*) SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_pointer(p1, (void*) &f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? void* f = (void*) &sense_socket;
            void* f = (void*) &accept_socket;

            copy_integer(p0, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_pointer(p1, (void*) &f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            void* f = (void*) &sense_unix_terminal;

            copy_integer(p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_pointer(p1, (void*) &f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup channel. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not startup channel. The channel is unknown. p2: %i\n", p2);
        fwprintf(stdout, L"Warning: Could not startup channel. The channel is unknown. *p2: %i\n", *((int*) p2));
    }
}

/* CHANNEL_STARTER_SOURCE */
#endif
