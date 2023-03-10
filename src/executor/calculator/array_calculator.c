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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ARRAY_CALCULATOR_SOURCE
#define ARRAY_CALCULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/calculator/calculator.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/memoriser/offset_adder.c"
#include "../../logger/logger.c"

/**
 * Calculates count elements of the result- and operand array.
 *
 * @param p0 the result array, which contains the operand BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the count
 */
void calculate_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate array elements.");

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p4 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p4);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        calculate_offset(p0, p1, p2, p3, (void*) &j);

        j++;
    }
}

/**
 * Adds offset to destination and source.
 *
 * @param p0 the result array, which contains the operand BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the count
 * @param p5 the result index
 * @param p6 the operand index
 */
void calculate_array_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // CAUTION! These null pointer comparisons are IMPORTANT,
    // in order to avoid a system crash if parametre values are null!

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate array offset.");

            // The result array, operand array.
            // CAUTION! They HAVE TO BE initialised with p0 and p1,
            // since an offset is added below.
            void* r = p0;
            void* o = p1;

            // Add offset.
            add_offset((void*) &r, p3, p5);
            add_offset((void*) &o, p3, p6);

            calculate_array_elements(r, o, p2, p3, p4);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate array offset. The result array (operand before the operation) is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate array offset. The operand array is null.");
    }
}

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

    // The result index comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The operand index comparison result.
    int o = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_less((void*) &r, p5, p4);
    compare_integer_less((void*) &o, p6, p4);

    if (o != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate array.");

            calculate_array_offset(p0, p1, p2, p3, p4, p5, p6);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate array. The result index is not smaller than the count.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate array. The operand index is not smaller than the count.");
    }
}

/* ARRAY_CALCULATOR_SOURCE */
#endif
