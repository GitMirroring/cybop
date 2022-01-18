/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DISPLAY_CLOSER_SOURCE
#define DISPLAY_CLOSER_SOURCE

#include <stdlib.h> // free

#include "../../../../constant/format/cyboi/logic/modify_logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Deallocates display-specific resources.
 *
 * @param p0 the client entry
 */
void close_display(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close display.");

    //
    // Declaration.
    //

    // The event buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The event buffer item data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The event.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval.
    //

    // Get event buffer item from input/output entry.
    copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BUFFER_MESSAGE_CLIENT_STATE_CYBOI_NAME);

    //
    // Deallocation.
    //

    //
    // CAUTION! Use descending order as compared to startup,
    // for the following deallocations.
    //

    //
    // Get event buffer item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bc, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Close display. bc: %i\n", bc);
    fwprintf(stdout, L"Debug: Close display. *bc: %i\n", *((int*) bc));

    //
    // CAUTION! Locking using a mutex is NOT necessary here anymore,
    // since the corresponding sensing thread has exited already.
    //

    // Loop event buffer and deallocate (free) all events.
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Reset comparison result.
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_greater_or_equal((void*) &r, bc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        fwprintf(stdout, L"Debug: Close display. loop r: %i\n", r);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The buffer contains at least one event.
            //

            // Get event from event buffer.
            copy_array_forward((void*) &e, bd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            fwprintf(stdout, L"Debug: Close display. e: %i\n", e);

            //
            // Remove event from event buffer item.
            //
            // CAUTION! Set the adjust count flag to TRUE since otherwise,
            // the destination item will hold a wrong "count" number
            // leading to unpredictable errors in further processing.
            //
            modify_item(b, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);
            fwprintf(stdout, L"Debug: Close display. after remove *bc: %i\n", *((int*) bc));

            if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

                //
                // Deallocate event.
                //
                // CAUTION! Free memory only if event is NOT null.
                //
                // CAUTION! It HAS TO BE destroyed manually here, since for:
                // - linux: it gets created automatically inside the xcb library
                // - win32: it gets created manually as message using the type MSG
                //
                // However, in BOTH CASES they are just pointers and hence
                // NOT platform-specific and therefore may get freed here.
                //
                free(e);
                fwprintf(stdout, L"Debug: Close display. after free e: %i\n", e);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close display. The event is null.");
                fwprintf(stdout, L"Error: Could not close display. The event is null. e: %i\n", e);
            }

        } else {

            //
            // The event buffer is empty.
            //

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close display. The event buffer is empty.");
            fwprintf(stdout, L"Debug: Close display. The event buffer is empty. *bc: %i\n", *((int*) bc));

            break;
        }
    }

    // Deallocate event buffer item.
    deallocate_item((void*) &b, (void*) POINTER_STATE_CYBOI_TYPE);
}

/* DISPLAY_CLOSER_SOURCE */
#endif
