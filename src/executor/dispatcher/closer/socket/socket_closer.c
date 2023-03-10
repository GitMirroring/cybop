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

#ifndef SOCKET_CLOSER_SOURCE
#define SOCKET_CLOSER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/dispatcher/closer/basic/basic_closer.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/dispatcher/closer/basic/basic_closer.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/maintainer/shutter/winsock/winsock_shutter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Shuts down the socket service.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the socket
 */
void close_socket(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close socket.");

#if defined(__linux__) || defined(__unix__)
    close_basic(p0);
#elif defined(__APPLE__) && defined(__MACH__)
    close_basic(p0);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    // Close socket.
    close_winsock_close(p0);
    // Cleanup socket.
    close_winsock_cleanup();
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* SOCKET_CLOSER_SOURCE */
#endif
