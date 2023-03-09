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

#ifndef OVERWRITER_SOURCE
#define OVERWRITER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../executor/referencer/referencer.c"
//
// CAUTION! Do NOT include the logger here.
// It uses functions causing circular references.
//

/**
 * Overwrites the destination- with the source array,
 * starting from the given index.
 *
 * The destination size gets adjusted automatically.
 * A new destination count is ONLY assigned,
 * if the "adjust count flag" is set.
 *
 * Example:
 *
 * destination array: "Hello ABCXYZ!"
 * source array: "blubla, World blubla"
 * count: 7
 * destination array index: 5
 * source array index: 6
 * destination array count: 13
 * ==> result: "Hello, World!"
 *
 * It is also allowed to assign elements far behind
 * the end of the original array. This is similar
 * to random access of an arbitrary byte of a file.
 *
 * Example:
 *
 * destination array: "Hello, World"
 * source array: "blubla!!! blubla"
 * count: 3
 * destination array index: 20
 * source array index: 6
 * destination array count: 12
 * ==> result: "Hello, World        !!!"
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
 * @param p9 the adjust count flag
 */
void overwrite(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        //
        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Overwrite.");
        //

        //?? fwprintf(stdout, L"Debug: Overwrite. p3: %i\n", p3);

        // The new destination count.
        int nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The overwritten elements count.
        int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        //
        // CAUTION! An element may be added far behind the end of the array.
        // This is similar to random access of an arbitrary byte of a file.
        // In such a case, the destination index plus number of source elements
        // to be added will deliver the new count of the destination array.
        //
        // CAUTION! If destination elements are overwritten
        // somewhere in the "middle" of the destination array,
        // then the calculated new destination count will be
        // smaller than the original destination array count.
        // In this case, the caller of this function may choose
        // by setting the "adjust count flag" parametre to:
        //
        // TRUE: destination array count is set to new destination count
        // FALSE: destination array count remains unchanged at its original value
        //

        // Add destination index.
        calculate_integer_add((void*) &nc, p5);
        // Add count of source elements to be written over destination elements.
        calculate_integer_add((void*) &nc, p4);

        //
        // CAUTION! An element may be added far behind the end of the array.
        // In such a case, the result will be negative.
        //

        // Initialise with original destination array count.
        copy_integer((void*) &oc, p7);
        // Subtract destination index.
        calculate_integer_subtract((void*) &oc, p5);

        if (oc < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // The index is outside the array boundaries,
            // NOT before, but BEHIND the array.
            // Therefore, NO elements are overwritten and the
            // overwritten elements count oc may thus be set
            // to zero here, in order to avoid errors below,
            // due to the negative value.
            //
            oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        }

        if (nc >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Test if new destination count exceeds original destination array size.
            compare_integer_greater((void*) &r, (void*) &nc, p8);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The new destination count is greater than
                // the current destination size.
                //

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
                if (ns > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    //
                    // Enlarge array using new destination size.
                    //
                    // CAUTION! Due to memory allocation handling, the size MUST NOT
                    // be negative or zero, but have at least a value of ONE.
                    //
                    reallocate_array(p0, p7, (void*) &ns, p2);

                    // Set new size.
                    copy_integer(p8, (void*) &ns);

                } else if (ns == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    fwprintf(stdout, L"Error: Could not overwrite. The new size is zero ns: %i\n", ns);

                } else if (ns < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    fwprintf(stdout, L"Error: Could not overwrite. The new size is negative ns: %i\n", ns);
                }
            }

            //
            // Decrement reference count of overwritten parts for rubbish (garbage) collection.
            //
            // CAUTION! This has to be done BEFORE actually overwriting old elements,
            // since afterwards, they are not reachable anymore from the destination.
            //
            // CAUTION! Use the overwritten elements count and
            // NOT the count handed over as parametre p4 here!
            //
            // CAUTION! The overwritten elements count oc might be negative,
            // e. g. if the destination index is greater than
            // the original destination array count.
            // However, this case was already handled further above.
            //
            reference(*d, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT, (void*) &oc, p5, p2);

            //
            // Copy source to destination.
            //
            // CAUTION! Set the deep copying flag to the PARAMETRE here,
            // since the source may be of primitive types like pointer or integer,
            // but also of a compound node type with sub tree.
            //
            copy_array_forward(*d, p1, p2, p3, p4, p5, p6);

            //
            // Increment reference count of new parts for rubbish (garbage) collection.
            //
            // CAUTION! This has to be done AFTER having overwritten old elements with new elements,
            // since beforehand, the latter are not known to the destination yet.
            //
            // CAUTION! Use the count handed over as parametre p4 and NOT the overwritten elements count here!
            //
            reference(*d, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT, p4, p5, p2);

            // Reset comparison result.
            r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_unequal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Adjust destination array COUNT only if "adjust" flag was set.
                //
                // The destination size does not really matter here.
                // It got extended above, if necessary.
                // For the destination count, there are two possibilities:
                //
                // 1 The adjust flag is FALSE:
                //
                // In this case, the original destination count REMAINS AS IS.
                //
                // Example:
                //
                // - destination array: "Today is a rainy day."
                // - source array: "sunny"
                // - type: (wide_character given as special integer constant)
                // - count: 5
                // - destination index: 11
                // - source index: 0
                // - destination array count: 21
                // - destination array size: 21 (or greater, does not matter)
                // - adjust flag: 0
                //
                // --> destination array: "Today is a sunny day."
                // --> destination array count: 21
                //
                // 2 The adjust flag is TRUE:
                //
                // In this case, the original destination count GETS ADJUSTED.
                //
                // Example:
                //
                // - destination array: "green"
                // - source array: "red"
                // - type: (wide_character given as special integer constant)
                // - count: 3
                // - destination index: 0
                // - source index: 0
                // - destination array count: 5
                // - destination array size: 5 (or greater, does not matter)
                // - adjust flag: 1
                //
                // --> destination array: "red"
                // --> destination array count: 3
                //
                // If the destination count hadn't been adjusted, the result would have been:
                // --> destination array: "reden"
                // --> destination array count: 5
                // ... which is clearly wrong, since this colour value does not exist.
                //
                // Therefore, the destination array count has to get adjusted
                // not only if the number of elements increases (extension),
                // but also if the number of elements decreases (shrinking).
                // If this was not done, false results would occur.
                //
                copy_integer(p7, (void*) &nc);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not overwrite. The new destination count is negative.");
            fwprintf(stdout, L"Error: Could not overwrite. The new destination count is negative nc: %i\n", nc);
        }

    } else {

        //
        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not overwrite. The destination array is null.");
    }
}

/* OVERWRITER_SOURCE */
#endif
