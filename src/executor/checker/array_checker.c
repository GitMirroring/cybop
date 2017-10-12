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

#ifndef ARRAY_CHECKER_SOURCE
#define ARRAY_CHECKER_SOURCE

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/checker/equal_checker.c"
#include "../../executor/checker/less_or_greater_or_equal_checker.c"
#include "../../executor/checker/unequal_checker.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../logger/logger.c"

/**
 * Checks two arrays lexicographically.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data
 * @param p2 the right data
 * @param p3 the left count
 * @param p4 the right count
 * @param p5 the operation type
 */
void check_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) EQUAL_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_equal(p0, p1, p2, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GREATER_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_less_or_greater_or_equal(p0, p1, p2, p3, p4, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GREATER_OR_EQUAL_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_less_or_greater_or_equal(p0, p1, p2, p3, p4, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) LESS_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_less_or_greater_or_equal(p0, p1, p2, p3, p4, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) LESS_OR_EQUAL_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_less_or_greater_or_equal(p0, p1, p2, p3, p4, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) UNEQUAL_CHECK_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_unequal(p0, p1, p2, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check array. The operation type is unknown.");
    }
}

/* ARRAY_CHECKER_SOURCE */
#endif
