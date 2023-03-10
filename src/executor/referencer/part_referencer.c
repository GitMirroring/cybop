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

#ifndef PART_REFERENCER_SOURCE
#define PART_REFERENCER_SOURCE

#include "../../executor/calculator/integer_calculator.c"
#include "../../executor/comparator/integer/less_integer_comparator.c"
#include "../../executor/copier/array/forward_array_copier.c"
#include "../../executor/memoriser/deallocator/part_deallocator.c"
#include "../../logger/logger.c"

/**
 * Increments or decrements the part's reference count.
 *
 * CAUTION! Deallocates the part if its reference count is zero.
 *
 * @param p0 the array
 * @param p1 the operation type
 * @param p2 the index
 */
void reference_part(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Reference part.");

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The references, type, model item.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The references, type, model item data, size.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ms = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int res = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //?? fwprintf(stdout, L"Debug: Reference part. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Reference part. *p0: %i\n", *((void**) p0));

    // Get part at index.
    copy_array_forward((void*) &p, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);
    // Get references, type, model item.
    copy_array_forward((void*) &r, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) REFERENCES_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &t, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &m, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get references, type, model item data, size.
    copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ms, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

/*??
    fwprintf(stdout, L"Debug: Reference part. p: %i\n", p);
    fwprintf(stdout, L"Debug: Reference part. r: %i\n", r);
    fwprintf(stdout, L"Debug: Reference part. t: %i\n", t);
    fwprintf(stdout, L"Debug: Reference part. m: %i\n", m);
    fwprintf(stdout, L"Debug: Reference part. rd: %i\n", rd);
    fwprintf(stdout, L"Debug: Reference part. *rd: %i\n", *((int*) rd));
*/

    // Increment or decrement references counter.
    calculate_integer(rd, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p1);

    //?? fwprintf(stdout, L"Debug: Reference part. rd: %i\n", rd);
    //?? fwprintf(stdout, L"Debug: Reference part. *rd: %i\n", *((int*) rd));

    if (res == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &res, rd, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (res != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deallocate_part((void*) &p);
        }
    }

    if (res == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &res, rd, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (res != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not reference part. The references data is negative.");
            fwprintf(stdout, L"Error: Could not reference part. The references data is negative. *rd: %i\n", rd);
            fwprintf(stdout, L"Error: Could not reference part. The references data is negative. *rd: %i\n", *((int*) rd));
        }
    }
}

/* PART_REFERENCER_SOURCE */
#endif
