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

#ifndef LOOP_SENSOR_SOURCE
#define LOOP_SENSOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/sensor/message_sensor.c"
#include "../../../logger/logger.c"

/**
 * Senses client requests via an endless loop.
 *
 * @param p0 the destination item
 * @param p1 the source client identification
 * @param p2 the input memory data
 * @param p3 the input memory size
 * @param p4 the destination item mutex
 * @param p5 the interrupt pipe write file descriptor
 * @param p6 the interrupt mutex
 * @param p7 the server identification
 * @param p8 the language
 * @param p9 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p10 the exit flag
 * @param p11 the client mode (true if reading as client from server socket; false otherwise)
 * @param p12 the channel
 */
void sense_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense loop.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, p10, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The exit flag was set in the main thread.
            // Therefore, leave this endless loop now.
            // The child thread exits when this function returns.
            //

            break;
        }

        sense_message(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
    }
}

/* LOOP_SENSOR_SOURCE */
#endif
