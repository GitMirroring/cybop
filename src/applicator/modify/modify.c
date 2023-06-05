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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "applicator.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Modifies the destination- with the source part.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the operation type
 */
void apply_modify(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply modify.");

    //
    // Declaration
    //

    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The move part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part.
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part.
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The repetition part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The searchterm part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination properties part.
    void* dpr = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The source properties part.
    //
    // CAUTION! Do NOT use the variable name "sp" for this flag,
    // since it gets used for the actual source properties item below.
    //
    void* spr = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The destination part type item.
    void* dt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part type, model, properties item.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The move part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part model item.
    void* dim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model item.
    void* sim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part model item.
    void* adm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The repetition part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The searchterm part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination properties part model item.
    void* dprm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source properties part model item.
    void* sprm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The destination part type item data.
    void* dtd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part type, model, properties item data, count.
    void* std = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* spc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The move part model item data.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination index part model item data.
    void* dimd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source index part model item data.
    void* simd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The adjust part model item data.
    void* admd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The repetition part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The searchterm part model item data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination properties model item data.
    void* dprmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source properties model item data.
    void* sprmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get destination part.
    get_part_name((void*) &d, p0, (void*) DESTINATION_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source part.
    get_part_name((void*) &s, p0, (void*) SOURCE_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get move part.
    get_part_name((void*) &m, p0, (void*) MOVE_MODIFICATION_LOGIC_CYBOL_NAME, (void*) MOVE_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_MODIFICATION_LOGIC_CYBOL_NAME, (void*) COUNT_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get destination index part.
    get_part_name((void*) &di, p0, (void*) DESTINATION_INDEX_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_INDEX_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source index part.
    get_part_name((void*) &si, p0, (void*) SOURCE_INDEX_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_INDEX_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get adjust part.
    get_part_name((void*) &ad, p0, (void*) ADJUST_MODIFICATION_LOGIC_CYBOL_NAME, (void*) ADJUST_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get repetition part.
    get_part_name((void*) &r, p0, (void*) REPETITION_MODIFICATION_LOGIC_CYBOL_NAME, (void*) REPETITION_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get searchterm part.
    get_part_name((void*) &t, p0, (void*) SEARCHTERM_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SEARCHTERM_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get destination properties part.
    get_part_name((void*) &dpr, p0, (void*) DESTINATION_PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source properties part.
    get_part_name((void*) &spr, p0, (void*) SOURCE_PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_PROPERTIES_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get destination part type item.
    copy_array_forward((void*) &dt, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Get source part type, model, properties item.
    copy_array_forward((void*) &st, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sp, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get move part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination index part model item.
    copy_array_forward((void*) &dim, di, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source index part model item.
    copy_array_forward((void*) &sim, si, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get adjust part model item.
    copy_array_forward((void*) &adm, ad, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get repetition part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get searchterm part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination properties model item.
    copy_array_forward((void*) &dprm, dpr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source properties model item.
    copy_array_forward((void*) &sprm, spr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get destination part type item data.
    copy_array_forward((void*) &dtd, dt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source part type, model, properties item data, count.
    copy_array_forward((void*) &std, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &spd, sp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &spc, sp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get move part model item data.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get destination index part model item data.
    copy_array_forward((void*) &dimd, dim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source index part model item data.
    copy_array_forward((void*) &simd, sim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get adjust part model item data.
    copy_array_forward((void*) &admd, adm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get repetition part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get searchterm part model item data, count.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tmc, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get destination properties model item data.
    copy_array_forward((void*) &dprmd, dprm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source properties model item data.
    copy_array_forward((void*) &sprmd, sprm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    void* source_array_data = smd;
    void* source_array_count = smc;
    int destination_type = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int destination_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int source_type = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    int source_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    //
    // CAUTION! Set adjust count flag to "true" by default,
    // to avoid memory errors.
    //
    int adjust = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
    int destination_part_item_index = *MODEL_PART_STATE_CYBOI_NAME;
    //
    // CAUTION! This variable is needed for the REMOVE function further below,
    // since the destination- and source container might differ.
    //
    int source_part_item_index = *MODEL_PART_STATE_CYBOI_NAME;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //

    // Use the destination part type data by default.
    copy_integer((void*) &destination_type, dtd);
    // Use the source part model count by default.
    copy_integer((void*) &count, smc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    //
    // Assign destination type to source type.
    //
    // Otherwise, an error would occur when comparing types in file "type_modify.c",
    // since some operations like "modify/empty" do only have
    // a destination part (and type), but NOT a source part (and type).
    //
    copy_integer((void*) &source_type, (void*) &destination_type);
    //
    // Use the actual source part type data, if existent,
    // by overwriting the standard value copied above.
    // If std is null, then nothing is copied and source_type left untouched.
    //
    copy_integer((void*) &source_type, std);
    // Use the explicit destination index that was given as parametre.
    copy_integer((void*) &destination_index, dimd);
    // Use the explicit source index that was given as parametre.
    copy_integer((void*) &source_index, simd);
    // Set adjust flag to the value that was given as parametre.
    copy_integer((void*) &adjust, admd);
    //
    // Set destination- and source part item index depending on
    // the destination- and source properties flag that was given as parametre.
    //
    apply_modify_index((void*) &destination_part_item_index, dprmd);
    apply_modify_index((void*) &source_part_item_index, sprmd);
    // Get source array.
    apply_modify_array((void*) &source_array_data, (void*) &source_array_count, (void*) &spd, (void*) &spc, sprmd);

    //
    // Functionality
    //

    //?? TODO: Delete later. Testing only.
    //?? DEBUG_CYBOP = 1;

    // Compare destination- and source type.
    apply_modify_type(d, source_array_data, (void*) &destination_type, mmd, (void*) &count, (void*) &destination_index, (void*) &source_index, (void*) &adjust, rmd, tmd, tmc, p5, (void*) &destination_part_item_index, (void*) &source_part_item_index, s, (void*) &source_type);

    //?? TODO: Delete later. Testing only.
    //?? DEBUG_CYBOP = 0;
}
