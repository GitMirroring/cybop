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
 * Print byte, word, and line counts, count the number of bytes,
 * whitespace-separated words, and newlines in each given FILE.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_word_count(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply word count.");

    //
    // Declaration
    //

    // The path part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The byte part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The char part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The max-length-party part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The word part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The byte part model item.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The char part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The max-line-length part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The word part model item.
    void* wm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The path part model item data and count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The byte part model item data.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The char part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line part model item data.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The max-line-length part model item data.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The word part model item data.
    void* wmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get path part.
    get_part_name((void*) &p, p0, (void*) PATH_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) PATH_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get byte part.
    get_part_name((void*) &b, p0, (void*) BYTE_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) BYTE_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get char part.
    get_part_name((void*) &c, p0, (void*) CHAR_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) CHAR_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get line part.
    get_part_name((void*) &l, p0, (void*) LINE_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) LINE_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get max-line-length part.
    get_part_name((void*) &m, p0, (void*) MAX_LINE_LENGTH_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) MAX_LINE_LENGTH_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get word part.
    get_part_name((void*) &w, p0, (void*) WORD_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME, (void*) WORD_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get path part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get byte part model item.
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get char part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get line part model item.
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get max-line-length part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get word part model item.
    copy_array_forward((void*) &wm, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get path part model item data and count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get byte part model item data.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get char part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get line part model item data.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get max-line-length part model item data.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get word part model item data.
    copy_array_forward((void*) &wmd, wm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    command_word_count(pmd, pmc, bmd, cmd, lmd, mmd, wmd);
}
