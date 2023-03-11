/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SERIAL_PORT_AWAKENER_SOURCE
#define SERIAL_PORT_AWAKENER_SOURCE

#include <sys/ioctl.h> // ioctl
#include <errno.h> // errno

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "logger.h"

/**
 * Let the system send an input to itself over serial port.
 *
 * @param p0 the device file descriptor
 */
void awake_serial_port(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awake serial port.");
    fwprintf(stdout, L"Debug: Awake serial port. p0: %i\n", p0);

    //
    // Initialise error number.
    //
    // It is a global variable and other operations
    // may have set some value that is not wanted here.
    //
    // CAUTION! Initialise the error number BEFORE calling
    // the function that might cause an error.
    //
    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    //?? TODO: Read in web how to do this.
    //?? See also wake up of "terminal"!
    //
    int r = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    //?? int r = ioctl(p0, TIOCSTI, LINE_FEED_ASCII_CHARACTER_CODE_MODEL);

    //
    // The meaning of the returned value depends upon the command used.
    //
    // Linux:
    // - success: zero or non-negative value
    // - error: -1 and errno set appropriately
    // - special case: sometimes used as output parameter
    //
    if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awake serial port. Success.");
        fwprintf(stdout, L"Debug: Awake serial port. Success. r: %i\n", r);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awake serial port. An error occured.");
        fwprintf(stdout, L"Error: Could not awake serial port. An error occured. %i\n", r);
        log_error((void*) &errno);
    }
}

/* SERIAL_PORT_AWAKENER_SOURCE */
#endif
