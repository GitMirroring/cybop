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
 * Indicates whether or not the part is empty (i.e. its element count is zero)
 * or data exist within (i.e. its element count is greater than zero).
 *
 * The kind of comparison depends upon the given operation type
 * ("access/indicate-empty" OR "access/indicate-exists").
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the operation type
 */
void apply_indicate(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply indicate.");

    //
    // Declaration
    //

    // The result part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get result part.
    get_part_name((void*) &r, p0, (void*) RESULT_INDICATE_ACCESS_LOGIC_CYBOL_NAME, (void*) RESULT_INDICATE_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get part part.
    get_part_name((void*) &p, p0, (void*) PART_INDICATE_ACCESS_LOGIC_CYBOL_NAME, (void*) PART_INDICATE_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get result part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get result part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // Indicate fill level of part.
    indicate_part(rmd, p, p5);
}
