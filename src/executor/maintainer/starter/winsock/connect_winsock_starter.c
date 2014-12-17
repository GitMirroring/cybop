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

#ifndef CONNECT_WINSOCK_STARTER_SOURCE
#define CONNECT_WINSOCK_STARTER_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Connects with a server via socket.
 *
 * @param p0 the socket
 * @param p1 the socket address data
 * @param p2 the socket address size
 */
void startup_winsock_connect(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock connect.");

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

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully startup winsock connect.");

                } else {

                    // If the return value is NOT zero, then an error occured.

                    // Get the calling thread's last-error code.
                    //
                    // CAUTION! This function is the winsock substitute
                    // for the Windows "GetLastError" function.
                    int e = WSAGetLastError();

                    if (e == WSANOTINITIALISED) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. A successful WSAStartup call must occur before using this function.");

                    } else if (e == WSAENETDOWN) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The network subsystem has failed.");

                    } else if (e == WSAEADDRINUSE) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs when executing bind, but could be delayed until the connect function if the bind was to a wildcard address (INADDR_ANY or in6addr_any) for the local IP address. A specific address needs to be implicitly bound by the connect function.");

                    } else if (e == WSAEINTR) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The blocking Windows Socket 1.1 call was canceled through WSACancelBlockingCall.");

                    } else if (e == WSAEINPROGRESS) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

                    } else if (e == WSAEALREADY) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. A nonblocking connect call is in progress on the specified socket. In order to preserve backward compatibility, this error is reported as WSAEINVAL to Windows Sockets 1.1 applications that link to either Winsock.dll or Wsock32.dll.");

                    } else if (e == WSAEADDRNOTAVAIL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The remote address is not a valid address (such as INADDR_ANY or in6addr_any).");

                    } else if (e == WSAEAFNOSUPPORT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. Addresses in the specified family cannot be used with this socket.");

                    } else if (e == WSAECONNREFUSED) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The attempt to connect was forcefully rejected.");

                    } else if (e == WSAEFAULT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The sockaddr structure pointed to by the name contains incorrect address format for the associated address family or the namelen parameter is too small. This error is also returned if the sockaddr structure pointed to by the name parameter with a length specified in the namelen parameter is not in a valid part of the user address space.");

                    } else if (e == WSAEINVAL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The parameter s is a listening socket.");

                    } else if (e == WSAEISCONN) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket is already connected (connection-oriented sockets only).");

                    } else if (e == WSAENETUNREACH) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The network cannot be reached from this host at this time.");

                    } else if (e == WSAEHOSTUNREACH) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. A socket operation was attempted to an unreachable host.");

                    } else if (e == WSAENOBUFS) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. No buffer space is available. The socket cannot be connected.");

                    } else if (e == WSAENOTSOCK) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The descriptor specified in the s parameter is not a socket.");

                    } else if (e == WSAETIMEDOUT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. An attempt to connect timed out without establishing a connection.");

                    } else if (e == WSAEWOULDBLOCK) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket is marked as nonblocking and the connection cannot be completed immediately.");

                    } else if (e == WSAEACCES) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. An attempt to connect a datagram socket to broadcast address failed because setsockopt option SO_BROADCAST is not enabled.");

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. An unknown error occured.");
                    }

                    // Cast int to DWORD (unsigned int 32-Bit).
                    DWORD d = (DWORD) e;

                    log_windows_system_error((void*) &d);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock connect. The address size is null.");
    }
}

/* CONNECT_WINSOCK_STARTER_SOURCE */
#endif
