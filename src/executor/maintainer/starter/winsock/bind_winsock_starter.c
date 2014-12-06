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

#ifndef BIND_WINSOCK_STARTER_SOURCE
#define BIND_WINSOCK_STARTER_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Binds the address to the socket.
 *
 * @param p0 the socket
 * @param p1 the address data
 * @param p2 the address size
 */
void startup_winsock_bind(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock bind.");

                // Cast int to winsock SOCKET.
                SOCKET ws = (SOCKET) *s;

                //
                // Associate local address with socket.
                //
                // http://msdn.microsoft.com/en-us/library/windows/desktop/ms737550%28v=vs.85%29.aspx
                //
                int r = bind(ws, ad, *as);

                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // Get the calling thread's last-error code.
                    //
                    // CAUTION! This function is the winsock substitute
                    // for the Windows "GetLastError" function.
                    int e = WSAGetLastError();

                    if (e == WSANOTINITIALISED) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. A successful WSAStartup call must occur before using this function.");

                    } else if (e == WSAENETDOWN) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The network subsystem has failed.");

                    } else if (e == WSAEACCES) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. An attempt was made to access a socket in a way forbidden by its access permissions. This error is returned if an attempt to bind a datagram socket to the broadcast address failed because the setsockopt option SO_BROADCAST is not enabled.");

                    } else if (e == WSAEADDRINUSE) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. Only one usage of each socket address (protocol/network address/port) is normally permitted. This error is returned if a process on the computer is already bound to the same fully qualified address and the socket has not been marked to allow address reuse with SO_REUSEADDR. For example, the IP address and port specified in the name parameter are already bound to another socket being used by another application. For more information, see the SO_REUSEADDR socket option in the SOL_SOCKET Socket Options reference, Using SO_REUSEADDR and SO_EXCLUSIVEADDRUSE, and SO_EXCLUSIVEADDRUSE.");

                    } else if (e == WSAEADDRNOTAVAIL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The requested address is not valid in its context. This error is returned if the specified address pointed to by the name parameter is not a valid local IP address on this computer.");

                    } else if (e == WSAEFAULT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The system detected an invalid pointer address in attempting to use a pointer argument in a call. This error is returned if the name parameter is NULL, the name or namelen parameter is not a valid part of the user address space, the namelen parameter is too small, the name parameter contains an incorrect address format for the associated address family, or the first two bytes of the memory block specified by name do not match the address family associated with the socket descriptor s.");

                    } else if (e == WSAEINPROGRESS) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

                    } else if (e == WSAEINVAL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. An invalid argument was supplied. This error is returned if the socket s is already bound to an address.");

                    } else if (e == WSAENOBUFS) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full. This error is returned of not enough buffers are available or there are too many connections.");

                    } else if (e == WSAENOTSOCK) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. An operation was attempted on something that is not a socket. This error is returned if the descriptor in the s parameter is not a socket.");

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. An unknown error occured.");
                    }

                    // Cast int to DWORD (unsigned int 32-Bit).
                    DWORD d = (DWORD) e;

                    log_windows_system_error((void*) &d);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock bind. The address size is null.");
    }
}

/* BIND_WINSOCK_STARTER_SOURCE */
#endif
