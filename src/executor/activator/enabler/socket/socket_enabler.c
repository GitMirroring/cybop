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

#ifndef SOCKET_ENABLER_SOURCE
#define SOCKET_ENABLER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/activator/enabler/socket/request_socket_enabler.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "logger.h"

/**
 * Enables server socket to accept client socket requests.
 *
 * CAUTION! Do NOT rename this function to "accept",
 * as that name is already used by low-level glibc functionality.
 *
 * @param p0 the destination sender client socket
 * @param p1 the server entry
 */
void enable_socket(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable socket.");

    // The server socket.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server socket from server entry.
    copy_array_forward((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_SOCKET_SERVER_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"Debug: Enable socket. server socket s: %i\n", s);
    //?? fwprintf(stdout, L"Debug: Enable socket. server socket *s: %i\n", *((int*) s));

    // Accept client request on server socket.
    enable_socket_request(p0, s);
}

/* SOCKET_ENABLER_SOURCE */
#endif
