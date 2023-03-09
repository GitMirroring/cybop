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

#ifndef ITEM_SETTER_SOURCE
#define ITEM_SETTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Copies the source array to a destination item array.
 *
 * Example:
 *
 * void* a = ...
 * set_item(item, (void*) &a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &j, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
 *
 * @param p0 the destination item
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination item index
 * @param p5 the source array index
 * @param p6 the destination item metadata index
 */
void set_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set item.");

    //
    // CAUTION! Do NOT simplify the lines below to one line like:
    // copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);
    // If doing this, the parametres type, count, index etc.
    // will not be considered.
    //

    // The source item array.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination item array.
    copy_array_forward((void*) &a, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p6, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a data item array.
        //

        // The count is only needed if the item array is "data".
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get destination item array count.
        copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Reset comparison result.
        copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // CAUTION! The given destination item index HAS TO BE
        // less than the destination item data array count.
        // Otherwise, array boundaries might get crossed
        // and false pointer values returned.
        //
        compare_integer_less((void*) &r, p4, c);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Reset comparison result.
            copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            //
            // CAUTION! The given destination item index MUST NOT be negative.
            // Otherwise, array boundaries might get crossed
            // and false pointer values returned.
            //
            compare_integer_greater_or_equal((void*) &r, p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Copy source array to destination item data array.
                copy_array_forward(a, p1, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set item. The destination index is smaller than zero.");
            }

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set item. The destination index is greater than or equal to the destination item count.");
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

        // Copy source array to destination item count or size array.
        copy_array_forward(a, p1, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5);
    }
}

/* ITEM_SETTER_SOURCE */
#endif
