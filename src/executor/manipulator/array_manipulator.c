/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ARRAY_MANIPULATOR_SOURCE
#define ARRAY_MANIPULATOR_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/manipulator/elements_array_manipulator.c"
#include "../../logger/logger.c"

/**
 * Manipulates the bit at the given position.
 * Processes count elements of the value array, starting from the given offset.
 *
 * @param p0 the value array
 * @param p1 the bit position
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the count
 * @param p5 the value index
 */
void manipulate_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    // CAUTION! This null pointer comparison is IMPORTANT,
    // in order to avoid a system crash if the array is null!

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate array.");

        // The array.
        // CAUTION! It HAS TO BE initialised with p0,
        // since an offset is added below.
        void* a = p0;

        // Add offset.
        add_offset((void*) &a, p3, p5);

        manipulate_array_elements(a, p1, p2, p3, p4);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate array. The value array is null.");
    }
}

/* ARRAY_MANIPULATOR_SOURCE */
#endif
