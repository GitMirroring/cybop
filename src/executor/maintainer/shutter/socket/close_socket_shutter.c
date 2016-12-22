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

#ifndef CLOSE_SOCKET_SHUTTER_SOURCE
#define CLOSE_SOCKET_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    #include "../../../../executor/maintainer/shutter/bsd_socket/close_bsd_socket_shutter.c"
#elif WIN32
    #include "../../../../executor/maintainer/shutter/winsock/winsock_shutter.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/maintainer/shutter/bsd_socket/close_bsd_socket_shutter.c"
#else
    #include "../../../../executor/maintainer/shutter/bsd_socket/close_bsd_socket_shutter.c"
#endif

/**
 * Shuts down the given socket.
 *
 * @param p0 the socket
 */
void shutdown_socket_close(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket close.");

#ifdef __APPLE__
    shutdown_bsd_socket_close(p0);
#elif WIN32
    shutdown_winsock(p0);
#elif GNU_LINUX_OPERATING_SYSTEM
    shutdown_bsd_socket_close(p0);
#else
    shutdown_bsd_socket_close(p0);
#endif
}

/* CLOSE_SOCKET_SHUTTER_SOURCE */
#endif
