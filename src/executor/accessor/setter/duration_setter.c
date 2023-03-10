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

#ifndef DURATION_SETTER_SOURCE
#define DURATION_SETTER_SOURCE

//
// Library interface
//

#include "constant.h"
#include "variable.h"

//
// Executable interface
//

#include "../../../executor/calculator/pointer/add_pointer_calculator.c"
#include "../../../executor/copier/datetime_copier.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../logger/logger.c"

/**
 * Sets the destination duration's element at the given index.
 *
 * @param p0 the destination
 * @param p1 the source element
 * @param p2 the source index
 */
void set_duration_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set duration element.");

    // The element pointer.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise element pointer.
    copy_pointer((void*) &e, (void*) &p0);

    if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) VALUE_DURATION_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.
                calculate_pointer_add((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                // Copy element to destination.
                copy_datetime(e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) START_DURATION_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.
                calculate_pointer_add((void*) &e, (void*) DATETIME_COMPOUND_TYPE_SIZE);

                // Copy element to destination.
                copy_datetime(e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) END_DURATION_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.
                calculate_pointer_add((void*) &e, (void*) DATETIME_COMPOUND_TYPE_SIZE);
                calculate_pointer_add((void*) &e, (void*) DATETIME_COMPOUND_TYPE_SIZE);

                // Copy element to destination.
                copy_datetime(e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set duration element. The given source index is not known.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set duration element. The destination duration is null.");
    }
}

/* DURATION_SETTER_SOURCE */
#endif
