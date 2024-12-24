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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Applies the given function to all elements of the input collection.
 *
 * @param p0 the output item
 * @param p1 the input collection data
 * @param p2 the input collection count
 * @param p3 the function
--
 * @param p0 the signal part
 * @param p1 the internal memory data
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the signal memory item
 * @param p5 the internal memory data (pointer reference)
 * @param p6 the direct execution flag
 * @param p7 the shutdown flag
 * @param p8 the cybol loop break property
 */
/*??
void apply_reduce_loop(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply reduce loop.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The input collection element part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary arguments item.
    int a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary arguments item data, count.
    int ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ac = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate temporary arguments item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &a, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, src_count);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // Get source part with given index.
            copy_array_forward((void*) &p, src-input-collection-data, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) j);

            // Empty temporary arguments item.
            modify_empty(a);

            // Append destination element to temporary arguments item.
            modify_append(a, dest);
            // Append source element to temporary arguments item.
            modify_append(a, se);

            // Get temporary arguments item data, count.
            copy_array(ad, a, DATA);
            copy_array(ac, a, COUNT);

            //
            // Handle logic operation.
            //
            // CAUTION! The comparison if to call "handle_operation"
            // or "handle_compound" is done inside the "handle" function.
            //
            //?? TODO: How to identify function arguments (properties) inside,
            // by their name or by position (index)?
            //
 * @param p0 the signal part
 * @param p1 the internal memory data
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the signal memory item
 * @param p5 the internal memory data (pointer reference)
 * @param p6 the direct execution flag
 * @param p7 the shutdown flag
 * @param p8 the cybol loop break property
            handle(ad, ac);
            handle(signal-model-part, p4, p2, p3, p5, p6, (void*) &x, p7, *NULL_POINTER_STATE_CYBOI_MODEL);

            // Increment loop variable.
            j++;
        }
    }

    // Deallocate temporary arguments item.
    deallocate_item((void*) &a, (void*) POINTER_STATE_CYBOI_TYPE);
}
*/
