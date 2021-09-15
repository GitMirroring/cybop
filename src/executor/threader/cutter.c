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

#ifndef CUTTER_SOURCE
#define CUTTER_SOURCE

#include <threads.h> // thrd_t, thrd_join, thrd_error

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Cuts the thread, that is wait for it to exit.
 *
 * @param p0 the thread identification
 */
void cut(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        thrd_t* t = (thrd_t*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cut.");

        // The result code.
        int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // Wait for thread to finish.
        int e = thrd_join(*t, &c);

        if (e != thrd_error) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"The thread was cut (exited) successfully.");
            fwprintf(stdout, L"Debug: The thread was cut (exited) successfully. result code: %i\n", c);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cut. The thread join function returned an error.");
            fwprintf(stdout, L"Error: Could not cut. The thread join function returned an error. result code: %i\n", c);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cut. The thread identification is null.");
    }
}

/* CUTTER_SOURCE */
#endif
