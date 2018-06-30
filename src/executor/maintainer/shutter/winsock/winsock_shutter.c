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

#ifndef WINSOCK_SHUTTER_SOURCE
#define WINSOCK_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../executor/maintainer/shutter/winsock/cleanup_winsock_shutter.c"
#include "../../../../executor/maintainer/shutter/winsock/close_winsock_shutter.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the socket service.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the socket
 */
void shutdown_winsock(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown winsock.");

    // Close socket.
    shutdown_winsock_close(p0);

    // Cleanup socket.
    shutdown_winsock_cleanup();
}

/* WINSOCK_SHUTTER_SOURCE */
#endif
