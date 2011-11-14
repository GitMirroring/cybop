/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_ALLOCATOR_ITEM_APPENDER_SOURCE
#define PART_ALLOCATOR_ITEM_APPENDER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Allocates a part using the given model
 * and finally appends it to the destination.
 *
 * This is a convenience method ("syntactic sugar")
 * to avoid redundant code, e.g. when converting models
 * with a lot of string processing going on.
 *
 * @param p0 the destination item
 * @param p1 the source name
 * @param p2 the source name count
 * @param p3 the source type
 * @param p4 the source type count
 * @param p5 the source model
 * @param p6 the source model count
 * @param p7 the source properties
 * @param p8 the source properties count
 */
void append_item_allocate_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p3);

    // Fill part.
    overwrite_part_element(p, p1, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, p3, (void*) INTEGER_STATE_CYBOI_TYPE, p4, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, p5, p3, p6, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, p7, (void*) PART_STATE_CYBOI_TYPE, p8, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Append part to destination.
    append_item_element(p0, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* PART_ALLOCATOR_ITEM_APPENDER_SOURCE */
#endif
