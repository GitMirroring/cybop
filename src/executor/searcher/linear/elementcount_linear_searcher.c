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

#ifndef ELEMENTCOUNT_LINEAR_SEARCHER_SOURCE
#define ELEMENTCOUNT_LINEAR_SEARCHER_SOURCE

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Verifies that the element count is within a valid value range.
 *
 * @param p0 the element count
 * @param p1 the searchword count
 * @param p2 the list count remaining
 */
void search_linear_elementcount(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear elementcount.");
    fwprintf(stdout, L"Debug: Search linear elementcount. p0: %i\n", p0);

    // The lower limit comparison result.
    int l = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The upper limit comparison result.
    int u = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater((void*) &l, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (l != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &u, p1, p2);

        if (u != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, p1);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search linear elementcount. The elementcount value is greater than the list count remaining.");
            fwprintf(stdout, L"Error: Could not search linear elementcount. The elementcount value is greater than the list count remaining. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search linear elementcount. The elementcount value is less or equal to zero.");
        fwprintf(stdout, L"Error: Could not search linear elementcount. The elementcount value is less or equal to zero. p1: %i\n", p1);
    }
}

/* ELEMENTCOUNT_LINEAR_SEARCHER_SOURCE */
#endif
