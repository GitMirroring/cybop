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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/*
 * Distinguishes operands between part and primitive type.
 *
 * @param p0 the result
 * @param p1 the left operand (pointer reference only if type is part or pointer)
 * @param p2 the right operand (pointer reference only if type is part or pointer)
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the criterion data (pointer reference)
 * @param p6 the criterion count
 * @param p7 the criterion type
 * @param p8 the knowledge memory part (pointer reference)
 * @param p9 the stack memory item
 * @param p10 the internal memory data
 */
void sort_bubble_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble type.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p4, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Use special comparison for compound parts.
        //

        sort_bubble_part(p0, p1, p2, p3, p5, p6, p7, p8, p9, p10);

    } else {

        //
        // Use standard comparison for all other cases.
        //

        compare(p0, p1, p2, p3, p4);
    }
}
