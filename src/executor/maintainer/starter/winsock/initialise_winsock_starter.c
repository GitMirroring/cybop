/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INITIALISE_WINSOCK_STARTER_SOURCE
#define INITIALISE_WINSOCK_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/*??
#include <stdio.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif
*/

/**
 * Initialises the winsock.
 *
 * @param p0 the internal memory data
 */
void startup_winsock_initialise(void* p0) {

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

    // Initialise this cyboi process, so that it can use
    // the winsock libraries: WS2_32.DLL and WINSOCK.DLL
    int r = WSAStartup(v, &d);

    if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock initialise. The WSAStartup call failed.");
    }
}

/* INITIALISE_WINSOCK_STARTER_SOURCE */
#endif
