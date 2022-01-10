/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WINSOCK_ACCEPTOR_SOURCE
#define WINSOCK_ACCEPTOR_SOURCE

#include <winsock.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Accepts data on the given winsock.
 *
 * @param p0 the sender client socket
 * @param p1 the receiver server socket
 */
void accept_winsock(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* c = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept winsock.");

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

            fwprintf(stdout, L"Debug: Accept winsock. client socket wc: %i\n", (int) wc);

            if (wc != INVALID_SOCKET) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept winsock. success.");

                // Cast winsock SOCKET to client int.
                *c = (int) wc;

            } else {

                //
                // If the return value is INVALID_SOCKET, then an error occured.
                //

                //
                // Get the calling thread's last-error code.
                //
                // CAUTION! This function is the winsock substitute
                // for the Windows "GetLastError" function.
                //
                int e = WSAGetLastError();

                if (e == WSANOTINITIALISED) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. A successful WSAStartup call must occur before using this function.");

                } else if (e == WSAECONNRESET) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. An incoming connection was indicated, but was subsequently terminated by the remote peer prior to accepting the call.");

                } else if (e == WSAEFAULT) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The addrlen parameter is too small or addr is not a valid part of the user address space.");

                } else if (e == WSAEINTR) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. A blocking Windows Sockets 1.1 call was canceled through WSACancelBlockingCall.");

                } else if (e == WSAEINVAL) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The listen function was not invoked prior to accept.");

                } else if (e == WSAEINPROGRESS) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

                } else if (e == WSAEMFILE) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The queue is nonempty upon entry to accept and there are no descriptors available.");

                } else if (e == WSAENETDOWN) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The network subsystem has failed.");

                } else if (e == WSAENOBUFS) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. No buffer space is available.");

                } else if (e == WSAENOTSOCK) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The descriptor is not a socket.");

                } else if (e == WSAEOPNOTSUPP) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The referenced socket is not a type that supports connection-oriented service.");

                } else if (e == WSAEWOULDBLOCK) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The socket is marked as nonblocking and no connections are present to be accepted.");

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. An unknown error occured.");
                }

                // Cast int to DWORD (unsigned int 32-Bit).
                DWORD d = (DWORD) e;

                log_windows_system_error((void*) &d);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The sender client socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept winsock. The receiver server socket is null.");
    }
}

/* WINSOCK_ACCEPTOR_SOURCE */
#endif
