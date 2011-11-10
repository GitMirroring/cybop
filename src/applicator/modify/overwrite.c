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

#ifndef OVERWRITE_SOURCE
#define OVERWRITE_SOURCE

#include "../../applicator/memoriser/copying/boolean_copying_memoriser.c"
#include "../../applicator/memoriser/copying/character_vector_copying_memoriser.c"
#include "../../applicator/memoriser/copying/integer_vector_copying_memoriser.c"
#include "../../constant/type/cybol/logicvalue_cybol_type.c"
#include "../../constant/type/cybol/number_cybol_type.c"
#include "../../constant/type/cybol/text_cybol_type.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/memory/copy_memory_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

/**
 * Overwrites the destination- with the source part.
 *
 * Expected parametres:
 * - destination (required): the destination part
 * - source (required): the source part
 * - type (required): the type of data
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be overwritten
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start copying elements to
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start copying elements from
 * - adjust (optional; if null, the destination will NOT be adjusted):
 *   the flag indicating whether or not the destination shall be adjusted to
 *   destination_index + count_of_elements_to_be_copied;
 *   otherwise, the destination count either remains as is or gets extended,
 *   if the number of elements exceeds the destination count, in order to avoid
 *   memory errors caused by crossing array boundaries
 *
 * @param p0 the parametres array (signal/ operation part properties with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_overwrite(void* p0, int* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply overwrite.");

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
    // The adjust part.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;

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
    // The adjust part model.
    void* adm = *NULL_POINTER_STATE_CYBOI_MODEL;

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
    // The adjust part model data.
    void* admd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part.
    get_name_array((void*) &d, p0, (void*) DESTINATION_OVERWRITE_OPERATION_CYBOL_NAME, (void*) DESTINATION_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get source part.
    get_name_array((void*) &s, p0, (void*) SOURCE_OVERWRITE_OPERATION_CYBOL_NAME, (void*) SOURCE_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get type part.
    get_name_array((void*) &a, p0, (void*) TYPE_OVERWRITE_OPERATION_CYBOL_NAME, (void*) TYPE_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get count part.
    get_name_array((void*) &c, p0, (void*) COUNT_OVERWRITE_OPERATION_CYBOL_NAME, (void*) COUNT_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get destination index part.
    get_name_array((void*) &di, p0, (void*) DESTINATION_INDEX_OVERWRITE_OPERATION_CYBOL_NAME, (void*) DESTINATION_INDEX_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get source index part.
    get_name_array((void*) &si, p0, (void*) SOURCE_INDEX_OVERWRITE_OPERATION_CYBOL_NAME, (void*) SOURCE_INDEX_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get adjust part.
    get_name_array((void*) &ad, p0, (void*) ADJUST_OVERWRITE_OPERATION_CYBOL_NAME, (void*) ADJUST_OVERWRITE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get source part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get type part model.
    copy_array_forward((void*) &am, a, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get count part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get destination index part model.
    copy_array_forward((void*) &dim, di, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get source index part model.
    copy_array_forward((void*) &sim, si, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get adjust part model.
    copy_array_forward((void*) &adm, ad, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Get source part model count.
    copy_array_forward((void*) &smc, sm, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    // Get type part model data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get count part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get destination index part model data.
    copy_array_forward((void*) &dimd, dim, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get source index part model data.
    copy_array_forward((void*) &simd, sim, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    // Get adjust part model data.
    copy_array_forward((void*) &admd, adm, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int destination_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int source_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int adjust = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

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
    // Set adjust flag to the value that was given as parametre.
    copy_integer((void*) &adjust, admd);

    // Overwrite the destination- with the source part.
    overwrite_part(d, s, amd, (void*) &count, (void*) &destination_index, (void*) &source_index, (void*) &adjust);
}

/* OVERWRITE_SOURCE */
#endif
