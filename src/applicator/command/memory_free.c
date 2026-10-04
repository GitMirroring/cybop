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
 * Shows the usage of the RAM.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_memory_free(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shows the usage of the RAM.");

    //
    // Declaration
    //

    // The human part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The kilobytes part.
    void* k = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The megabytes part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gigabytes part.
    void* g = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The total part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The human part.
    void* hm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The kilobytes part.
    void* km = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The megabytes part.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gigabytes part.
    void* gm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The total part.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The human part.
    void* hmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The kilobytes part.
    void* kmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The megabytes part.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gigabytes part.
    void* gmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The total part.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get human part.
    get_part_name((void*) &h, p0, (void*) HUMAN_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME, (void*) HUMAN_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get kilobytes part.
    get_part_name((void*) &k, p0, (void*) KILOBYTES_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME, (void*) KILOBYTES_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get megabytes part.
    get_part_name((void*) &m, p0, (void*) MEGABYTES_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME, (void*) MEGABYTES_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get gigabytes part.
    get_part_name((void*) &g, p0, (void*) GIGABYTES_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME, (void*) GIGABYTES_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get total part.
    get_part_name((void*) &t, p0, (void*) TOTAL_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME, (void*) TOTAL_MEMORY_FREE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get human part model item.
    copy_array_forward((void*) &hm, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get kilobytes part model item.
    copy_array_forward((void*) &km, k, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get megabytes part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get gigabytes part model item.
    copy_array_forward((void*) &gm, g, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get total part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get human part model item.
    copy_array_forward((void*) &hmd, hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get kilobytes part model item.MOD
    copy_array_forward((void*) &kmd, km, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get megabytes part model item.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get gigabytes part model item.
    copy_array_forward((void*) &gmd, gm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get total part model item.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_memory_free(hmd, kmd, mmd, gmd, tmd);
}
