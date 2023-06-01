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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SEARCHER_SOURCE
#define SEARCHER_SOURCE

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/*
 * Searches data using the given algorithm (operation type).
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the list data
 * @param p2 the list count
 * @param p3 the list type
 * @param p4 the list model flag (false = name, true = model)
 * @param p5 the searchword data
 * @param p6 the searchword count
 * @param p7 the searchword type
 * @param p8 the backward flag
 * @param p9 the operation type
 */
void search(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search.");
    //?? fwprintf(stdout, L"Debug: Search. operation type p9: %i\n", p9);
    //?? fwprintf(stdout, L"Debug: Search. operation type *p9: %i\n", *((int*) p9));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) BINARY_SEARCH_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            search_binary(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) INTERPOLATION_SEARCH_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            search_interpolation(p0, p1, p2);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) LINEAR_SEARCH_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            search_linear(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search. The operation type is unknown.");
        fwprintf(stdout, L"Warning: Could not search. The operation type is unknown. p9: %i\n", p9);
        fwprintf(stdout, L"Warning: Could not search. The operation type is unknown. *p9: %i\n", *((int*) p9));
    }
}

/* SEARCHER_SOURCE */
#endif
