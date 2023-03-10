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

#ifndef FIND_COMMAND_SOURCE
#define FIND_COMMAND_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/commander/find_command_commander.c"
#include "../../logger/logger.c"

#ifndef _MSC_VER
    #include <unistd.h>
#endif

/**
 * Locates the binary, source, and manual page files for a command.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_find_command(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply change directory.");

    //
    // Declaration
    //

    // The command part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The binary part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The manual part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The command part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The binary part model item.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The manual part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The command part model item data and count.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* cmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The binary part model item data.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The manual part model item data.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get command part.
    get_part_name((void*) &c, p0, (void*) COMMAND_FIND_COMMAND_COMMANDER_LOGIC_CYBOL_NAME, (void*) COMMAND_FIND_COMMAND_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get print differing chars part.
    get_part_name((void*) &b, p0, (void*) BINARY_FIND_COMMAND_COMMANDER_LOGIC_CYBOL_NAME, (void*) BINARY_FIND_COMMAND_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get print offset part.
    get_part_name((void*) &m, p0, (void*) MANUAL_FIND_COMMAND_COMMANDER_LOGIC_CYBOL_NAME, (void*) MANUAL_FIND_COMMAND_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get silent part.
    get_part_name((void*) &s, p0, (void*) SOURCE_FIND_COMMAND_COMMANDER_LOGIC_CYBOL_NAME, (void*) SOURCE_FIND_COMMAND_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get command part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get binary part model item.
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get manual part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get command part model item data and count.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &cmc, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get print differing chars part model item data.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get print offset model item data.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get silent part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_find_command(cmd, cmc, bmd, mmd, smd);
}

/* FIND_COMMAND_SOURCE */
#endif
