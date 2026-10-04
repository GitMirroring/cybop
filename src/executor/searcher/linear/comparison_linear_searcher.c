/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Checks if the element type and searchword type are equal.
 *
 * @param p0 the found flag (set to TRUE if found; unchanged otherwise)
 * @param p1 the element data
 * @param p2 the element count
 * @param p3 the element type
 * @param p4 the searchword data
 * @param p5 the searchword count
 * @param p6 the searchword type
 */
void search_linear_comparison(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear comparison.");
    //?? fwprintf(stdout, L"Debug: Search linear comparison. p0: %i\n", p0);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p3, p6);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The element type and searchword type are EQUAL.
        //

        //
        // Compare element with searchword.
        //
        // CAUTION! Since the operation "check" does lexicographical comparison,
        // the COUNTS of both operands have to be EQUAL for a positive result.
        //
        check_operation(p0, p1, p4, p2, p5, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, p6);

    } else {

        //
        // The element type and searchword type are UNEQUAL.
        //
        // CAUTION! In this case the current element of the list is just SKIPPED,
        // but the loop will CONTINUE to run and compare the remaining elements.
        //

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search linear comparison. The element type and searchword type are unequal.");
        fwprintf(stdout, L"Warning: Could not search linear comparison. The element type and searchword type are unequal. p3: %i, p6: %i\n", p3, p6);
        fwprintf(stdout, L"Warning: Could not search linear comparison. The element type and searchword type are unequal. *p3: %i, *p6: %i\n", *((int*) p3), *((int*) p6));
    }
}
