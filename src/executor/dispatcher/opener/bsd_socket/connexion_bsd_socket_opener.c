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

#ifndef CONNEXION_BSD_SOCKET_OPENER_SOURCE
#define CONNEXION_BSD_SOCKET_OPENER_SOURCE

#include <sys/socket.h> // connect
#include <errno.h> // errno

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "logger.h"

/**
 * Connects the bsd socket to the server given by the address.
 *
 * @param p0 the socket
 * @param p1 the server address data
 * @param p2 the server address size
 */
void open_bsd_socket_connexion(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open bsd socket connexion.");
                //?? fwprintf(stdout, L"Debug: Open bsd socket connexion. s: %i\n", s);
                //?? fwprintf(stdout, L"Debug: Open bsd socket connexion. *s: %i\n", *s);

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

                //
                // Make connexion with server.
                //
                // CAUTION! This function call waits until the server
                // responds to the request before it returns.
                //
                int r = connect(*s, ad, sl);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open bsd socket connexion. success");
                    //?? fwprintf(stdout, L"Debug: Open bsd socket connexion. success r: %i\n", r);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket connexion. An error occured.");
                    fwprintf(stdout, L"Error: Could not open bsd socket connexion. An error occured. %i\n", r);
                    log_error((void*) &errno);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket connexion. The socket is null.");
                fwprintf(stdout, L"Error: Could not open bsd socket connexion. The socket is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket connexion. The address data is null.");
            fwprintf(stdout, L"Error: Could not open bsd socket connexion. The address data is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket connexion. The address size is null.");
        fwprintf(stdout, L"Error: Could not open bsd socket connexion. The address size is null. p2: %i\n", p2);
    }
}

/* CONNEXION_BSD_SOCKET_OPENER_SOURCE */
#endif
