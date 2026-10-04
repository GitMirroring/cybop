/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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
 * Connects the windows socket to the server given by the address.
 *
 * @param p0 the socket
 * @param p1 the server address data
 * @param p2 the server address size
 */
void open_winsock_connexion(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open winsock connexion.");

                // Cast int to winsock SOCKET.
                SOCKET ws = (SOCKET) *s;

                //
                // Establish connection to specified socket.
                //
                // CAUTION! This function call WAITS until the server
                // responds to the request before it returns.
                //
                // http://msdn.microsoft.com/en-us/library/windows/desktop/ms737625%28v=vs.85%29.aspx
                //
                int r = connect(ws, ad, *as);

                if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open winsock connexion. success.");

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

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open winsock. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open winsock. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open winsock. The address size is null.");
    }
}
