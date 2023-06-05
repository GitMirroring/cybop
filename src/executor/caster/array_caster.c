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

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Casts count elements of the source- to the destination array.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the source type
 * @param p3 the operation (destination) type
 * @param p4 the count
 */
void cast_array_elements(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cast array elements.");

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

        cast_offset(p0, p1, p2, p3, (void*) &j);

        j++;
    }
}

/**
 * Adds offset to destination and source.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the source type
 * @param p3 the operation (destination) type
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 */
void cast_array_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // CAUTION! These null pointer comparisons are IMPORTANT,
    // in order to avoid a system crash if parametre values are null!

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cast array.");

            // The destination array, source array.
            // CAUTION! They HAVE TO BE initialised with p0 and p1,
            // since an offset is added below.
            void* d = p0;
            void* s = p1;

            // Add offset.
            add_offset((void*) &d, p3, p5);
            add_offset((void*) &s, p2, p6);

            cast_array_elements(d, s, p2, p3, p4);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast array. The destination array is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast array. The source array is null.");
    }
}

/**
 * Tests destination and source for null pointers.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the source type
 * @param p3 the operation (destination) type
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 */
void cast_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The destination index comparison result.
    int d = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The source index comparison result.
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_less((void*) &d, p5, p4);
    compare_integer_less((void*) &s, p6, p4);

    if (s != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (d != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cast array.");

            cast_array_offset(p0, p1, p2, p3, p4, p5, p6);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast array. The destination index is not smaller than the count.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast array. The source index is not smaller than the count.");
    }
}
