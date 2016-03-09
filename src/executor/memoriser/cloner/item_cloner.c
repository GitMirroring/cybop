/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ITEM_CLONER_SOURCE
#define ITEM_CLONER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Clones the source item into the destination item.
 *
 * Essentially, the "clone" function does nothing else than combining:
 * - allocation of a destination or cloning of a source element
 * - copying content from source to destination
 *
 * @param p0 the destination item (pointer reference)
 * @param p1 the source item
 * @param p2 the type
 */
void clone_item(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** i = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Clone item.");

        // The destination item data, count, size.
        void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source item data, count.
        // CAUTION! The source item size is NOT needed here,
        // since the source item count is assigned TWICE,
        // once for the destination item COUNT and once more
        // for the destination item SIZE.
        // This helps avoid allocation of unneeded memory space,
        // since count keeps the actual number of elements.
        void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get source item data, count, size.
        copy_array_forward((void*) &sd, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sc, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Clone source item data, count, size.
        clone_array((void*) &dd, sd, sc, p2);
        clone_array((void*) &dc, sc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        clone_array((void*) &ds, sc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Allocate destination item.
        allocate_array(p0, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        // Set data, count, size.
        copy_array_forward(*i, (void*) &dd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*i, (void*) &dc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) COUNT_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(*i, (void*) &ds, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SIZE_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not clone item. The item is null.");
    }
}

/* ITEM_CLONER_SOURCE */
#endif
