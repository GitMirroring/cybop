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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LISTEN_BSD_SOCKET_STARTER_SOURCE
#define LISTEN_BSD_SOCKET_STARTER_SOURCE

//
// System interface
//

#include <sys/socket.h> // listen
#include <errno.h> // errno
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Enable socket to accept connexions, thus making it a server socket.
 *
 * @param p0 the socket
 * @param p1 the connexions (number of possible pending client requests)
 */
void startup_bsd_socket_listen(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* c = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* s = (int*) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket listen.");

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

            //
            // Enable socket to accept connexions, thus making it a server socket.
            // The second parametre determines the number of possible
            // pending client connexion requests.
            //
            int r = listen(*s, *c);

            if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket listen. Success!");
                //?? fwprintf(stdout, L"Debug: Startup bsd socket listen. Success! *s: %i\n", *s);
                //?? fwprintf(stdout, L"Debug: Startup bsd socket listen. Success! *c: %i\n", *c);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket listen. An error occured.");
                fwprintf(stdout, L"Error: Could not startup bsd socket listen. An error occured. %i\n", r);
                log_error((void*) &errno);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket listen. The socket is null.");
            fwprintf(stdout, L"Error: Could not startup bsd socket listen. The socket is null. p0: %i\n", p0);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket listen. The connexions is null.");
        fwprintf(stdout, L"Error: Could not startup bsd socket listen. The connexions is null. p1: %i\n", p1);
    }
}

/* LISTEN_BSD_SOCKET_STARTER_SOURCE */
#endif
