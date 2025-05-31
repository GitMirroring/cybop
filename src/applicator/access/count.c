/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Counts the parts of a compound part.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_count(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply count.");

    //
    // Declaration
    //

    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The selection part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The filter part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The selection part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The filter part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The selection part model item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The filter part model item data, count.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* fmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_COUNT_ACCESS_LOGIC_CYBOL_NAME, (void*) COUNT_COUNT_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get part part.
    get_part_name((void*) &p, p0, (void*) PART_COUNT_ACCESS_LOGIC_CYBOL_NAME, (void*) PART_COUNT_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get selection part.
    get_part_name((void*) &s, p0, (void*) SELECTION_COUNT_ACCESS_LOGIC_CYBOL_NAME, (void*) SELECTION_COUNT_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get filter part.
    get_part_name((void*) &f, p0, (void*) FILTER_COUNT_ACCESS_LOGIC_CYBOL_NAME, (void*) FILTER_COUNT_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get selection part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get filter part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get selection part model item data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get filter part model item data, count.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fmc, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    //
    // Count certain elements of the given part.
    // If the given selection is null, then the
    // element count is returned without any comparison.
    //
    count_part(cmd, p, fmd, fmc, smd, smc);
}
