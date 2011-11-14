/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_DECREMENTER_SOURCE
#define ARRAY_DECREMENTER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/converter/encoder/model_diagram_encoder.c"
#include "../../../executor/searcher/mover/position_mover.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

/**
 * Decrements the reference count of the array elements.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the count
 */
void decrement_array_elements(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decrement part elements.");

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        decrement_part(p0, p1, (void*) &j);

        j++;
    }
}

/**
 * Decrements the reference count of the array elements,
 * starting from the given offset.
 *
 * @param p0 the array
 * @param p1 the type
 * @param p2 the count
 * @param p3 the index
 */
void decrement_array(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decrement array.");

        // The array.
        // CAUTION! It HAS TO BE initialised with p0,
        // since an offset is added below.
        void* a = p0;

        // Add offset.
        add_offset((void*) &a, p1, p3);

        decrement_array_elements(a, p1, p2);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decrement array. The array is null.");
    }
}

/* ARRAY_DECREMENTER_SOURCE */
#endif
