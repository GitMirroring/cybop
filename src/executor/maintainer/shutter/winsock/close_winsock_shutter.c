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

#ifndef CLOSE_WINSOCK_SHUTTER_SOURCE
#define CLOSE_WINSOCK_SHUTTER_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Closes the winsock socket.
 *
 * @param p0 the socket
 */
void shutdown_winsock_close(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown winsock close.");

        // Cast socket to winsock.
        SOCKET ws = (SOCKET) *s;

        //
        // Close existing socket.
        //
        // CAUTION! The winsock api provides this "closesocket" function.
        // It does basically the same as the standard "close" function.
        //
        // http://msdn.microsoft.com/en-us/library/windows/desktop/ms737582%28v=vs.85%29.aspx
        //
        int r = closesocket(ws);

        if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully shutdown winsock close.");

        } else {

            // If the return value is NOT zero, then an error occured.

            // Get the calling thread's last-error code.
            //
            // CAUTION! This function is the winsock substitute
            // for the Windows "GetLastError" function.
            int e = WSAGetLastError();

            if (e == WSANOTINITIALISED) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown winsock close. A successful WSAStartup call must occur before using this function.");

            } else if (e == WSAENETDOWN) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown winsock close. The network subsystem has failed.");

            } else if (e == WSAENOTSOCK) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown winsock close. The descriptor is not a socket.");

            } else if (e == WSAEINPROGRESS) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown winsock close. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

            } else if (e == WSAEINTR) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown winsock close. The (blocking) Windows Socket 1.1 call was canceled through WSACancelBlockingCall.");

            } else if (e == WSAEWOULDBLOCK) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown winsock close. The socket is marked as nonblocking, but the l_onoff member of the linger structure is set to nonzero and the l_linger member of the linger structure is set to a nonzero timeout value.");

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown winsock close. An unknown error occured.");
            }

            // Cast int to DWORD (unsigned int 32-Bit).
            DWORD d = (DWORD) e;

            log_windows_system_error((void*) &d);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown winsock close. The socket is null.");
    }
}

/* CLOSE_WINSOCK_SHUTTER_SOURCE */
#endif
