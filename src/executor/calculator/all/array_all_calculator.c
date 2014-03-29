/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_ALL_CALCULATOR_SOURCE
#define ARRAY_ALL_CALCULATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/calculator/basic/array_calculator.c"
#include "../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../logger/logger.c"

/**
 * Calculates all elements of the left- with those of the right array.
 *
 * @param p0 the result array, which contains the operands BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the result array count
 * @param p5 the operand array count
 */
void calculate_all_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {
  
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate all array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! The sizes do NOT have to be identical,
    // since they just represent allocated memory.
    // Only the count (actual number of elements) is of interest.

    // Compare if integer vectors have the same length.
    compare_integer_equal((void*) &r, p4, p5);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! Both, the result- or the operand array count may be
        // handed over alternatively as count parametre, since they are equal.
        calculate_array(p0, p1, p2, p3, p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate all array. The result array count is not equal to the operand array count.");
    }
}

/* ARRAY_ALL_CALCULATOR_SOURCE */
#endif
