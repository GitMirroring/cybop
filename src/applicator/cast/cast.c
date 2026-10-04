/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Casts a value from one type to another.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the operation type
 */
void apply_cast(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply cast.");

    //
    // Declaration
    //

    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part.
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part.
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The destination part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part type, model item.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part model item.
    void* dim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model item.
    void* sim = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The destination part model item count.
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part type, model item data, count.
    void* std = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part model item data.
    void* dimd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model item data.
    void* simd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get destination part.
    get_part_name((void*) &d, p0, (void*) DESTINATION_CAST_LOGIC_CYBOL_NAME, (void*) DESTINATION_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source part.
    get_part_name((void*) &s, p0, (void*) SOURCE_CAST_LOGIC_CYBOL_NAME, (void*) SOURCE_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_CAST_LOGIC_CYBOL_NAME, (void*) COUNT_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get destination index part.
    get_part_name((void*) &di, p0, (void*) DESTINATION_INDEX_CAST_LOGIC_CYBOL_NAME, (void*) DESTINATION_INDEX_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source index part.
    get_part_name((void*) &si, p0, (void*) SOURCE_INDEX_CAST_LOGIC_CYBOL_NAME, (void*) SOURCE_INDEX_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get destination part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source part type, model item.
    copy_array_forward((void*) &st, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination index part model item.
    copy_array_forward((void*) &dim, di, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source index part model item.
    copy_array_forward((void*) &sim, si, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get destination part model item count.
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get source part type, model item data, count.
    copy_array_forward((void*) &std, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get destination index part model item data.
    copy_array_forward((void*) &dimd, dim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source index part model item data.
    copy_array_forward((void*) &simd, sim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // The default values.
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int destination_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int source_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //

    // Use the source part model count by default.
    copy_integer((void*) &count, smc);
    // Determine minimum of left and right operand.
    calculate_integer_minimum((void*) &count, dmc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit destination index that was given as parametre.
    copy_integer((void*) &destination_index, dimd);
    // Use the explicit source index that was given as parametre.
    copy_integer((void*) &source_index, simd);

    //
    // Functionality
    //

    // Cast value by applying operation.
    cast_part(d, s, std, p5, (void*) &count, (void*) &destination_index, (void*) &source_index);
}
