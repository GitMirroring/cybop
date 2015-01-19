/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHANNELS_SENSE_CHECKER_SOURCE
#define CHANNELS_SENSE_CHECKER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../executor/lifeguard/sensor/display/display_sensor.c"
#include "../../executor/lifeguard/sensor/terminal/terminal_sensor.c"
#include "../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../executor/logifier/boolean/or_boolean_logifier.c"
#include "../../executor/modifier/copier/integer_copier.c"
#include "../../executor/runner/sleeper.c"
#include "../../logger/logger.c"

/**
 * Senses interrupt request at the given channels.
 *
 * This is the NEW solution avoiding threads,
 * in order to be more platform-independent.
 *
 * @param p0 the display enable flag
 * @param p1 the display interrupt request
 * @param p2 the serial port enable flag
 * @param p3 the serial port interrupt request
 * @param p4 the socket enable flag
 * @param p5 the socket interrupt request
 * @param p6 the terminal enable flag
 * @param p7 the terminal interrupt request
 * @param p8 the break flag
 * @param p9 the internal memory data
 */
void check_sense_channels(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* b = (int*) p8;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check sense channels.");

        // The results.
        int d = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        int so = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        int t = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Initialise results.
        logify_boolean_or((void*) &d, p0);
        logify_boolean_or((void*) &s, p2);
        logify_boolean_or((void*) &so, p4);
        logify_boolean_or((void*) &t, p6);

        // Test display for input.
        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Test if enabled.
            compare_integer_unequal((void*) &d, p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (d != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                sense_display(p1, p8, p9);
            }
        }

        // Test serial for input.
        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Test if enabled.
            compare_integer_unequal((void*) &s, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (s != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??                sense_serial(p3, p8, p9);
            }
        }

        // Test socket for input.
        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Test if enabled.
            compare_integer_unequal((void*) &so, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (so != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??                sense_socket(p5, p8, p9);
            }
        }

        // Test terminal for input.
        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Test if enabled.
            compare_integer_unequal((void*) &t, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (t != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                sense_terminal(p7, p8, p9);
            }
        }

        if (*b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check sense channels. The break flag is null.");
    }
}

/* CHANNELS_SENSE_CHECKER_SOURCE */
#endif
