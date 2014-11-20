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
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    #include "../../../../executor/maintainer/starter/bsd_socket/bsd_socket_starter.c"
#elif WIN32
    #include "../../../../executor/maintainer/starter/winsock/winsock_starter.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/maintainer/starter/bsd_socket/bsd_socket_starter.c"
#else
    #include "../../../../executor/maintainer/starter/bsd_socket/bsd_socket_starter.c"
#endif

/**
 * Starts up the socket.
 *
 * @param p0 the internal memory data
 */
void startup_socket(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket.");

#ifdef __APPLE__
    startup_bsd_socket(p0);
#elif WIN32
    startup_winsock(p0);
#elif GNU_LINUX_OPERATING_SYSTEM
    startup_bsd_socket(p0);
#else
/*??
    @param p0 the internal memory data (pointer reference)
    @param p1 the family data (namespace)
    @param p2 the family count
    @param p3 the style data
    @param p4 the style count
    @param p5 the filename data
    @param p6 the filename count
    @param p7 the host address data
    @param p8 the host address count
    @param p9 the port
    @param p10 the internal memory base
    @param p11 the connexions
    @param p12 the mode data
    @param p13 the mode count
*/
    startup_bsd_socket(p0);
#endif
}

/* SOCKET_STARTER_SOURCE */
#endif
