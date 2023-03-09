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

#ifndef CLIENT_ENTRY_ALLOCATOR_SOURCE
#define CLIENT_ENTRY_ALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/copier/thread_identification_copier.c"
#include "../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../executor/memoriser/allocator/mutex_allocator.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_type_mapper.c"

/**
 * Allocates the client entry.
 *
 * @param p0 the client entry (pointer reference)
 * @param p1 the channel
 */
void allocate_client_entry(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** e = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate client entry.");
        //?? fwprintf(stdout, L"Debug: Allocate client entry. p0: %i\n", p0);

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
        // CAUTION! The buffer allocation is CHANNEL-SPECIFIC,
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
        // Allocation
        //

        //
        // Allocate client entry.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) CLIENT_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        //
        // Allocate client device identification.
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
        // Allocate channel.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &c, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate server flag.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &sf, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate port.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &p, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate language.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &l, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate input buffer item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &ibi, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) &t);
        // Allocate input buffer mutex.
        allocate_mutex((void*) &ibm);
        //
        // Allocate input thread identification.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &iti, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
        //
        // Allocate input thread exit flag.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &ite, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate output buffer item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &obi, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) &t);
        // Allocate output buffer mutex.
        allocate_mutex((void*) &obm);

        //
        // Initialisation
        //

        // Initialise client device identification.
        copy_integer(id, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Initialise channel.
        copy_integer(c, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Initialise server flag.
        copy_integer(sf, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        // Initialise port.
        copy_integer(p, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Initialise language.
        copy_integer(l, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        // Initialise input thread identification.
        copy_thread_identification(iti, (void*) &DEFAULT_THREAD_IDENTIFICATION);
        // Initialise input thread exit flag.
        copy_integer(ite, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Storage
        //

        // Set client device identification into client entry.
        copy_array_forward(*e, (void*) &id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set client device name item into client entry.
        copy_array_forward(*e, (void*) &n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NAME_GENERAL_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set channel into client entry.
        copy_array_forward(*e, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHANNEL_COMMUNICATION_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set server flag into client entry.
        copy_array_forward(*e, (void*) &sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SERVER_COMMUNICATION_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set port into client entry.
        copy_array_forward(*e, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PORT_COMMUNICATION_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set language into client entry.
        copy_array_forward(*e, (void*) &l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) LANGUAGE_COMMUNICATION_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set input buffer item into client entry.
        copy_array_forward(*e, (void*) &ibi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ITEM_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set input buffer mutex into client entry.
        copy_array_forward(*e, (void*) &ibm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set input thread identification into client entry.
        copy_array_forward(*e, (void*) &iti, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set input thread exit flag into client entry.
        copy_array_forward(*e, (void*) &ite, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EXIT_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set output buffer item into client entry.
        copy_array_forward(*e, (void*) &obi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ITEM_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set output buffer mutex into client entry.
        copy_array_forward(*e, (void*) &obm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate client entry. The client entry is null.");
        fwprintf(stdout, L"Error: Could not allocate client entry. The client entry is null. p0: %i\n", p0);
    }
}

/* CLIENT_ENTRY_ALLOCATOR_SOURCE */
#endif
