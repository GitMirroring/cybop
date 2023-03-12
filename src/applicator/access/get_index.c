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

#ifndef GET_INDEX_SOURCE
#define GET_INDEX_SOURCE

//
// Library interface
//

#include "constant.h"
#include "executor.h"
#include "logger.h"

/**
 * Gets the index of the part within the whole.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_get_index(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply get index.");

    //
    // Declaration
    //

    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole part model item.
    void* wm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The index part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole part model item data, count.
    void* wmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* wmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get index part.
    get_part_name((void*) &i, p0, (void*) INDEX_GET_INDEX_ACCESS_LOGIC_CYBOL_NAME, (void*) INDEX_GET_INDEX_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get name part.
    get_part_name((void*) &n, p0, (void*) NAME_GET_INDEX_ACCESS_LOGIC_CYBOL_NAME, (void*) NAME_GET_INDEX_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get whole part.
    get_part_name((void*) &w, p0, (void*) WHOLE_GET_INDEX_ACCESS_LOGIC_CYBOL_NAME, (void*) WHOLE_GET_INDEX_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get name part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get whole part model item.
    copy_array_forward((void*) &wm, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get index part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get name part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get whole part model item data, count.
    copy_array_forward((void*) &wmd, wm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wmc, wm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // Determine index of searched part within whole.
    find_array(imd, wmd, nmd, nmc, wmc, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
}

/* GET_INDEX_SOURCE */
#endif
