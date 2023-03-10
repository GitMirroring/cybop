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

#ifndef INTEGER_COMPARATOR_SOURCE
#define INTEGER_COMPARATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/comparator/integer/less_integer_comparator.c"
#include "../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../logger/logger.c"

/**
 * Compares the left- with the right integer.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation type
 */
void compare_integer(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare integer.");

    // The comparison result.
    // CAUTION! It is used instead of if-else statements.
    // May be one day, this is useful when using assembler or implementing cyboi as hardware chip.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_greater(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_greater_or_equal(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_less(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_less_or_equal(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare integer. The operation type is unknown.");
    }
}

/* INTEGER_COMPARATOR_SOURCE */
#endif
