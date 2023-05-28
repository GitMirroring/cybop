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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FIFO_ARRAY_FINDER_SOURCE
#define FIFO_ARRAY_FINDER_SOURCE

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Finds the index of the given sequence within the investigated array,
 * using the first-in-first-out (fifo) principle (queue).
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated data
 * @param p2 the searched name data
 * @param p3 the investigated count
 * @param p4 the searched name count
 * @param p5 the type
 */
void find_array_fifo(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find array fifo.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The loop variable.
    //
    // CAUTION! Do NOT delete this variable since it is needed as result index.
    //
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The investigated data position.
    void* pos = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The investigated count remaining.
    int rem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise investigated data position.
    copy_pointer((void*) &pos, (void*) &p1);
    // Initialise investigated count remaining.
    copy_integer((void*) &rem, p3);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! The second comparison operand would normally be ZERO:
        // compare_integer_less_or_equal((void*) &b, (void*) &rem, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        //
        // However, in order to be more efficient and break the loop earlier,
        // the searched name count is used as second operand here since
        // both operands cannot be equal anymore if their count differs.
        //
        // CAUTION! Use the "less" and NOT the "less_or_equal" function here,
        // since the case of equal counts still has to be considered below
        // and both operands might be equal.
        //
        compare_integer_less((void*) &b, (void*) &rem, p4);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The maximum loop count has been reached.
            // All elements have been compared.
            // A part with the searched name could not be found.
            // Leave index untouched.
            //

            break;

        } else {

            // Compare part name with given searched name.
            check_operation((void*) &r, pos, p2, (void*) &rem, p4, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, p5);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The part with the searched name has been found.
                //

                // Remember the index.
                copy_integer(p0, (void*) &j);

                // The loop may be left now.
                break;

            } else {

                // Move the current position.
                move((void*) &pos, (void*) &rem, p5, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                // Increment loop variable.
                j++;
            }
        }
    }
}

/* FIFO_ARRAY_FINDER_SOURCE */
#endif
