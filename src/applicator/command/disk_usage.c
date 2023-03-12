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

#ifndef DISK_USAGE_SOURCE
#define DISK_USAGE_SOURCE

//
// Library interface
//

#include "constant.h"
#include "executor.h"
#include "logger.h"

/**
 * Shows the disk usage of a directory.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_disk_usage(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shows the disk-usage of a directory.");

    //
    // Declaration
    //

    // The human part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The summarize part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bytes part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The total part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The human part.
    void* hm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The summarize part.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bytes part.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The total part.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The human part.
    void* hmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The summarize part.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bytes part.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The total part.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get human part.
    get_part_name((void*) &h, p0, (void*) HUMAN_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME, (void*) HUMAN_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get summarize part.
    get_part_name((void*) &s, p0, (void*) SUMMARIZE_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME, (void*) SUMMARIZE_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get all part.
    get_part_name((void*) &a, p0, (void*) ALL_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME, (void*) ALL_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get bytes part.
    get_part_name((void*) &b, p0, (void*) BYTES_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME, (void*) BYTES_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get total part.
    get_part_name((void*) &t, p0, (void*) TOTAL_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME, (void*) TOTAL_DISK_USAGE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get human part model item.
    copy_array_forward((void*) &hm, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get summarize part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get all part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get bytes part model item.
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get total part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get human part model item.
    copy_array_forward((void*) &hmd, hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get summarize part model item.MOD
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get all part model item.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get bytes part model item.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get total part model item.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_disk_usage(hmd, smd, amd, bmd, tmd);
}

/* DISK_USAGE_SOURCE */
#endif
