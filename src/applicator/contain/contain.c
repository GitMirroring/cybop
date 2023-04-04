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

#ifndef CONTAIN_SOURCE
#define CONTAIN_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "algorithm.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Compares if the bounded area contains the value.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the operation type
 */
void apply_contain(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply contain.");

    //
    // Declaration
    //

    // The result part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The value part.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left bound part.
    void* lb = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right bound part.
    void* rb = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The selection part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The selection part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item data.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The selection part model item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get result part.
    get_part_name((void*) &r, p0, (void*) RESULT_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) RESULT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get value part.
    get_part_name((void*) &v, p0, (void*) VALUE_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) VALUE_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get left part.
    get_part_name((void*) &lb, p0, (void*) LEFT_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) LEFT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get right part.
    get_part_name((void*) &rb, p0, (void*) RIGHT_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) RIGHT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get type part.
    get_part_name((void*) &t, p0, (void*) TYPE_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) TYPE_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get selection part.
    get_part_name((void*) &s, p0, (void*) SELECTION_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) SELECTION_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get result part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get selection part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get result part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get type part model item data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get selection part model item data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

/*??
    fwprintf(stdout, L"Debug: apply contain r: %i\n", r);
    fwprintf(stdout, L"Debug: apply contain v: %i\n", v);
    fwprintf(stdout, L"Debug: apply contain lb: %i\n", lb);
    fwprintf(stdout, L"Debug: apply contain rb: %i\n", rb);
    fwprintf(stdout, L"Debug: apply contain t: %i\n", t);
    fwprintf(stdout, L"Debug: apply contain s: %i\n", s);
*/

    //
    // Functionality
    //

//??    contain(rmd, v, lb, rb, p5);
}

/* CONTAIN_SOURCE */
#endif
