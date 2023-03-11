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

#ifndef LIST_NUMERAL_VECTOR_DESERIALISER_SOURCE
#define LIST_NUMERAL_VECTOR_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/numeral/numeral_deserialiser.c"
#include "logger.h"

/**
 * Iterates through the list items in order to deserialise them into numbers.
 *
 * @param p0 the destination number item
 * @param p1 the source part element data
 * @param p2 the source part element count
 * @param p3 the decimal separator data
 * @param p4 the decimal separator count
 * @param p5 the thousands separator data
 * @param p6 the thousands separator count
 * @param p7 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p8 the destination number item format
 */
void deserialise_numeral_vector_list(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral vector list.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral vector list. source count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral vector list. source count *p2: %i\n", *((int*) p2));

    //
    // Declaration
    //

    // The type item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type item data.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The number.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The wide character part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The wide character part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The wide character part model item data, count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Preparation
    //

    //
    // Allocate type item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    //
    // Initialise type item.
    //
    // CAUTION! A type IS ESSENTIAL in order to avoid memory leaks.
    // Logic formats like "live/exit" do not have a counterpart as type.
    // Also, invalid formats may have been used in a cybol file.
    // Therefore, for these cases, assign a default type here.
    //
    modify_item(t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

    // Deserialise format into type item.
    deserialise_cybol_type(t, p8);

    //
    // Get type item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Allocation
    //

    //
    // Allocate number.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! This has to be an ARRAY and NOT an item since
    // it represents a primitive number value.
    //
    allocate_array((void*) &n, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, td);

    //
    // Retrieval
    //

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            //
            // Get wide character part from list at index.
            //
            // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE but
            // POINTER_STATE_CYBOI_TYPE instead, since the variable is
            // managed locally only and reference counting NOT wanted.
            //
            copy_array_forward((void*) &p, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j);
            // Get wide character part model item.
            copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            // Get wide character part model item data, count.
            copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            //
            // Deserialise wide character data to number.
            //
            // CAUTION! Hand over FALSE as consider number base prefix flag,
            // so that floating-point numbers with leading zero as pre-point
            // value get recognised correctly and used with decimal number base.
            //
            deserialise_numeral(n, *NULL_POINTER_STATE_CYBOI_MODEL, pmd, pmc, p3, p4, p5, p6, p7, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p8);

            //
            // Append number to destination number item.
            //
            // CAUTION! The "adjust count" flag is set to NULL here,
            // since the destination count gets ALWAYS adjusted.
            //
            // CAUTION! The usage of INSERT_MODIFY_LOGIC_CYBOI_FORMAT
            // is NOT necessary here. Other deserialisers parse data
            // diving into depth, so that last values are added first.
            // However, this is not the case for numeral vectors whose
            // string values have been provided in the correct order.
            // Therefore, the APPEND_MODIFY_LOGIC_CYBOI_FORMAT operation
            // may be used here.
            //
            modify_item(p0, n, td, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            // Increment loop variable.
            j++;
        }
    }

    //
    // Deallocation
    //

    //
    // Deallocate number.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, td);
    //
    // Deallocate type item.
    //
    // CAUTION! This has to be done AFTER having deallocated
    // the number above, since the type is needed for it.
    //
    deallocate_item((void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/* LIST_NUMERAL_VECTOR_DESERIALISER_SOURCE */
#endif
