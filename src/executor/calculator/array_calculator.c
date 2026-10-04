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
#include "knowledge.h"
#include "logger.h"

/**
 * Tests result and operand for null pointers.
 *
 * @param p0 the result array, which contains the operand BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the count
 * @param p5 the result index
 * @param p6 the operand index
 */
void calculate_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate array.");
    //?? fwprintf(stdout, L"Debug: Calculate array. operation type p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Calculate array. operation type *p2: %i\n", *((int*) p2));

    // The comparison results.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int r1 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int r2 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_less((void*) &r1, p5, p4);
    compare_integer_less((void*) &r2, p6, p4);

    copy_integer((void*) &r, (void*) &r1);

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A second operand IS given.
        // Therefore, consider the SECOND comparison result here as well.
        //

        logify_boolean_and((void*) &r, (void*) &r2);

    } else {

        //
        // A second operand is NOT given.
        //
        // This is probably an operation which needs only ONE operand,
        // like for instance "calculate/increment".
        // Therefore, the second comparison result must NOT be
        // considered here since otherwise, this function will
        // not return true and the operation FAIL in the end.
        //
        // REMARK: This empty block containing a comment only
        // does no harm, since the compiler will remove it anyway.
        //
    }

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_array_offset(p0, p1, p2, p3, p4, p5, p6);

    } else {

        //
        // The result index or operand index is NOT smaller than the count.
        //
        // This should not happen and is probably an error
        // in cybol application code.
        //

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate array. The result index or operand index is not smaller than the count.");
        fwprintf(stdout, L"Error: Could not calculate array. The result index or operand index is not smaller than the count.\n");

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Possibly, the count is zero or the element was not initialised or it is null.");
        fwprintf(stdout, L"Error: Possibly, the count is zero or the element was not initialised or it is null.\n");
    }
}
