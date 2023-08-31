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
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Modifies the destination item with the source array.
 *
 * @param p0 the destination item
 * @param p1 the source array (should be null for remove)
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index (should be null for append)
 * @param p6 the source index (should be null for remove)
 * @param p7 the adjust count flag (should be null for append and insert)
 * @param p8 the repetition number for "modify/repeat"
 * @param p9 the searchterm data for "modify/replace"
 * @param p10 the searchterm count for "modify/replace"
 * @param p11 the operation type
 */
void modify_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify item.");
    //?? fwprintf(stdout, L"Debug: Modify item. p3: %i\n", p3);

    // The destination data, count, size.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get destination data, count, size.
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    if (DEBUG_CYBOP == 1) {
        fwprintf(stdout, L"Debug: Modify item. count p4: %i\n", p4);
        fwprintf(stdout, L"Debug: Modify item. count *p4: %i\n", *((int*) p4));
        fwprintf(stdout, L"Debug: Modify item. destination index p5: %i\n", p5);
        fwprintf(stdout, L"Debug: Modify item. destination index *p5: %i\n", *((int*) p5));
        fwprintf(stdout, L"Debug: Modify item. source index p6: %i\n", p6);
        fwprintf(stdout, L"Debug: Modify item. source index *p6: %i\n", *((int*) p6));
        fwprintf(stdout, L"Debug: Modify item. destination count c: %i\n", c);
        fwprintf(stdout, L"Debug: Modify item. destination count *c: %i\n", *((int*) c));
        fwprintf(stdout, L"Debug: Modify item. operation type p11: %i\n", p11);
        fwprintf(stdout, L"Debug: Modify item. operation type *p11: %i\n", *((int*) p11));
    }

    //
    // CAUTION! Some functions called internally do NOT use a source index.
    // For these cases, the destination count determined above is handed over.
    // Furthermore, DEFAULT VALUES are defined in file "applicator/modify/modify.c".
    //
    modify_verify((void*) &r, p4, p5, p6, c, p4, p11);

    //?? TODO TEST: DELETE later!
    r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Modify destination data.
        // The count and size are adjusted inside.
        //
        modify_array((void*) &d, p1, p2, p3, p4, p5, p6, c, s, p7, p8, p9, p10, p11);

        //
        // Set data array as destination item element.
        //
        // CAUTION! This IS NECESSARY, because reallocation may have happened
        // above which would return a completely new data array (memory area).
        //
        // CAUTION! It is NOT necessary to also set count and size,
        // since only their references were used above to modify values.
        //
        copy_array_forward(p0, (void*) &d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        //
        // These lines are commented out, since this can be normal behaviour.
        // The model pointed to by a cybol path like ".var.request:uri:query.action"
        // might contain data in some cases, but in other cases be empty on purpose.
        //
        //?? log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not modify item. The sum of the given index and count is outside the data array count. This may be regular behaviour. Probably, the model pointed to by a cybol path is null or empty or a cybol model (e.g. a string) is wrong since it was not emptied before being filled.");
        fwprintf(stdout, L"Warning: Could not modify item. The sum of the given index and count is outside the data array count. This may be regular behaviour. Probably, the model pointed to by a cybol path is null or empty or a cybol model (e.g. a string) is wrong since it was not emptied before being filled. r: %i\n", r);
    }
}
