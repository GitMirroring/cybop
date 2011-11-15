/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_REMOVER_SOURCE
#define ARRAY_REMOVER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/calculator/integer_subtracter.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../logger/logger.c"

/**
 * Removes the given number of array elements.
 *
 * All current elements existing behind the area to be removed
 * from the array are moved towards the beginning.
 *
 * CAUTION! This is done in a FORWARD order, starting from the
 * FIRST element (behind the area to be removed) since otherwise,
 * overlapping elements might get overwritten.
 *
 * Example:
 *
 * array: "Hello, XYZWorld!"
 * count: 3
 * index: 7
 * array count: 16
 * ==> result: "Hello, World!"
 *
 * @param p0 the array (pointer reference)
 * @param p1 the type
 * @param p2 the count
 * @param p3 the index
 * @param p4 the array count
 * @param p5 the array size
 */
void remove_array_inside(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Remove array inside.");

        // The move source index.
        int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The move source count.
        int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The new size.
        int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Add index.
        calculate_integer_add((void*) &i, p3);
        // Add count.
        calculate_integer_add((void*) &i, p2);

        // Add array count.
        calculate_integer_add((void*) &c, p4);
        // Subtract move source index.
        calculate_integer_subtract((void*) &c, (void*) &i);

        // Add array count.
        calculate_integer_add((void*) &n, p4);
        // Subtract count of elements to be removed.
        calculate_integer_subtract((void*) &n, p2);

        // Decrement reference count of removed parts for rubbish (garbage) collection.
        reference(*d, (void*) SUBTRACT_LOGIC_CYBOI_TYPE, p2, p3, p1);

        // Move current elements behind area to be removed towards the beginning of the array.
        // CAUTION! Move array elements starting from the FIRST since otherwise,
        // overlapping array elements might get overwritten!
        // CAUTION! Call this function BEFORE resizing the array
        // since elements might get lost while shrinking the array.
        copy_array_forward(*d, *d, p1, (void*) &c, p3, (void*) &i);

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_smaller((void*) &r, (void*) &n, p5);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Shrink array using new count as size.
            reallocate_array(p0, p4, (void*) &n, p1);

            // Set new size.
            copy_integer(p5, (void*) &n);
        }

        // Assign destination array count.
        copy_integer(p4, (void*) &n);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove array inside. The array is null.");
    }
}

/**
 * Removes the given number of elements from the array,
 * starting from the given index.
 *
 * @param p0 the array (pointer reference)
 * @param p1 the type
 * @param p2 the count
 * @param p3 the index
 * @param p4 the array count
 * @param p5 the array size
 */
void remove_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Remove array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer((void*) &r, p3, p4, (void*) SMALLER_PRIMITIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            remove_array_inside(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove array. The destination index is outside the array boundaries.");
    }
}

/* ARRAY_REMOVER_SOURCE */
#endif
