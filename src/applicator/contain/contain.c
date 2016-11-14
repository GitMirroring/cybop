/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTAIN_SOURCE
#define CONTAIN_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/containment/containment_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
//?? #include "../../executor/container/container.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Compares if the bounded area contains the value.
 *
 * Expected parametres:
 * - result (required): the knowledge model, in which the result is stored (of type boolean)
 * - value (required): the value
 * - left (required): the left bound
 * - right (required): the right bound
 * [TODO, not used yet]
 * - type (required): the operand type which is equal for value, left- and right bound
 * - selection (required): the area of two strings or number vectors to be compared;
 *   may be one of: full, prefix, suffix, subsequence
 *
 * The "selection" parametre is mostly needed for comparing models of type "character".
 * But also numbers may be given as vectors, e.g. the integer sequence "1,2,3".
 * However, this function relies on it, for finding the right comparison function to call.
 * Therefore, that parametre IS REQUIRED.
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the stack memory item
 * @param p4 the operation type
 */
void apply_contain(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply contain.");

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

    // Get result part.
    get_part_name((void*) &r, p0, (void*) RESULT_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) RESULT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);
    // Get value part.
    get_part_name((void*) &v, p0, (void*) VALUE_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) VALUE_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);
    // Get left part.
    get_part_name((void*) &lb, p0, (void*) LEFT_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) LEFT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);
    // Get right part.
    get_part_name((void*) &rb, p0, (void*) RIGHT_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) RIGHT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);
    // Get type part.
    get_part_name((void*) &t, p0, (void*) TYPE_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) TYPE_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);
    // Get selection part.
    get_part_name((void*) &s, p0, (void*) SELECTION_CONTAINMENT_LOGIC_CYBOL_NAME, (void*) SELECTION_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);

    // Get result part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get selection part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get result part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get type part model item data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get selection part model item data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

/*
fwprintf(stdout, L"TEST apply contain r: %i\n", r);
fwprintf(stdout, L"TEST apply contain v: %i\n", v);
fwprintf(stdout, L"TEST apply contain lb: %i\n", lb);
fwprintf(stdout, L"TEST apply contain rb: %i\n", rb);
fwprintf(stdout, L"TEST apply contain t: %i\n", t);
fwprintf(stdout, L"TEST apply contain s: %i\n", s);
*/

//??    contain(rmd, v, lb, rb, p4);
}

/* CONTAIN_SOURCE */
#endif
