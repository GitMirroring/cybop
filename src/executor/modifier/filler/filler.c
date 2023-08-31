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

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Fills the array.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the destination array count
 * @param p7 the destination array size
 * @param p8 the adjust count flag
 */
void fill(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Fill.");

    // The loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Initialise loop count with destination index parametre
    // PLUS the count parametre.
    //
    calculate_integer_add((void*) &c, p5);
    calculate_integer_add((void*) &c, p4);
    //
    // Initialise loop variable with destination index parametre.
    //
    // That way, all destination entries starting from
    // the given index parametre are processed.
    //
    calculate_integer_add((void*) &j, p5);

    //
    // CAUTION! The usual loop count parametre test for NULL
    // is NOT necessary here, since a local variable is used.
    // Therefore, the loop count variable comparison will work
    // and the break flag may be set to true.
    //

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        //
        // Fill given element repeatedly into array.
        // The count and size are adjusted inside.
        //
        overwrite(p0, p1, p2, p3, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &j, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6, p7, p8);

        // Increment loop variable.
        calculate_integer_add((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}
