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

#ifndef PART_GETTER_SOURCE
#define PART_GETTER_SOURCE

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Copies a source part item data array to the destination array.
 *
 * Example:
 *
 * void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
 * get_part((void*) &a, part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j, (void*) MODEL_PART_STATE_CYBOI_NAME);
 *
 * @param p0 the destination array
 * @param p1 the source part
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination array index
 * @param p5 the source part index
 * @param p6 the source part metadata index
 */
void get_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get part.");

    // The source part metadata item.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source part metadata item.
    copy_array_forward((void*) &i, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    // Copy source part metadata item data array to destination array.
    get_item(p0, i, p2, p3, p4, p5, (void*) DATA_ITEM_STATE_CYBOI_NAME);
}

/* PART_GETTER_SOURCE */
#endif
