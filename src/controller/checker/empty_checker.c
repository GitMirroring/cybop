/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EMPTY_CHECKER_SOURCE
#define EMPTY_CHECKER_SOURCE

#include <pthread.h>
#include <signal.h>

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/checker/interrupt_checker.c"
#include "../../controller/checker/wait_checker.c"
#include "../../controller/handler.c"
#include "../../logger/logger.c"

/**
 * Handles the situation that no signal is available in the signal memory
 * and queries interrupts instead.
 *
 * @param p0 the internal memory data
 * @param p1 the knowledge memory part
 * @param p2 the signal memory item
 * @param p3 the signal memory sleep time
 * @param p4 the shutdown flag
 */
void check_empty(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check empty.");

    // The interrupt.
    // CAUTION! It CANNOT be handed over as parametre, since it
    // is not always only the signal memory interrupt request.
    // Other input channels' interrupts may be assigned as well below.
    volatile sig_atomic_t* irq = (volatile sig_atomic_t*) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    // CAUTION! It CANNOT be handed over as parametre (like the interrupt).
    pthread_mutex_t* mt = (pthread_mutex_t*) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal part representing the interrupt request handler.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The direct execution flag.
    int x = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

//?? fwprintf(stdout, L"TEST check empty: %i\n", irq);

    // The signal memory is empty, so that the cyboi system
    // may check for new interrupt requests now.
    //
    // CAUTION! This code section also covers the situation
    // when a new signal has been placed in signal memory
    // just after it was checked to be empty.
    // In such a case, the signal memory flag was set
    // so that the new signal may be recognised here
    // and does not get forgotten.

    // Check interrupt requests and get the appropriate:
    // - interrupt request (to be reset below)
    // - mutex (to be blocked while resetting the interrupt request below)
    // - handler (the signal to be forwarded to the "handle" function below)
    check_interrupt((void*) &irq, (void*) &mt, (void*) &s, p0);

    // CAUTION! These conditions HAVE TO BE connected by a boolean AND operator,
    // because otherwise, the "else" branch below would not always be reached.
    if ((irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) irq) != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

        // Handle signal.
        //
        // CAUTION! The "handle" function has to be called DIRECTLY
        // (with direct execution flag set) here!
        // For reasons, see the comment block above!
        handle(s, p0, p1, p2, (void*) &x, p4);

        // Lock mutex.
        pthread_mutex_lock(mt);

        // Reset interrupt.
        //
        // CAUTION! Do FIRST handle the signal and
        // ONLY AFTERWARDS reset the interrupt!
        //
        // There is NO reason to hurry to sense data on
        // the same channel the interrupt belongs to.
        // The interrupt's purpose of waking up the
        // signal checker has been fulfilled and signals are
        // being read from the signal memory (queue) right now.
        //
        // If resetting the interrupt too early, the old
        // (already sensed) data are still available on the channel
        // and the interrupt would be set right again.
        // But this double or triple etc. detection of data
        // might lead to cases in which cyboi tries to
        // receive data it MEANWHILE already received.
        // This would lead to empty data which complicates
        // CYBOL programming, because cybol developers then would
        // have to consider empty input using a flag, if-else etc.
        // But if data were sensed (detected), it should be
        // possible for cybol developers to rely on their availability.
        //
        // This effect is caused by the main thread
        // and sensing threads running in parallel.
        // It is comparable to something like a "race".
        //
        // Following an example of what would happen
        // when (falsely) resetting the interrupt first
        // and only then handle and process the signal:
        // - sensing thread detects data input on terminal, sets irq
        // - main thread wakes up, resets irq
        // - main thread receives data from terminal
        // - sensing thread MEANWHILE (IN PARALLEL) detects the same data again on terminal, sets irq
        // - main thread tries to receive data (because irq is set), but finds nothing
        // - main thread provides empty data (null data pointer and zero count) to next cybol operation
        //
        // CAUTION! Do NOT try to reset the irq in the corresponding
        // "receive" functions of the several channels.
        // Spreading the reset code over many functions is bad
        // and leads to redundant logic.
        // Further, it is not always clear where to reset
        // the irq, e.g. after having read all characters
        // or just one? But ansi escape sequences consist
        // of many characters that may or may not belong together ...
        // Therefore, LEAVE the code for resetting irq HERE.
        //
        // CAUTION! Avoid using the "copy_integer" function,
        // since the irq is atomic and casting it to int
        // might possibly falsify its behaviour.
        *irq = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Unlock mutex.
        pthread_mutex_unlock(mt);

        // CAUTION! An interrupt request was detected and the corresponding data received.
        // It is therefore VERY likely that new signals have been generated while handling the data.
        // The cyboi system is therefore NOT sent to sleep, so that possibly existing
        // signals may be handled in the next iteration of the signal checker loop.

    } else {

        // No interrupt request was detected, so that the cyboi system
        // can be sent to sleep now, in order to save cpu time.

        check_wait(p0, p3);
    }
}

/* EMPTY_CHECKER_SOURCE */
#endif
