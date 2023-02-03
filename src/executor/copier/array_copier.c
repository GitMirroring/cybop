/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ARRAY_COPIER_SOURCE
#define ARRAY_COPIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/comparator/integer/less_integer_comparator.c"
#include "../../executor/copier/copier.c"
#include "../../executor/memoriser/offset_adder.c"
#include "../../logger/logger.c"

/**
 * Copies count source array elements into the destination array.
 *
 * It uses FORWARD copying, i.e. the loop variable is INCREMENTED.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 */
void copy_array_elements_forward(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //
    // CAUTION! Do NOT call the logger here.
    // It uses functions causing circular references.
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy array elements forward.");
    //

    //?? fwprintf(stdout, L"Debug: Copy array elements forward. p3: %i\n", p3);

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p4 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"Debug: Copy array elements forward. p4: %i\n", p4);

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p4);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        copy_offset(p0, p1, p2, p3, (void*) &j);

        j++;
    }
}

/**
 * Copies count source array elements into the destination array.
 *
 * It uses BACKWARD copying, i.e. the loop variable is DECREMENTED.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 */
void copy_array_elements_backward(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy array elements backward.");
    //?? fwprintf(stdout, L"Debug: Copy array elements backward. p3: %i\n", p3);

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p4 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    // Initialise loop variable with count.
    copy_integer((void*) &j, p4);
    // CAUTION! Subtract one because this is an index.
    calculate_integer_subtract((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &b, (void*) &j, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        copy_offset(p0, p1, p2, p3, (void*) &j);

        j--;
    }
}

/**
 * Copies source- into destination array,
 * starting from the given offset.
 *
 * This is the FORWARD version.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 */
void copy_array_forward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! These null pointer comparisons are IMPORTANT, in order to
    // avoid a system crash if source- or destination array are null!
    // All other modifier functions are based on this copier function,
    // so that checking for null pointer right here suffices.
    //

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy array forward.");
            //

            //
            // The destination array, source array.
            // CAUTION! They HAVE TO BE initialised with p0 and p1,
            // since an offset is added below.
            //
            void* d = p0;
            void* s = p1;

            add_offset((void*) &d, p2, p5);
            add_offset((void*) &s, p2, p6);

            copy_array_elements_forward(d, s, p2, p3, p4);

        } else {

            //
            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy array forward. The destination array is null.");
            //

            fwprintf(stdout, L"Error: Could not copy array forward. The destination array is null. p0: %i\n", p0);
        }

    } else {

        //
        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy array forward. The source array is null.");
        //

        //?? fwprintf(stdout, L"Error: Could not copy array forward. The source array is null. p1: %i\n", p1);
    }
}

/**
 * Copies source- into destination array,
 * starting from the given offset.
 *
 * This is the BACKWARD version.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 */
void copy_array_backward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! These null pointer comparisons are IMPORTANT, in order to
    // avoid a system crash if one or both of the two arrays are null!
    // All other copying functions are based on this copier function,
    // so that checking for null pointer right here suffices.
    //

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy array backward.");

            //
            // The destination array, source array.
            //
            // CAUTION! They HAVE TO BE initialised with p0 and p1,
            // since an offset is added below.
            //
            void* d = p0;
            void* s = p1;

            add_offset((void*) &d, p2, p5);
            add_offset((void*) &s, p2, p6);

            copy_array_elements_backward(d, s, p2, p3, p4);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy array backward. The destination array is null.");
            fwprintf(stdout, L"Error: Could not copy array forward. The destination array is null. p0: %i\n", p0);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy array backward. The source array is null.");
        fwprintf(stdout, L"Error: Could not copy array forward. The source array is null. p1: %i\n", p1);
    }
}

/* ARRAY_COPIER_SOURCE */
#endif
