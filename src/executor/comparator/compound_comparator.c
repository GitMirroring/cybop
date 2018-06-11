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

#ifndef COMPOUND_COMPARATOR_SOURCE
#define COMPOUND_COMPARATOR_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/comparator/lexicographical_comparator.c"
#include "../../executor/comparator/scalar_count_comparator.c"
#include "../../logger/logger.c"

/**
 * Tests whether or not this is a compound part and calls the corresponding function.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data (array)
 * @param p2 the right data (array)
 * @param p3 the left count
 * @param p4 the right count
 * @param p5 the operation type
 * @param p6 the operand type
 * @param p7 the count
 * @param p8 the result count
 * @param p9 the lexicographical flag
 */
void compare_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare compound.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p6, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a compound part.
        // Apply comparison with only ONE scalar return value.
        //

        // Leave last argument (lexicographical flag) untouched.
        compare_count_scalar(p0, p1, p2, p3, p4, p5, p6, p8);

    } else {

        compare_lexicographical(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
    }
}

/* COMPOUND_COMPARATOR_SOURCE */
#endif
