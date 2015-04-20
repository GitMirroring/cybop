/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_WINSOCK_STARTER_SOURCE
#define CREATE_WINSOCK_STARTER_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/maintainer/starter/winsock/status_winsock_starter.c"
#include "../../../../logger/logger.c"

/**
 * Create socket.
 *
 * @param p0 the socket
 * @param p1 the protocol family (socket namespace)
 * @param p2 the communication style
 * @param p3 the protocol
 * @param p4 the blocking flag
 */
void startup_winsock_create(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* pr = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* st = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* pf = (int*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* s = (int*) p0;

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock create.");

                    //
                    // Create winsock socket that is bound to a specific transport service provider.
                    //
                    // param 0: protocol family (namespace)
                    // param 1: communication style
                    // param 2: protocol (zero is usually right)
                    //
                    // CAUTION! Use prefix "PF_" here and NOT "AF_"!
                    // The latter is to be used for address family assignment.
                    // See further below!
                    //
                    // http://msdn.microsoft.com/en-us/library/windows/desktop/ms740506%28v=vs.85%29.aspx
                    //
                    SOCKET ws = socket(*pf, *st, *pr);

                    if (ws != INVALID_SOCKET) {

                        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully startup winsock create.");

                        // Cast winsock SOCKET to destination int.
                        *s = (int) ws;

                        // Make socket nonblocking.
                        startup_winsock_status(p0, p4);

                    } else {

                        // If the return value IS invalid, then an error occured.

                        // Get the calling thread's last-error code.
                        //
                        // CAUTION! This function is the winsock substitute
                        // for the Windows "GetLastError" function.
                        int e = WSAGetLastError();

                        if (e == WSANOTINITIALISED) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. A successful WSAStartup call must occur before using this function.");

                        } else if (e == WSAENETDOWN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The network subsystem or the associated service provider has failed.");

                        } else if (e == WSAEAFNOSUPPORT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The specified address family is not supported. For example, an application tried to create a socket for the AF_IRDA address family but an infrared adapter and device driver is not installed on the local computer.");

                        } else if (e == WSAEINPROGRESS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

                        } else if (e == WSAEMFILE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. No more socket descriptors are available.");

                        } else if (e == WSAEINVAL) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. An invalid argument was supplied. This error is returned if the af parameter is set to AF_UNSPEC and the type and protocol parameter are unspecified.");

                        } else if (e == WSAEINVALIDPROVIDER) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The service provider returned a version other than 2.2.");

                        } else if (e == WSAEINVALIDPROCTABLE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The service provider returned an invalid or incomplete procedure table to the WSPStartup.");

                        } else if (e == WSAENOBUFS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. No buffer space is available. The socket cannot be created.");

                        } else if (e == WSAEPROTONOSUPPORT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The specified protocol is not supported.");

                        } else if (e == WSAEPROTOTYPE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The specified protocol is the wrong type for this socket.");

                        } else if (e == WSAEPROVIDERFAILEDINIT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The service provider failed to initialize. This error is returned if a layered service provider (LSP) or namespace provider was improperly installed or the provider fails to operate correctly.");

                        } else if (e == WSAESOCKTNOSUPPORT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The specified socket type is not supported in this address family.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. An unknown error occured.");
                        }

                        // Cast int to DWORD (unsigned int 32-Bit).
                        DWORD d = (DWORD) e;

                        log_windows_system_error((void*) &d);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The socket is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The protocol family is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The communication style is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The protocol is null.");
    }
}

/* CREATE_WINSOCK_STARTER_SOURCE */
#endif
