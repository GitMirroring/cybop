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
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/activator/enabler/socket/request_socket_enabler.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/dispatcher/opener/opener.c"
#include "../../../../executor/feeler/sensor/sensor.c"
#include "../../../../executor/maintainer/client_list/add_client_list_maintainer.c"
#include "../../../../logger/logger.c"

/**
 * Enables server socket to accept client socket requests.
 *
 * @param p0 the client entry list item
 * @param p1 the client identification list item
 * @param p2 the server entry
 * @param p3 the channel
 */
void enable_socket(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable socket.");

    // The server socket.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client socket.
    int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server socket from server entry.
    copy_array_forward((void*) &s, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_SOCKET_SERVER_STATE_CYBOI_NAME);

    // Accept client request on server socket and get client identification.
    enable_socket_request((void*) &c, s);

    if (c >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        //
        // Open up client entry.
        //
        // CAUTION! Hand over accepted client socket as client identification.
        //
        // CAUTION! Whilst for the display channel, a client window has to be opened
        // MANUALLY by the developer through calling the cybol operation "dispatch/open",
        // the socket client connexions are managed AUTOMATICALLY inside cyboi.
        // Therefore, a socket client gets opened here.
        //
        open_client((void*) &ce, p2, p3);

        // Get client entry client identification from client entry.
        copy_array_forward((void*) &id, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);
        // Get client entry thread identification from client entry.
        copy_array_forward((void*) &t, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_CLIENT_STATE_CYBOI_NAME);

        // Copy client identification to client entry client identification.
        copy_integer(id, (void*) &c);

        // Store client entry in client list items using client identification as index.
        maintain_client_list_add(p0, p1, (void*) &ce, (void*) &c);

        // Sense client data input.
        sense(TODO ??);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable socket. The client socket is invalid.");
        fwprintf(stdout, L"Error: Could not enable socket. The client socket is invalid. c: %i\n", c);
    }
}

/* SOCKET_ENABLER_SOURCE */
#endif
