/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ITEM_MODIFIER_SOURCE
#define ITEM_MODIFIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/modifier/array_modifier.c"
#include "../../logger/logger.c"

/**
 * Modifies the destination item element given by the
 * destination item element index with the source array.
 *
 * The destination item element may be either of:
 * data, count, size.
 *
 * @param p0 the destination item
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination item index
 * @param p5 the source array index
 * @param p6 the adjust count flag
 * @param p7 the model flag
 * @param p8 the properties flag
 * @param p9 the operation type
 * @param p10 the destination item element index
 */
void modify_item_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify item element.");

    // The destination item element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination item element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p10);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p10, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // This is a data item element.

        // The count and size are only needed if the item element is "data".
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get destination item element count, size.
        copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

        // Modify array as element of the item container.
        // Since this is a data item element, the count and size are set inside.
        modify_array((void*) &e, p1, p2, p3, p4, p5, c, s, p6, p7, p8, p9);

        // Set data array as element of the item container.
        // CAUTION! This IS NECESSARY, because reallocation may have happened
        // above which would return a completely new data array (memory area).
        // CAUTION! It is NOT necessary to also set count and size,
        // since only their references were used above to modify values.
        copy_array_forward(p0, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        // This is a count or size item element.

        // Modify array as element of the item container.
        // CAUTION! It never gets reallocated, since count and size
        // are integer primitives. Setting the count array or size array
        // as element of the item container is therefore not necessary.
        modify_array((void*) &e, p1, p2, p3, p4, p5, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6, p7, p8, p9);
    }
}

/**
 * Modifies the destination- with the source item.
 *
 * The count and size are adjusted automatically.
 *
 * @param p0 the destination item
 * @param p1 the source item
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 * @param p6 the adjust count flag
 * @param p7 the model flag
 * @param p8 the properties flag
 * @param p9 the operation type
 */
void modify_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify item.");

    // The destination data, count, size.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source data.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination data, count, size.
    copy_array_forward((void*) &dd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ds, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);
    // Get source data.
    copy_array_forward((void*) &sd, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Modify destination- with source item data array.
    modify_array((void*) &dd, sd, p2, p3, p4, p5, dc, ds, p6, p7, p8, p9);

    // Set data as item element.
    // CAUTION! This IS NECESSARY, because reallocation may have happened
    // above which would return a completely new data array (memory area).
    // CAUTION! It is NOT necessary to also set count and size,
    // since only their references were used above to modify values.
    copy_array_forward(p0, (void*) &dd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* ITEM_MODIFIER_SOURCE */
#endif
