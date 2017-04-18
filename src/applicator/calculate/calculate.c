/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CALCULATE_SOURCE
#define CALCULATE_SOURCE

#include "../../applicator/calculate/type_calculate.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/calculation/calculation_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/accessor/name_getter/array_name_getter.c"
#include "../../executor/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Calculates a result by applying the given operation to the given operands.
 *
 * Expected parametres:
 * - result (required): the knowledge model in which the result is stored; used as first operand
 * - operand (required): the second operand
 *
 * CAUTION! Do NOT use the "add" operation for characters!
 * They may be concatenated by using the "modify/append" or "modify/overwrite" operation.
 *
 * CAUTION! There are several ways to use addition, with unary or binary operators.
 * This function works like an UNARY operator.
 * The "result" parametre represents the FIRST operand;
 * the "operand" parametre the SECOND.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the operation type
 */
void apply_calculate(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply calculate.");

    // The result part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand part.
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part type item.
    void* rt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand part type item.
    void* ot = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part type item data.
    void* rtd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand part type item data.
    void* otd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result part.
    get_part_name((void*) &r, p0, (void*) RESULT_CALCULATION_LOGIC_CYBOL_NAME, (void*) RESULT_CALCULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get operand part.
    get_part_name((void*) &o, p0, (void*) OPERAND_CALCULATION_LOGIC_CYBOL_NAME, (void*) OPERAND_CALCULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get result part type item.
    copy_array_forward((void*) &rt, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Get operand part type item.
    copy_array_forward((void*) &ot, o, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);

    // Get result part type item data.
    copy_array_forward((void*) &rtd, rt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get operand part type item data.
    copy_array_forward((void*) &otd, ot, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int type = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the result part type data by default.
    copy_integer((void*) &type, rtd);

    // Compare result- and operand type.
    apply_calculate_type(r, o, p5, (void*) &type, otd);
}

/* CALCULATE_SOURCE */
#endif
