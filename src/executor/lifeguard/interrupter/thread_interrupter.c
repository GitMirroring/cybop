/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef THREAD_INTERRUPTER_SOURCE
#define THREAD_INTERRUPTER_SOURCE

#include <signal.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../logger/logger.c"
#include "../../../variable/service_interrupt.c"
#include "../../../variable/thread_identification.c"

/**
 * Interrupts the thread.
 *
 * @param p0 the thread
 * @param p1 the thread interrupt
 */
void interrupt_thread(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        pthread_t* t = (pthread_t*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Interrupt thread.");

        // Compare thread identifications.
        //
        // Returns a non-zero value (true) if t1 and t2
        // are equal and zero if they are unequal (false).
        //
        // CAUTION! The pthread implementation under
        // mingw win32 uses a struct and NOT a scalar value.
        int r = pthread_equal(DEFAULT_THREAD, *t);

        // CAUTION! Kill thread ONLY if EXISTENT.
        if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Set thread interrupt flag for signal handler.
            copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Send signal to thread.
            //
            // CAUTION! Sending a SIGKILL signal to a thread using pthread_kill()
            // ends the ENTIRE PROCESS, not simply the target thread.
            // SIGKILL is defined to end the entire process, regardless
            // of the thread it is delivered to, or how it is sent.
            //
            // The user signal SIGUSR1 is used here instead.
            // It is processed in the interrupt_service_system_signal_handler
            // procedure, situated in the following module:
            // controller/manager/system_signal_handler_manager.c
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

            // Wait for thread to finish.
            pthread_join(*t, *NULL_POINTER_STATE_CYBOI_MODEL);

            // A mutex is not needed while setting the following parametres,
            // since the corresponding thread was killed above so that NO
            // other entities exist that may access the parametres.

            // Reset thread.
            *t = DEFAULT_THREAD;

            // Reset thread interrupt flag for signal handler.
            copy_integer(p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not interrupt thread. The service thread is invalid.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not interrupt thread. The service thread is null.");
    }
}

/* THREAD_INTERRUPTER_SOURCE */
#endif
