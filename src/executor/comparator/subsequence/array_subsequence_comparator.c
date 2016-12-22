/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_SUBSEQUENCE_COMPARATOR_SOURCE
#define ARRAY_SUBSEQUENCE_COMPARATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../executor/calculator/basic/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/basic/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/comparator/basic/array_comparator.c"
#include "../../../logger/logger.c"

/**
 * Compares if the elements of the right- are a subsequence of the left array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the left array count
 * @param p6 the right array count
 */
void compare_subsequence_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare subsequence array elements.");

    // The loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Add left array count.
    calculate_integer_add((void*) &c, p5);
    // Subtract right array count.
    calculate_integer_subtract((void*) &c, p6);
    // Add number one.
    // CAUTION! This IS NECESSARY since otherwise, two arrays with
    // identical length will never be processed as the count is zero then.
    // Problems with the loop variable used as investigated array index
    // will NOT occur, since the loop is left before.
    calculate_integer_add((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The subsequence had been found in the previous loop cycle.
            // The result flag has been set to true.
            // The loop may be left now.

            break;
        }

        if (j >= c) {

            // The maximum loop count has been reached.
            // All elements have been compared.
            // The subsequence could not be found.
            // Leave result flag untouched.

            break;
        }

        // CAUTION! Hand over RIGHT array count as count,
        // since it is shorter or equal to that of the left array.
        // CAUTION! Use loop variable as left array index.
        compare_array(p0, p1, p2, p3, p4, p6, (void*) &j, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        j++;
    }
}

/**
 * Compares if the right- is a subsequence of the left array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the left array count
 * @param p6 the right array count
 */
void compare_subsequence_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare subsequence array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater_or_equal((void*) &r, p5, p6);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_subsequence_array_elements(p0, p1, p2, p3, p4, p5, p6);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare subsequence array. The left array count is smaller than the right array count.");
    }
}

/* ARRAY_SUBSEQUENCE_COMPARATOR_SOURCE */
#endif
