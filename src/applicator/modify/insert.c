/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INSERT_SOURCE
#define INSERT_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/modification/insert_modification_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/modifier/inserter/part_inserter.c"
#include "../../logger/logger.c"

/**
 * Inserts the source- into the destination part.
 *
 * Expected parametres:
 * - destination (required): the destination part
 * - source (required): the source part
 * - type (required): the type of data
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be inserted
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start copying elements to
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start copying elements from
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_insert(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply insert.");

    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part.
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part.
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part model.
    void* dim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model.
    void* sim = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model count.
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part model data.
    void* dimd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model data.
    void* simd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part.
    get_part_name((void*) &d, p0, (void*) DESTINATION_INSERT_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_INSERT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source part.
    get_part_name((void*) &s, p0, (void*) SOURCE_INSERT_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_INSERT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get type part.
    get_part_name((void*) &a, p0, (void*) TYPE_INSERT_MODIFICATION_LOGIC_CYBOL_NAME, (void*) TYPE_INSERT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_INSERT_MODIFICATION_LOGIC_CYBOL_NAME, (void*) COUNT_INSERT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get destination index part.
    get_part_name((void*) &di, p0, (void*) DESTINATION_INDEX_INSERT_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_INDEX_INSERT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source index part.
    get_part_name((void*) &si, p0, (void*) SOURCE_INDEX_INSERT_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_INDEX_INSERT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get source part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination index part model.
    copy_array_forward((void*) &dim, di, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source index part model.
    copy_array_forward((void*) &sim, si, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get source part model count.
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get type part model data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get destination index part model data.
    copy_array_forward((void*) &dimd, dim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source index part model data.
    copy_array_forward((void*) &simd, sim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int destination_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int source_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the source part model count by default.
    copy_integer((void*) &count, smc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit destination index that was given as parametre.
    copy_integer((void*) &destination_index, dimd);
    // Use the explicit source index that was given as parametre.
    copy_integer((void*) &source_index, simd);

    // Insert the source- into the destination part.
    insert_part(d, s, amd, (void*) &count, (void*) &destination_index, (void*) &source_index);
}

/* INSERT_SOURCE */
#endif
