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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SERVER_ENTRY_DEALLOCATOR_SOURCE
#define SERVER_ENTRY_DEALLOCATOR_SOURCE

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

/**
 * Deallocates the server entry.
 *
 * @param p0 the server entry (pointer reference)
 */
void deallocate_server_entry(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** e = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate server entry.");
        //?? fwprintf(stdout, L"Debug: Deallocate server entry. p0: %i\n", p0);

        //
        // Declaration
        //

        // The service identification (port).
        void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The client list item.
        void* cli = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The channel.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The request input buffer item.
        void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The request input buffer mutex.
        void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The request input thread identification.
        void* ti = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The request input thread exit flag.
        void* te = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Retrieval
        //

        // Get service identification (port) from server entry.
        copy_array_forward((void*) &id, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME);
        // Get client list item from server entry.
        copy_array_forward((void*) &cli, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_CLIENTS_SERVER_STATE_CYBOI_NAME);
        // Get channel from server entry.
        copy_array_forward((void*) &c, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_COMMUNICATION_SERVER_STATE_CYBOI_NAME);
        // Get request input buffer item from server entry.
        copy_array_forward((void*) &bi, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME);
        // Get request input buffer mutex from server entry.
        copy_array_forward((void*) &bm, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME);
        // Get request input thread identification from server entry.
        copy_array_forward((void*) &ti, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_INPUT_SERVER_STATE_CYBOI_NAME);
        // Get request input thread exit flag from server entry.
        copy_array_forward((void*) &te, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_INPUT_SERVER_STATE_CYBOI_NAME);

        //
        // Deallocation
        //

        //
        // Deallocate service identification (port).
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &id, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Deallocate client list item.
        deallocate_item((void*) &cli, (void*) POINTER_STATE_CYBOI_TYPE);
        //
        // Deallocate channel.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &c, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Deallocate request input buffer item.
        deallocate_item((void*) &bi, (void*) POINTER_STATE_CYBOI_TYPE);
        // Deallocate request input buffer mutex.
        deallocate_mutex((void*) &bm);
        //
        // Deallocate request input thread identification.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &ti, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
        //
        // Deallocate request input thread exit flag.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &te, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // Deallocate server entry.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) SERVER_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate server entry. The server entry is null.");
        fwprintf(stdout, L"Error: Could not deallocate server entry. The server entry is null. p0: %i\n", p0);
    }
}

/* SERVER_ENTRY_DEALLOCATOR_SOURCE */
#endif
