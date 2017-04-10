/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef THREADS_IO_CHECKER_SOURCE
#define THREADS_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../../executor/logifier/boolean/or_boolean_logifier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Check if flags have been set within a sensing thread.
 *
 * The sensing threads run in parallel to this main thread.
 *
 * This is the OLD solution using thread,
 * which causes problems when porting to other platforms.
 *
 * @param p0 the break flag
 * @param p1 the internal memory data
 */
void check_io_threads(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io threads.");

    // The display enable flag and interrupt request.
    void* de = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial enable flag and interrupt request.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal enable flag and interrupt request.
    void* te = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ti = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get display enable flag and interrupt request.
    copy_array_forward((void*) &de, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &di, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get serial enable flag and interrupt request.
    copy_array_forward((void*) &se, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &si, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get terminal enable flag and interrupt request.
    copy_array_forward((void*) &te, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ti, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // The results.
    int d = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int t = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise results.
    logify_boolean_or((void*) &d, de);
    logify_boolean_or((void*) &s, se);
    logify_boolean_or((void*) &t, te);

    // Check if both, enabled flag AND interrupt request are TRUE.
    logify_boolean_and((void*) &d, di);
    logify_boolean_and((void*) &s, si);
    logify_boolean_and((void*) &t, ti);

    if (d || s || t) {

        // Set break flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* THREADS_IO_CHECKER_SOURCE */
#endif
