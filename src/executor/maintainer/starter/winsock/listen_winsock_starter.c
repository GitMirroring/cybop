/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LISTEN_WINSOCK_STARTER_SOURCE
#define LISTEN_WINSOCK_STARTER_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

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

                // If the return value is NOT zero, then an error occured.

                // Get the calling thread's last-error code.
                //
                // CAUTION! This function is the winsock substitute
                // for the Windows "GetLastError" function.
                int e = WSAGetLastError();

                if (e == WSANOTINITIALISED) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. A successful WSAStartup call must occur before using this function.");

                } else if (e == WSAENETDOWN) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The network subsystem has failed.");

                } else if (e == WSAEADDRINUSE) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs during execution of the bind function, but could be delayed until this function if the bind was to a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be committed at the time of this function.");

                } else if (e == WSAEINPROGRESS) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

                } else if (e == WSAEINVAL) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The socket has not been bound with bind.");

                } else if (e == WSAEISCONN) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The socket is already connected.");

                } else if (e == WSAEMFILE) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. No more socket descriptors are available.");

                } else if (e == WSAENOBUFS) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. No buffer space is available.");

                } else if (e == WSAENOTSOCK) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The descriptor is not a socket.");

                } else if (e == WSAEOPNOTSUPP) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The referenced socket is not of a type that supports the listen operation.");

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. An unknown error occured.");
                }

                // Cast int to DWORD (unsigned int 32-Bit).
                DWORD d = (DWORD) e;

                log_windows_system_error((void*) &d);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock listen. The connexions is null.");
    }
}

/* LISTEN_WINSOCK_STARTER_SOURCE */
#endif
