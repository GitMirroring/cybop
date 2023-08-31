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
#include "mapper.h"

/**
 * Deallocates the client entry.
 *
 * @param p0 the client entry (pointer reference)
 * @param p1 the channel
 */
void deallocate_client_entry(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** e = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate client entry.");
        //?? fwprintf(stdout, L"Debug: Deallocate client entry. p1: %i\n", p1);
        //?? fwprintf(stdout, L"Debug: Deallocate client entry. *p1: %i\n", *((int*) p1));

        //
        // Declaration
        //

        // The client device identification as integer number (e.g. file descriptor, client socket number, window id).
        void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The client device name item (e.g. a file system path pointing to some device).
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The channel.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The server flag.
        void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The port.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The language.
        void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The input buffer item.
        void* ibi = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The input buffer mutex.
        void* ibm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The input thread identification.
        void* iti = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The input thread exit flag.
        void* ite = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The output buffer item.
        void* obi = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The output buffer mutex.
        void* obm = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // The data type.
        //
        // CAUTION! The buffer deallocation is CHANNEL-SPECIFIC,
        // since buffer types differ between devices.
        //
        // - CHARACTER buffer for file, serial port, terminal, fifo, socket
        // - POINTER buffer for display events
        //
        int t = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        //
        // Mapping
        //

        // Map channel to datatype.
        map_channel_to_type((void*) &t, p1);

        //
        // Retrieval
        //

        // Get client device identification from client entry.
        copy_array_forward((void*) &id, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);
        // Get client device name item from client entry.
        copy_array_forward((void*) &n, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_GENERAL_CLIENT_STATE_CYBOI_NAME);
        // Get channel from client entry.
        copy_array_forward((void*) &c, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
        // Get server flag from client entry.
        copy_array_forward((void*) &sf, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVER_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
        // Get port from client entry.
        copy_array_forward((void*) &p, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PORT_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
        // Get language from client entry.
        copy_array_forward((void*) &l, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
        // Get input buffer item from client entry.
        copy_array_forward((void*) &ibi, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);
        // Get input buffer mutex from client entry.
        copy_array_forward((void*) &ibm, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);
        // Get input thread identification from client entry.
        copy_array_forward((void*) &iti, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME);
        // Get input thread exit flag from client entry.
        copy_array_forward((void*) &ite, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME);
        // Get output buffer item from client entry.
        copy_array_forward((void*) &obi, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME);
        // Get output buffer mutex from client entry.
        copy_array_forward((void*) &obm, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME);

        //
        // Deallocation
        //

        //
        // Deallocate client device identification.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &id, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Deallocate client device name item.
        deallocate_item((void*) &n, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        //
        // Deallocate channel.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &c, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Deallocate server flag.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &sf, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Deallocate port.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &p, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Deallocate language.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &l, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Deallocate input buffer item.
        deallocate_item((void*) &ibi, (void*) &t);
        // Deallocate input buffer mutex.
        deallocate_mutex((void*) &ibm);
        //
        // Deallocate input thread identification.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &iti, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
        //
        // Deallocate input thread exit flag.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &ite, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Deallocate output buffer item.
        deallocate_item((void*) &obi, (void*) &t);
        // Deallocate output buffer mutex.
        deallocate_mutex((void*) &obm);

        //
        // Deallocate client entry.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) CLIENT_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate client entry. The client entry is null.");
        fwprintf(stdout, L"Error: Could not deallocate client entry. The client entry is null. p0: %i\n", p0);
    }
}
