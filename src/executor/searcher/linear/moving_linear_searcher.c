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
 * Moves pointer to the next position.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the list data position (pointer reference)
 * @param p2 the list count remaining
 * @param p3 the list type
 * @param p4 the break flag
 * @param p5 the loop variable
 * @param p6 the step (increment or decrement)
 * @param p7 the backward flag
 * @param p8 the found flag (false = NOT found, true = element WAS found)
 */
void search_linear_moving(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear moving.");
    //?? fwprintf(stdout, L"Debug: Search linear moving. step p6: %i\n", p6);
    //?? fwprintf(stdout, L"Debug: Search linear moving. step *p6: %i\n", *((int)* p6));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The searchword has been found.
        //

        // Copy current element's index as result.
        copy_integer(p0, p5);

        // Set break flag.
        copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        // Move the current position.
        move(p1, p2, p3, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p7);

        // Calculate loop variable using step (increment or decrement).
        calculate_integer_add(p5, p6);
    }
}
