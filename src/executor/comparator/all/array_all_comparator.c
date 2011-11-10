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

#ifndef ARRAY_ALL_COMPARATOR_SOURCE
#define ARRAY_ALL_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/comparator/basic/array_comparator.c"
#include "../../../executor/comparator/basic/integer_comparator.c"
#include "../../../logger/logger.c"

/**
 * Compares all elements of the left- with those of the right array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the left array count
 * @param p6 the right array count
 */
void compare_all_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare all array.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_integer((void*) &r, p5, p6, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE);

    if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // CAUTION! Both, the left- or the right array count may be
        // handed over alternatively as count parametre, since they are equal.
        compare_array(p0, p1, p2, p3, p4, p6, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare all array. The left array count is not equal to the right array count.");
    }
}

/* ARRAY_ALL_COMPARATOR_SOURCE */
#endif
