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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_COMPARATOR_SOURCE
#define PART_COMPARATOR_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void compare_all_part_all(void* p0, void* p1, void* p2, void* p3);

/**
 * Compares left- with right part.
 *
 * Compares both parts' name, type, model, properties.
 *
 * This is DEEP COMPARISON, i.e. all child nodes will be compared as well.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation type
 */
void compare_part(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare part.");

    //
    // Recursively call a comparison function, which in turn
    // may call this comparison function and so forth.
    // This is necessary when processing knowledge tree hierarchies.
    //

    compare_all_part_all(p0, p1, p2, p3);

/*??
    //??
    //?? The code below is an ALTERNATIVE to the "overwrite_part_all" function.
    //?? It may be deleted later, if not needed.
    //?? If reactivated, then it STILL NEEDS TO BE DEBUGGED,
    //?? since it was not quite complete yet.
    //??

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** rp = (void**) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** lp = (void**) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* r = (int*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare part.");

                // The source part name, type, model, properties.
                void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* sa = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
                // The source part elements data, count.
                void* snd = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* snc = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* sad = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* sac = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* sdd = *NULL_POINTER_STATE_CYBOI_MODEL;
                void* sdc = *NULL_POINTER_STATE_CYBOI_MODEL;

                // Get source part name, type, model, properties.
                copy_array_forward((void*) &sn, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
                copy_array_forward((void*) &sa, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
                copy_array_forward((void*) &sm, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
                copy_array_forward((void*) &sd, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
                // Get source item data, count.
                copy_array_forward((void*) &snd, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &snc, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &sad, sa, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &sac, sa, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &sdd, sd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                copy_array_forward((void*) &sdc, sd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

                // Allocate destination part.
                // CAUTION! Use source part type for allocation!
                allocate_part(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, sad);

                // Copy source part name, type, model, properties to destination.
                // The name is always of type "wide_character".
                overwrite_part_element(*d, snd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, snc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
                // The type is always of type "wide_character".
                overwrite_part_element(*d, sad, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, sac, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
                // The model is always of the type determined above.
                overwrite_part_element(*d, smd, sad, smc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MODEL_PART_STATE_CYBOI_NAME);
                // The properties is always of type "part" (whole, compound).
                overwrite_part_element(*d, sdd, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, sdc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare part. The result is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare part. The left part is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare part. The right part is null.");
    }
*/
}

/* PART_COMPARATOR_SOURCE */
#endif
