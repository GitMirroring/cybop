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

#ifndef PART_CASTER_SOURCE
#define PART_CASTER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/caster/item_caster.c"
#include "../../executor/copier/array/forward_array_copier.c"
#include "../../logger/logger.c"

/**
 * Casts elements of the source- into the destination part.
 *
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the source type
 * @param p3 the operation (destination) type
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 */
void cast_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cast part.");

    // The destination model.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source model.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination model.
    copy_array_forward((void*) &dm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source model.
    copy_array_forward((void*) &sm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Cast elements of the source- into the destination item.
    cast_item(dm, sm, p2, p3, p4, p5, p6);
}

/* PART_CASTER_SOURCE */
#endif
