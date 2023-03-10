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

#ifndef FIND_FILE_SOURCE
#define FIND_FILE_SOURCE

#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/commander/find_file_commander.c"
#include "../../logger/logger.c"

#ifndef _MSC_VER
    #include <unistd.h>
#endif

/**
 * Finds a file.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_find_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply find file.");

    //
    // Declaration
    //

    // The path part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The insensitive part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The insensitive part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path part model item data and count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part model item data and count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The insensitive part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursvie part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get path part.
    get_part_name((void*) &p, p0, (void*) PATH_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) PATH_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get name part.
    get_part_name((void*) &n, p0, (void*) NAME_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) NAME_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get insensitive part.
    get_part_name((void*) &i, p0, (void*) INAME_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) INAME_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get recursive part.
    get_part_name((void*) &r, p0, (void*) RECURSIVE_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) RECURSIVE_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get path part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get name part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get insensitive part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get recursive part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get path part model item data and count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get name part model item data and count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get insensitive part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get recursive part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_find_file(pmd, pmc, nmd, nmc, imd, rmd);
}

/* FIND_FILE_SOURCE */
#endif
