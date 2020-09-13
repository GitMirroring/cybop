/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INDEX_COUNT_VERIFIER_SOURCE
#define INDEX_COUNT_VERIFIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../executor/calculator/integer/add_integer_calculator.c"
#include "../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../executor/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Verifies that the sum of the given index and count is within the data array.
 *
 * This is necessary to avoid segmentation fault errors caused by
 * pointers adressing memory that is outside the given data array.
 *
 * The first and second data count do NOT have to be identical,
 * as long as the sum of the given index and count is smaller than
 * or equal to both of them.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the count
 * @param p2 the first index
 * @param p3 the second index
 * @param p4 the first count
 * @param p5 the second count
 */
void verify_index_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Verify index count.");

    // The first and second count.
    int c1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int c2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The first and second count comparison result.
    int r1 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int r2 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Calculate first count as sum of first index and count.
    calculate_integer_add((void*) &c1, p2);
    calculate_integer_add((void*) &c1, p1);
    // Calculate second count as sum of second index and count.
    calculate_integer_add((void*) &c2, p3);
    calculate_integer_add((void*) &c2, p1);

    // Compare calculated count with actual first and second count.
    compare_integer_less_or_equal((void*) &r1, (void*) &c1, p4);
    compare_integer_less_or_equal((void*) &r2, (void*) &c2, p5);

/*??
    fwprintf(stdout, L"Test: Verify index count p1: %i\n", p1);
    fwprintf(stdout, L"Test: Verify index count p2: %i\n", p2);
    fwprintf(stdout, L"Test: Verify index count p3: %i\n", p3);
    fwprintf(stdout, L"Test: Verify index count p4: %i\n", p4);
    fwprintf(stdout, L"Test: Verify index count p5: %i\n", p5);
*/

/*??
    if (r2 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (r1 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
*/

            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

/*??
        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not verify index count. The sum of the given index and count is greater than the first count.");
            fwprintf(stdout, L"Warning: Could not verify index count. The sum of the given index and count is greater than the first count.\n");
            fwprintf(stdout, L"Hint: Sum c1: %i. First count *p4: %i.\n", c1, *((int*) p4));
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not verify index count. The sum of the given index and count is greater than the second count.");
        fwprintf(stdout, L"Warning: Could not verify index count. The sum of the given index and count is greater than the second count.\n");
        //?? fwprintf(stdout, L"Hint: Sum c2: %i. First count *p5: %i.\n", c2, *((int*) p5));
    }
*/
}

/* INDEX_COUNT_VERIFIER_SOURCE */
#endif
