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
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    #include "../../../../executor/maintainer/shutter/bsd_socket/bsd_socket_shutter.c"
#elif WIN32
    #include "../../../../executor/maintainer/shutter/winsock/winsock_shutter.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/maintainer/shutter/bsd_socket/bsd_socket_shutter.c"
#else
    #include "../../../../executor/maintainer/shutter/bsd_socket/bsd_socket_shutter.c"
#endif

/**
 * Shuts down the socket service.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 * @param p3 the base internal (depends on the protocol/port)
 */
void shutdown_socket(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket.");

    // The socket.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Calculate internal memory index.
    copy_integer((void*) &i, p3);
    calculate_integer_add((void*) &i, (void*) SOCKET_NUMBER_INDEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get socket.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    // Only deallocate socket resources if the socket internal is NOT null.
    if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Interrupt terminal service thread.
        interrupt_thread(p1, p2);

#ifdef __APPLE__
        shutdown_bsd_socket(s);
#elif WIN32
        shutdown_winsock(s);
#elif GNU_LINUX_OPERATING_SYSTEM
        shutdown_bsd_socket(s);
#else
        shutdown_bsd_socket(s);
#endif

        // Deallocate socket.
        deallocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Reset values.
        // CAUTION! Assign NULL to the internal memory.
        // It is ESSENTIAL, since cyboi tests for null pointers.
        // Otherwise, wild pointers would lead to memory corruption.
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SOCKET_NUMBER_INDEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown socket. There is no socket running at the given base internal.");
    }
}

/* SOCKET_SHUTTER_SOURCE */
#endif
