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

#ifndef SERVER_ENTRY_DEALLOCATOR_SOURCE
#define SERVER_ENTRY_DEALLOCATOR_SOURCE

#include <threads.h> // mtx_t, mtx_destroy

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the server entry.
 *
 * @param p0 the server entry
 */
void deallocate_server_entry(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** e = (void**) p0;

        //
        // CAUTION! This log message has been commented out
        // due to the large number of potential calls caused
        // by the the number of socket services (65536).
        // See file "shutdown_manager.c".
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate server entry.");
        //?? fwprintf(stdout, L"Debug: Deallocate server entry. p0: %i\n", p0);

        //
        // Declaration.
        //

        // The input/output identification.
        //?? void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The sender identification.
        //?? void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The language (protocol).
        //?? void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The channel.
        //?? void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The client list item.
        void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The client list mutex.
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The client identification list item.
        //?? void* ci = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The client entry list item.
        //?? void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The client accepttime list item.
        //?? void* ca = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The thread identification.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The thread exit flag.
        void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Retrieval.
        //

        // Get identification from server entry.
        //?? copy_array_forward((void*) &id, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME);
        // Get sender identification from server entry.
        //?? copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SENDER_GENERAL_SERVER_STATE_CYBOI_NAME);
        // Get language (protocol) into server entry.
        //?? copy_array_forward((void*) &l, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_GENERAL_SERVER_STATE_CYBOI_NAME);
        // Get channel into server entry.
        //?? copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_GENERAL_SERVER_STATE_CYBOI_NAME);
        // Get client list item from server entry.
        copy_array_forward((void*) &cl, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_LIST_SERVER_STATE_CYBOI_NAME);
        // Get client list mutex from server entry.
        copy_array_forward((void*) &m, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_LIST_SERVER_STATE_CYBOI_NAME);
        // Get thread identification from server entry.
        copy_array_forward((void*) &t, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_SERVER_STATE_CYBOI_NAME);
        // Get thread exit flag from server entry.
        copy_array_forward((void*) &ex, *e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_SERVER_STATE_CYBOI_NAME);

        //
        // CAUTION! Resetting the values is not necessary,
        // since the server entry gets deallocated anyway.
        //

        //
        // Finalisation.
        //

        // Cast client list mutex to correct type.
        mtx_t* mt = (mtx_t*) m;
        // Finalise client list mutex.
        mtx_destroy(mt);

        //
        // Deallocation.
        //

        //
        // Deallocate identification.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        //?? deallocate_array((void*) &id, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Deallocate sender identification.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        //?? deallocate_array((void*) &s, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Deallocate language (protocol).
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        //?? deallocate_array((void*) &l, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Deallocate channel.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        //?? deallocate_array((void*) &c, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Deallocate client list item.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_item((void*) &cl, (void*) POINTER_STATE_CYBOI_TYPE);
        //
        // Deallocate client list mutex.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &m, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);
        //
        // Deallocate thread identification.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &t, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
        //
        // Deallocate thread exit flag.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &ex, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

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
