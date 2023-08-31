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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <sys/socket.h> // bind
#include <errno.h> // errno
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Binds the address to the bsd socket.
 *
 * @param p0 the socket
 * @param p1 the address data
 * @param p2 the address size
 */
void startup_bsd_socket_bind(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr* ad = (struct sockaddr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket bind.");

                // The address size casted to the correct type.
                socklen_t ast = (socklen_t) *as;

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

                int r = bind(*s, ad, ast);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket bind. Success!");
                    //?? fwprintf(stdout, L"Debug: Startup bsd socket bind. r: %i\n", r);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. An error occured.");
                    fwprintf(stdout, L"Error: Could not startup bsd socket bind. An error occured. %i\n", r);
                    log_error((void*) &errno);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The socket is null.");
                fwprintf(stdout, L"Error: Could not startup bsd socket bind. The socket is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The address data is null.");
            fwprintf(stdout, L"Error: Could not startup bsd socket bind. The address data is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The address size is null.");
        fwprintf(stdout, L"Error: Could not startup bsd socket bind. The address size is null. p2: %i\n", p2);
    }
}
