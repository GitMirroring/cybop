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

#ifndef COMPLEX_GETTER_SOURCE
#define COMPLEX_GETTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/complex_state_cyboi_name.c"
#include "../../../executor/calculator/pointer/add_pointer_calculator.c"
#include "../../../executor/copier/double_copier.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/real_type_size.c"

/**
 * Gets the source complex's element at the given index.
 *
 * @param p0 the destination element
 * @param p1 the source complex
 * @param p2 the source index
 */
void get_complex_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get complex element.");

    // The element pointer.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise element pointer.
    copy_pointer((void*) &e, (void*) &p1);

    if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.
                calculate_pointer_add((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                // Copy element to destination.
                copy_double(p0, e);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add offset to element pointer.
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.
                calculate_pointer_add((void*) &e, (void*) DOUBLE_REAL_TYPE_SIZE);

                // Copy element to destination.
                copy_double(p0, e);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get complex element. The source index is not known.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get complex element. The source complex is null.");
    }
}

/* COMPLEX_GETTER_SOURCE */
#endif
