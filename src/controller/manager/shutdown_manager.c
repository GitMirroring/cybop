/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHUTDOWN_MANAGER_SOURCE
#define SHUTDOWN_MANAGER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../controller/manager/services_shutdown_manager.c"
#include "../../executor/maintainer/shutter/display/display_shutter.c"
#include "../../executor/maintainer/shutter/serial_port/serial_port_shutter.c"
#include "../../executor/maintainer/shutter/terminal/terminal_shutter.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Shuts down all services.
 *
 * @param p0 the internal memory data
 */
void manage_shutdown(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manage shutdown.");

    // The following calls of "shutdown" procedures are just to be sure,
    // in case a cybol application developer has forgotten to call the
    // corresponding service shutdown operation in cybol logic templates.
    // The "interrupt" procedures are called within the "shutdown" procedures.

//?? fwprintf(stdout, L"TEST manage shutdown p0: %i\n", p0);

    // Shutdown display.
    shutdown_display(p0, (void*) DISPLAY_THREAD, (void*) DISPLAY_EXIT); //?? TODO: This is the OLD version, soon to be replaced with "manage_shutdown_all"
    // Shutdown serial port.
    shutdown_serial_port(p0, (void*) SERIAL_THREAD, (void*) SERIAL_EXIT); //?? TODO: This is the OLD version, soon to be replaced with "manage_shutdown_all"
    // Shutdown socket.
    manage_shutdown_services(p0, (void*) NUMBER_65536_INTEGER_STATE_CYBOI_MODEL, (void*) SOCKET_CYBOI_CHANNEL);
    // Shutdown terminal.
    shutdown_terminal(p0, (void*) TERMINAL_THREAD, (void*) TERMINAL_EXIT); //?? TODO: This is the OLD version, soon to be replaced with "manage_shutdown_all"
}

/* SHUTDOWN_MANAGER_SOURCE */
#endif
