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

#ifndef PART_FINDER_SOURCE
#define PART_FINDER_SOURCE

#include "../../../constant/type/cybol/number_cybol_type.c"
#include "../../../constant/type/cybol/path_cybol_type.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Tries to find the searched array in the investigated part.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated part
 * @param p2 the searched array
 * @param p3 the type
 * @param p4 the searched array count
 * @param p5 the investigated part element index
 */
void find_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find part element.");

    // The investigated part element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get investigated part element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p5);

    // Find the searched array in the investigated part model item.
    find_item_element(p0, e, p2, p3, p4, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Tries to find the searched part in the investigated part.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated part
 * @param p2 the searched part
 * @param p3 the type
 */
void find_part(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find part.");

    // The investigated model.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The searched model.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get investigated model.
    copy_array_forward((void*) &im, p1, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get searched model.
    copy_array_forward((void*) &sm, p2, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Find the searched item in the investigated item.
    find_item(p0, im, sm, p3);
}

/* PART_FINDER_SOURCE */
#endif
