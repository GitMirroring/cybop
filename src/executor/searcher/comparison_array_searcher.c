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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COMPARISON_ARRAY_SEARCHER_SOURCE
#define COMPARISON_ARRAY_SEARCHER_SOURCE

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Checks if the list contains parts or primitive types.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the list data position (pointer reference)
 * @param p2 the list count remaining
 * @param p3 the list type
 * @param p4 the element data
 * @param p5 the element count
 * @param p6 the searchword data
 * @param p7 the searchword count
 * @param p8 the type
 * @param p9 the loop variable
 * @param p10 the step (increment or decrement)
 * @param p11 the backward flag
 * @param p12 the break flag
 * @param p13 the element type
 */
void search_array_comparison(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search array comparison.");
    fwprintf(stdout, L"Debug: Search array comparison.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p8, p13);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The given type and determined element type are EQUAL.
        //

        // Compare list element with given searchword.
        search_array_check(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);

    } else {

        //
        // The given type and determined element type are UNEQUAL.
        //
        // CAUTION! In this case the current element of the list is just SKIPPED,
        // but the loop will CONTINUE to run and compare the remaining elements.
        //

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search array comparison. The given type and determined element type are unequal.");
        fwprintf(stdout, L"Error: Could not search array comparison. The given type and determined element type are unequal. p8: %i, p13: %i\n", p8, p13);
        fwprintf(stdout, L"Error: Could not search array comparison. The given type and determined element type are unequal. *p8: %i, *p13: %i\n", *((int*) p8), *((int*) p13));
    }
}

/* COMPARISON_ARRAY_SEARCHER_SOURCE */
#endif
