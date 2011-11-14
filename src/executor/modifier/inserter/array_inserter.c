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

#ifndef ARRAY_INSERTER_SOURCE
#define ARRAY_INSERTER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/basic/value_comparator.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Inserts the source- INSIDE the destination array.
 *
 * All current elements existing behind the given index in the destination array
 * are moved towards the end by the number of elements inserted.
 *
 * CAUTION! This is done in a backwards order, starting from the last element,
 * since otherwise, some elements might overlap and get overwritten.
 *
 * Example:
 *
 * destination array: "HelloWorld!"
 * source array: "blubla, blubla"
 * count: 2
 * destination index: 5
 * source index: 6
 * destination array count: 11
 * ==> result: "Hello, World"
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 * @param p6 the destination array count
 * @param p7 the destination array size
 */
void insert_array_inside(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Insert array inside.");

        // The move destination index.
        int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The move count.
        int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The new size.
        int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Add destination index.
        calculate_integer_add((void*) &i, p4);
        // Add count.
        calculate_integer_add((void*) &i, p3);

        // Add destination array count.
        calculate_integer_add((void*) &c, p6);
        // Subtract destination index.
        calculate_integer_subtract((void*) &c, p4);

        // Add destination array count.
        calculate_integer_add((void*) &n, p6);
        // Add count of new elements to be inserted.
        calculate_integer_add((void*) &n, p3);

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer((void*) &r, (void*) &n, p7, (void*) GREATER_PRIMITIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Multiply new size with factor.
            // CAUTION! This multiplication has to be done AFTER the comparison
            // of new size and old size since otherwise, the new size is falsified,
            // which would lead to runtime errors.
            // multiply_with_integer((void*) &n, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE);

            // Enlarge array using new count as size.
            reallocate_array(p0, p6, (void*) &n, p2);

            // Set new size.
            copy_integer(p7, (void*) &n);
        }

        // Move current elements behind given index towards the end of the array.
        // CAUTION! Move array elements starting from the LAST since otherwise,
        // overlapping array elements might get overwritten!
        // CAUTION! Call this function AFTER having resized the array
        // since otherwise, it might not be big enough and elements be cut.
        copy_array_backward(*d, *d, p2, (void*) &c, (void*) &i, p4);

        // Copy source to destination.
        copy_array_forward(*d, p1, p2, p3, p4, p5);

        // Set destination array count.
        copy_integer(p6, (void*) &n);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not insert array inside. The destination array is null.");
    }
}

/**
 * Inserts the source- into the destination array,
 * starting from the given index.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 * @param p6 the destination array count
 * @param p7 the destination array size
 */
void insert_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Insert array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer((void*) &r, p4, p6, (void*) GREATER_OR_EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Inserting elements outside the current array
            // boundaries is equivalent to just overwriting
            // elements, since none have to be moved.
            overwrite_array(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer((void*) &r, p4, p6, (void*) SMALLER_PRIMITIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            insert_array_inside(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }
}

/* ARRAY_INSERTER_SOURCE */
#endif
