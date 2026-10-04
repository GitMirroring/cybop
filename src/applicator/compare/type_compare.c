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
 * Compares the type of left- and right operand.
 *
 * If a wrong knowledge path is given, e.g. with non-existing node-names,
 * then a cybol operation might write data into a wrong destination,
 * e.g. source data of format "text/plain" (type wide character)
 * into a destination of format "element/part" (type pointer).
 *
 * Therefore, the types have to be IDENTICAL.
 *
 * @param p0 the result
 * @param p1 the left operand part
 * @param p2 the right operand part
 * @param p3 the operation type
 * @param p4 the left operand type
 * @param p5 the count
 * @param p6 the left index
 * @param p7 the right index
 * @param p8 the result count
 * @param p9 the lexicographical flag
 * @param p10 the right operand type
 */
void apply_compare_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply compare type.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p4, p10);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The left- and right type are identical.
        //

        compare_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply compare type. The left- and right operand type are different.");
        fwprintf(stdout, L"Error: Could not apply compare type. The left- and right operand type are different.\n");
        fwprintf(stdout, L"Error: Left operand type: %i. Right operand type: %i.\n", *((int*) p4), *((int*) p5));
    }
}
