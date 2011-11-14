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

#ifndef ARRAY_FINDER_SOURCE
#define ARRAY_FINDER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/calculator/integer_adder.c"
#include "../../../executor/calculator/integer_multiplier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/memoriser/offset_adder.c"
#include "../../../executor/modifier/copier/value_copier.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"

/**
 * Tries to find the searched array in the investigated array.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated array
 * @param p2 the searched array
 * @param p3 the type
 * @param p4 the investigated array count
 * @param p5 the searched array count
 */
void find_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find array elements.");

    // The loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Add investigated array count.
    calculate_integer_add((void*) &c, p4);
    // Subtract searched array count.
    calculate_integer_subtract((void*) &c, p5);
    // Add number one.
    // CAUTION! This IS NECESSARY since otherwise, two arrays with
    // identical length will never be processed as the count is zero then.
    // Problems with the loop variable used as investigated array index
    // will NOT occur, since the loop is left before.
    calculate_integer_add((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, (void*) &c);

        if (b != FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The maximum loop count has been reached.
            // All elements have been compared.
            // The searched array could not be found.
            // Leave index untouched.

            break;
        }

        // CAUTION! Hand over SEARCHED (right) array count as count,
        // since it is shorter or equal to that of the left array.
        // CAUTION! Use loop variable as INVESTIGATED (left) array index.
        compare_array((void*) &b, p1, p2, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, p3, p5, (void*) &j, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The searched array has been found.

            // Remember the index.
            copy_integer(p0, (void*) &j);

            // The loop may be left now.
            break;
        }

        j++;
    }
}

/**
 * Tries to find the searched array in the investigated array.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated array
 * @param p2 the searched array
 * @param p3 the type
 * @param p4 the investigated array count
 * @param p5 the searched array count
 */
void find_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater_or_equal((void*) &r, p4, p5);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        find_array_elements(p0, p1, p2, p3, p4, p5);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not find array. The investigated array count is smaller than the searched array count.");
    }
}

/* ARRAY_FINDER_SOURCE */
#endif
