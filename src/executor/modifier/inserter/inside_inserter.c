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

#ifndef INSIDE_INSERTER_SOURCE
#define INSIDE_INSERTER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../executor/copier/array/backward_array_copier.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../executor/referencer/referencer.c"
#include "logger.h"

/**
 * Inserts the source- INSIDE the destination array.
 *
 * All current elements existing behind the given index in the destination array
 * are moved towards the end by the number of elements inserted.
 *
 * CAUTION! This is done in a BACKWARDS order, starting from the last element,
 * since otherwise, some elements might overlap and get overwritten.
 *
 * Example:
 *
 * destination array: "HelloWorld!"
 * source array: "blubla, blubla"
 * count: 2
 * destination index: 5
 * source index: 6
 * destination array count: 11
 * ==> result: "Hello, World"
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 * @param p7 the destination array count
 * @param p8 the destination array size
 */
void insert_inside(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Insert inside.");

        // The move destination index.
        int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The move count.
        int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The new destination array count.
        int nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Add destination index.
        calculate_integer_add((void*) &i, p5);
        // Add count of source elements to be inserted.
        calculate_integer_add((void*) &i, p4);

        // Add destination array count.
        calculate_integer_add((void*) &c, p7);
        // Subtract destination index.
        calculate_integer_subtract((void*) &c, p5);

        // Add destination array count.
        calculate_integer_add((void*) &nc, p7);
        // Add count of new elements to be inserted.
        calculate_integer_add((void*) &nc, p4);

        if (i >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            if (c >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                if (nc >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // The comparison result.
                    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                    compare_integer_greater((void*) &r, (void*) &nc, p8);

                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        // Initialise new destination size with new destination count.
                        int ns = nc;

                        //
                        // Multiply new destination size with factor.
                        //
                        // CAUTION! This multiplication has to be done AFTER the comparison
                        // of new size and old size since otherwise, the new size is falsified,
                        // which would lead to runtime errors.
                        //
                        calculate_integer_multiply((void*) &ns, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);

                        // Make sure allocation size is at least one.
                        if (ns < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
                            fwprintf(stdout, L"Error: Could not insert inside. The new size is negative ns: %i\n", ns);
                        } else if (ns == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
                            fwprintf(stdout, L"Error: Could not insert inside. The new size is zero ns: %i\n", ns);
//??                            ns = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                        }

                        //
                        // Enlarge array using new destination size.
                        //
                        // CAUTION! Due to memory allocation handling, the size MUST NOT
                        // be negative or zero, but have at least a value of ONE.
                        //
                        reallocate_array(p0, p7, (void*) &ns, p2);

                        // Set new size.
                        copy_integer(p8, (void*) &ns);
                    }

                    //
                    // Move current elements behind given index towards the end of the array.
                    //
                    // CAUTION! Move array elements starting from the LAST since otherwise,
                    // overlapping array elements might get overwritten!
                    //
                    // CAUTION! Call this function AFTER having resized the array
                    // since otherwise, it might not be big enough and elements be cut.
                    //
                    // CAUTION! Set the deep copying flag to FALSE here,
                    // since only POINTERS or PRIMITIVE VALUES are to be moved,
                    // but NOT sub trees copied.
                    //
                    copy_array_backward(*d, *d, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &c, (void*) &i, p5);

                    //
                    // Copy source to destination.
                    //
                    // CAUTION! Set the deep copying flag to the PARAMETRE here,
                    // since the source may be of primitive types like pointer or integer,
                    // but also of a compound node type with sub tree.
                    //
                    copy_array_forward(*d, p1, p2, p3, p4, p5, p6);

                    // Set destination array count.
                    copy_integer(p7, (void*) &nc);

                    //
                    // Increment reference count of inserted parts for rubbish (garbage) collection.
                    //
                    // CAUTION! This has to be done AFTER having inserted elements,
                    // since beforehand, these are not known to the destination yet.
                    //
                    reference(*d, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT, p4, p5, p2);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not insert inside. The new size is negative.");
                    fwprintf(stdout, L"Error: Could not insert inside. The new size is negative n: %i\n", nc);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not insert inside. The move count is negative.");
                fwprintf(stdout, L"Error: Could not insert inside. The move count is negative c: %i\n", c);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not insert inside. The move destination index is negative.");
            fwprintf(stdout, L"Error: Could not insert inside. The move destination index is negative i: %i\n", i);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not insert inside. The destination array is null.");
    }
}

/* INSIDE_INSERTER_SOURCE */
#endif
