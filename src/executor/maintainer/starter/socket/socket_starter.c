/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SOCKET_STARTER_SOURCE
#define SOCKET_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../executor/maintainer/starter/socket/mode_socket_starter.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/representer/deserialiser/network_service/network_service_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the socket.
 *
 * @param p0 the internal memory data
 * @param p1 the service id, e.g. socket port
 * @param p2 the family data (namespace)
 * @param p3 the family count
 * @param p4 the style data (communication type)
 * @param p5 the style count
 * @param p6 the protocol data
 * @param p7 the protocol count
 * @param p8 the blocking flag
 * @param p9 the filename data
 * @param p10 the filename count
 * @param p11 the host address data
 * @param p12 the host address count
 * @param p13 the connexions (number of possible pending client requests)
 * @param p14 the client socket
 * @param p15 the mode data
 * @param p16 the mode count
 * @param p17 the network service data
 * @param p18 the network service count
 */
void startup_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket.");

    // The port.
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy port.
    // CAUTION! It will NOT be copied, if its value is a NULL pointer.
    copy_integer((void*) &p, p1);

    if (p == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // A direct port was NOT given as parametre.
        // Therefore, determine port from service name.

        // Deserialise port from network service name.
        deserialise_network_service((void*) &p, p17, p18);
    }

fwprintf(stdout, L"TEST: startup socket pre p: %i \n", p);
    // Startup socket in either client or server mode.
    startup_socket_mode(p0, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, (void*) &p, p13, p14, p15, p16);
fwprintf(stdout, L"TEST: startup socket post p: %i \n", p);
}

/* SOCKET_STARTER_SOURCE */
#endif
