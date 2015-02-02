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

#ifndef STATUS_WINSOCK_STARTER_SOURCE
#define STATUS_WINSOCK_STARTER_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Set socket status flags.
 *
 * In this case, the "nonblocking" mode is set.
 *
 * @param p0 the socket
 * @param p1 the blocking flag
 */
void startup_winsock_status(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock status.");

        // Cast int to winsock SOCKET.
        SOCKET ws = (SOCKET) *s;
        // The command.
        //
        // In this case, FIONBIO enables nonblocking mode
        // for the socket based on the numerical value of
        // the argument below.
        long c = FIONBIO;
        //
        // The argument.
        //
        // CAUTION! When a socket is created, it operates in
        // blocking mode by default (consistent with BSD sockets).
        //
        // The following argument values do only make sense
        // together with the command "FIONBIO":
        //
        // ----------------------------
        // Value       | Mode
        // ----------------------------
        // 0           | blocking
        // nonzero     | nonblocking
        // ----------------------------
        //
        // The default is NON-BLOCKING status by setting non-blocking flag (bit).
        //
        // CAUTION! If the O_NONBLOCK flag (a bit) is set,
        // read/write requests on the socket (file) can return
        // immediately with a failure status, instead of blocking,
        // in case no data are immediately available.
        //
        unsigned long int a = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, p1, FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set BLOCKING status by clearing non-blocking flag (bit).
            a = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        }

        //
        // Control the i/o mode of the socket.
        //
        // CAUTION! The "ioctlsocket" function can be used
        // on any socket in any state. It is used to set or retrieve
        // some operating parameters associated with the socket,
        // independent of the protocol and communications subsystem.
        //
        // https://msdn.microsoft.com/en-us/library/windows/desktop/ms738573%28v=vs.85%29.aspx
        //
        // A new socket will be blocking unless one explicitly sets it
        // nonblocking using "ioctlsocket" or "WSAIoctl" with FIONBIO
        // (the latter requiring Winsock 2.2).
        //
        // https://stackoverflow.com/questions/3974193/how-to-find-out-if-a-socket-is-already-in-non-blocking-mode-in-windows/3979776#3979776
        //
        int rv = ioctlsocket(ws, c, &a);

        if (rv == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock status success.");

        } else {

            // If the return value is NOT zero, then an error occured.

            // Get the calling thread's last-error code.
            //
            // CAUTION! This function is the winsock substitute
            // for the Windows "GetLastError" function.
            int e = WSAGetLastError();

            if (e == WSANOTINITIALISED) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock status. A successful WSAStartup call must occur before using this function.");

            } else if (e == WSAENETDOWN) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock status. The network subsystem has failed.");

            } else if (e == WSAEINPROGRESS) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock status. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

            } else if (e == WSAENOTSOCK) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock status. The descriptor s is not a socket.");

            } else if (e == WSAEFAULT) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock status. The argp parameter is not a valid part of the user address space.");

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock status. An unknown error occured.");
            }

            // Cast int to DWORD (unsigned int 32-Bit).
            DWORD d = (DWORD) e;

            log_windows_system_error((void*) &d);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock status. The socket is null.");
    }
}

/* STATUS_WINSOCK_STARTER_SOURCE */
#endif
