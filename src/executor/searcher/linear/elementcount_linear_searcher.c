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
#include "knowledge.h"
#include "logger.h"

/**
 * Assigns the searchword count to the element count only if it is within a valid value range.
 *
 * @param p0 the element count
 * @param p1 the searchword count
 * @param p2 the list count remaining
 */
void search_linear_elementcount(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear elementcount.");
    //?? fwprintf(stdout, L"Debug: Search linear elementcount. searchword count p1: %i; list count remaining p2: %i\n", p1, p2);
    //?? fwprintf(stdout, L"Debug: Search linear elementcount. searchword count *p1: %i; list count remaining *p2: %i\n", *((int*) p1), *((int*) p2));

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

            //
            // CAUTION! Do NOT log this case since it is REGULAR behaviour that
            // the list starts growing element by element so that at the beginning,
            // its count (length) might be smaller than the searchword count.
            //
            // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search linear elementcount. The searchword count is greater than the list count remaining.");
            // fwprintf(stdout, L"Warning: Could not search linear elementcount. The searchword count is greater than the list count remaining. searchword count p1: %i; list count remaining p2: %i\n", p1, p2);
            // fwprintf(stdout, L"Warning: Could not search linear elementcount. The searchword count is greater than the list count remaining. searchword count *p1: %i; list count remaining *p2: %i\n", *((int*) p1), *((int*) p2));
            //
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search linear elementcount. The searchword count is less or equal to zero.");
        fwprintf(stdout, L"Warning: Could not search linear elementcount. The searchword count is less or equal to zero. searchword count p1: %i; list count remaining p2: %i\n", p1, p2);
        fwprintf(stdout, L"Warning: Could not search linear elementcount. The searchword count is less or equal to zero. searchword count *p1: %i; list count remaining *p2: %i\n", *((int*) p1), *((int*) p2));
    }
}
