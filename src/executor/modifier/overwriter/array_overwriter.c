/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_OVERWRITER_SOURCE
#define ARRAY_OVERWRITER_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/modifier/copier/value_copier.c"
#include "../../../executor/memoriser/offset_adder.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../executor/referencer/referencer.c"
#include "../../../logger/logger.c"

/**
 * Overwrites the destination- with the source array,
 * starting from the given index.
 *
 * The count and size are adjusted automatically.
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
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 * @param p6 the destination array count
 * @param p7 the destination array size
 * @param p8 the adjust count flag
 */
void overwrite_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Overwrite array.");

        // The new destination count.
        int nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // CAUTION! An element may be added far behind the end of the array.
        // This is similar to random access of an arbitrary byte of a file.
        // In such a case, the destination index plus number of source elements
        // to be added will deliver the new count of the destination array.

        // Add destination index.
        calculate_integer_add((void*) &nc, p4);
        // Add count of source elements to be written over destination elements.
        calculate_integer_add((void*) &nc, p3);

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_greater((void*) &r, (void*) &nc, p7);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The new destination count is greater than
            // the current destination size.

            // The new destination size.
            int ns = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Copy count to size.
            copy_integer((void*) &ns, (void*) &nc);

            // Multiply new destination size with factor.
            // CAUTION! This multiplication has to be done AFTER the comparison
            // of new size and old size since otherwise, the new size is falsified,
            // which would lead to runtime errors.
            calculate_integer_multiply((void*) &ns, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);

            // Enlarge array using new destination size.
            reallocate_array(p0, p6, (void*) &ns, p2);

            // Adjust new size.
            copy_integer(p7, (void*) &ns);
        }

        // Decrement reference count of overwritten parts for rubbish (garbage) collection.
        reference(*d, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT, p3, p4, p2);

        // Copy source to destination.
        copy_array_forward(*d, p1, p2, p3, p4, p5);

        // Increment reference count of new parts for rubbish (garbage) collection.
        reference(*d, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT, p3, p4, p2);

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

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
            copy_integer(p6, (void*) &nc);
        }

    } else {

        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not overwrite array. The destination array is null.");
    }
}

/* ARRAY_OVERWRITER_SOURCE */
#endif
