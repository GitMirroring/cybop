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

#ifndef CLIENT_ENTRY_ALLOCATOR_SOURCE
#define CLIENT_ENTRY_ALLOCATOR_SOURCE

#include <threads.h> // mtx_t, mtx_init, thrd_error

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_data_type_mapper.c"
#include "../../../variable/symbolic_name/mutex_thread_symbolic_name.c"

/**
 * Allocates the client entry.
 *
 * The buffer allocation is channel-specific,
 * since buffer types differ between devices.
 *
 * - CHARACTER buffer for file, serial port, terminal, named pipeline, socket
 * - POINTER buffer for display events
 *
 * @param p0 the client entry (pointer reference)
 * @param p1 the channel
 */
void allocate_client_entry(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** e = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate client entry.");
        fwprintf(stdout, L"Debug: Allocate client entry. p0: %i\n", p0);

        //
        // Declaration.
        //

        // The client device identification.
        void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The client device name item.
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The buffer item.
        void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The buffer mutex.
        void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The thread identification.
        void* ti = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The thread exit flag.
        void* te = *NULL_POINTER_STATE_CYBOI_MODEL;

        // The data type.
        int t = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        //
        // Mapping.
        //

        // Map channel to datatype.
        map_channel_to_type((void*) &t, p1);

        //
        // Allocation.
        //

        //
        // Allocate client entry.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) CLIENT_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        //
        // Allocate identification.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &id, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate client device name item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &n, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
        //
        // Allocate buffer item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &bi, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &t);
        //
        // Allocate buffer mutex.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &bm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);
        //
        // Allocate thread identification.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &ti, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
        //
        // Allocate thread exit flag.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &te, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // Initialisation.
        //

        // Initialise client identification.
        copy_integer(id, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Cast buffer mutex to correct type.
        mtx_t* bmt = (mtx_t*) bm;
        // Initialise buffer mutex.
        int r = mtx_init(bmt, *PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME);

        if (r == thrd_error) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate client entry. The buffer mutex object creation failed.");
            fwprintf(stdout, L"Error: Could not allocate client entry. The buffer mutex object creation failed. r: %i\n", r);
        }

        // Initialise thread identification.
        copy_integer(ti, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Initialise exit flag.
        copy_integer(te, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

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

        // Set client identification into client entry.
        copy_array_forward(*e, (void*) &id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set client device name item into client entry.
        copy_array_forward(*e, (void*) &n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NAME_GENERAL_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set buffer item into client entry.
        copy_array_forward(*e, (void*) &bi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ITEM_BUFFER_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set buffer mutex into client entry.
        copy_array_forward(*e, (void*) &bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_BUFFER_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set thread identification into client entry.
        copy_array_forward(*e, (void*) &ti, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set thread exit flag into client entry.
        copy_array_forward(*e, (void*) &te, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EXIT_THREAD_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate client entry. The client entry is null.");
        fwprintf(stdout, L"Error: Could not allocate client entry. The client entry is null. p0: %i\n", p0);
    }
}

/* CLIENT_ENTRY_ALLOCATOR_SOURCE */
#endif
