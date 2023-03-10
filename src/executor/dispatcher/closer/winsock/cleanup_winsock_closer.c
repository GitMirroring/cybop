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

#ifndef CLEANUP_WINSOCK_CLOSER_SOURCE
#define CLEANUP_WINSOCK_CLOSER_SOURCE

#include <winsock.h>

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../logger/logger.c"

/**
 * Cleanup winsock.
 *
 * CAUTION! Do this only AFTER having closed the socket.
 */
void close_winsock_cleanup() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close winsock cleanup.");

    //
    // Cleanup winsock.
    //
    // CAUTION! This releases the link with libraries WS2_32.DLL and WINSOCK.DLL,
    // by doing internal cleanups and decrementing a library reference counter.
    //
    // CAUTION! In a multithreaded environment, WSACleanup
    // terminates Windows Sockets operations for all threads.
    //
    // http://msdn.microsoft.com/en-us/library/windows/desktop/ms741549%28v=vs.85%29.aspx
    //
    int r = WSACleanup();

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close winsock cleanup. Success.");

    } else {

        //
        // Get the calling thread's last-error code.
        //
        // CAUTION! This function is the winsock substitute
        // for the Windows "GetLastError" function.
        //
        int e = WSAGetLastError();

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close winsock cleanup. An error occured.");
        fwprintf(stdout, L"Error: Could not close winsock cleanup. An error occured. %i\n", r);
        log_errno((void*) &e);
    }
}

/* CLEANUP_WINSOCK_CLOSER_SOURCE */
#endif
