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

#ifndef ITEM_ALL_CALCULATOR_SOURCE
#define ITEM_ALL_CALCULATOR_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/calculator/all/array_all_calculator.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../logger/logger.c"

/**
 * Calculates all elements of the result item with those of the operand array.
 *
 * @param p0 the result item, which contains the operands BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the operand array count
 * @param p5 the result item element index
 */
void calculate_all_item_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate all item element.");

    // The result item element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result item element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p5);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p5, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // This is a data item element.

        // The result item count.
        // CAUTION! It is only needed because this is a data item element.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get result item count.
        copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Calculate all elements of the operand array with those of the result item data array.
        calculate_all_array(e, p1, p2, p3, c, p4);

    } else {

        // This is a count or size item element.

        // Calculate all elements of the right array with those of the left item data array.
        calculate_all_array(e, p1, p2, p3, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p4);
    }
}

/**
 * Calculates all elements of the result- with those of the operand item.
 *
 * @param p0 the result item, which contains the operands BEFORE the operation
 * @param p1 the operand item
 * @param p2 the operation type
 * @param p3 the operand type
 */
void calculate_all_item(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate all item.");

    // The result data, count.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand data, count.
    void* od = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* oc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result data, count.
    copy_array_forward((void*) &rd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get operand data, count.
    copy_array_forward((void*) &od, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &oc, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Calculate all elements of the result- with those of the operand item data array.
    calculate_all_array(rd, od, p2, p3, rc, oc);
}

/* ITEM_ALL_CALCULATOR_SOURCE */
#endif
