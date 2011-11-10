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

#ifndef PART_DEALLOCATOR_SOURCE
#define PART_DEALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the part.
 *
 * @param p0 the part (Hand over as reference!)
 * @param p1 the size
 * @param p2 the type
 */
void deallocate_part(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** p = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate part.");

        // The name, type, model, properties.
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* d = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get name, type, model, properties.
        copy_array_forward((void*) &n, *p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
        copy_array_forward((void*) &a, *p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
        copy_array_forward((void*) &m, *p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
        copy_array_forward((void*) &d, *p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) PROPERTIES_PART_MEMORY_NAME);

        // Deallocate name, type, model, properties.
        deallocate_item((void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE);
        deallocate_item((void*) &a, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE);
        deallocate_item((void*) &m, p1, p2);
        deallocate_item((void*) &d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_MEMORY_TYPE);

        // Deallocate part.
        deallocate_array(p0, (void*) PART_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_MEMORY_TYPE);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate part. The part is null.");
    }
}

/* PART_DEALLOCATOR_SOURCE */
#endif
