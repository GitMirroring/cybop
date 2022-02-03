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

#ifndef BSD_SOCKET_OPENER_SOURCE
#define BSD_SOCKET_OPENER_SOURCE

#include <sys/socket.h> // connect
#include <errno.h> // errno

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Connects with a server via bsd socket.
 *
 * @param p0 the socket
 * @param p1 the address data
 * @param p2 the address size
 */
void open_bsd_socket(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open bsd socket.");
                fwprintf(stdout, L"Debug: Open bsd socket. s: %i\n", s);
                fwprintf(stdout, L"Debug: Open bsd socket. *s: %i\n", *s);

                // Cast address size to correct type.
                socklen_t sl = (socklen_t) *as;

                //
                // Initialise error number.
                //
                // It is a global variable and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                //
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                //?? fwprintf(stdout, L"Debug: Open bsd socket. *as: %i\n", *as);
                //?? fwprintf(stdout, L"Debug: Open bsd socket. ad: %i\n", ad);
                //?? fwprintf(stdout, L"Debug: Open bsd socket. *s: %i\n", *s);

                //
                // Make connexion with server.
                //
                // This function call waits until the server responds
                // to the request before it returns.
                //
                int r = connect(*s, ad, sl);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open bsd socket. success");
                    fwprintf(stdout, L"Debug: Open bsd socket. success r: %i\n", r);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. An error occured.");
                    fwprintf(stdout, L"Error: Could not open bsd socket. An error occured. %i\n", r);
                    log_errno((void*) &errno);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The socket is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket. The address size is null.");
    }
}

/* BSD_SOCKET_OPENER_SOURCE */
#endif
