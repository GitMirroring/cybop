/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CLOSE_SERIAL_PORT_SHUTTER_SOURCE
#define CLOSE_SERIAL_PORT_SHUTTER_SOURCE

#include <errno.h>
#include <stdio.h>

#if defined(__linux__) || defined(__unix__)
    #include <termios.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <termios.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    //?? Add Win support
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Closes the serial port.
 *
 * @param p0 the file descriptor data
 */
void shutdown_serial_port_close(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown serial port close.");

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        int e = -1;
        // Close file descriptor.
#if defined(__linux__) || defined(__unix__)
        e = close(*d);
#elif defined(__APPLE__) && defined(__MACH__)
        e = close(*d);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
        //?? TODO: Use handle instead of file descriptor here!
        //??    e = CloseHandle(*d);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

        // The normal return value from "close" is zero;
        // a value of minus one is returned in case of failure.
        if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            if (errno == EBADF) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port close. The filedes argument is not a valid file descriptor.");

            } else if (errno == EINTR) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port close. The close call was interrupted by a signal.");

            } else if (errno == ENOSPC) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port close. ENOSPC.");

            } else if (errno == EIO) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port close. EIO.");

#if defined(__linux__) || defined(__unix__)
            } else if (errno == EDQUOT) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port close. When the file is accessed by NFS, these errors from write can sometimes not be detected until close.");

#elif defined(__APPLE__) && defined(__MACH__)
            } else if (errno == EDQUOT) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port close. When the file is accessed by NFS, these errors from write can sometimes not be detected until close.");

// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
                //?? Add Win32 support
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port close. An unknown error occured.");
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port close. The file descriptor data is null.");
    }
}

/* CLOSE_SERIAL_PORT_SHUTTER_SOURCE */
#endif
