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

#ifndef SET_STATUS_SERIAL_PORT_STARTER_SOURCE
#define SET_STATUS_SERIAL_PORT_STARTER_SOURCE

#include "../../../../logger/logger.c"

/**
 * Starts up the serial port status setter.
 *
 * @param p0 the file descriptor data
 * @param p1 the status
 */
void startup_serial_port_status_set(void* p0, void* p1) {

            // Turn on DTR.
            *s |= TIOCM_DTR;
            // Turn on RTS.
            *s |= TIOCM_RTS;

            // Set serial port status.
            int e = ioctl(*d, TIOCMSET, s);
}

/* SET_STATUS_SERIAL_PORT_STARTER_SOURCE */
#endif
