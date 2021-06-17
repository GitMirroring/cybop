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

//?? #include <signal.h> // SIGUSR1
#include <threads.h> // thrd_t, thrd_equal, thrd_join, thrd_error

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../logger/logger.c"
#include "../../../variable/service_interrupt.c"
#include "../../../variable/thread_identification.c"

/**
 * Cuts the thread, so that it is interrupted.
 *
 * @param p0 the thread identification
 * @param p1 the thread interrupt
 */
void cut(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        thrd_t* t = (thrd_t*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cut.");

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

        if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // The thread DOES exist.
            // It is unequal to the empty default thread.
            //

            // Set thread service interrupt flag for signal handler.
            copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            //
            // Send signal to thread.
            //
            // CAUTION! Sending a SIGKILL signal to a thread using pthread_kill()
            // ends the ENTIRE PROCESS, not simply the target thread.
            // SIGKILL is defined to end the entire process, regardless
            // of the thread it is delivered to, or how it is sent.
            //
            // The user signal SIGUSR1 is used here instead.
            // It is processed in function "interrupt_service_system_signal_handler",
            // situated in file "system_signal_handler_startup_manager.c".
            //
            // CAUTION! Several documentations suggest to replace
            // the system signal solution with an atomic exit flag being
            // frequently tested in an endless loop within the thread.
            // However, this is NOT AN OPTION for cyboi, since its
            // sensing threads are often blocking while waiting for input.
            // As a result, they cannot repeatedly test for an exit flag.
            //
#if defined(__linux__) || defined(__unix__)
            pthread_kill(*t, SIGUSR1);
#elif defined(__APPLE__) && defined(__MACH__)
            pthread_kill(*t, SIGUSR1);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            // Pthread-Win32 only supports a zero value!
            // ...
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

            // The result code.
            int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Wait for thread to finish.
            int e = thrd_join(*t, &c);

            if (e != thrd_error) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"The cut was successful. The service thread is now interrupted.");
                fwprintf(stdout, L"Debug: The cut was successful. The service thread is now interrupted. result code: %i\n", c);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cut. The service thread join function returned an error.");
                fwprintf(stdout, L"Error: Could not cut. The service thread join function returned an error. result code: %i\n", c);
            }

            //
            // A mutex is not needed while setting the following parametres,
            // since the corresponding thread was killed above so that NO
            // other entities exist that may access the parametres.
            //

            // Reset thread.
            *t = DEFAULT_THREAD;

            // Reset thread interrupt flag for signal handler.
            copy_integer(p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cut. The service thread is invalid (empty like the default thread).");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cut. The service thread is null.");
    }
}

/* CUTTER_SOURCE */
#endif
