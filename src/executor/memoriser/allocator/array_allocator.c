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

#ifndef ARRAY_ALLOCATOR_SOURCE
#define ARRAY_ALLOCATOR_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <stdlib.h> // malloc
#include <string.h> // memset
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"
#include "mapper.h"
#include "variable.h"

/**
 * Allocates the array.
 *
 * @param p0 the array (pointer reference)
 * @param p1 the size
 * @param p2 the type
 */
void allocate_array(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** a = (void**) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate array.");

                // The memory area.
                int ma = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                // Determine type (type) size.
                map_type_to_size((void*) &ma, p2);
                // Calculate memory area.
                calculate_integer_multiply((void*) &ma, p1);

                if (ma > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    //
                    // The memory area casted to the correct type.
                    //
                    // CAUTION! It IS NECESSARY because on 64 Bit machines,
                    // the "size_t" type has a size of 8 Byte,
                    // whereas the "int" type has the usual size of 4 Byte.
                    //
                    // When trying to cast between the two, memory errors
                    // will occur and the valgrind memcheck tool report:
                    // "Invalid read of size 8".
                    //
                    // CAUTION! Initialise temporary size_t variable with final int value
                    // JUST BEFORE handing that over to the glibc function requiring it.
                    //
                    // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
                    // because values are CASTED to INTEGER int* internally again.
                    //
                    size_t mat = (size_t) ma;

                    //
                    // Allocate memory area.
                    //
                    // CAUTION! Due to memory allocation handling, the size MUST NOT
                    // be negative or zero, but have at least a value of ONE.
                    //
                    // Otherwise, NOTHING gets allocated.
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
                    *a = malloc(mat);

                    //
                    // Increment array reference counter.
                    //
                    // CAUTION! This is ONLY needed for debugging.
                    //
                    (*ARRAY_REFERENCE_COUNTER)++;

                    if (*a != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        //
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
                        //
                        memset(*a, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, mat);

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The allocated memory area is null.");
                        fwprintf(stdout, L"Error: Could not allocate array. The allocated memory area is null. *a: %i\n", *a);
                    }

                } else if (ma == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The memory area to be allocated is zero which should NEVER happen.");
                    fwprintf(stdout, L"Error: Could not allocate array. The memory area to be allocated is zero which should NEVER happen. ma: %i, size p1: %i, type p2: %i\n", ma, p1, p2);
                    fwprintf(stdout, L"Error: Could not allocate array. The memory area to be allocated is zero which should NEVER happen. ma: %i, size *p1: %i, type *p2: %i\n", ma, *((int*) p1), *((int*) p2));

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The memory area to be allocated is negative which should NEVER happen.");
                    fwprintf(stdout, L"Error: Could not allocate array. The memory area to be allocated is negative which should NEVER happen. ma: %i\n", ma);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The array is null.");
                fwprintf(stdout, L"Error: Could not allocate array. The array is null. array p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The size is null.");
            fwprintf(stdout, L"Error: Could not allocate array. The size is null. size p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate array. The type is null.");
        fwprintf(stdout, L"Error: Could not allocate array. The type is null. type p2: %i\n", p2);
    }
}

/* ARRAY_ALLOCATOR_SOURCE */
#endif
