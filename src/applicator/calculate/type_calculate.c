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
#include "knowledge.h"
#include "logger.h"

/**
 * Compares the type of result- and operand node.
 *
 * If a wrong knowledge path is given, e.g. with non-existing node-names,
 * then a cybol operation might write data into a wrong destination,
 * e.g. source data of format "text/plain" (type wide character)
 * into a destination of format "element/part" (type pointer).
 *
 * Therefore, the types have to be IDENTICAL.
 *
 * @param p0 the result part, which contains the operand BEFORE the operation
 * @param p1 the operand part
 * @param p2 the operation type
 * @param p3 the result type
 * @param p4 the count
 * @param p5 the result index
 * @param p6 the operand index
 * @param p7 the operand type
 */
void apply_calculate_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply calculate type.");
    //?? fwprintf(stdout, L"Debug: Apply calculate type. p7: %i\n", p7);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p7 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The second operand (besides result) is MISSING.
        //
        // Therefore, a comparison of result- and operand type
        // is NOT possible and the function called directly.
        // This is probably an increment or decrement operation.
        //

        calculate_part(p0, p1, p2, p3, p4, p5, p6);

        // Set comparison result.
        r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Debug: Apply calculate type. Inside element/part. This should NOT be used with a calculate/* operation! It is probably an ERROR. Check this out. r: %i\n", r);
            fwprintf(stdout, L"TODO: Can this if-branch be deleted altogether? r: %i\n", r);

            //
            // The second operand's type is "element/part".
            //
            // Therefore, a comparison of result- and operand type
            // is NOT possible and the function called directly.
            // This is probably an operation with MANY operands
            // given as children of a PART.
            //

            calculate_part(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The type comparison result.
        int tr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_equal((void*) &tr, p3, p7);

        if (tr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The result- and operand type are IDENTICAL.
            //
            // Call function normally.
            // This is the standard case.
            //

            calculate_part(p0, p1, p2, p3, p4, p5, p6);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply calculate type. The result type and operand type are different.");
            fwprintf(stdout, L"Error: Could not apply calculate type. The result type and operand type are different.\n");
            fwprintf(stdout, L"Error: Result type: %i. Operand type: %i.\n", *((int*) p3), *((int*) p7));
        }
    }
}
