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

#ifndef SYSTEM_SIGNAL_HANDLER_STARTUP_MANAGER_SOURCE
#define SYSTEM_SIGNAL_HANDLER_STARTUP_MANAGER_SOURCE

#include <signal.h> // SIGIO, SIGUSR1, sigset_t, struct sigaction, sigemptyset, sigaddset
#include <threads.h> // thrd_t, thrd_exit

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Reacts to an interrupt service system signal.
 *
 * Services run in a separate thread each, for:
 * - display
 * - serial port
 * - socket
 * - terminal
 *
 * This signal handler procedure is used by all threads in the process.
 *
 * @param p0 the signal numeric code
 */
void interrupt_service_system_signal_handler(int p0) {

#ifdef WIN32
#else
    // This thread itself.
    thrd_t t = thrd_current();
    // The result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
/*??
    // This thread's identification.
    pthread_id_np_t id;

    // Get this thread's identification.
    pthread_getunique_np(&t, &id);

    // Get unique thread id.
    //?? pthread_id_np_t id = pthread_getthreadid_np();
*/

    //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. thread t: %l\n", t);

    if (t == *DISPLAY_THREAD_IDENTIFICATION) {

        //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. display %l\n", t);

        if (*DISPLAY_SERVICE_INTERRUPT != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. display exit p0: %i\n", p0);

            //
            // Terminate the calling thread.
            //
            // The parametre handed over is the return value that
            // (if the thread is joinable) is available to another thread
            // in the same process that calls pthread_join(3).
            // Since this is not needed here, NULL is handed over as value.
            //
            thrd_exit(r);

            //
            // CAUTION! The thread CANNOT be reset here with:
            // *DISPLAY_THREAD_IDENTIFICATION = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // because this line would NOT be reached anymore,
            // after "pthread_exit" has been called above!
            //
            // Therefore, do the reset in the corresponding
            // "interrupt" procedure where "kill" was called!
            //
        }
    }

    if (t == *SERIAL_THREAD_IDENTIFICATION) {

        //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. serial %l\n", t);

        if (*SERIAL_SERVICE_INTERRUPT != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. serial exit p0: %i\n", p0);

            //
            // Terminate the calling thread.
            //
            // The parametre handed over is the return value
            // that (if the thread is joinable) is available
            // to another thread in the same process that calls pthread_join(3).
            // Since this is not needed here, NULL is handed over as value.
            //
            thrd_exit(r);

            //
            // CAUTION! The thread CANNOT be reset here with:
            // *SERIAL_THREAD_IDENTIFICATION = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // because this line would NOT be reached anymore,
            // after "pthread_exit" has been called above!
            //
            // Therefore, do the reset in the corresponding
            // "interrupt" procedure where "kill" was called!
            //
        }
    }

    if (t == *SOCKET_THREAD_IDENTIFICATION) {

        //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. socket %l\n", t);

        if (*SOCKET_SERVICE_INTERRUPT != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. socket exit p0: %i\n", p0);

            //
            // Terminate the calling thread.
            //
            // The parametre handed over is the return value
            // that (if the thread is joinable) is available
            // to another thread in the same process that calls pthread_join(3).
            // Since this is not needed here, NULL is handed over as value.
            //
            thrd_exit(r);

            //
            // CAUTION! The thread CANNOT be reset here with:
            // *SOCKET_THREAD_IDENTIFICATION = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // because this line would NOT be reached anymore,
            // after "pthread_exit" has been called above!
            //
            // Therefore, do the reset in the corresponding
            // "interrupt" procedure where "kill" was called!
            //
        }
    }

    if (t == *TERMINAL_THREAD_IDENTIFICATION) {

        //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. terminal %l\n", t);

        if (*TERMINAL_SERVICE_INTERRUPT != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Test: Interrupt service system signal handler. terminal exit p0: %i\n", p0);

            //
            // Terminate the calling thread.
            //
            // The parametre handed over is the return value
            // that (if the thread is joinable) is available
            // to another thread in the same process that calls pthread_join(3).
            // Since this is not needed here, NULL is handed over as value.
            //
            thrd_exit(r);

            //
            // CAUTION! The thread CANNOT be reset here with:
            // *TERMINAL_SERVICE_INTERRUPT = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // because this line would NOT be reached anymore,
            // after "pthread_exit" has been called above!
            //
            // Therefore, do the reset in the corresponding
            // "interrupt" procedure where "kill" was called!
            //
        }
    }
#endif
}

/**
 * Starts up the system signal handler.
 *
 * CAUTION! Operating system signals are NOT TO BE MIXED UP with cyboi signals!
 * The system signals are used in cyboi to notify and exit threads that
 * served for sensing input. These threads are not able to exit themselves
 * because they block while waiting for cyboi signals.
 */
void manage_startup_system_signal_handler() {

#ifdef WIN32
#else
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manage startup system signal handler.");

    // The signal set (mask).
    sigset_t mask;
    // The old signal set (mask).
    sigset_t oldmask;
    // The signal action.
    struct sigaction act;
    // The old signal action.
    struct sigaction oldact;

    //
    // Initialise signal set (mask) to exclude all of the defined signals.
    // Specify the set of signals to be blocked while the handler runs.
    //
    sigemptyset(&mask);

    //
    // All sigaddset does is to modify the signal set (mask).
    // It does not block or unblock any signals.
    //
    sigaddset(&mask, SIGIO);

    // Establish signal handler.
    act.sa_handler = interrupt_service_system_signal_handler;
    act.sa_mask = mask;
    act.sa_flags = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Establish old signal handler.
    oldact.sa_mask = oldmask;

    // Set up a new action for the SIGUSR1 signal.
    sigaction(SIGUSR1, &act, *NULL_POINTER_STATE_CYBOI_MODEL);

/*??
    // Examine or change the calling process's signal mask.
    sigprocmask(SIG_BLOCK, &mask, &oldmask);

    //
    // Wait for a signal to arrive.
    //
    // Although the program is apparently only waiting for special
    // signals, the while loop is necessary. The signal set (mask)
    // passed to sigsuspend permits the process to be woken up
    // by the delivery of other kinds of signals, as well --
    // for example, job control signals. If the process is woken up
    // by a signal that doesn't set INTERRUPT_REQUEST, it just suspends
    // itself again until the "right" kind of signal eventually arrives.
    //
    while (*INTERRUPT_REQUEST == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This function replaces the process's signal set (mask) with
        // the old set and then suspends the process until a signal is
        // delivered whose action is either to terminate the process
        // or to invoke a signal handling function. In other words,
        // the program is effectively suspended until one of the
        // signals that is NOT a member of the signal set arrives.
        // If the process is woken up by delivery of a signal that
        // invokes a handler function, and the handler function
        // returns, then sigsuspend also returns.
        //
        // The signal set (mask) remains set only as long as sigsuspend
        // is waiting. The function sigsuspend always restores the
        // previous signal mask when it returns.
        //
        sigsuspend(&oldmask);
    }

    //
    // Examine or change the calling process's signal mask.
    //
    // When sigsuspend returns, it resets the process's signal set (mask)
    // to the original value, the value from before the call to
    // sigsuspend -- in this case, the SIGIO and SIGUSR1 signals are
    // once again blocked. This call to sigprocmask is necessary to
    // explicitly unblock this signal.
    //
    sigprocmask(SIG_UNBLOCK, &mask, *NULL_POINTER_STATE_CYBOI_MODEL);
*/
#endif
}

/* SYSTEM_SIGNAL_HANDLER_STARTUP_MANAGER_SOURCE */
#endif
