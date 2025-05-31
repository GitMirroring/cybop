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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/*
 * Sorts the given data array using the bubble algorithm.
 *
 * @param p0 the array data (pointer reference only if type is part or pointer)
 * @param p1 the type
 * @param p2 the array count
 * @param p3 the criterion data (pointer reference)
 * @param p4 the criterion count
 * @param p5 the criterion type
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 * @param p9 the descending flag
 */
void sort_bubble(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble.");

    // The loop variable.
    // CAUTION! Initialise it with value "1",
    // in order to fulfill the requirements of the algorithm,
    // so that e.g. predecessor and successor are determined correctly
    // without crossing array boundaries.
    int j = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The swapped flag.
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The left value.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right value.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bubble loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! Do NOT use local variables for left and right value here.
    // Their type is unknown at design time and only determined
    // by parametre argument at runtime.
    // Therefore, the "allocate_array" function has to be used,
    // in order to be able to forward the given type argument.
    //
    // This is done ONLY ONCE right here and NOT INSIDE the loop
    // and called functions, since memory allocation takes time.
    //

    // Allocate left value.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p1);
    // Allocate right value.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &r, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p1);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Reset swapped flag.
        s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // Reset bubble loop count.
        c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Calculate bubble loop count.
        //
        // CAUTION! This is an optimisation.
        // Reduce the data array count by the current index!
        // This causes the loop to sort only that part of
        // the array that has not been sorted yet.
        //
        // CAUTION! Since j got initialised with 1 (one) above,
        // it may happen that the result is -1 (negative),
        // in case the array count p2 is zero.
        // However, this is NOT a problem, since the loop criterion inside the
        // "sort_bubble_bubble" function uses the "greater_or_equal" operation.
        copy_integer((void*) &c, p2);
        calculate_integer_subtract((void*) &c, (void*) &j);

        // Bubble up the greater value.
        sort_bubble_bubble(p0, p1, (void*) &s, l, r, (void*) &c, p3, p4, p5, p6, p7, p8, p9);

        // CAUTION! This is an optimisation.
        // Break loop if nothing is left to be sorted.
        // If the swapped flag remained unchanged,
        // then nothing was changed inside the array.
        if (s == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Increment loop variable.
        j++;
    }

    // Deallocate left value.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &l, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p1);
    // Deallocate right value.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &r, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p1);
}
