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

#ifndef ITEM_FINDER_SOURCE
#define ITEM_FINDER_SOURCE

#include <stdlib.h>
#include <string.h>

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../logger/logger.c"

/**
 * Finds a part with the searched name in the investigated item.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated item (each element pointing to a part)
 * @param p2 the searched name data
 * @param p3 the searched name count
 */
void find_item_element(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find item element.");

    // The investigated item data, count.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get investigated item data, count.
    copy_array_forward((void*) &d, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Find the searched name array in the investigated item data array.
    find_array(p0, d, p2, c, p3);
}

/**
 * Finds a part with the searched name in the investigated item.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated item (each element pointing to a part)
 * @param p2 the searched name item
 */
void find_item(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find item.");

    // The investigated item data, count.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ic = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The searched name item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get investigated item data, count.
    copy_array_forward((void*) &id, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ic, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get searched name item data, count.
    copy_array_forward((void*) &sd, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Find the searched name item data array in the investigated item data array.
    find_array(p0, id, sd, ic, sc);
}

/* ITEM_FINDER_SOURCE */
#endif
