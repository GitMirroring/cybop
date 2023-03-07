/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MOVER_SOURCE
#define MOVER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../executor/calculator/integer/add_integer_calculator.c"
#include "../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../executor/calculator/integer/negate_integer_calculator.c"
#include "../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../executor/calculator/pointer/add_pointer_calculator.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../logger/logger.c"
#include "../../mapper/type_to_size_mapper.c"

/**
 * Moves the current parsing position by element count
 * and also adapts the remaining element count.
 *
 * @param p0 the data position (pointer reference)
 * @param p1 the count remaining
 * @param p2 the type
 * @param p3 the element count
 * @param p4 the backward flag
 */
void move(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Move position.");

    // The memory area.
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Determine type size.
    map_type_to_size((void*) &m, p2);
    // Calculate memory area.
    calculate_integer_multiply((void*) &m, p3);

    // Compare if backward flag is set.
    compare_integer_equal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The backward flag is NOT set.
        //
        // This is the standard case.
        // In most cases, the pointer has to be moved FORWARD.
        //

        // Add memory area to current position.
        calculate_pointer_add(p0, (void*) &m);
        // Subtract count from remaining count.
        calculate_integer_subtract(p1, p3);

    } else {

        //
        // The backward flag IS set.
        //
        // This is sometimes necessary when parsing data.
        // Some data structures require to "peek ahead",
        // i.e. read next data in order to find out about
        // the end or meaning of the current data.
        //
        // In such cases, the pointer has to be moved BACKWARD
        // after having finished "peeking ahead",
        // so that the data may be processed once again.
        //

        // Negate memory area.
        calculate_integer_negate((void*) &m, (void*) &m);
        //
        // Add NEGATIVE memory area to current position,
        // which is equal to a subtraction,
        // so that the pointer is moved BACKWARD.
        //
        calculate_pointer_add(p0, (void*) &m);
        // Add count to remaining count.
        calculate_integer_add(p1, p3);
    }
}

/* MOVER_SOURCE */
#endif
