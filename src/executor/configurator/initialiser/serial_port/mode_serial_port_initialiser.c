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

#ifndef MODE_SERIAL_PORT_INITIALISER_SOURCE
#define MODE_SERIAL_PORT_INITIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/configurator/initialiser/unix_serial_port/unix_serial_port_initialiser.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/configurator/initialiser/unix_serial_port/unix_serial_port_initialiser.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/configurator/initialiser/win32_serial_port/win32_serial_port_initialiser.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Initialises the serial port mode.
 *
 * @param p0 the terminal mode
 * @param p1 the baudrate
 */
void initialise_serial_port_mode(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise serial port mode.");

#if defined(__linux__) || defined(__unix__)
    initialise_unix_serial_port(p0, p1);
#elif defined(__APPLE__) && defined(__MACH__)
    initialise_unix_serial_port(p0, p1);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    initialise_win32_serial_port(p0, p1);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* MODE_SERIAL_PORT_INITIALISER_SOURCE */
#endif
