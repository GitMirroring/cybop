/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ITEM_INSERTER_SOURCE
#define ITEM_INSERTER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../executor/modifier/inserter/array_inserter.c"
#include "../../../logger/logger.c"

/**
 * Inserts the source array into the destination item element
 * given by the destination item element index.
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
 * @param p6 the destination item element index
 */
void insert_item_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Insert item element.");

    // The destination item element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination item element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_integer((void*) &r, p6, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // This is a data item element.

        // The count and size are only needed if the item element is "data".
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get destination item element count, size.
        copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

        // Insert array as element of the item container.
        // Since this is a data item element, the count and size are set inside.
        insert_array((void*) &e, p1, p2, p3, p4, p5, c, s);

        // Set data array as element of the item container.
        // CAUTION! This IS NECESSARY, because reallocation may have happened
        // above which would return a completely new data array (memory area).
        // CAUTION! It is NOT necessary to also set count and size,
        // since only their references were used above to modify values.
        copy_array_forward(p0, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        // This is a count or size item element.

        // Insert array as element of the item container.
        // CAUTION! It never gets reallocated, since count and size
        // are integer primitives. Setting the count array or size array
        // as element of the item container is therefore not necessary.
        insert_array((void*) &e, p1, p2, p3, p4, p5, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }
}

/**
 * Inserts the source into the destination.
 *
 * The count and size are adjusted automatically.
 *
 * @param p0 the destination item
 * @param p1 the source item
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 */
void insert_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Insert item.");

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

    // Insert source- into destination item data array.
    insert_array((void*) &dd, sd, p2, p3, p4, p5, dc, ds);

    // Set data as item element.
    // CAUTION! This IS NECESSARY, because reallocation may have happened
    // above which would return a completely new data array (memory area).
    // CAUTION! It is NOT necessary to also set count and size,
    // since only their references were used above to modify values.
    copy_array_forward(p0, (void*) &dd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* ITEM_INSERTER_SOURCE */
#endif
