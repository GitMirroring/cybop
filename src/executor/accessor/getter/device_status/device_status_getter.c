/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DEVICE_STATUS_GETTER_SOURCE
#define DEVICE_STATUS_GETTER_SOURCE

#include <sys/ioctl.h> // TIOCMGET

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../executor/configurator/configurator.c"
#include "../../../../logger/logger.c"

/**
 * Gets the device status.
 *
 * @param p0 the destination status
 * @param p1 the source device file descriptor
 */
void get_device_status(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get device status.");
    fwprintf(stdout, L"Debug: Get device status. p0: %i\n", p0);

    // Get device status.
    configure(p1, TIOCMGET, p0);
}

/* DEVICE_STATUS_GETTER_SOURCE */
#endif
