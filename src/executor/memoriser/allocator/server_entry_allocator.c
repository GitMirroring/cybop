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

#ifndef SERVER_ENTRY_ALLOCATOR_SOURCE
#define SERVER_ENTRY_ALLOCATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/copier/thread_identification_copier.c"
#include "../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../executor/memoriser/allocator/mutex_allocator.c"
#include "logger.h"

/**
 * Allocates the server entry.
 *
 * @param p0 the server entry (pointer reference)
 */
void allocate_server_entry(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** e = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate server entry.");
        //?? fwprintf(stdout, L"Debug: Allocate server entry. p0: %i\n", p0);

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
        // Allocation
        //

        //
        // Allocate server entry.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) SERVER_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        //
        // Allocate service identification (port).
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &id, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate client list item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &cli, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
        //
        // Allocate channel.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &c, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate request input buffer item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &bi, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
        // Allocate request input buffer mutex.
        allocate_mutex((void*) &bm);
        //
        // Allocate request input thread identification.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &ti, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
        //
        // Allocate request input thread exit flag.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &te, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // Initialisation
        //

        // Initialise service identification (port).
        copy_integer(id, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Initialise channel.
        copy_integer(c, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Initialise request input thread identification.
        copy_thread_identification(ti, (void*) &DEFAULT_THREAD_IDENTIFICATION);
        // Initialise request input thread exit flag.
        copy_integer(te, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Storage
        //

        // Set service identification (port) into server entry.
        copy_array_forward(*e, (void*) &id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set client list item into server entry.
        copy_array_forward(*e, (void*) &cli, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ITEM_CLIENTS_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set channel into server entry.
        copy_array_forward(*e, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHANNEL_COMMUNICATION_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set request input buffer item into server entry.
        copy_array_forward(*e, (void*) &bi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ITEM_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set request input buffer mutex into server entry.
        copy_array_forward(*e, (void*) &bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set request input thread identification into server entry.
        copy_array_forward(*e, (void*) &ti, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_INPUT_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set request input thread exit flag into server entry.
        copy_array_forward(*e, (void*) &te, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EXIT_THREAD_INPUT_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate server entry. The server entry is null.");
        fwprintf(stdout, L"Error: Could not allocate server entry. The server entry is null. p0: %i\n", p0);
    }
}

/* SERVER_ENTRY_ALLOCATOR_SOURCE */
#endif
