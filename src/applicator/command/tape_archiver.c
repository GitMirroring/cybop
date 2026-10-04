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

#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"
#include "shell.h"

/**
 * Packs or unpacks a directory or file.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_tape_archiver(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply tape archiver.");

    //
    // Declaration
    //

    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gzip part.
    void* g = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The unpack part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gzip part model item.
    void* gm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The unpack part model item.
    void* um = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item.
    void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source path part model item data and count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model item data and count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exclude part model item data and count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The force part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gzip part model item data.
    void* gmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The unpack part model item data.
    void* umd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The verbal part model item data.
    void* vmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get source part.
    get_part_name((void*) &s, p0, (void*) SOURCE_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) SOURCE_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get destination part.
    get_part_name((void*) &d, p0, (void*) DESTINATION_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) DESTINATION_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get force part.
    get_part_name((void*) &f, p0, (void*) FORCE_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) FORCE_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get gzip part.
    get_part_name((void*) &g, p0, (void*) GZIP_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) GZIP_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get unpack part.
    get_part_name((void*) &u, p0, (void*) UNPACK_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) UNPACK_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get verbal part.
    get_part_name((void*) &v, p0, (void*) VERBAL_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME, (void*) VERBAL_TAPE_ARCHIVER_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get source part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get force part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get gzip part model item.
    copy_array_forward((void*) &gm, g, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get unpack part model item.
    copy_array_forward((void*) &um, u, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get verbal part model item.
    copy_array_forward((void*) &vm, v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get source part model item data and count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get destination part model item data and count.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get force part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get gzip part model item data.
    copy_array_forward((void*) &gmd, gm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get unpack part model item data.
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get verbal part model item data.
    copy_array_forward((void*) &vmd, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_tape_archiver(smd, smc, dmd, dmc, fmd, gmd, umd, vmd);
}
