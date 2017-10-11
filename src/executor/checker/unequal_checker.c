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

#ifndef UNEQUAL_CHECKER_SOURCE
#define UNEQUAL_CHECKER_SOURCE

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/comparator/value_comparator.c"
#include "../../executor/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Checks two arrays lexicographically for unequality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data
 * @param p2 the right data
 * @param p3 the left count
 * @param p4 the right count
 */
void check_unequal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check unequal.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The unequal comparison result.
    int u = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Compare array counts.
    compare_integer_unequal((void*) &r, p3, p4);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Assign loop count.
        // Either p3 or p4 may be used, since both are equal (tested above).
        copy_integer((void*) &c, p3);

        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_greater_or_equal((void*) &b, (void*) &j, (void*) &c);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // All elements have been compared and were equal.

                break;
            }

            compare_value_offset((void*) &u, p1, p2, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &j);

            if (u != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // An unequal element has been found.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                break;
            }

            j++;
        }
    }
}

/* UNEQUAL_CHECKER_SOURCE */
#endif
