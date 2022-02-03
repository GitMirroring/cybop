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

#ifndef GET_STATUS_SERIAL_PORT_STARTER_SOURCE
#define GET_STATUS_SERIAL_PORT_STARTER_SOURCE

#include <stdio.h>

#if defined(__linux__) || defined(__unix__)
    #include <sys/ioctl.h>
    #include <termios.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/ioctl.h>
    #include <termios.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    // Add Win32 support
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/serial_port/set_status_serial_port_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the serial port status getter.
 *
 * @param p0 the file descriptor data
 */
void startup_serial_port_status_get(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup serial port status get.");

        // The serial port status.
        int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // Get serial port status.
        int e = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
#if defined(__linux__) || defined(__unix__)
        e = ioctl(*d, TIOCMGET, &s);
#elif defined(__APPLE__) && defined(__MACH__)
        //?? Check support for apple, different libraries
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
        //?? Add WIN32 support
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

        if (e >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            startup_serial_port_status_set(p0, (void*) &s);

        } else {

            // Close serial port on error.
            close(*d);

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port status get. The retrieval of the status of bits failed.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port status get. The serial port file descriptor data is null.");
    }
}

/* GET_STATUS_SERIAL_PORT_STARTER_SOURCE */
#endif
