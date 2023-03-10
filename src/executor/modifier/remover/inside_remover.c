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

#ifndef INSIDE_REMOVER_SOURCE
#define INSIDE_REMOVER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/referencer/referencer.c"
#include "../../../logger/logger.c"

/**
 * Removes the given number of array elements.
 *
 * All current elements existing behind the area to be removed
 * from the array are moved towards the beginning.
 *
 * CAUTION! This is done in a FORWARD order, starting from the
 * FIRST element (behind the area to be removed) since otherwise,
 * overlapping elements might get overwritten.
 *
 * The destination size is NOT changed.
 * See comment in source code for reasons!
 *
 * A new destination count is ONLY assigned,
 * if the "adjust count flag" is set.
 * The reason is that sometimes, constants are handed over
 * as count, which may NOT be changed. Otherwise, unpredictable
 * values and pointers would occur in the programme.
 *
 * Example:
 *
 * array: "Hello, XYZWorld!"
 * count: 3
 * index: 7
 * array count: 16
 * ==> result: "Hello, World!"
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the type
 * @param p2 the count
 * @param p3 the destination index
 * @param p4 the destination array count
 * @param p5 the destination array size
 * @param p6 the adjust count flag
 */
void remove_inside(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! The following parametres ARE tested for null
    // even though not all of them are dereferenced below.
    // This is because sometimes, the cybol application has
    // exited already or wrong values may arrive from there.
    // Otherwise, wrong indices and count values might be calculated
    // below and lead to segmentation fault memory access errors.
    //

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ds = (int*) p5;

        if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* dc = (int*) p4;

            if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* di = (int*) p3;

                if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* c = (int*) p2;

                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        void** d = (void**) p0;

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Remove inside.");
                        //?? fwprintf(stdout, L"Debug: Remove inside. p2: %i\n", p2);
                        //?? fwprintf(stdout, L"Debug: Remove inside. *p2: %i\n", *((int*) p2));

                        // The move source index.
                        int si = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The move source count.
                        int sc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The new destination array count.
                        int nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The comparison result.
                        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                        // Add index.
                        calculate_integer_add((void*) &si, p3);
                        // Add count of elements to be removed.
                        calculate_integer_add((void*) &si, p2);

                        // Add array count.
                        calculate_integer_add((void*) &sc, p4);
                        // Subtract move source index.
                        calculate_integer_subtract((void*) &sc, (void*) &si);

                        // Add array count.
                        calculate_integer_add((void*) &nc, p4);
                        // Subtract count of elements to be removed.
                        calculate_integer_subtract((void*) &nc, p2);

                        if (si >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                            if (sc >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                if (nc >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                    //
                                    // Decrement reference count of removed parts for rubbish (garbage) collection.
                                    //
                                    // CAUTION! This has to be done BEFORE actually removing elements,
                                    // since afterwards, they are not reachable anymore from the destination.
                                    //
                                    reference(*d, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT, p2, p3, p1);

                                    //
                                    // Move current elements behind area to be removed towards the beginning of the array.
                                    //
                                    // CAUTION! Move array elements starting from the FIRST since otherwise,
                                    // overlapping array elements might get overwritten!
                                    //
                                    // CAUTION! Call this function BEFORE resizing the array
                                    // since elements might get lost while shrinking the array.
                                    //
                                    // CAUTION! If the array is to be emptied, then c is zero (see calculation above),
                                    // so that NOTHING is copied from behind the end of the array,
                                    // as that would break array boundaries and would copy unpredictable content.
                                    //
                                    // CAUTION! Set the deep copying flag to FALSE here,
                                    // since only POINTERS or PRIMITIVE VALUES are to be moved,
                                    // but NOT sub trees copied.
                                    //
                                    copy_array_forward(*d, *d, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &sc, p3, (void*) &si);

                                    compare_integer_unequal((void*) &r, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                                        //
                                        // It was decided NOT to shrink arrays when their size gets smaller,
                                        // in order to be more efficient.
                                        // When an array gets deallocated, there is no use in shrinking it beforehand.
                                        // Those arrays which contain less elements than their size is
                                        // probably won't occupy that much memory space and are left untouched.
                                        //
                                        // However, here comes the source code how shrinking might work:
                                        //
                                        // // The comparison result.
                                        // int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
                                        //
                                        // // Test if new size is smaller than array size.
                                        // compare_integer_less((void*) &r, (void*) &n, p5);
                                        //
                                        // if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                                        //
                                        //     if (n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
                                        //
                                        //         //
                                        //         // Shrink array using new count as size.
                                        //         //
                                        //         // CAUTION! Due to memory allocation handling, the size MUST NOT
                                        //         // be negative or zero, but have at least a value of ONE.
                                        //         //
                                        //         reallocate_array(p0, p4, (void*) &n, p1);
                                        //
                                        //     } else if (n == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
                                        //
                                        //         //
                                        //         // Set new size to value one.
                                        //         //
                                        //         // CAUTION! It is just normal that the calculated new size is zero,
                                        //         // e.g. if a part was emptied and all of its child elements removed.
                                        //         // However, in such cases it has to be made sure,
                                        //         // that allocation size is at least one.
                                        //         //
                                        //         n = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                                        //
                                        //         //
                                        //         // Shrink array using new count as size.
                                        //         //
                                        //         // CAUTION! Due to memory allocation handling, the size MUST NOT
                                        //         // be negative or zero, but have at least a value of ONE.
                                        //         //
                                        //         reallocate_array(p0, p4, (void*) &n, p1);
                                        //
                                        //     } else {
                                        //
                                        //         log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The new size is negative.");
                                        //     }
                                        //
                                        //     // Set new size.
                                        //     copy_integer(p5, (void*) &n);
                                        // }
                                        //

                                        // Assign destination array count.
                                        copy_integer(p4, (void*) &nc);
                                    }

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The new size is negative.");
                                    fwprintf(stdout, L"Error: Could not remove inside. The new size is negative n: %i\n", nc);
                                }

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The move source count is negative.");
                                fwprintf(stdout, L"Error: Could not remove inside. The move source count is negative sc: %i\n", sc);
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The move source index is negative.");
                            fwprintf(stdout, L"Error: Could not remove inside. The move source index is negative si: %i\n", si);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The destination array is null.");
                        fwprintf(stdout, L"Error: Could not remove inside. The destination array is null. p0: %i\n", p0);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The count is null.");
                    fwprintf(stdout, L"Error: Could not remove inside. The count is null. p2: %i\n", p2);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The destination index is null.");
                fwprintf(stdout, L"Error: Could not remove inside. The destination index is null. p3: %i\n", p3);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The destination array count is null.");
            fwprintf(stdout, L"Error: Could not remove inside. The destination array count is null. p4: %i\n", p4);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove inside. The destination array size is null.");
        fwprintf(stdout, L"Error: Could not remove inside. The destination array size is null. p5: %i\n", p5);
    }
}

/* INSIDE_REMOVER_SOURCE */
#endif
