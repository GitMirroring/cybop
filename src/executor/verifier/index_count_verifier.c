/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.24.0 2022-12-24
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
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the element count
 * @param p2 the data index
 * @param p3 the data count
 */
void verify_index_count(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Verify index count.");

    // The test count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Calculate test count as sum of data index and element count.
    calculate_integer_add((void*) &c, p2);
    calculate_integer_add((void*) &c, p1);

    //?? TODO DELETE: p0, p2 = 0, p1 = 1 <= p3 = 1
    //?? TODO DELETE: p0, p2 = 5, p1 = 1 <= p3 = 1

    // Compare test count with actual data count.
    compare_integer_less_or_equal((void*) &r, (void*) &c, p3);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        //
        // The sum of the data index and count
        // is greater than the data count.
        //
        // This is most often caused by a knowledge path
        // pointing to a non-existing node, which may be
        // regular behaviour in a cybol application.
        //
        // REMARK: In order to keep the log file size low,
        // the following log messages are commented out.
        //
        // REMARK: This empty block containing a comment only
        // does no harm, since the compiler will remove it anyway.
        //

        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not verify index count. The sum of the data index and count is greater than the data count.");
        // fwprintf(stdout, L"Warning: Could not verify index count. The sum of the data index and count is greater than the data count.\n");

        // CAUTION! The following print messages causes an error, if p3 is null! It is therefore commented out.
        // fwprintf(stdout, L"Hint: Test count sum c: %i. Data count *p3: %i.\n", c, *((int*) p3));
    }
}

/* INDEX_COUNT_VERIFIER_SOURCE */
#endif
