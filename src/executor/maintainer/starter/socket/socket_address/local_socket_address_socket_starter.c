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

#ifndef LOCAL_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE
#define LOCAL_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE

#include <sys/socket.h>
#include <stddef.h> // size_t
#include <stdlib.h> // malloc
#include <string.h> // memset

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "../../../../../executor/maintainer/starter/socket/socket_address/initialise_local_socket_address_socket_starter.c"
#include "../../../../../logger/logger.c"
#include "../../../../../variable/type_size/integral_type_size.c"

/**
 * Startup local socket address.
 *
 * @param p0 the socket address data (pointer reference)
 * @param p1 the socket address size
 * @param p2 the filename data
 * @param p3 the filename count
 */
void startup_socket_socket_address_local(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** ad = (void**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket socket address local.");

        //
        // Allocate socket address.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) LOCAL_SOCKET_ADDRESS_STATE_CYBOI_TYPE);

        //
        // Initialise socket address size.
        //
        // CAUTION! For the allocation above, the size gets determined inside
        // the "allocate_array" function, so that it is not needed as argument.
        // However, socket functions DO REQUIRE the socket address size
        // as argument, so that it has to be assigned here explicitly.
        //
        copy_integer(p1, (void*) LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

        // Initialise address.
        startup_socket_socket_address_local_initialise(*ad, p2, p3);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address local. The address data is null.");
    }
}

/* LOCAL_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE */
#endif
