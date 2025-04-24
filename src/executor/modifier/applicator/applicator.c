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

//
// Forward declaration
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

/**
 * Applies the given function to the items of the destination node.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the index pointing to the current element
 * @param p4 the function part
 * @param p5 the internal memory data
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the signal memory item
 * @param p9 the internal memory data (pointer reference)
 * @param p10 the shutdown flag
 */
void apply(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply.");
    fwprintf(stdout, L"Information: Apply. destination array count p1: %i\n", p1);
    fwprintf(stdout, L"Information: Apply. destination array count *p1: %i\n", *((int*) p1));
    fwprintf(stdout, L"Information: Apply. index p3: %i\n", p3);
    fwprintf(stdout, L"Information: Apply. index *p3: %i\n", *((int*) p3));

    //
    // CAUTION! The destination is NOT an item, but an array,
    // since this function is called from file "array_modifier.c".
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The direct execution flag.
    //
    // CAUTION! The flag has to be set to true, because otherwise,
    // each loop cycle places a new signal in signal memory so that
    // these would only be processed with a delay.
    // But this is not desirable, since follow-up signals of this
    // loop may rely on its full execution, including all cycles.
    //
    int x = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p1 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_greater_or_equal((void*) &b, p3, p1);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The break flag is TRUE.
            //

            // Leave the loop.
            break;

        } else {

            //
            // The break flag is FALSE (not set).
            //

            // Handle the function as new operation.
            handle(p4, p5, p6, p7, p8, p9, (void*) &x, p10, *NULL_POINTER_STATE_CYBOI_MODEL);

            // Increment loop variable.
            calculate_integer_add(p3, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }
}
