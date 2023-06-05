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

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Copies a source item array to the destination array.
 *
 * Example:
 *
 * void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
 * get_item((void*) &a, item, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j, (void*) DATA_ITEM_STATE_CYBOI_NAME);
 *
 * @param p0 the destination array
 * @param p1 the source item
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination array index
 * @param p5 the source item index
 * @param p6 the source item metadata index
 */
void get_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get item.");

    //
    // CAUTION! Do NOT simplify the lines below to one line like:
    // copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);
    // If doing this, the parametres type, count, index etc.
    // will not be considered.
    //

    // The source item array.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source item array.
    copy_array_forward((void*) &a, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p6, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a data item array.
        //

        // The count is only needed if the item array is "data".
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get source item array count.
        copy_array_forward((void*) &c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Reset comparison result.
        copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // CAUTION! The given source item index HAS TO BE
        // less than the source item data array count.
        // Otherwise, array boundaries might get crossed
        // and false pointer values returned.
        //
        compare_integer_less((void*) &r, p5, c);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Reset comparison result.
            copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            //
            // CAUTION! The given source item index MUST NOT be negative.
            // Otherwise, array boundaries might get crossed
            // and false pointer values returned.
            //
            compare_integer_greater_or_equal((void*) &r, p5, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Copy source item data array to destination array.
                copy_array_forward(p0, a, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get item. The source index is smaller than zero.");
            }

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get item. The source index is greater than or equal to the source item count.");
        }

    } else {

        //
        // This is a count or size item array.
        //

        //
        // CAUTION! The count or size do NOT have
        // a count or size themselves. They are just
        // primitive data values with a fixed size of one.
        // Therefore, nothing has to be checked here.
        //

        // Copy source item count or size array to destination array.
        copy_array_forward(p0, a, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5);
    }
}
