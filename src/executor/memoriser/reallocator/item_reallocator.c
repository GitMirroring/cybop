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

#ifndef ITEM_REALLOCATOR_SOURCE
#define ITEM_REALLOCATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "logger.h"

/**
 * Reallocates the item.
 *
 * CAUTION! Do NOT hand over the item as pointer reference!
 * Its main structure does NOT get reallocated,
 * but only the internal data array.
 *
 * @param p0 the item
 * @param p1 the size
 * @param p2 the type
 */
void reallocate_item(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Reallocate item.");

    // The data, count, size.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination item data, count, size.
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    //
    // Reallocate data.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    reallocate_array((void*) &d, c, p1, p2);

    if (d != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // Set data.
        //
        // CAUTION! This IS necessary since the data array
        // got reallocated and a new memory pointer returned.
        //
        // CAUTION! The count and size do NOT have to be set,
        // since they were not reallocated and thus
        // still point to the same memory area.
        //
        copy_array_forward(p0, (void*) &d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        //
        // Set size.
        //
        // CAUTION! The count remains the same.
        //
        copy_integer(s, p1);

    } else {

        //
        // Reasons might be:
        // - given size is zero
        // - given size is negative
        // - no more system heap memory
        //
        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not reallocate item. The data is null.");
        fwprintf(stdout, L"Warning: Could not reallocate item. The data is null. d: %p\n", d);
        fwprintf(stdout, L"Hint: This should NEVER happen. Is the given size zero or negative? Is the system heap out of memory?\n");
    }
}

/* ITEM_REALLOCATOR_SOURCE */
#endif
