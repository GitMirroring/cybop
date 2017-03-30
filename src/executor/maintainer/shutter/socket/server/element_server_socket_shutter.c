/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_SERVER_SOCKET_SHUTTER_SOURCE
#define ELEMENT_SERVER_SOCKET_SHUTTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../executor/maintainer/shutter/socket/close_socket_shutter.c"
#include "../../../../../executor/modifier/copier/array_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Shuts down one client.
 *
 * @param p0 the source client list data
 * @param p1 the source client list index
 */
void shutdown_socket_server_element(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket server element.");

    // The client.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get client at the given index.
    copy_array_forward((void*) &c, p0, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1);

    // Close client socket.
    shutdown_socket_close((void*) &c);
}

/* ELEMENT_SERVER_SOCKET_SHUTTER_SOURCE */
#endif
