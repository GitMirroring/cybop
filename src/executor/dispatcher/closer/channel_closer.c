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

#ifndef CHANNEL_CLOSER_SOURCE
#define CHANNEL_CLOSER_SOURCE

#include "../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/dispatcher/closer/socket/socket_closer.c"
#include "../../../executor/dispatcher/closer/client_closer.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../logger/logger.c"

/**
 * Closes client of the given channel.
 *
 * @param p0 the destination client list item
 * @param p1 the client list mutex
 * @param p2 the interrupt pipe (pointer reference)
 * @param p3 the interrupt mutex (pointer reference)
 * @param p4 the input/output identification (pointer reference, input/output base + socket port)
 * @param p5 the language (pointer reference, protocol)
 * @param p6 the channel (pointer reference)
 * @param p7 the sense function (pointer reference)
 * @param p8 the exit flag
 * @param p9 the channel
 */
void close_channel(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close channel.");
    fwprintf(stdout, L"Debug: Close channel. p9: %i\n", p9);
    fwprintf(stdout, L"Debug: Close channel. *p9: %i\n", *((int*) p9));

    //
    // CAUTION! Hand over ZERO as client identification
    // (second parametre) for all channels but the socket.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            close_locking(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            close_locking(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Free socket resources.
            //?? close_locking(p0, px ??, p1, p2, p3, p4, p5, p6, p7, p8);

            // Close socket.
            //?? close_socket((void*) &c, p1);
            //?? fwprintf(stdout, L"Debug: Close channel. client socket c: %i\n", c);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            close_locking(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close channel. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not close channel. The channel is unknown. Channel p9: %i\n", *((int*) p9));
    }
}

/* CHANNEL_CLOSER_SOURCE */
#endif
