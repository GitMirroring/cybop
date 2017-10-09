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

#ifndef ITEM_CHECKER_SOURCE
#define ITEM_CHECKER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/checker/checker.c"
#include "../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../logger/logger.c"

/**
 * Tests if given count is smaller or equal to the arrays' count.
 *
 * @param p0 the result item (number 1 if true; unchanged otherwise)
 * @param p1 the left data
 * @param p2 the right data
 * @param p3 the count
 * @param p4 the operation type
 * @param p5 the operand type
 * @param p6 the left count
 * @param p7 the right count
 */
void check_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check count.");

    //
    // CAUTION! The data counts do NOT have to be identical,
    // as long as the given count is smaller than both of them,
    // the corresponding elements may be checked.
    //
    // CAUTION! The sizes do NOT matter anyway,
    // since they just represent allocated memory,
    // but only the count as actual number of elements is of interest.
    //

    // The left count comparison result.
    int l = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The right count comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_less_or_equal((void*) &l, p3, p6);
    compare_integer_less_or_equal((void*) &r, p3, p7);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (l != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check(p0, p1, p2, p3, p4, p5);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check count. The given count is greater than the left count.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check count. The given count is greater than the right count.");
    }
}

/* ITEM_CHECKER_SOURCE */
#endif
