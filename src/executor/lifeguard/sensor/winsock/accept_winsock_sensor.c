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

#ifndef ACCEPT_WINSOCK_SENSOR_SOURCE
#define ACCEPT_WINSOCK_SENSOR_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Accepts data on the given winsock.
 *
 * @param p0 the sender client socket
 * @param p1 the server socket
 */
void sense_winsock_accept(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* c = (int*) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense winsock accept.");

            // Cast server int to winsock SOCKET.
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

            if (wc != INVALID_SOCKET) {

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense winsock accept successfully.");

                // Cast winsock SOCKET to client int.
                *c = (int) wc;

    fwprintf(stdout, L"TEST: sense winsock accept c: %i \n", *c);

            } else {

                // If the return value is INVALID_SOCKET, then an error occured.

                // Get the calling thread's last-error code.
                //
                // CAUTION! This function is the winsock substitute
                // for the Windows "GetLastError" function.
                int e = WSAGetLastError();

                if (e == WSANOTINITIALISED) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. A successful WSAStartup call must occur before using this function.");

                } else if (e == WSAECONNRESET) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. An incoming connection was indicated, but was subsequently terminated by the remote peer prior to accepting the call.");

                } else if (e == WSAEFAULT) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The addrlen parameter is too small or addr is not a valid part of the user address space.");

                } else if (e == WSAEINTR) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. A blocking Windows Sockets 1.1 call was canceled through WSACancelBlockingCall.");

                } else if (e == WSAEINVAL) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The listen function was not invoked prior to accept.");

                } else if (e == WSAEINPROGRESS) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

                } else if (e == WSAEMFILE) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The queue is nonempty upon entry to accept and there are no descriptors available.");

                } else if (e == WSAENETDOWN) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The network subsystem has failed.");

                } else if (e == WSAENOBUFS) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. No buffer space is available.");

                } else if (e == WSAENOTSOCK) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The descriptor is not a socket.");

                } else if (e == WSAEOPNOTSUPP) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The referenced socket is not a type that supports connection-oriented service.");

                } else if (e == WSAEWOULDBLOCK) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The socket is marked as nonblocking and no connections are present to be accepted.");

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. An unknown error occured.");
                }

                // Cast int to DWORD (unsigned int 32-Bit).
                DWORD d = (DWORD) e;

                log_windows_system_error((void*) &d);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The client socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense winsock accept. The server socket is null.");
    }
}

/* ACCEPT_WINSOCK_SENSOR_SOURCE */
#endif
