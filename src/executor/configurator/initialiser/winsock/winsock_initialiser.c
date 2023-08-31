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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf
#include <winsock.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Initialises the winsock.
 */
void initialise_winsock() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise winsock.");

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

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise winsock.");

    } else {

        //
        // Get the calling thread's last-error code.
        //
        // CAUTION! This function is the winsock substitute
        // for the Windows "GetLastError" function.
        //
        int e = WSAGetLastError();

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise winsock. An error occured.");
        fwprintf(stdout, L"Error: Could not initialise winsock. An error occured. %i\n", r);
        log_error((void*) &e);
    }
}
