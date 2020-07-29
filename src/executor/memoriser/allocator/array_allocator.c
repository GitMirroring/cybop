/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ARRAY_ALLOCATOR_SOURCE
#define ARRAY_ALLOCATOR_SOURCE

#include <stdlib.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"
#include "../../../variable/reference_counter.c"

/**
 * Allocates the array.
 *
 * @param p0 the array (pointer reference)
 * @param p1 the size
 * @param p2 the type
 */
void allocate_array(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** a = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate array.");

        // The memory area.
        int ma = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Determine type (type) size.
        determine_size((void*) &ma, p2);
        // Calculate memory area.
        calculate_integer_multiply((void*) &ma, p1);

        // Test memory area for valid value.
        //
        // Quotation from the C standard:
        // If the space cannot be allocated, a null pointer is returned.
        // If the size of the space requested is zero, the behavior is
        // implementation defined: either a null pointer is returned,
        // or the behavior is as if the size were some nonzero value,
        // except that the returned pointer shall NOT be used to access an object.
        //
        // In other words:
        // Calling malloc(0) will return either a null pointer or
        // a unique pointer that can be successfully passed to free().
        // For practical purposes, it's pretty much the same as doing:
        // variable = NULL;
        //
        // Even though nothing gets allocated, the variable may be passed
        // to a call to free() without worry, since:
        // - free(NULL) is ok, no operation is done
        // - free(address) is ok, if address was received from malloc
        //
        // http://stackoverflow.com/questions/1073157/zero-size-malloc/1073175
        // http://stackoverflow.com/questions/2022335/whats-the-point-in-malloc0
        //
        // CAUTION! Wherever something gets allocated in source code,
        // it HAS TO HAVE a size of at least one byte.
        // Otherwise, nothing gets allocated.
        if (ma > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // The temporary size_t variable.
            //
            // CAUTION! It IS NECESSARY because on 64 Bit machines,
            // the "size_t" type has a size of 8 Byte,
            // whereas the "int" type has the usual size of 4 Byte.
            // When trying to cast between the two, memory errors
            // will occur and the valgrind memcheck tool report:
            // "Invalid read of size 8".
            //
            // CAUTION! Initialise temporary size_t variable with final int value
            // JUST BEFORE handing that over to the glibc function requiring it.
            //
            // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
            // because values are casted to int* internally again.
            size_t tma = (size_t) ma;

            // Allocate memory area.
            *a = malloc(tma);

            // Increment array reference counter.
            // CAUTION! This is ONLY needed for debugging.
            (*ARRAY_REFERENCE_COUNTER)++;

            if (*a != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Initialise array elements.
                //
                // CAUTION! Initialising with zero values is essential,
                // since cyboi frequently tests variables for null pointer values.
                // Otherwise, unpredictable pre-existing values might reside in memory.
                //
                // Whether the values will be interpreted as
                // zero integer or zero float or null pointer or
                // something else, depends on the programming
                // context, i.e. where the array got allocated.
                memset(*a, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, tma);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The allocated memory area is null.");
            }

        } else if (ma == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The memory area to be allocated is zero.");
//??            fwprintf(stdout, L"Error: Could not allocate array. The memory area to be allocated is zero: %i\n", *a);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The memory area to be allocated is negative.");
            fwprintf(stdout, L"Error: Could not allocate array. The memory area to be allocated is negative: %i\n", *a);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The array is null.");
    }
}

/* ARRAY_ALLOCATOR_SOURCE */
#endif
