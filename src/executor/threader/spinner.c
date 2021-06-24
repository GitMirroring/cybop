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

#ifndef SPINNER_SOURCE
#define SPINNER_SOURCE

#include <threads.h> // thrd_t, thrd_equal, thrd_create

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Spins the thread, so that it is created.
 *
 * @param p0 the thread identification
 * @param p1 the thread function
 * @param p2 the thread function argument
 */
void spin(void* p0, void* p1, void* p2) {

    //
    // It is IMPORTANT that the thread and function are NOT NULL,
    // since they are handed over as parametre to "thrd_create"
    // which possibly does not check for null and might
    // exit the whole cyboi process on error.
    //

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! The type "thrd_start_t" is a pointer,
        // so that an aserisk "*" is NOT needed here.
        //
        thrd_start_t f = (thrd_start_t) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            thrd_t* t = (thrd_t*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Spin.");

            fwprintf(stdout, L"Test: Spin. empty thread t: %i\n", t);
            fwprintf(stdout, L"Test: Spin. empty thread *t: %i\n", *((int*) t));

            //
            // Compare thread identifications.
            //
            // Returns a non-zero value (true) if t1 and t2
            // are equal and zero if they are unequal (false).
            //
            // CAUTION! The threads (pthread) implementation under
            // mingw win32 uses a struct and NOT a scalar value.
            //
            int r = thrd_equal(DEFAULT_THREAD_IDENTIFICATION, *t);

            if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                //
                // The thread does NOT exist yet.
                // It is equal to the empty default thread.
                //

                //
                // The returned value is non-zero, which means
                // that both threads compared above are EQUAL.
                // Since one of the two thread variables was
                // introduced with empty initialisation,
                // this means that the other is empty, too.
                // Therefore, the thread has NOT been created
                // before and CAN be created below now.
                //

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Spin. Create thread.");

                //
                // Create thread.
                //
                // CAUTION! Do NOT allocate any resources within the thread function!
                // The reason is that this main process thread gets forked when executing
                // external programs. A "fork" duplicates ALL resources of the parent process,
                // including ALL resources of any threads running within the parent process.
                // However, since the created child process does not have those threads running,
                // their duplicated resources will never be deallocated, which eats up memory.
                // See source code file: applicator/run/run_execute.c
                //
                // Any dynamically allocated resources needed within the thread have to be:
                // - allocated at service startup
                // - added to the internal memory
                // - handed over to the thread function HERE (as internal memory)
                // - deallocated at service shutdown
                //
                thrd_create(t, f, p2);

                fwprintf(stdout, L"Test: Spin. created thread t: %i\n", t);
                fwprintf(stdout, L"Test: Spin. created thread *t: %i\n", *((int*) t));
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not spin. The thread identification is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not spin. The thread function is null.");
    }
}

/* SPINNER_SOURCE */
#endif
