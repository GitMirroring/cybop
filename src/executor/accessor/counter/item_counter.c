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

//
// Library interface
//

#include "knowledge.h"
#include "logger.h"

/**
 * Counts certain elements of the given item.
 *
 * @param p0 the destination count
 * @param p1 the source item
 * @param p2 the filter data
 * @param p3 the filter count
 * @param p4 the selection data
 * @param p5 the selection count
 * @param p6 the format
 */
void count_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Count item.");

    // The data, count.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get data, count.
    copy_array_forward((void*) &d, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // CAUTION! Only parts with format "element/part" have
    // child nodes which again have names that may be filtered.
    // A part representing an array of primitive data like "number/integer" has children,
    // but those children (the single integer numbers) do not have a name to compare with.
    //
    // Ignoring the following test would lead to "Segmentation fault" errors in cyboi.
    //
    // Therefore, filtering for the selection makes sense
    // ONLY if the part's format is "element/part"
    // (which means the part's children are of that type).
    //
    compare_integer_equal((void*) &r, p6, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The part's format is "element/part".

        // CAUTION! Test both, filter AND selection for null.
        // Otherwise, a "Segmentation fault" might occur.
        if ((p2 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p4 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

            // Both, selection AND filter are given.

            // Count those elements in source item data array
            // whose name matches the filter string.
            count_array(p0, d, c, p2, p3, p4, p5);

        } else {

            // No selection OR no filter OR none of both is given.

            // Return element count without any comparison.
            copy_integer(p0, c);
        }

    } else {

        // The part's format is NOT "element/part".
        // It probably defines primitive data like "number/integer".

        // Return element count without any comparison.
        copy_integer(p0, c);
    }
}
