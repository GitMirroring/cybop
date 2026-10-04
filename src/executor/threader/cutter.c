/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <threads.h> // thrd_t, thrd_equal, thrd_join, thrd_error
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"
#include "variable.h"

/**
 * Cuts the thread, that is wait for it to exit.
 *
 * @param p0 the thread identification
 */
void cut(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        thrd_t* t = (thrd_t*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cut.");
        //?? fwprintf(stdout, L"Debug: Cut. thread t: %i\n", t);
        //?? fwprintf(stdout, L"Debug: Cut. thread *t: %i\n", *t);

        //
        // Compare thread identifications.
        //
        // Returns a non-zero value (true) if they are equal
        // and ZERO if they are UNEQUAL (false).
        //
        // CAUTION! The threads (pthread) implementation under
        // mingw win32 uses a struct and NOT a scalar value.
        //
        int r = thrd_equal(DEFAULT_THREAD_IDENTIFICATION, *t);

        if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // The thread DOES exist.
            //
            // The given thread is unequal to the DEFAULT thread,
            // with which it was assigned at startup,
            // which means that it WAS created and EXISTS.
            // Therefore, the thread CAN be exited now.
            //
            // However, the exit is done via an awakener,
            // so that the thread can exit itself.
            // This function here just waits for the thread to exit.
            //

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cut. Join thread.");
            //?? fwprintf(stdout, L"Debug: Cut. Join thread. t: %i\n", t);
            //?? fwprintf(stdout, L"Debug: Cut. Join thread. +t: %i\n", *t);

            // The result code.
            int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Wait for thread to finish.
            int e = thrd_join(*t, &c);

            if (e != thrd_error) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cut (exit) thread successfully. The thread join function returned zero.");
                //?? fwprintf(stdout, L"Debug: Cut (exit) thread successfully. The thread join function returned zero. result code: %i\n", c);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cut. The thread join function returned an error.");
                fwprintf(stdout, L"Error: Could not cut. The thread join function returned an error. c: %i\n", c);
            }

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cut. The thread identification is invalid. This is unproblematic, since synchronous communication does not use threads.");
            // fwprintf(stdout, L"Warning: Could not cut. The thread identification is invalid. This is unproblematic, since synchronous communication does not use threads. *t: %i\n", *t);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cut. The thread identification is null.");
        fwprintf(stdout, L"Error: Could not cut. The thread identification is null. p0: %i\n", p0);
    }
}
