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

#ifndef SENSE_CHECKER_SOURCE
#define SENSE_CHECKER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/extra_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../controller/checker/io_sense_checker.c"
#include "../../executor/modifier/copier/integer_copier.c"
#include "../../executor/runner/nano_sleeper.c"
#include "../../logger/logger.c"

//
// If no signals are waiting in the signal memory (queue)
// and no hardware requests have been received from either the:
// - terminal
// - display
// - www service
// - cyboi service
// then cpu processing time may be saved by sending the system to sleep.
//
// Several possibilities have been considered to achieve this:
//
// 1 pause
//
// The simplicity of pause can conceal serious timing errors
// that can make a program hang mysteriously.
// One can't safely use pause to wait until one more signal
// arrives, and then resume real work. Even if one arranges
// for the signal handler to cooperate by setting a flag,
// one still can't use pause reliably.
//
// Example:
// // The irq flag is set by some signal handler.
// if (irq == 0) {
//     pause();
// }
// // Do work once the signal arrives.
// ...
//
// This has a bug: the signal could arrive after the variable
// irq is checked, but before the call to pause. If no further
// signals arrive, the process would never wake up again.
//
// 2 sleep
//
// One can put an upper limit on the excess waiting by using
// sleep in a loop, instead of using pause.
//
// Example:
// // The irq flag is set by some signal handler.
// while (irq == 0) {
//     sleep(1);
// }
// // Do work once the signal arrives.
// ...
//
// For some purposes, that is good enough.
//
// 3 signals of the operating system
//
// With a little more complexity, one can wait reliably until
// a particular signal handler is run, using sigsuspend.
//
// Solution in CYBOI
//
// The signal handler approach was tried out and implemented.
// However, when the process was sent to sleep with sigsuspend,
// all its threads were sleeping as well. This is a problem,
// because the input/output (including user interface control)
// is running in special threads. Since these were sleeping,
// there was no way to wake up the CYBOI system on user request.
//
// Another approach was to let the input/output run in their
// own process (instead of only a thread), each.
// The problem here is resource sharing between the processes.
// While threads use the same resources as their parent process,
// child processes copy their parent process' resources at
// creation and afterwards work independently on their own resources.
// This is a problem because CYBOI's signal memory needs to be
// accessed by all input/output processes without conflicts.
//
// Furthermore, the usage of operating system signals enforces
// a global interrupt request flag variable. Since a signal
// handler procedure may receive only the numeric code of the
// signal, but not further parametres, the interrupt request
// flag may not be handed over within the internal memory and
// a global flag would have to be used, which is undesirable.
//
// Therefore, the decision fell on the usage of a simple SLEEP
// procedure, which seems sufficient for the purposes of CYBOI.
//

/**
 * Senses an interrupt request.
 *
 * @param p0 the break flag
 * @param p1 the internal memory
 * @param p2 the sleep time
 */
void check_sense(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check sense.");

    // The sense result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_sense_io((void*) &r, p1, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_sense_io((void*) &r, p1, (void*) SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_sense_io((void*) &r, p1, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_65536_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_sense_io((void*) &r, p1, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Set break flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        // Sleep for some time.
        sleep_nano(p2);
    }
}

/* SENSE_CHECKER_SOURCE */
#endif
