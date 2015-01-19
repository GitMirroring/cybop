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

#ifndef WAIT_CHECKER_SOURCE
#define WAIT_CHECKER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/checker/channels_sense_checker.c"
#include "../../controller/checker/threads_sense_checker.c"
#include "../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/modifier/copier/integer_copier.c"
#include "../../executor/runner/sleeper.c"
#include "../../logger/logger.c"

/**
 * Waits for an interrupt request.
 *
 * @param p0 the internal memory data
 * @param p1 the sleep time
 */
void check_wait(void* p0, void* p1) {

    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check wait.");

//?? fwprintf(stdout, L"TEST wait *sl: %i\n", *((int*) p1));

    // The break flag.
    // CAUTION! Using this single break flag is easier than
    // querying all possible interrupt request flags below.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Check if flags have been set within a sensing thread,
        // running in parallel to this main thread.
        check_sense_threads((void*) &b, p0);

        // Senses interrupt request at the given channels.
        check_sense_channels((void*) &b, p0);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // Sleep for some time.
            sleep_nano(p1);
        }
    }

/*??
    fwprintf(stdout, L"TEST wait *display_irq: %i\n", *((int*) di));
    fwprintf(stdout, L"TEST wait *serial_irq: %i\n", *((int*) si));
    fwprintf(stdout, L"TEST wait *socket_irq: %i\n", *((int*) soi));
    fwprintf(stdout, L"TEST wait *terminal_irq: %i\n", *((int*) ti));
*/

    // The sleep loop above is left as soon as at least one of the
    // interrupt variables is set to a value other than false (zero).
    // This may happen if some user action is noted in one of the
    // receive threads, e.g. terminal, display, socket.
    // In this case, probably a signal was placed in the signal memory and
    // the corresponding interrupt variable set to "true".
}

/* WAIT_CHECKER_SOURCE */
#endif
