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

#ifndef SERVER_ENTRY_ALLOCATOR_SOURCE
#define SERVER_ENTRY_ALLOCATOR_SOURCE

#include <threads.h> // mtx_t, mtx_init, thrd_error

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/symbolic_name/mutex_thread_symbolic_name.c"

/**
 * Allocates the server entry.
 *
 * @param p0 the server entry (pointer reference)
 * @param p1 the interrupt pipe (pointer reference)
 * @param p2 the interrupt mutex (pointer reference)
 * @param p3 the input/output identification
 * @param p4 the thread function (pointer reference)
 * @param p5 the function argument (pointer reference)
 * @param p6 the socket timeout
 * @param p7 the channel (pointer reference)
 */
void allocate_server_entry(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** e = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate server entry.");
        fwprintf(stdout, L"Debug: Allocate server entry. p0: %i\n", p0);

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
        // Allocation.
        //

        //
        // Allocate server entry.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) SERVER_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        //
        // Allocate identification.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        //?? allocate_array((void*) &id, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate sender identification.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        //?? allocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate language (protocol).
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        //?? allocate_array((void*) &l, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate channel.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        //?? allocate_array((void*) &c, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // Allocate client list item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &cl, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
        //
        // Allocate client list mutex.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &m, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);
        //
        // Allocate client identification list item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        //?? allocate_item((void*) &ci, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate client entry list item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        //?? allocate_item((void*) &ce, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
        //
        // Allocate accepttime list item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        //?? allocate_item((void*) &ca, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate thread identification.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &t, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
        //
        // Allocate thread exit flag.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &ex, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // Initialisation.
        //

        // Initialise input/output identification.
        //?? copy_integer(id, p3);
        // Initialise sender identification.
        //?? copy_integer(s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        // Copy timeout.
        //?? copy_integer(to, p6);
        // Initialise language (protocol).
        //?? copy_integer(l, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        //
        // Initialise channel.
        //
        // CAUTION! Assign -1 first, since nothing gets assigned if p7 is null.
        // The default value would otherwise be 0 and lead to errors,
        // since that value references a channel constant.
        //
        //?? copy_integer(c, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        //?? copy_integer(c, p7);
        // The list mutex with casted type.
        mtx_t* mt = (mtx_t*) m;
        // Initialise list mutex.
        int r = mtx_init(mt, *PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME);

        if (r == thrd_error) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate server entry. The mutex object creation failed.");
            fwprintf(stdout, L"Error: Could not allocate server entry. The mutex object creation failed. r: %i\n", r);
        }

        // Initialise thread identification.
        copy_integer(t, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Initialise exit flag.
        copy_integer(ex, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Storage.
        //

        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Do NOT hand over entry as pointer reference.
        //
        // CAUTION! Hand over value as pointer REFERENCE.
        //

        //
        // Set interrupt pipe into server entry.
        //
        // CAUTION! This reference is actually stored in internal memory.
        // However, it gets stored in server entry HERE a SECOND time,
        // in order to be able to pass it to the corresponding sensing thread,
        // which does accept only ONE function argument.
        //
        //?? copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTERRUPT_PIPE_GENERAL_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        //
        // Set interrupt mutex into server entry.
        //
        // CAUTION! This reference is actually stored in internal memory.
        // However, it gets stored in server entry HERE a SECOND time,
        // in order to be able to pass it to the corresponding sensing thread,
        // which does accept only ONE function argument.
        //
        //?? copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTERRUPT_MUTEX_GENERAL_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set identification into server entry.
        //?? copy_array_forward(p0, (void*) &id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set sender identification into server entry.
        //?? copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SENDER_GENERAL_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set client list item into server entry.
        copy_array_forward(*e, (void*) &cl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ITEM_LIST_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set client list mutex into server entry.
        copy_array_forward(*e, (void*) &m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_LIST_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set client identification list item into server entry.
        //?? copy_array_forward(p0, (void*) &ci, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_CLIENT_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set client entry list item into server entry.
        //?? copy_array_forward(p0, (void*) &ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ENTRY_CLIENT_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set client accepttime list item into server entry.
        //?? copy_array_forward(p0, (void*) &ca, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ACCEPTTIME_CLIENT_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set timeout number into server entry.
        //?? copy_array_forward(p0, (void*) &to, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TIMEOUT_SOCKET_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set language (protocol) into server entry.
        //?? copy_array_forward(p0, (void*) &l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) LANGUAGE_GENERAL_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set channel into server entry.
        //?? copy_array_forward(p0, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHANNEL_GENERAL_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set thread identification into server entry.
        copy_array_forward(*e, (void*) &t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set thread exit flag into server entry.
        copy_array_forward(*e, (void*) &ex, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EXIT_THREAD_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate server entry. The server entry is null.");
        fwprintf(stdout, L"Error: Could not allocate server entry. The server entry is null. p0: %i\n", p0);
    }
}

/* SERVER_ENTRY_ALLOCATOR_SOURCE */
#endif
