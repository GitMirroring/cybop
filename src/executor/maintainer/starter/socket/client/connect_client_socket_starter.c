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

#ifndef CONNECT_CLIENT_SOCKET_STARTER_SOURCE
#define CONNECT_CLIENT_SOCKET_STARTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../logger/logger.c"

#ifdef __APPLE__
    #include "../../../../../executor/maintainer/starter/bsd_socket/connect_bsd_socket_starter.c"
#elif WIN32
    #include "../../../../../executor/maintainer/starter/winsock/connect_winsock_starter.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../../executor/maintainer/starter/bsd_socket/connect_bsd_socket_starter.c"
#else
    #include "../../../../../executor/maintainer/starter/bsd_socket/connect_bsd_socket_starter.c"
#endif

/**
 * Connects a client socket.
 *
 * @param p0 the socket
 * @param p1 the socket address data
 * @param p2 the socket address size
 */
void startup_socket_client_connect(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket client connect.");

fwprintf(stdout, L"TEST: startup socket client connect s: %i \n", *((int*) p0));
sleep(2);

#ifdef __APPLE__
    startup_bsd_socket_connect(p0, p1, p2);
#elif WIN32
    startup_winsock_connect(p0, p1, p2);
#elif GNU_LINUX_OPERATING_SYSTEM
    startup_bsd_socket_connect(p0, p1, p2);
#else
    startup_bsd_socket_connect(p0, p1, p2);
#endif
}

/* CONNECT_CLIENT_SOCKET_STARTER_SOURCE */
#endif
