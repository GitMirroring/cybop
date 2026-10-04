/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "variable.h"

/**
 * Sets the destination fraction's element at the given index.
 *
 * @param p0 the destination fraction
 * @param p1 the source element
 * @param p2 the source index
 */
void set_fraction_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set fraction element.");

    // The element pointer.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise element pointer.
    copy_pointer((void*) &e, (void*) &p0);

    if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Add offset to element pointer.
                //
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                //
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                //
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.
                //
                calculate_pointer_add((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                // Copy element to destination.
                copy_integer(e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p2, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Add offset to element pointer.
                //
                // CAUTION! Add the type sizes of all elements PRECEDING
                // this one, but NOT the type size of this element itself.
                //
                // CAUTION! Multiplication with just one type size is NOT used,
                // since some compound types have elements of different type.
                //
                // CAUTION! The pointer type is needed here, since
                // the result is a pointer to which the offset is added.
                //
                calculate_pointer_add((void*) &e, (void*) SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

                // Copy element to destination.
                copy_integer(e, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set fraction element. The given source index is not known.");
            fwprintf(stdout, L"Warning: Could not set fraction element. The given source index is not known. source index p2: %i\n", p2);
            fwprintf(stdout, L"Warning: Could not set fraction element. The given source index is not known. source index *p2: %i\n", *((int*) p2));
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set fraction element. The destination fraction is null.");
        fwprintf(stdout, L"Warning: Could not set fraction element. The destination fraction is null. destination fraction p0 the same as e: %i\n", e);
    }
}
