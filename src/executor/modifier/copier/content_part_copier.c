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

#ifndef CONTENT_PART_COPIER_SOURCE
#define CONTENT_PART_COPIER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
//
// CAUTION! Do NOT include the following source code modules:
// "../../../executor/memoriser/allocator/part_allocator.c"
// "../../../executor/modifier/copier/array_copier.c"
// "../../../executor/modifier/copier/part_copier.c"
// They would cause circular dependencies.
// Therefore, forward declarations are used instead.
//
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void allocate_part(void* p0, void* p1, void* p2);
void copy_array_elements_forward(void* p0, void* p1, void* p2, void* p3);
void copy_part(void* p0, void* p1);

/**
 * Copies the part content (child nodes).
 *
 * This is DEEP COPYING, also called CLONING.
 *
 * Essentially, this function does nothing else than combining:
 * - allocation of destination
 * - copying content from source to destination
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source part
 */
void copy_part_content(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** s = (void**) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** d = (void**) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy part content.");

            // The source part type, model item.
            void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The source part type, model item data, count.
            void* std = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get source part type, model item.
            copy_array_forward((void*) &st, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &sm, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            // Get source part type, model item data, count.
            copy_array_forward((void*) &std, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Allocate destination part.
            allocate_part(p0, smc, std);

            // Copy details from source- into destination part.
            copy_part(*d, *s);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy part content. The destination part is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy part content. The source part is null.");
    }
}

/* CONTENT_PART_COPIER_SOURCE */
#endif
