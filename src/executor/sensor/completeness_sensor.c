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

#ifndef COMPLETENESS_SENSOR_SOURCE
#define COMPLETENESS_SENSOR_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
//?? #include "../../executor/sensor/display/completeness_display_sensor.c"
//?? #include "../../executor/sensor/serial/completeness_serial_sensor.c"
#include "../../executor/sensor/socket/completeness_socket_sensor.c"
//?? #include "../../executor/sensor/terminal/completeness_terminal_sensor.c"
#include "../../logger/logger.c"

/**
 * Checks if the message is complete.
 *
 * @param p0 the complete flag
 * @param p1 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p2 the message item
 * @param p3 the language (protocol)
 * @param p4 the channel
 */
void sense_completeness(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense completeness.");
    //?? fwprintf(stdout, L"Debug: Sense completeness. p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Sense completeness. *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Set complete flag.
            //
            // CAUTION! Whenever the blocking sensing function is left,
            // this means that at least one data element has been received.
            //
            // The buffer as defined in file "sensor.c" has a size of 1024,
            // so that many xcb events match in there. However, each event
            // is complete in itself and just a pointer.
            //
            // Therefore, a detection of a length prefix or end suffix
            // is NOT necessary here and the complete flag can be set right away.
            //
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Set complete flag.
            //
            // CAUTION! Whenever the blocking sensing function is left,
            // this means that at least one data element has been received.
            //
            // The buffer as defined in file "sensor.c" has a size of 1024.
            //
            //?? TODO: Activate detection of length prefix or end suffix later!
            //
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            sense_socket_completeness(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Set complete flag.
            //
            // CAUTION! Whenever the blocking sensing function is left,
            // this means that at least one data element has been received.
            //
            // The buffer as defined in file "sensor.c" has a size of 1024,
            // so that all possible ansi escape sequences match in there.
            //
            // Therefore, a detection of a length prefix or end suffix
            // is NOT necessary here and the complete flag can be set right away.
            //
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense completeness. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not sense completeness. The channel is unknown. p4: %i\n", p4);
        fwprintf(stdout, L"Warning: Could not sense completeness. The channel is unknown. *p4: %i\n", *((int*) p4));

        //?? TEST:
        fwprintf(stdout, L"Debug: Could not sense completeness. Exit for test reasons. r: %i\n", r);
        exit(-1);
    }
}

/* COMPLETENESS_SENSOR_SOURCE */
#endif
