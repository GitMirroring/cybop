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

#ifndef LEXICOGRAPHICAL_COMPARATOR_SOURCE
#define LEXICOGRAPHICAL_COMPARATOR_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/checker/operation_checker.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/comparator/array_comparator.c"
#include "../../logger/logger.c"

/**
 * Tests if the lexicographical flag is set and calls the corresponding function.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data (array)
 * @param p2 the right data (array)
 * @param p3 the left count
 * @param p4 the right count
 * @param p5 the operation type
 * @param p6 the operand type
 * @param p7 the count
 * @param p8 the lexicographical flag
 */
void compare_lexicographical(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare lexicographical.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The lexicographical flag is FALSE.
        // Apply standard comparison with MANY return values in a vector.
        //

        //?? TODO: Use DEEP compare flag here if implemented one day in the future.
        compare_array(p0, p1, p2, p5, p6, p7);

    } else {

        //
        // The lexicographical flag is TRUE.
        // Apply lexicographical comparison with only ONE return value.
        //

        check_operation(p0, p1, p2, p3, p4, p5, p6);
    }
}

/* LEXICOGRAPHICAL_COMPARATOR_SOURCE */
#endif
