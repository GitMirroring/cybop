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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <stdlib.h>
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"
#include "mapper.h"

/**
 * Reallocates the array.
 *
 * @param p0 the array (pointer reference)
 * @param p1 the count
 * @param p2 the size
 * @param p3 the type
 */
void reallocate_array(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* c = (int*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** a = (void**) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Reallocate array.");

                // The memory area.
                int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                // Determine type size.
                map_type_to_size((void*) &m, p3);

                // Calculate memory area.
                calculate_integer_multiply((void*) &m, p2);

                //
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
                //
                if (m > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    //
                    // Cast memory area to correct type.
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
                    //
                    size_t mt = (size_t) m;

                    //
                    // Create a new array with extended size.
                    //
                    // Since the space after the end of the block may be in use,
                    // realloc may find it necessary to copy the block to a
                    // new address where more free space is available.
                    // The value of realloc is the new address of the block.
                    // If the block needs to be moved, realloc copies the old contents.
                    //
                    // CAUTION! Do NOT assign the returned pointer to *a right away.
                    // If it is null and assigned to *a, then the original array
                    // is not reachable anymore and thus cannot be deallocated properly,
                    // leading to memory leaks.
                    // Therefore, assign to a temporary variable
                    // which gets tested for NULL below.
                    //
                    void* tmp = realloc(*a, mt);

                    if (tmp != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        // Assign pointer to reallocated array ONLY if successful.
                        *a = tmp;

                        if (*s > *c) {

                            //
                            // CAUTION! If count and size are equal, then nothing
                            // is to be done.
                            //
                            // CAUTION! Do NOT change this value if the size is
                            // smaller than the count, because this will result
                            // in a negative value and cause the new array elements
                            // pointer further below to cross the array's boundary!
                            // If the size is smaller than the count, elements
                            // outside the smaller size area are just lost.
                            //

                            // The NEW memory area to be initialised.
                            int nm = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                            //
                            // Calculate extra array size, which is the given array size
                            // reduced by the existing element count.
                            //
                            int es = *s - *c;

                            // Determine type size.
                            map_type_to_size((void*) &nm, p3);

                            // Calculate new memory area.
                            calculate_integer_multiply((void*) &nm, (void*) &es);

                            // The memory area difference.
                            int d = m - nm;
                            // The new array elements.
                            void* na = (void*) ((size_t) *a + d);

                            //
                            // Cast new memory area to correct type.
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
                            //
                            size_t nmt = (size_t) nm;

                            //
                            // Initialise ONLY NEW array elements (new memory area)
                            // with zero. Leave existing elements untouched.
                            //
                            // CAUTION! Initialising with zero values is essential, since
                            // cyboi frequently tests variables for null pointer values.
                            //
                            // CAUTION! Do NOT use large values, since the zero value gets
                            // converted to an unsigned char inside the "memset" function.
                            //
                            memset(na, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, nmt);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not reallocate array. The allocated memory area is null.");
                        fwprintf(stdout, L"Error: Could not reallocate array. The allocated memory area is null. tmp: %i\n", tmp);
                    }

                } else if (m == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    //
                    // CAUTION! The memory area (new array size) MUST NOT be zero.
                    // If it was equal to zero, then the "realloc" function call
                    // would be equivalent to "free" -- an unwanted side effect
                    // that would destroy allocated memory areas and lead to errors.
                    //

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not reallocate array. The memory area to be allocated is zero.");
                    fwprintf(stdout, L"Error: Could not reallocate array. The memory area to be allocated is zero: %i\n", *a);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not reallocate array. The memory area to be allocated is negative.");
                    fwprintf(stdout, L"Error: Could not reallocate array. The memory area to be allocated is negative: %i\n", *a);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not reallocate array. The array is null.");
                fwprintf(stdout, L"Error: Could not reallocate array. The array is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not reallocate array. The count is null.");
            fwprintf(stdout, L"Error: Could not reallocate array. The count is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not reallocate array. The size is null.");
        fwprintf(stdout, L"Error: Could not reallocate array. The size is null. p2: %i\n", p2);
    }
}
