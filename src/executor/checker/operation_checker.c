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
 * @version CYBOP 0.27.0 2023-08-31
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
#include "logger.h"

/**
 * Checks two arrays lexicographically.
 *
 * In order to achieve this, different functions have to be handed over,
 * depending on the given operation type (operator).
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data
 * @param p2 the right data
 * @param p3 the left count
 * @param p4 the right count
 * @param p5 the operation type
 * @param p6 the operand type
 */
void check_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check operation.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_array(p0, p1, p2, p3, p4, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_array(p0, p1, p2, p3, p4, p6, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_array(p0, p1, p2, p3, p4, p6, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_array(p0, p1, p2, p3, p4, p6, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_array(p0, p1, p2, p3, p4, p6, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_array(p0, p1, p2, p3, p4, p6, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check operation. The operation type is unknown.");
        fwprintf(stdout, L"Warning: Could not check operation. The operation type is unknown. p5: %i\n", p5);
        fwprintf(stdout, L"Warning: Could not check operation. The operation type is unknown. *p5: %i\n", *((int*) p5));
    }
}
