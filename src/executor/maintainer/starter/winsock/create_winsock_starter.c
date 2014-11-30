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

#ifndef CREATE_WINSOCK_STARTER_SOURCE
#define CREATE_WINSOCK_STARTER_SOURCE

#include <winsock.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/maintainer/starter/winsock/bind_winsock_starter.c"
#include "../../../../executor/maintainer/starter/winsock/listen_winsock_starter.c"
#include "../../../../executor/maintainer/starter/winsock/socket_address_winsock_starter.c"
#include "../../../../logger/logger.c"

/**
 * Create winsock.
 *
 * @param p0 the socket
 * @param p1 the protocol family (socket namespace)
 * @param p2 the communication style
 * @param p3 the protocol
 */
void startup_winsock_create(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* pr = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* st = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* pf = (int*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* s = (int*) p0;

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup winsock create.");

                    // Initialise server socket.
                    //
                    // param 0: protocol family (namespace)
                    // param 1: communication style
                    // param 2: protocol (zero is usually right)
                    //
                    // CAUTION! Use prefix "PF_" here and NOT "AF_"!
                    // The latter is to be used for address family assignment.
                    // See further below!
                    SOCKET ws = socket(*pf, *st, *pr);

                    // Assign winsock to destination socket.
                    *s = ws;

                    if (*s < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // Get the calling thread's last-error code.
                        DWORD e = WSAGetLastError();

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup winsock create. The socket creation failed.");
                        log_windows_system_error((void*) &e);

                        MessageBox(*NULL_POINTER_STATE_CYBOI_MODEL, "Socket Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
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
