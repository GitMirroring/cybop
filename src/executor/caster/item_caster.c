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
 * Compares if given count is smaller or equal to the items' count.
 *
 * @param p0 the destination data
 * @param p1 the source data
 * @param p2 the source type
 * @param p3 the operation (destination) type
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 * @param p7 the destination count
 * @param p8 the source count
 */
/*??
void cast_item_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cast item count.");

    //
    // CAUTION! The data counts do NOT have to be identical,
    // as long as the given count is smaller than both of them,
    // the corresponding elements may be casted.
    //
    // CAUTION! The sizes do NOT matter anyway,
    // since they just represent allocated memory,
    // but only the count as actual number of elements is of interest.
    //

    // The destination count comparison result.
    int d = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The source count comparison result.
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_less_or_equal((void*) &d, p4, p7);
    compare_integer_less_or_equal((void*) &s, p4, p8);

    if (s != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (d != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            cast_array(p0, p1, p2, p3, p4, p5, p6);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast item count. The given count is greater than the destination count.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast item count. The given count is greater than the source count.");
    }
}
*/

/**
 * Casts elements of the source item to the destination item.
 *
 * @param p0 the destination item
 * @param p1 the source item
 * @param p2 the source type
 * @param p3 the operation (destination) type
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 */
void cast_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cast item.");

    // The destination data, count.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get destination data, count.
    copy_array_forward((void*) &dd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get source data, count.
    copy_array_forward((void*) &sd, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    verify_double_index_count((void*) &r, p4, p5, p6, dc, sc);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        cast_array(dd, sd, p2, p3, p4, p5, p6);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast item. The sum of the given index and count is outside the data array count.");
    }
}
