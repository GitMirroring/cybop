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
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Evaluates the case insensitive flag.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data
 * @param p2 the right data
 * @param p3 the left count
 * @param p4 the right count
 * @param p5 the operation type
 * @param p6 the operand type
 * @param p7 the case insensitive flag
 */
void check_case(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check case.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Use case SENSITIVE comparison by default.
        // [German: schreibungsABHÄNGIG]
        //

        check_operation(p0, p1, p2, p3, p4, p5, p6);

    } else {

        //
        // Use case INSENSITIVE comparison by default.
        // [German: schreibungsUNABHÄNGIG]
        //

        check_insensitiveness(p0, p1, p2, p3, p4, p5, p6);
    }
}
