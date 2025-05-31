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
#include "shell.h"

/**
 * Shows the opened files.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_list_open_files(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply list open files.");

    //
    // Declaration
    //

    // The list-uid part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The list-file-size part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The list-tasks part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The disable-tasks part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terse-listing part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The list-uid part.
    void* um = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The list-file-size part.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The list-tasks part.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The disable-tasks part.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terse-listing part.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The list-uid part.
    void* umd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The list-file-size part.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The list-tasks part.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The disable-tasks part.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terse-listing part.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get list-uid part.
    get_part_name((void*) &u, p0, (void*) LIST_UID_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) LIST_UID_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get list-file-size part.
    get_part_name((void*) &s, p0, (void*) LIST_FILE_SIZE_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) LIST_FILE_SIZE_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get list-tasks part.
    get_part_name((void*) &l, p0, (void*) LIST_TASKS_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) LIST_TASKS_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get disable-tasks part.
    get_part_name((void*) &d, p0, (void*) DISABLE_TCP_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) DISABLE_TCP_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get terse-listing part.
    get_part_name((void*) &t, p0, (void*) TERSE_LISTING_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) TERSE_LISTING_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get list-uid part model item.
    copy_array_forward((void*) &um, u, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get list-file-size part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get list-tasks part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get disable-tasks part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get terse-listing part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get list-uid part model item.
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get list-file-size part model item.MOD
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get list-tasks part model item.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get disable-tasks part model item.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get terse-listing part model item.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_list_open_files(umd, smd, lmd, dmd, tmd);
}
