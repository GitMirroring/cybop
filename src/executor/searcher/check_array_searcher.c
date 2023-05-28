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

#ifndef CHECK_ARRAY_SEARCHER_SOURCE
#define CHECK_ARRAY_SEARCHER_SOURCE

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Compares list element with given searchword.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the list data position (pointer reference)
 * @param p2 the list count remaining
 * @param p3 the list type
 * @param p4 the element data
 * @param p5 the element count
 * @param p6 the searchword data
 * @param p7 the searchword count
 * @param p8 the element type
 * @param p9 the loop variable
 * @param p10 the step (increment or decrement)
 * @param p11 the backward flag
 * @param p12 the break flag
 */
void search_array_check(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search array check.");
    fwprintf(stdout, L"Debug: Search array check.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Compare part name with given searched name.
    //
    // CAUTION! Since the operation "check" does lexicographical comparison,
    // the COUNTS of both operands have to be EQUAL for a positive result.
    //
    check_operation((void*) &r, p4, p6, p5, p7, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, p8);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The searchword has been found.
        //

        // Copy index.
        copy_integer(p0, p9);

        // Set break flag.
        copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        // Move the current position.
        move(p1, p2, p3, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p11);

        // Calculate loop variable using step (increment or decrement).
        calculate_integer_add(p9, p10);
    }
}

/* CHECK_ARRAY_SEARCHER_SOURCE */
#endif
