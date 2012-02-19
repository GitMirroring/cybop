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

#ifndef CALCULATE_SOURCE
#define CALCULATE_SOURCE

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../logger/logger.c"

/**
 * Calculates a result by applying the given operation to the given operands.
 *
 * Expected parametres:
 * - result (required): the knowledge model, in which the result is stored
 * - left (required): the left operand
 * - right (required): the right operand
 * - type (required): the operand type which is equal for left- and right parametre
 *
 * CAUTION! Do NOT use the "add" operation for characters!
 * They may be concatenated by using the "append" operation.
 *
 * CAUTION! There are several ways to use addition.
 *
 * Example 1: Unary Operator
 *
 * sum: .knowledge.sum
 * summand_1: .knowledge.summand_1
 * summand_2: 0
 *
 * If only one summand is to be added to the sum,
 * then the second summand should be SET TO ZERO.
 *
 * CAUTION! The two operands (sum, summand_1)
 * MAY reference the same cybol knowledge model.
 * Since only one addition takes place and summand_2
 * is expected to have been set to zero,
 * wrong operand values CANNOT occur.
 * So, the following operands would be fine, too:
 *
 * sum: .knowledge.same_model
 * summand_1: .knowledge.same_model
 * summand_2: 0
 *
 * Example 2: Binary Operator
 *
 * sum: .knowledge.sum
 * summand_1: .knowledge.summand_1
 * summand_2: .knowledge.summand_2
 *
 * This is the standard case. Both summands are added,
 * one after the other, to the sum.
 *
 * CAUTION! All three operands (sum, summand_1, summand_2)
 * HAVE TO point to DIFFERENT cybol knowledge models.
 * Otherwise, when writing the result into the output sum,
 * one input operand would be OVERWRITTEN at the same time,
 * as both are pointing to the same operand.
 *
 * If the sum and summand_2 referenced the same knowledge model,
 * then after having added summand_1 to the sum,
 * summand_2 would have a FALSIFIED value.
 *
 * @param p0 the parametres array (signal/ operation part properties with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_calculate(void* p0, int* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply calculate.");

    // The result part.
    void* res = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The left operand part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right operand part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand type part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model.
    void* resm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand type part model.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model data, count.
    void* resmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand type part model data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result part.
    get_name_array((void*) &res, p0, (void*) RESULT_COMPARE_OPERATION_CYBOL_NAME, (void*) RESULT_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get left operand part.
    get_name_array((void*) &l, p0, (void*) LEFT_OPERAND_COMPARE_OPERATION_CYBOL_NAME, (void*) LEFT_OPERAND_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get right operand part.
    get_name_array((void*) &r, p0, (void*) RIGHT_OPERAND_COMPARE_OPERATION_CYBOL_NAME, (void*) RIGHT_OPERAND_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get operand type part.
    get_name_array((void*) &t, p0, (void*) OPERATOR_COMPARE_OPERATION_CYBOL_NAME, (void*) TYPE_COMPARE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get result part model.
    copy_array_forward((void*) &resm, res, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get operand type part model.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get result part model data, count.
    copy_array_forward((void*) &resmd, resm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get operand type part model data, count.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Calculate result by applying operation to operands.
    calculate_all_part(resmd, l, r, tmd);
}

/* CALCULATE_SOURCE */
#endif
