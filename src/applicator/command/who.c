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

#ifndef WHO_SOURCE
#define WHO_SOURCE

#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/commander/who_commander.c"
#include "../../logger/logger.c"

#ifndef _MSC_VER
    #include <unistd.h>
#endif

/**
 * Display who.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_who(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply who.");

    //
    // Declaration
    //

    // The ALL part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The BATCH part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The DEAD part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The LOGIN part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The SHORT part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The option part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The option part model item data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get option part.
    get_part_name((void*) &a, p0, (void*) ALL_WHO_COMMANDER_LOGIC_CYBOL_NAME, (void*) ALL_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    get_part_name((void*) &b, p0, (void*) BOOT_WHO_COMMANDER_LOGIC_CYBOL_NAME, (void*) BOOT_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    get_part_name((void*) &d, p0, (void*) DEAD_WHO_COMMANDER_LOGIC_CYBOL_NAME, (void*) DEAD_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    get_part_name((void*) &l, p0, (void*) LOGIN_WHO_COMMANDER_LOGIC_CYBOL_NAME, (void*) LOGIN_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    get_part_name((void*) &s, p0, (void*) SHORT_WHO_COMMANDER_LOGIC_CYBOL_NAME, (void*) SHORT_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get option part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get option part model item data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_who(amd, bmd, dmd, lmd, smd);
}

/* WHO_SOURCE */
#endif
