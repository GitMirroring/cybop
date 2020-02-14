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

#ifndef MODE_SOCKET_STARTER_SOURCE
#define MODE_SOCKET_STARTER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cybol/socket/mode_socket_cybol_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/checker/operation_checker.c"
#include "../../../../executor/maintainer/starter/socket/client/client_socket_starter.c"
#include "../../../../executor/maintainer/starter/socket/server/server_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up socket in either client or server mode.
 *
 * @param p0 the internal memory data
 * @param p1 the family data (namespace)
 * @param p2 the family count
 * @param p3 the style data (communication type)
 * @param p4 the style count
 * @param p5 the protocol data
 * @param p6 the protocol count
 * @param p7 the blocking flag
 * @param p8 the filename data
 * @param p9 the filename count
 * @param p10 the host address data
 * @param p11 the host address count
 * @param p12 the port
 * @param p13 the connexions (number of possible pending client requests)
 * @param p14 the client socket
 * @param p15 the mode data
 * @param p16 the mode count
 */
void startup_socket_mode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket mode.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p15, (void*) CLIENT_MODE_SOCKET_CYBOL_MODEL, p16, (void*) CLIENT_MODE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Hand over client socket.
            // CAUTION! It does NOT have to be determined from internal memory.
            startup_socket_client(p14, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p15, (void*) SERVER_MODE_SOCKET_CYBOL_MODEL, p16, (void*) SERVER_MODE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST: startup socket mode pre r: %i \n", r);
            startup_socket_server(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
fwprintf(stdout, L"TEST: startup socket mode post r: %i \n", r);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket mode. The mode is unknown.");
    }
}

/* MODE_SOCKET_STARTER_SOURCE */
#endif
