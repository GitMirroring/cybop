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

#ifndef PART_ALLOCATOR_SOURCE
#define PART_ALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../logger/logger.c"

/**
 * Allocates the part.
 *
 * @param p0 the part (pointer reference)
 * @param p1 the size
 * @param p2 the type
 */
void allocate_part(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** p = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate part.");

        // Allocate part.
        allocate_array(p0, (void*) PART_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        // The references, name, type, model, properties.
        void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate references, name, type, model, properties.
        allocate_item((void*) &r, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE);
        allocate_item((void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
        allocate_item((void*) &t, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE);
        allocate_item((void*) &m, p1, p2);
        allocate_item((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE);

        // Set references, name, type, model, properties.
        copy_array_forward(*p, (void*) &r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) REFERENCES_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NAME_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TYPE_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MODEL_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*p, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PROPERTIES_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate part. The part is null.");
    }
}

/* PART_ALLOCATOR_SOURCE */
#endif
