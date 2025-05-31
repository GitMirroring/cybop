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
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "variable.h"

/**
 * Allocates the part.
 *
 * @param p0 the part (pointer reference)
 * @param p1 the size
 * @param p2 the type
 */
void allocate_part(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** part = (void**) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate part.");

                //
                // The references, name, format, type, model, properties.
                //
                // CAUTION! The "format" contains the MIME type value, e.g. "number/integer";
                // the "type" represents the RUNTIME data type in memory, e.g. "int".
                //
                void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

                allocate_item((void*) &m, p1, p2);

                if (m != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    //
                    // Allocate references, name, format, type, model, properties.
                    //
                    // CAUTION! Due to memory allocation handling, the size MUST NOT
                    // be negative or zero, but have at least a value of ONE.
                    //
                    // CAUTION! Initialise integer items with a size of ONE,
                    // in order to avoid later reallocation when overwriting
                    // the element and to thus increase EFFICIENCY.
                    //
                    allocate_item((void*) &r, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
                    allocate_item((void*) &n, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
                    allocate_item((void*) &f, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
                    allocate_item((void*) &t, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
                    allocate_item((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

                    //
                    // Initialise references.
                    //
                    // CAUTION! The format and type do ALWAYS have to be initialised
                    // as well, in order to make the rubbish (garbage) collection work.
                    //
                    // But since their values depend on the KIND of part,
                    // they have to be assigned in the corresponding CONTEXT,
                    // right AFTER having allocated the part,
                    // that is OUTSIDE this function.
                    //
                    modify_item(r, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

                    //
                    // Allocate part.
                    //
                    // CAUTION! Due to memory allocation handling, the size MUST NOT
                    // be negative or zero, but have at least a value of ONE.
                    //
                    allocate_array(p0, (void*) PART_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

                    //
                    // Increment part reference counter.
                    //
                    // CAUTION! This is ONLY needed for debugging.
                    //
                    (*PART_REFERENCE_COUNTER)++;

                    // Set references, name, format, type, model, properties.
                    copy_array_forward(*part, (void*) &r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) REFERENCES_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    copy_array_forward(*part, (void*) &n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NAME_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    copy_array_forward(*part, (void*) &f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FORMAT_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    copy_array_forward(*part, (void*) &t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TYPE_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    copy_array_forward(*part, (void*) &m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MODEL_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    copy_array_forward(*part, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PROPERTIES_PART_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                } else {

                    //
                    // Reasons might be:
                    // - given size is zero
                    // - given size is negative
                    // - no more system heap memory
                    //

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate part. The model is null.");
                    fwprintf(stdout, L"Error: Could not allocate part. The model is null. m: %i\n", m);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate part. The part is null.");
                fwprintf(stdout, L"Error: Could not allocate part. The part is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate part. The size is null.");
            fwprintf(stdout, L"Error: Could not allocate part. The size is null. size p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate part. The type is null.");
        fwprintf(stdout, L"Error: Could not allocate part. The type is null. type p2: %i\n", p2);
    }
}
