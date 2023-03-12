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

#ifndef LIST_DIRECTORY_CONTENTS_SOURCE
#define LIST_DIRECTORY_CONTENTS_SOURCE

//
// Library interface
//

#include "constant.h"
#include "executor.h"
#include "logger.h"

/**
 * Lists the directory contents.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_list_directory_contents(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply list directory contents.");

    //
    // Declaration
    //

    // The path part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The almost-all part.
    void* aa = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The one row per entry part.
    void* orpe = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The short part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by file size part.
    void* sbfs = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by modification date part.
    void* sbmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by extension part.
    void* sbe = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The export path part.
    void* ep = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The almost-all part model item.
    void* aam = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The one row per entry part model item.
    void* orpem = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The short part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by file size part model item.
    void* sbfsm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by modification date part model item.
    void* sbmdm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by extension part model item.
    void* sbem = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The export path part model item.
    void* epm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path part model item data and count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The all part model item data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The almost all part model item data.
    void* aamd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The long part model item data.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The one row per entry part model item data.
    void* orpemd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The recursive part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The short part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by file size part model item data.
    void* sbfsmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by modification date part model item data.
    void* sbmdmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sort by extension part model item data.
    void* sbemd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The export path part model item data and count.
    void* epmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* epmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get path part.
    get_part_name((void*) &p, p0, (void*) PATH_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) PATH_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get all part.
    get_part_name((void*) &a, p0, (void*) ALL_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) ALL_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get almost all part.
    get_part_name((void*) &aa, p0, (void*) ALMOST_ALL_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) ALMOST_ALL_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get long part.
    get_part_name((void*) &l, p0, (void*) LONG_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) LONG_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get one row per entry part.
    get_part_name((void*) &orpe, p0, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get recursive part.
    get_part_name((void*) &r, p0, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get short part.
    get_part_name((void*) &s, p0, (void*) SHORT_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) SHORT_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get sort by file size part.
    get_part_name((void*) &sbfs, p0, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get sort by modification date part.
    get_part_name((void*) &sbmd, p0, (void*) SORT_BY_MODIFICATION_DATE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) SORT_BY_MODIFICATION_DATE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get sort by extension part.
    get_part_name((void*) &sbe, p0, (void*) SORT_BY_EXTENSION_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) SORT_BY_EXTENSION_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get export path part.
    get_part_name((void*) &ep, p0, (void*) EXPORT_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) EXPORT_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get path part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get all part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get almost all part model item.
    copy_array_forward((void*) &aam, aa, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get long part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get one row per entry part model item.
    copy_array_forward((void*) &orpem, orpe, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get recursive part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get short part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get sort by file size part model item.
    copy_array_forward((void*) &sbfsm, sbfs, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get sort by modification date part model item.
    copy_array_forward((void*) &sbmdm, sbmd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get sort by extension part model item.
    copy_array_forward((void*) &sbem, sbe, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get export path part model item.
    copy_array_forward((void*) &epm, ep, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get path part model item data and count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get all part model item data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get almost all part model item data.
    copy_array_forward((void*) &aamd, aam, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get long part model item data.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get one row per entry part model item data.
    copy_array_forward((void*) &orpemd, orpem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get recursive part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get short part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get short by file size part model item data.
    copy_array_forward((void*) &sbfsmd, sbfsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get sort by modification date part model item data.
    copy_array_forward((void*) &sbmdmd, sbmdm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get sort by extension part model item data.
    copy_array_forward((void*) &sbemd, sbem, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get export path part model item data and count.
    copy_array_forward((void*) &epmd, epm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &epmc, epm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_list_directory_contents(pmd, pmc, amd, aamd, lmd, orpemd, rmd, smd, sbfsmd, sbmdmd, sbemd, epmd, epmc);
}

/* LIST_DIRECTORY_CONTENTS_SOURCE */
#endif
