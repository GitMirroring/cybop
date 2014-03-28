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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSE_CHECKER_SOURCE
#define SENSE_CHECKER_SOURCE

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
 * @param p0 the cyboi service enable flag
 * @param p1 the cyboi service interrupt request
 * @param p2 the display enable flag
 * @param p3 the display interrupt request
 * @param p4 the serial port enable flag
 * @param p5 the serial port interrupt request
 * @param p6 the terminal enable flag
 * @param p7 the terminal interrupt request
 * @param p8 the www service enable flag
 * @param p9 the www service interrupt request
 * @param p10 the break flag
 * @param p11 the internal memory data
 * @param p12 the sleep time
 */
void check_sense(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p10 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* b = (int*) p10;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check sense.");

//?? fwprintf(stdout, L"TEST check sense b: %i\n", *((int*) b));

        // The results.
        int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        int d = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        int t = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        int w = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Check if flags have been set within a sensing thread,
        // running in parallel to this main thread.
        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Initialise results.
            logify_boolean_or((void*) &c, p0);
            logify_boolean_or((void*) &d, p2);
            logify_boolean_or((void*) &s, p4);
            logify_boolean_or((void*) &t, p6);
            logify_boolean_or((void*) &w, p8);

            // Check if both, enabled flag AND interrupt request are TRUE.
            logify_boolean_and((void*) &c, p1);
            logify_boolean_and((void*) &d, p3);
            logify_boolean_and((void*) &s, p5);
            logify_boolean_and((void*) &t, p7);
            logify_boolean_and((void*) &w, p9);

            if (c || d || s || t || w) {

                // Set break flag.
                copy_integer(p10, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }
        }

        // Check display for input.
        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &d, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (d != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                sense_display(p3, p10, p11);
            }
        }

        // Check terminal for input.
        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &t, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (t != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                sense_terminal(p7, p10, p11);
            }
        }

        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Sleep for some time.
            sleep_nano(p12);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check sense. The break flag is null.");
    }
}

/* SENSE_CHECKER_SOURCE */
#endif
