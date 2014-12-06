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

#ifndef LISTEN_SOCKET_STARTER_SOURCE
#define LISTEN_SOCKET_STARTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../logger/logger.c"

#ifdef __APPLE__
    #include "../../../../executor/maintainer/starter/bsd_socket/listen_bsd_socket_starter.c"
#elif WIN32
    #include "../../../../executor/maintainer/starter/winsock/listen_winsock_starter.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/maintainer/starter/bsd_socket/listen_bsd_socket_starter.c"
#else
    #include "../../../../executor/maintainer/starter/bsd_socket/listen_bsd_socket_starter.c"
#endif

/**
 * Enable socket to accept connections, thus making it a server socket.
 *
 * @param p0 the socket
 * @param p1 the connexions (number of possible pending client requests)
 */
void startup_socket_listen(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket listen.");

#ifdef __APPLE__
    startup_bsd_socket_listen(p0, p1, p2, p3);
#elif WIN32
    startup_winsock_listen(p0, p1, p2, p3);
#elif GNU_LINUX_OPERATING_SYSTEM
    startup_bsd_socket_listen(p0, p1, p2, p3);
#else
    startup_bsd_socket_listen(p0, p1, p2, p3);
#endif
}

/* LISTEN_SOCKET_STARTER_SOURCE */
#endif
