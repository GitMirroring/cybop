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

#ifndef SOCKET_STARTER_SOURCE
#define SOCKET_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/maintainer/starter/socket/mode_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the socket.
 *
 * @param p0 the internal memory data (pointer reference)
 * @param p1 the family data (namespace)
 * @param p2 the family count
 * @param p3 the style data
 * @param p4 the style count
 * @param p5 the filename data
 * @param p6 the filename count
 * @param p7 the host address data
 * @param p8 the host address count
 * @param p9 the port
 * @param p10 the internal memory base
 * @param p11 the connexions (number of possible pending client requests)
 * @param p12 the mode data
 * @param p13 the mode count
 */
void startup_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket.");

    //?? TODO: Allocate an integer number for storing the socket number in internal memory, e.g. like this:
    // Allocate socket.
    // allocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    // Retrieval of necessary internal memory values can be done here.

    // Startup socket in either client or server mode.
    startup_socket_mode();
}

/* SOCKET_STARTER_SOURCE */
#endif
