/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_SOURCE
#define COMPARE_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/comparison/comparison_operation_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/comparator.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Compares left and right parametre.
 *
 * Expected parametres:
 * - result (required): the knowledge model, in which the result is stored (of type boolean)
 * - left (required): the left operand
 * - right (required): the right operand
 * - type (required): the operand type which is equal for both operands
 * - selection (required): the area of two strings or number vectors to be compared;
 *   may be one of: full, prefix, suffix, subsequence
 *
 * The "selection" parametre is mostly needed for comparing models of type "character".
 * But also numbers may be given as vectors, e.g. the integer sequence "1,2,3".
 * However, this function relies on it, for finding the right comparison function to call.
 * Therefore, that parametre IS REQUIRED.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the operation type
 */
void apply_compare(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply compare.");

    // The result part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left part.
    void* lo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right part.
    void* ro = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    get_part_knowledge((void*) &r, p0, (void*) RESULT_COMPARISON_OPERATION_CYBOL_NAME, (void*) RESULT_COMPARISON_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get left part.
    get_part_knowledge((void*) &lo, p0, (void*) LEFT_COMPARISON_OPERATION_CYBOL_NAME, (void*) LEFT_COMPARISON_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get right part.
    get_part_knowledge((void*) &ro, p0, (void*) RIGHT_COMPARISON_OPERATION_CYBOL_NAME, (void*) RIGHT_COMPARISON_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get type part.
    get_part_knowledge((void*) &t, p0, (void*) TYPE_COMPARISON_OPERATION_CYBOL_NAME, (void*) TYPE_COMPARISON_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get selection part.
    get_part_knowledge((void*) &s, p0, (void*) SELECTION_COMPARISON_OPERATION_CYBOL_NAME, (void*) SELECTION_COMPARISON_OPERATION_CYBOL_NAME_COUNT, p1, p2);

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

/*??
fwprintf(stdout, L"TEST apply compare r: %i\n", r);
fwprintf(stdout, L"TEST apply compare lo: %i\n", lo);
fwprintf(stdout, L"TEST apply compare ro: %i\n", ro);
fwprintf(stdout, L"TEST apply compare t: %i\n", t);
fwprintf(stdout, L"TEST apply compare s: %i\n", s);
*/

    compare(rmd, lo, ro, p3, tmd, smd, smc);
}

/* COMPARE_SOURCE */
#endif
