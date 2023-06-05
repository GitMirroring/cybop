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
 * Accepts a client request on the given winsock.
 *
 * CAUTION! Do NOT rename this function to "accept",
 * as that name is already used by low-level win32 functionality.
 *
 * @param p0 the destination sender client socket
 * @param p1 the source receiver server socket
 */
void enable_winsock(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* c = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable winsock.");

            // Cast receiver server socket int to winsock SOCKET.
            SOCKET ws = (SOCKET) *s;

            //
            // Permit incoming connexion attempt on a socket.
            //
            // CAUTION! If addr (second argument) and/or addrlen (third argument)
            // are equal to NULL, then no information about the remote address
            // of the accepted client socket is returned.
            //
            // http://msdn.microsoft.com/en-us/library/windows/desktop/ms737526%28v=vs.85%29.aspx
            //
            SOCKET wc = accept(ws, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

            fwprintf(stdout, L"Debug: Enable winsock. client socket wc: %i\n", (int) wc);

            if (wc != INVALID_SOCKET) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable winsock. success.");

                // Cast winsock SOCKET to client int.
                *c = (int) wc;

            } else {

                //
                // Get the calling thread's last-error code.
                //
                // CAUTION! This function is the winsock substitute
                // for the Windows "GetLastError" function.
                //
                int e = WSAGetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable winsock. An error occured.");
                fwprintf(stdout, L"Error: Could not enable winsock. An error occured. %i\n", r);
                log_error((void*) &e);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable winsock. The sender client socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable winsock. The receiver server socket is null.");
    }
}
