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
 * @version CYBOP 0.27.0 2023-08-31
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
 * Compares two files.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_compare_files(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply compare files.");

    //
    // Declaration
    //

    // The path1 part.
    void* pa1 = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The path2 part.
    void* pa2 = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The print differing chars part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The print offset part.
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The silent part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The case insensitive part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compare unicode part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compare ascii part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The display line numbers part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compress whitespace part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path1 part model item.
    void* pa1m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The path2 part model item.
    void* pa2m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The print differing chars part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The print offset part model item.
    void* om = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The silent part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The case insensitive part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compare unicode part model item.
    void* um = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The follow symbolic link part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The change current drive part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compress whitespace part model item.
    void* wm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path1 part model item data and count.
    void* pa1md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pa1mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The path2 part model item data and count.
    void* pa2md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pa2mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The print differing chars part model item data.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The print offset part model item data.
    void* omd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The silent part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The case insensitive part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compare unicode part model item data.
    void* umd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compare ascii part model item data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The display line numbers part model item data.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The compress whitespace part model item data.
    void* wmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get path1 part.
    get_part_name((void*) &pa1, p0, (void*) PATH_1_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) PATH_1_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get path2 part.
    get_part_name((void*) &pa2, p0, (void*) PATH_2_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) PATH_2_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get print differing chars part.
    get_part_name((void*) &d, p0, (void*) PRINT_DIFFERING_CHARS_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) PRINT_DIFFERING_CHARS_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get print offset part.
    get_part_name((void*) &o, p0, (void*) PRINT_OFFSET_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) PRINT_OFFSET_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get silent part.
    get_part_name((void*) &s, p0, (void*) SILENT_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) SILENT_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get case insensitive part.
    get_part_name((void*) &c, p0, (void*) CASE_INSENSITIVE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) CASE_INSENSITIVE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get compare unicode part.
    get_part_name((void*) &u, p0, (void*) UNICODE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) UNICODE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get compare ascii part.
    get_part_name((void*) &a, p0, (void*) ASCII_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) ASCII_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get display line numbers link part.
    get_part_name((void*) &l, p0, (void*) DISPLAY_LINE_NUMBERS_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) DISPLAY_LINE_NUMBERS_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get compress whitespace part.
    get_part_name((void*) &w, p0, (void*) COMPRESS_WHITESPACE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME, (void*) COMPRESS_WHITESPACE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get path part model item.
    copy_array_forward((void*) &pa1m, pa1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get path part model item.
    copy_array_forward((void*) &pa2m, pa2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get print differing chars part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get print offset part model item.
    copy_array_forward((void*) &om, o, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get silent part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get case insensitive part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get compare unicode model item.
    copy_array_forward((void*) &um, u, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get compare ascii part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get display line numbers part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get compress whitespace part model item.
    copy_array_forward((void*) &wm, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get path part model item data and count.
    copy_array_forward((void*) &pa1md, pa1m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pa1mc, pa1m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get path part model item data and count.
    copy_array_forward((void*) &pa2md, pa2m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pa2mc, pa2m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get print differing chars part model item data.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get print offset model item data.
    copy_array_forward((void*) &omd, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get silent part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get case insensitive part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get compare unicode model item data.
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get compare ascii part model item data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get display line numbers part model item data.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get compress whitespace model item data.
    copy_array_forward((void*) &wmd, wm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_compare_files(pa1md, pa1mc, pa2md, pa2mc, dmd, omd, smd, cmd, umd, amd, lmd, wmd);
}
