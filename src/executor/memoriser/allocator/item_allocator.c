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

#ifndef ITEM_ALLOCATOR_SOURCE
#define ITEM_ALLOCATOR_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/name/memory/item_memory_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../logger/logger.c"

/**
 * Allocates the item.
 *
 * @param p0 the item (pointer reference)
 * @param p1 the size
 * @param p2 the type
 */
void allocate_item(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** i = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate item.");

        // Allocate item.
        allocate_array(p0, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        // The data, count, size.
        void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate data, count, size.
        allocate_array((void*) &d, p1, p2);
        allocate_array((void*) &c, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_STATE_CYBOI_TYPE);
        allocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_STATE_CYBOI_TYPE);

        // Initialise count, size.
        // The data does NOT have to be initialised and remains empty.
        // The count is set to zero, since the model does not contain any elements yet.
        // The size is set to the value that was handed over as argument.
        copy_array_forward(c, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(s, p1, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Set data, count, size.
        copy_array_forward(*i, (void*) &d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*i, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) COUNT_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*i, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SIZE_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate item. The item is null.");
    }
}

/* ITEM_ALLOCATOR_SOURCE */
#endif
