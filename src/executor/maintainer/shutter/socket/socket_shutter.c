/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_SHUTTER_SOURCE
#define SOCKET_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the socket service.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 * @param p3 the base internal
 */
void shutdown_socket(void* p0, void* p1, void* p2, void* p3) {

/*??
    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* base = (int*) p3;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The socket of this system.
        int* s = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get socket of this system.
        i = *base + *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Interrupt ALL socket service threads of this system.
            interrupt_thread(p1, p2);

            // The socket address (local, ipv4, ipv6) of this system.
            void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The communication partner socket address (local, ipv4, ipv6).
            void* pa = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The socket address size of this system.
            void* as = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The communication partner socket address size.
            void* pas = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The communication partner socket.
            int* ps = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
            // The character buffer being used in the thread procedure receiving messages via socket.
            void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* bs = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get socket address of this system.
            i = *base + *DATA_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward((void*) &a, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get communication partner socket address.
            i = *base + *ADDRESS_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward((void*) &pa, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get socket address size of this system.
            i = *base + *SIZE_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward((void*) &as, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get communication partner socket address size.
            i = *base + *ADDRESS_SIZE_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward((void*) &pas, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get communication partner socket.
            i = *base + *COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward((void*) &ps, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get character buffer.
            i = *base + *DATA_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            i = *base + *COUNT_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward((void*) &bc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            i = *base + *SIZE_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward((void*) &bs, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

            // Close socket of this system.
            close(*s);
            // Close communication partner socket.
//??            close(*ps);

/*??
            // Deallocate character buffer.
            deallocate((void*) &b, bs, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            deallocate((void*) &bc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate((void*) &bs, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            // Deallocate socket of this system.
            deallocate((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            // Deallocate communication partner socket.
            deallocate((void*) &ps, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            // Deallocate socket address of this system.
            free(a);
            // Deallocate communication partner socket address.
            free(pa);
            // Deallocate socket address size of this system.
            deallocate((void*) &as, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            // Deallocate communication partner socket address size.
            deallocate((void*) &pas, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            // Reset socket variables.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.

            // Reset socket address of this system.
            i = *base + *DATA_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Reset communication partner socket address.
            i = *base + *ADDRESS_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Reset socket address size of this system.
            i = *base + *SIZE_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Reset communication partner socket address size.
            i = *base + *ADDRESS_SIZE_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Reset communication partner socket.
            i = *base + *COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Reset character buffer.
            i = *base + *DATA_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            i = *base + *COUNT_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            i = *base + *SIZE_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
*/

/*??
        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket. There is no socket of this system running.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket. The base internal is null.");
    }
*/
}

/* SOCKET_SHUTTER_SOURCE */
#endif
