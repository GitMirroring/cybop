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
 * @param p3 the list type
 * @param p4 the list model flag (false = name, true = model)
 * @param p5 the searchword data
 * @param p6 the searchword count
 * @param p7 the searchword type
 * @param p8 the perfect match flag (requesting equal count)
 * @param p9 the break flag
 * @param p10 the loop variable
 * @param p11 the step (increment or decrement)
 * @param p12 the backward flag
 */
void search_linear_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The position represents the current PART.
        void** pos = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear type.");
        //?? fwprintf(stdout, L"Debug: Search linear type. list type p3: %i\n", p3);
        //?? fwprintf(stdout, L"Debug: Search linear type. list type *p3: %i\n", *((int*) p3));

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The found flag.
        int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_equal((void*) &r, p3, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The list represents primitive data.
            //

            search_linear_primitive((void*) &f, *pos, p2, p3, p5, p6, p7, p8);

        } else {

            //
            // The list contains compound parts.
            //

            //
            // Initialise element with part name OR model,
            // depending on the given model flag.
            //
            search_linear_part((void*) &f, *pos, p4, p5, p6, p7, p8);
        }

        // Assign index and break OR move to the next position.
        search_linear_moving(p0, p1, p2, p3, p9, p10, p11, p12, (void*) &f);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search linear type. The list data position is null.");
        fwprintf(stdout, L"Error: Could not search linear type. The list data position is null. list data position p1: %i\n", p1);
    }
}
