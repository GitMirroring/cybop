/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Tests if the result count is equal to the count.
 *
 * If this was not done here, then assigning a result value
 * might cause segmentation fault errors, since even if
 * the result pointer exists and is not null,
 * its size might be zero or less than the count,
 * so that assigning a value would cross array boundaries.
 *
 * @param p0 the result array (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the count
 * @param p6 the left index
 * @param p7 the right index
 * @param p8 the left count
 * @param p9 the right count
 * @param p10 the result count
 */
void compare_count_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare count vector.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p10, p5);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_index(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare count vector. The result count and count are not equal.");
        fwprintf(stdout, L"Error: Could not compare count vector. The result count and count are not equal.\n");
        fwprintf(stdout, L"Hint: Result count p10: %i. Count p5: %i.\n", p10, p5);
        fwprintf(stdout, L"Hint: Result count *p10: %i. Count *p5: %i.\n", *((int*) p10), *((int*) p5));
    }
}
