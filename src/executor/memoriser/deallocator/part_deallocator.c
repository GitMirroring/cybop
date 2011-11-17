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
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void reference_array(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Deallocates the part.
 *
 * @param p0 the part (pointer reference)
 * @param p1 the size
 * @param p2 the type
 */
void deallocate_part(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** part = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate part.");

        // The references, name, type, model, properties.
        void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The data, size.
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get references, name, type, model, properties.
        copy_array_forward((void*) &r, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) REFERENCES_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &n, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &t, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &m, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &p, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
        // Get data, size.
        copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Decrement reference count of child parts for rubbish (garbage) collection.
        reference(md, (void*) SUBTRACT_LOGIC_CYBOI_TYPE, mc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, td);

        // Deallocate references, name, type, model, properties.
        deallocate_item((void*) &r, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE);
        deallocate_item((void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
        deallocate_item((void*) &t, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE);
        deallocate_item((void*) &m, p1, p2);
        deallocate_item((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE);

        // Deallocate part.
        deallocate_array(p0, (void*) PART_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate part. The part is null.");
    }
}

/* PART_DEALLOCATOR_SOURCE */
#endif
