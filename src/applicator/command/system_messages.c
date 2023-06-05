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

#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"
#include "shell.h"

/**
 * Shows the system messages.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_system_messages(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply system messages.");

    //
    // Declaration
    //

    // The human part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The ctime part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The kernel part.
    void* k = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The color part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The userspace part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The human part.
    void* hm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The ctime part.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The kernel part.
    void* km = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The color part.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The userspace part.
    void* um = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The human part.
    void* hmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The ctime part.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The kernel part.
    void* kmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The color part.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The userspace part.
    void* umd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get human part.
    get_part_name((void*) &h, p0, (void*) HUMAN_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME, (void*) HUMAN_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get ctime part.
    get_part_name((void*) &c, p0, (void*) CTIME_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME, (void*) CTIME_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get kernel part.
    get_part_name((void*) &k, p0, (void*) KERNEL_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME, (void*) KERNEL_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get color part.
    get_part_name((void*) &l, p0, (void*) COLOR_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME, (void*) COLOR_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get userspace part.
    get_part_name((void*) &u, p0, (void*) USERSPACE_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME, (void*) USERSPACE_SYSTEM_MESSAGES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get human part model item.
    copy_array_forward((void*) &hm, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get ctime part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get kernel part model item.
    copy_array_forward((void*) &km, k, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get color part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get userspace part model item.
    copy_array_forward((void*) &um, u, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get human part model item.
    copy_array_forward((void*) &hmd, hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get ctime part model item.MOD
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get kernel part model item.
    copy_array_forward((void*) &kmd, km, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get color part model item.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get userspace part model item.
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_system_messages(hmd, cmd, kmd, lmd, umd);
}
