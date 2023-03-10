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

#ifndef ARRAY_CHECKER_SOURCE
#define ARRAY_CHECKER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/checker/count_checker.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/comparator/integer/less_integer_comparator.c"
#include "../../executor/comparator/offset_comparator.c"
#include "../../executor/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Checks two arrays lexicographically.
 *
 * At first, elements are compared.
 * Afterwards, the array count (length) gets compared.
 *
 * https://de.wikipedia.org/wiki/Lexikographische_Ordnung
 * https://en.wikipedia.org/wiki/Lexicographical_order
 *
 * Three operation types are handed over, for these cases:
 * - match criterion
 * - fail criterion
 * - count comparison
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data
 * @param p2 the right data
 * @param p3 the left count
 * @param p4 the right count
 * @param p5 the operand type
 * @param p6 the element success operation type
 * @param p7 the element failure operation type
 * @param p8 the count success operation type
 */
void check_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check array.");

    // The loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result 1.
    int r1 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result 2.
    int r2 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result 3.
    int r3 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Assign loop count.
    check_count((void*) &c, p3, p4);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // All elements have been compared and were equal.
            // Therefore, the array count (length) has to decide now.
            //
            compare_integer((void*) &r3, p3, p4, p8);

            if (r3 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // CAUTION! Just a hint: If the data are compared for equality,
                // then they are expected to be EQUAL, even if their count is zero.
                // This is important, because the PROPERTIES (cybol meta properties)
                // of many otherwise equal models are EMPTY.
                //

                // The left array count matches the comparison criterion.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                break;

            } else {

                // The left array count fails the comparison criterion.

                break;
            }
        }

        compare_offset((void*) &r1, p1, p2, p6, p5, (void*) &j);

        if (r1 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // An element that matches the comparison criterion has been found.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            break;
        }

        compare_offset((void*) &r2, p1, p2, p7, p5, (void*) &j);

        if (r2 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // An element that fails the comparison criterion has been found.
            //

            break;
        }

        j++;
    }
}

/* ARRAY_CHECKER_SOURCE */
#endif
