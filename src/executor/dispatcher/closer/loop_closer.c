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

#ifndef LOOP_CLOSER_SOURCE
#define LOOP_CLOSER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../executor/closer/channel_closer.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../logger/logger.c"

/**
 * Closes all clients using a loop.
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
 */
void close_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close loop.");

    // The client socket.
    int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The sense function.
    void* f = (void*) &sense_socket;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, ex, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The exit flag was set in the main thread.
            // Therefore, leave this endless loop now.
            // The child thread exits when this function returns.
            //

            break;
        }

        close_channel(p0, (void*) &c, p1, p2, p3, p4, p5, p6, p7, p8);
    }
}

/* LOOP_CLOSER_SOURCE */
#endif
