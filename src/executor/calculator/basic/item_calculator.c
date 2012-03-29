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

#ifndef ITEM_CALCULATOR_SOURCE
#define ITEM_CALCULATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../executor/calculator/basic/array_calculator.c"
#include "../../../logger/logger.c"

/**
 * Calculates left- with right item.
 *
 * @param p0 the result item, which contains the operands BEFORE the operation
 * @param p1 the operand item
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the count
 * @param p5 the result index
 * @param p6 the operand index
 */
void calculate_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate item.");

    // The result data.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand data.
    void* od = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result data.
    copy_array_forward((void*) &rd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get operand data.
    copy_array_forward((void*) &od, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    calculate_array(rd, od, p2, p3, p4, p5, p6);
}

/* ITEM_CALCULATOR_SOURCE */
#endif
