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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WINSOCK_CLOSER_SOURCE
#define WINSOCK_CLOSER_SOURCE

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
void close_winsock(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close winsock.");

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

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully closed winsock.");

        } else {

            //
            // Get the calling thread's last-error code.
            //
            // CAUTION! This function is the winsock substitute
            // for the Windows "GetLastError" function.
            //
            int e = WSAGetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close winsock. An error occured.");
            fwprintf(stdout, L"Error: Could not close winsock. An error occured. %i\n", r);
            log_errno((void*) &e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close winsock. The socket is null.");
    }
}

/* WINSOCK_CLOSER_SOURCE */
#endif
