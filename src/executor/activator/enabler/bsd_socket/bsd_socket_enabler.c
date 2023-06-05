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

//
// System interface
//

#include <sys/socket.h> // accept
#include <errno.h> // errno
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Accepts client request on the given bsd socket.
 *
 * @param p0 the destination sender client socket
 * @param p1 the source receiver server socket
 */
void enable_bsd_socket(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable bsd socket.");
        //?? fwprintf(stdout, L"Debug: Enable bsd socket p1: %i\n", p1);
        //?? fwprintf(stdout, L"Debug: Enable bsd socket *p1: %i\n", *((int*) p1));

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
        // Accept request and store client socket.
        //
        // Accepting a connexion does NOT make the original server socket
        // part of the connexion. Instead, it creates a new client socket
        // which becomes connected. The normal return value of
        // "accept" is the file descriptor for the new client socket.
        //
        // After "accept", the original server socket remains open and
        // unconnected, and continues listening until it gets closed.
        // One can accept further connexions with the original
        // server socket by calling "accept" again.
        //
        // CAUTION! If addr (second argument) and/or addrlen (third argument)
        // are equal to NULL, then no information about the remote address
        // of the accepted client socket is returned.
        //
        // Therefore, the following source code is NOT necessary:
        //     struct sockaddr_in ad;
        //     socklen_t as = sizeof(ad);
        //     *c = accept(*s, (struct sockaddr*) &ad, &as);
        //
        int c = accept(*s, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        if (c >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable bsd socket. success");
            //?? fwprintf(stdout, L"Debug: Enable bsd socket. success. client socket c: %i\n", c);

            // Copy client socket to destination.
            copy_integer(p0, (void*) &c);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable bsd socket. An error occured.");
            fwprintf(stdout, L"Error: Could not enable bsd socket. An error occured. c: %i\n", c);
            log_error((void*) &errno);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable bsd socket. The receiver server socket is null.");
        fwprintf(stdout, L"Error: Could not enable bsd socket. The receiver server socket is null. p1: %i\n", p1);
    }
}
