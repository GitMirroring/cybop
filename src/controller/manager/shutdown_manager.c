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
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../controller/manager/services_shutdown_manager.c"
#include "../../logger/logger.c"

/**
 * Shuts down all services.
 *
 * @param p0 the internal memory data
 */
void manage_shutdown(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manage shutdown.");

    //
    // The following calls of "shutdown" procedures are necessary for cleanup,
    // in case a cybol application developer has forgotten to call the
    // corresponding service shutdown operations.
    //

    // Shutdown display.
    manage_shutdown_services(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DISPLAY_CYBOI_CHANNEL);
    // Shutdown serial port.
    manage_shutdown_services(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) SERIAL_CYBOI_CHANNEL);
    //
    // Shutdown socket.
    //
    // CAUTION! A small delay is caused by the large number of potential services (65536).
    // However, speed is more important at system startup than at shutdown.
    //
    manage_shutdown_services(p0, (void*) NUMBER_65536_INTEGER_STATE_CYBOI_MODEL, (void*) SOCKET_CYBOI_CHANNEL);
    // Shutdown terminal.
    manage_shutdown_services(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) TERMINAL_CYBOI_CHANNEL);
}

/* SHUTDOWN_MANAGER_SOURCE */
#endif
