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

#ifndef TYPE_ARRAY_SEARCHER_SOURCE
#define TYPE_ARRAY_SEARCHER_SOURCE

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Checks if the list contains parts or primitive types.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the list data position (pointer reference)
 * @param p2 the list count remaining
 * @param p3 the list model flag (false = name, true = model)
 * @param p4 the searchword data
 * @param p5 the searchword count
 * @param p6 the type
 * @param p7 the loop variable
 * @param p8 the step (increment or decrement)
 * @param p9 the backward flag
 * @param p10 the break flag
 */
void search_array_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The position represents the current PART.
        void** pos = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search array type.");
        fwprintf(stdout, L"Debug: Search array type.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The list type.
        int lt = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The element data, count, type.
        void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
        int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int et = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        compare_integer_equal((void*) &r, p6, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The list represents primitive data.
            //

            // Copy list type.
            copy_integer((void*) &lt, p6);
            //
            // Initialise element with current list data.
            //
            // CAUTION! Since the operation "check" called further below does
            // lexicographical comparison, the COUNTS of both operands have to
            // be EQUAL for a positive result. But the list count remaining
            // is mostly greater than the searchword count. Therefore, the
            // searchword count gets assigned to the element count here.
            //
            copy_pointer((void*) &ed, p1);
            copy_integer((void*) &ec, p5);
            copy_integer((void*) &et, p6);

        } else {

            //
            // The list contains compound parts.
            //

            // Copy list type.
            copy_integer((void*) &lt, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            //
            // Initialise element with part name OR model,
            // depending on the given model flag.
            //
            search_array_part((void*) &ed, (void*) &ec, (void*) &et, *pos, p3);
        }

        search_array_comparison(p0, p1, p2, (void*) &lt, ed, (void*) &ec, p4, p5, p6, p7, p8, p9, p10, (void*) &et);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search array type. The list data position is null.");
        fwprintf(stdout, L"Error: Could not search array type. The list data position is null. p1: %i\n", p1);
    }
}

/* TYPE_ARRAY_SEARCHER_SOURCE */
#endif
