/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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
 * Tests if the result count has the numeric value of exactly "one".
 *
 * If this was not done here, then assigning a result value
 * might cause segmentation fault errors, since even if
 * the result pointer exists and is not null,
 * its size might be zero so that assigning a value
 * would cross array boundaries.
 *
 * A result count greater than one does not make sense
 * and is therefore excluded here.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data
 * @param p2 the right data
 * @param p3 the left count
 * @param p4 the right count
 * @param p5 the operation type
 * @param p6 the operand type
 * @param p7 the result count
 */
void compare_count_scalar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare count scalar.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p7, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation(p0, p1, p2, p3, p4, p5, p6);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare count scalar. The result count is not one.");
        fwprintf(stdout, L"Error: Could not compare count scalar. The result count is not one.\n");
        fwprintf(stdout, L"Hint: Result count p7: %i\n", p7);
        fwprintf(stdout, L"Hint: Result count *p7: %i\n", *((int*) p7));
    }
}
