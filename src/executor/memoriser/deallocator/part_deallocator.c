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

#ifndef PART_DEALLOCATOR_SOURCE
#define PART_DEALLOCATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../logger/logger.c"
#include "../../../variable/reference_counter.c"

/**
 * Deallocates the part.
 *
 * @param p0 the part (pointer reference)
 */
void deallocate_part(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** part = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate part.");
        //?? fwprintf(stdout, L"Debug: Deallocate part. *part: %i\n", *part);

        // The references, name, format, type, model, properties.
        void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The data.
        void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The comparison result.
        int res = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Get references, name, format, type, model, properties.
        copy_array_forward((void*) &r, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) REFERENCES_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &n, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &f, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &t, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &m, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &p, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
        // Get data.
        copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        //
        // Verify that reference data is zero.
        //
        // CAUTION! Otherwise, do NOT deallocate this part.
        // This test IS USEFUL in order to find out via log file
        // if there are forgotten allocations/deallocations in source code.
        //
        compare_integer_equal((void*) &res, rd, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (res != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Deallocate references, name, format, type, model, properties.
            //
            // CAUTION! Use REVERSE ORDER as compared to allocation!
            // This is important for at least TYPE and MODEL,
            // since the type is needed for model deallocation.
            // If the type got destroyed before the model,
            // then model deallocation would NOT work.
            //
            deallocate_item((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            deallocate_item((void*) &m, td);
            deallocate_item((void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &n, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            deallocate_item((void*) &r, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            //
            // Deallocate part.
            //
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            //
            deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

            //
            // Decrement part reference counter.
            //
            // CAUTION! This is ONLY needed for debugging.
            //
            (*PART_REFERENCE_COUNTER)--;

        } else {

            // Reset comparison result.
            res = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_greater((void*) &res, rd, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (res != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate part. It is still referenced by other parts.");
                fwprintf(stdout, L"Error: Could not deallocate part. It is still referenced by other parts: %i\n", *part);

            } else {

                //
                // If the references count is neither zero (first comparison),
                // NOR greater than zero (second comparison),
                // then it is SMALLER than zero.
                //

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate part. Its references count is negative.");
                fwprintf(stdout, L"Error: Could not deallocate part. Its references count is negative: %i\n", *part);
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate part. The part is null.");
        fwprintf(stdout, L"Error: Could not deallocate part. The part is null. p0: %i\n", p0);
    }
}

/* PART_DEALLOCATOR_SOURCE */
#endif
