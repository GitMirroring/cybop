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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_SUFFIX_COMPARATOR_SOURCE
#define ARRAY_SUFFIX_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/memoriser/offset_adder.c"
#include "../../../executor/modifier/copier/value_copier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Compares if the right- is a suffix of the left array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the left array count
 * @param p6 the right array count
 */
void compare_suffix_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare suffix array.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_integer((void*) &r, p5, p6, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // The left array index.
        int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Add left array count.
        calculate_integer_add((void*) &i, p5);
        // Subtract right array count.
        calculate_integer_subtract((void*) &i, p6);

        // CAUTION! Hand over RIGHT array count as count,
        // since it is shorter or equal to that of the left array.
        compare_array(p0, p1, p2, p3, p4, p6, (void*) &i, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare suffix array. The left array count is smaller than the right array count.");
    }
}

/* ARRAY_SUFFIX_COMPARATOR_SOURCE */
#endif
