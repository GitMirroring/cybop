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

#ifndef ITEM_FINDER_SOURCE
#define ITEM_FINDER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../executor/calculator/basic/integer/multiply_integer_calculator.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../logger/logger.c"

/**
 * Tries to find the searched array in the investigated item.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated item
 * @param p2 the searched array
 * @param p3 the type
 * @param p4 the searched array count
 * @param p5 the investigated item element index
 */
void find_item_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find item element.");

    // The investigated item element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get investigated item element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p5);

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_integer((void*) &r, p5, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // This is a data item element.

        // The investigated item count.
        // CAUTION! It is only needed because this is a data item element.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get investigated item count.
        copy_array_forward((void*) &c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Find the searched array in the investigated item data array.
        find_array(p0, e, p2, p3, c, p4);

    } else {

        // This is a count or size item element.

        // Find the searched array in the investigated item data array.
        find_array(p0, e, p2, p3, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    }
}

/**
 * Tries to find the searched item in the investigated item.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated item
 * @param p2 the searched item
 * @param p3 the type
 */
void find_item(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find item.");

    // The investigated data, count.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ic = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The searched data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get investigated data, count.
    copy_array_forward((void*) &id, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ic, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get searched data, count.
    copy_array_forward((void*) &sd, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Find the searched item data array in the investigated item data array.
    find_array(p0, id, sd, p3, ic, sc);
}

/* ITEM_FINDER_SOURCE */
#endif
