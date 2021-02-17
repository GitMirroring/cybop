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

#ifndef SOCKET_SHUTTER_SOURCE
#define SOCKET_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../executor/maintainer/shutter/socket/mode_socket_shutter.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/representer/deserialiser/network_service/network_service_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the socket service.
 *
 * CAUTION! This is done in the reverse order the service was started up.
 *
 * @param p0 the input/output entry
 * @param p1 the port
 * @param p2 the client socket
 * @param p3 the mode data
 * @param p4 the mode count
 * @param p5 the network service data
 * @param p6 the network service count
 */
void shutdown_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket.");

    // The port.
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Copy port.
    //
    // CAUTION! It will NOT be copied, if its value is a NULL pointer.
    //
    copy_integer((void*) &p, p1);

    //?? fwprintf(stdout, L"TEST: shutdown socket p: %i \n", p);

    if (p == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        //
        // A direct port was NOT given as parametre.
        // Therefore, determine port from service name.
        //

        // Deserialise port from network service name.
        deserialise_network_service((void*) &p, p5, p6);
    }

    shutdown_socket_mode(p0, (void*) &p, p2, p3, p4);
}

/* SOCKET_SHUTTER_SOURCE */
#endif
