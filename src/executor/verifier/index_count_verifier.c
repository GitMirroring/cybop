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
 * The left and right data count do NOT have to be identical,
 * as long as the sum of the given index and count is smaller than
 * or equal to both of them.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the count
 * @param p2 the left index
 * @param p3 the right index
 * @param p4 the left count
 * @param p5 the right count
 */
void verify_index_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Verify index count.");

    // The left- and right count.
    int lc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int rc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The left- and right count comparison result.
    int lr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int rr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Calculate left count as sum of left index and count.
    calculate_integer_add((void*) &lc, p2);
    calculate_integer_add((void*) &lc, p1);
    // Calculate right count as sum of right index and count.
    calculate_integer_add((void*) &rc, p3);
    calculate_integer_add((void*) &rc, p1);

    // Compare calculated count with actual left- and right count.
    compare_integer_less_or_equal((void*) &lr, (void*) &lc, p4);
    compare_integer_less_or_equal((void*) &rr, (void*) &rc, p5);

    if (rr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (lr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not verify index count. The sum of the given index and count is greater than the left count.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not verify index count. The sum of the given index and count is greater than the right count.");
    }
}

/* INDEX_COUNT_VERIFIER_SOURCE */
#endif
