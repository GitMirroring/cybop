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

#ifndef PART_FINDER_SOURCE
#define PART_FINDER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/copier/array/forward_array_copier.c"
#include "logger.h"

/**
 * Finds a part with the searched name in the investigated part.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated part (each element pointing to a part)
 * @param p2 the searched name data
 * @param p3 the searched name count
 * @param p4 the investigated index
 */
void find_part_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find part element.");

    // The investigated part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get investigated part.
    copy_array_forward((void*) &i, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p4);

    // Find the searched item in the investigated item.
    find_item_element(p0, i, p2, p3);
}

/**
 * Finds a part with the searched name in the investigated part.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated part (each element pointing to a part)
 * @param p2 the searched name part
 */
void find_part(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find part.");

    // The investigated part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The searched name part name.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get investigated part.
    copy_array_forward((void*) &i, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get searched name part name.
    copy_array_forward((void*) &s, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);

    // Find the searched name item in the investigated item.
    find_item(p0, i, s);
}

/* PART_FINDER_SOURCE */
#endif
