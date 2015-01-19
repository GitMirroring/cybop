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

#ifndef THREADS_SENSE_CHECKER_SOURCE
#define THREADS_SENSE_CHECKER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../executor/logifier/boolean/or_boolean_logifier.c"
#include "../../executor/modifier/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Check if flags have been set within a sensing thread.
 *
 * The sensing threads run in parallel to this main thread.
 *
 * This is the OLD solution using thread,
 * which causes problems when porting to other platforms.
 *
 * @param p0 the display enable flag
 * @param p1 the display interrupt request
 * @param p2 the serial port enable flag
 * @param p3 the serial port interrupt request
 * @param p4 the socket enable flag
 * @param p5 the socket interrupt request
 * @param p6 the terminal enable flag
 * @param p7 the terminal interrupt request
 * @param p8 the break flag
 */
void check_sense_threads(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check sense threads.");

    // The results.
    int d = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int so = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int t = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise results.
    logify_boolean_or((void*) &d, p0);
    logify_boolean_or((void*) &s, p2);
    logify_boolean_or((void*) &so, p4);
    logify_boolean_or((void*) &t, p6);

    // Check if both, enabled flag AND interrupt request are TRUE.
    logify_boolean_and((void*) &d, p1);
    logify_boolean_and((void*) &s, p3);
    logify_boolean_and((void*) &so, p5);
    logify_boolean_and((void*) &t, p7);

    if (d || s || so || t) {

        // Set break flag.
        copy_integer(p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* THREADS_SENSE_CHECKER_SOURCE */
#endif
