/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INITIALISE_WINSOCK_STARTER_SOURCE
#define INITIALISE_WINSOCK_STARTER_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Initialises the winsock.
 */
void startup_winsock_initialise() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock initialise.");

    //
    // The winsock version.
    //
    // CAUTION! The "MAKEWORD" win32 macro eases handling of
    // low-order byte and high-order byte in the value of type WORD.
    //
    // Possible winsock versions:
    // 1.1 -- MAKEWORD(1, 1);
    // 1.2 -- MAKEWORD(1, 2);
    // 2.0 -- MAKEWORD(2, 0);
    // 2.2 -- MAKEWORD(2, 2);
    //
    // Version 2 is used here, since it is backward compatible to version 1.1.
    // This sets the highest version of Windows Sockets support that the caller can use.
    // Further, it supports more protocols than those based on TCP/IP.
    // Finally, Windows Sockets 2 can be used on all Windows platforms.
    // http://msdn.microsoft.com/en-us/library/windows/desktop/ms740673%28v=vs.85%29.aspx
    //
    WORD v = MAKEWORD(2, 2);
    // The data filled with winsock information inside the function called below.
    WSADATA d;

    //
    // Initialise this cyboi process, so that it can use
    // the winsock libraries: WS2_32.DLL and WINSOCK.DLL
    //
    // http://msdn.microsoft.com/en-us/library/windows/desktop/ms742213%28v=vs.85%29.aspx
    //
    int e = WSAStartup(v, &d);

    if (e == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully startup winsock initialise.");

    } else {

        // If the return value is NOT zero, then an error occured.

        // CAUTION! The WSAStartup function directly returns the
        // extended error code in the return value for this function.
        // A call to the WSAGetLastError function is NOT needed
        // and should NOT be used.

        if (e == WSASYSNOTREADY) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock initialise. The underlying network subsystem is not ready for network communication.");

        } else if (e == WSAVERNOTSUPPORTED) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock initialise. The version of Windows Sockets support requested is not provided by this particular Windows Sockets implementation.");

        } else if (e == WSAEINPROGRESS) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock initialise. A blocking Windows Sockets 1.1 operation is in progress.");

        } else if (e == WSAEPROCLIM) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock initialise. A limit on the number of tasks supported by the Windows Sockets implementation has been reached.");

        } else if (e == WSAEFAULT) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock initialise. The lpWSAData parameter is not a valid pointer.");

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock initialise. An unknown error occured.");
        }

        // Cast int to DWORD (unsigned int 32-Bit).
        DWORD d = (DWORD) e;

        log_windows_system_error((void*) &d);
    }
}

/* INITIALISE_WINSOCK_STARTER_SOURCE */
#endif
