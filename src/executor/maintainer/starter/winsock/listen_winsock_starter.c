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
 * @version CYBOP 0.26.0 2023-04-04
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
 * Enable socket to accept connections, thus making it a server socket.
 *
 * @param p0 the socket
 * @param p1 the connexions (number of possible pending client requests)
 */
void startup_winsock_listen(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* c = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* s = (int*) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock listen.");

            // Cast int to winsock SOCKET.
            SOCKET ws = (SOCKET) *s;

            //
            // Enable socket to accept connections, thus making it a server socket.
            // The second parametre determines the number of possible
            // pending client connection requests.
            //
            // http://msdn.microsoft.com/en-us/library/windows/desktop/ms739168%28v=vs.85%29.aspx
            //
            int r = listen(ws, *c);

            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully startup winsock listen.");

            } else {

                //
                // Get the calling thread's last-error code.
                //
                // CAUTION! This function is the winsock substitute
                // for the Windows "GetLastError" function.
                //
                int e = WSAGetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open winsock connexion. An error occured.");
                fwprintf(stdout, L"Error: Could not open winsock connexion. An error occured. %i\n", r);
                log_error((void*) &e);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The connexions is null.");
    }
}
