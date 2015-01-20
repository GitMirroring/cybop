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

#ifndef SOCKET_SENSOR_SOURCE
#define SOCKET_SENSOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    #include "../../../../executor/lifeguard/sensor/bsd_socket/accept_bsd_socket_sensor.c"
#elif WIN32
    #include "../../../../executor/lifeguard/sensor/winsock/accept_winsock_sensor.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/lifeguard/sensor/bsd_socket/accept_bsd_socket_sensor.c"
#else
    #include "../../../../executor/lifeguard/sensor/bsd_socket/accept_bsd_socket_sensor.c"
#endif

/**
 * Senses data on the given server socket.
 *
 * @param p0 the interrupt request
 * @param p1 the sender client socket
 * @param p2 the server socket
 */
void sense_socket(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket server listen.");

#ifdef __APPLE__
    sense_bsd_socket_accept(p0, p1, p2);
#elif WIN32
    sense_winsock_accept(p0, p1, p2);
#elif GNU_LINUX_OPERATING_SYSTEM
    sense_bsd_socket_accept(p0, p1, p2);
#else
    sense_bsd_socket_accept(p0, p1, p2);
#endif
}

/* SOCKET_SENSOR_SOURCE */
#endif
