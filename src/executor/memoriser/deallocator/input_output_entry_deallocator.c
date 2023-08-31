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
 * @version CYBOP 0.27.0 2023-08-31
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
#include "server.h"

/**
 * Deallocates the input output entry.
 *
 * @param p0 the input output entry (pointer reference)
 * @param p1 the channel
 * @param p2 the internal memory data
 */
void deallocate_input_output_entry(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** e = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate input output entry.");
        //?? fwprintf(stdout, L"Debug: Deallocate input output entry. p0: %i\n", p0);

        //
        // Declaration
        //

        // The client list item.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The server list item.
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Retrieval
        //

        // Get client list item from input output entry.
        copy_array_forward((void*) &c, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CLIENTS_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Get server list item from input output entry.
        copy_array_forward((void*) &s, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVERS_INPUT_OUTPUT_STATE_CYBOI_NAME);

        //
        // Finalisation
        //

        //?? fwprintf(stdout, L"Debug: Deallocate input output entry. shutdown server list s: %i\n", s);

        // Shutdown servers.
        shutdown_list(s, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //?? fwprintf(stdout, L"Debug: Deallocate input output entry. shutdown client list c: %i\n", c);

        // Shutdown clients.
        shutdown_list(c, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME, p1, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Deallocation
        //

        // Deallocate client list item.
        deallocate_item((void*) &c, (void*) POINTER_STATE_CYBOI_TYPE);
        // Deallocate server list item.
        deallocate_item((void*) &s, (void*) POINTER_STATE_CYBOI_TYPE);

        //
        // Deallocate input output entry.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INPUT_OUTPUT_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate input output entry. The input output entry is null.");
        fwprintf(stdout, L"Error: Could not deallocate input output entry. The input output entry is null. p0: %i\n", p0);
    }
}
