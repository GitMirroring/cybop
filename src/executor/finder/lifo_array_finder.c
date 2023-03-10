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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LIFO_ARRAY_FINDER_SOURCE
#define LIFO_ARRAY_FINDER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/checker/operation_checker.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/copier/array/forward_array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Finds a part with the given name in the investigated array,
 * using the last-in-first-out (lifo) principle (stack).
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated data (pointer reference) (each element pointing to a part)
 * @param p2 the searched name data
 * @param p3 the searched name count
 * @param p4 the investigated count
 */
void find_array_lifo(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find array lifo.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    // CAUTION! The value of -1 causes the loop to break by default.
    int j = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name item.
    void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name item data, count.
    void* pnd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pnc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise loop variable.
    // CAUTION! It gets changed ONLY IF the loop count handed over
    // as argument is valid (not null).
    // Otherwise, it just gets ignored inside the copy function.
    copy_integer((void*) &j, p4);
    // CAUTION! Subtracting 1 is ESSENTIAL,
    // since this is NOT the count, but the index!
    // Otherwise, a "bus error" will occur and the system crash.
    calculate_integer_subtract((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &b, (void*) &j, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The maximum loop count has been reached.
            // All elements have been compared.
            // A part with the searched name could not be found.
            // Leave index untouched.

            break;
        }

        // Get part j from investigated pointer array p1.
        copy_array_forward((void*) &p, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j);
        // Get part name item.
        copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        // Get part name item data, count.
        copy_array_forward((void*) &pnd, pn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pnc, pn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Compare part name with given searched name.
        check_operation((void*) &r, pnd, p2, pnc, p3, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The part with the searched name has been found.

            // Remember the index.
            copy_integer(p0, (void*) &j);

            // The loop may be left now.
            break;
        }

        j--;
    }
}

/* LIFO_ARRAY_FINDER_SOURCE */
#endif
