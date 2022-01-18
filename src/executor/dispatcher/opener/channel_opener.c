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

#ifndef CHANNEL_OPENER_SOURCE
#define CHANNEL_OPENER_SOURCE

#include "../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/activator/enabler/socket/socket_enabler.c"
#include "../../../executor/dispatcher/opener/locking_opener.c"
#include "../../../executor/sensor/sensor.c"
#include "../../../logger/logger.c"

/**
 * Opens up a client via the given channel.
 *
 * @param p0 the destination client list item
 * @param p1 the client list mutex
 * @param p2 the interrupt pipe (pointer reference)
 * @param p3 the interrupt mutex (pointer reference)
 * @param p4 the input/output identification (pointer reference, input/output base + socket port)
 * @param p5 the language (pointer reference, protocol)
 * @param p6 the channel (pointer reference)
 * @param p7 the serial port file descriptor (pointer reference)
 * @param p8 the terminal file descriptor (pointer reference)
 * @param p9 the xcb connexion (pointer reference)
 * @param p10 the server socket file descriptor
 * @param p11 the exit flag
 * @param p12 the channel
 */
void open_channel(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open channel.");
    fwprintf(stdout, L"Debug: Open channel. p12: %i\n", p12);
    fwprintf(stdout, L"Debug: Open channel. *p12: %i\n", *((int*) p12));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Hand over ZERO as client identification, since there is just one client.
            open_locking(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p11, p12);

            // CAUTION! Set exit flag, since only ONE client gets started.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Hand over ZERO as client identification, since there is just one client.
            open_locking(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p11, p12);

            // CAUTION! Set exit flag, since only ONE client gets started.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            //?? TODO: Initialise with zero like the other channels or with minus one ?
            //

            // The client socket.
            int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            //?? int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

            // Accepts client on server socket.
            enable_socket((void*) &c, p10);
            fwprintf(stdout, L"Debug: Open channel. client socket c: %i\n", c);

            // CAUTION! Hand over accepted client socket as client identification.
            open_locking(p0, (void*) &c, p1, p2, p3, p4, p5, p6, p7, p8, p9, p11, p12);

            //
            // CAUTION! Do NOT set exit flag here,
            // since MANY clients may get started in the loop
            // that this function was called from.
            //
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p12, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Hand over ZERO as client identification, since there is just one client.
            open_locking(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p11, p12);

            // CAUTION! Set exit flag, since only ONE client gets started.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open channel. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not open channel. The channel is unknown. Channel p12: %i\n", *((int*) p12));
    }
}

/* CHANNEL_OPENER_SOURCE */
#endif
