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

#ifndef SOCKET_ENABLER_SOURCE
#define SOCKET_ENABLER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Enables server socket to accept client socket requests.
 *
 * CAUTION! Do NOT rename this function to "accept",
 * as that name is already used by low-level glibc functionality.
 *
 * @param p0 the client list item
 * @param p2 the server entry
 */
void enable_socket(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable socket.");

    // The server socket.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client socket.
    int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Get server socket from server entry.
    copy_array_forward((void*) &s, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_SOCKET_SERVER_STATE_CYBOI_NAME);

    // Accept client request on server socket.
    enable_socket_request((void*) &c, s);

    // Store client socket stub in cybol property "client".
}

/* SOCKET_ENABLER_SOURCE */
#endif
