/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SHUTDOWN_MANAGER_SOURCE
#define SHUTDOWN_MANAGER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../controller/manager/channel_shutdown_manager.c"
#include "../../logger/logger.c"

/**
 * Shuts down all services.
 *
 * @param p0 the internal memory data
 */
void manage_shutdown(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manage shutdown.");
    fwprintf(stdout, L"Debug: Manage shutdown. p0: %i\n", p0);

    //
    // The following calls of "shutdown" procedures are necessary
    // for CLEANUP, in case a cybol application developer forgot it.
    //

    // Shutdown display channel.
    manage_shutdown_channel(p0, (void*) DISPLAY_CYBOI_CHANNEL);
    // Shutdown file channel.
    manage_shutdown_channel(p0, (void*) FILE_CYBOI_CHANNEL);
    // Shutdown pipeline channel.
    manage_shutdown_channel(p0, (void*) PIPELINE_CYBOI_CHANNEL);
    // Shutdown serial channel.
    manage_shutdown_channel(p0, (void*) SERIAL_CYBOI_CHANNEL);
    // Shutdown socket channel.
    manage_shutdown_channel(p0, (void*) SOCKET_CYBOI_CHANNEL);
    // Shutdown terminal channel.
    manage_shutdown_channel(p0, (void*) TERMINAL_CYBOI_CHANNEL);
}

/* SHUTDOWN_MANAGER_SOURCE */
#endif
