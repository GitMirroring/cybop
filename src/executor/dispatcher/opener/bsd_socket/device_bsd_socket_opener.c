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

#ifndef DEVICE_BSD_SOCKET_OPENER_SOURCE
#define DEVICE_BSD_SOCKET_OPENER_SOURCE

#include <sys/socket.h> // socket
#include <errno.h> // errno

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/configurator/initialiser/bsd_socket/bsd_socket_initialiser.c"
#include "../../../../executor/copier/integer_copier.c"
#include "logger.h"

/**
 * Open bsd socket device.
 *
 * The socket is blocking by default.
 * There is no need to assign an option for this.
 *
 * @param p0 the socket
 * @param p1 the protocol family (socket namespace)
 * @param p2 the communication style
 * @param p3 the protocol
 */
void open_bsd_socket_device(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* pr = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* st = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* pf = (int*) p1;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open bsd socket device.");
                //?? fwprintf(stdout, L"Debug: Open bsd socket device p0: %i\n", p0);
                //?? fwprintf(stdout, L"Debug: Open bsd socket device *p0: %i\n", *((int*) p0));
                //?? fwprintf(stdout, L"Debug: Open bsd socket device *pf: %i\n", *pf);
                //?? fwprintf(stdout, L"Debug: Open bsd socket device *st: %i\n", *st);
                //?? fwprintf(stdout, L"Debug: Open bsd socket device *pr: %i\n", *pr);

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
                // Create socket.
                //
                // param 0: protocol family (namespace)
                // param 1: communication style
                // param 2: protocol (zero is usually right, following the glibc manual)
                //
                // CAUTION! Use prefix "PF_" here and NOT "AF_"!
                // The latter is to be used for address family assignment.
                // See further below!
                //
                // CAUTION! When using the protocol "tcp" and an ipv4 stream socket,
                // then everything just works fine. However, for some unknown reason,
                // the protocol "udp" does NOT work with a local datagram udp socket.
                // *s = socket(*pf, *st, *pr);
                // In order to avoid problems, the third parametre is set to ZERO here.
                // This decision follows the recommendation of the glibc documentation:
                // "zero is usually right for protocol".
                // *s = socket(PF_LOCAL, SOCK_DGRAM, 0);
                //
                int r = socket(*pf, *st, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open bsd socket device. Success.");
                    //?? fwprintf(stdout, L"Debug: Open bsd socket device. Success. r: %i\n", r);

                    // Configure socket.
                    initialise_bsd_socket((void*) &r);

                    // Copy socket file descriptor to destination socket.
                    copy_integer(p0, (void*) &r);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket device. An error occured.");
                    fwprintf(stdout, L"Error: Could not open bsd socket device. An error occured. %i\n", r);
                    log_error((void*) &errno);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket device. The protocol family is null.");
                fwprintf(stdout, L"Error: Could not open bsd socket device. The protocol family is null. p1: %i\n", p1);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket device. The communication style is null.");
            fwprintf(stdout, L"Error: Could not open bsd socket device. The communication style is null. p2: %i\n", p2);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open bsd socket device. The protocol is null.");
        fwprintf(stdout, L"Error: Could not open bsd socket device. The protocol is null. p3: %i\n", p3);
    }
}

/* DEVICE_BSD_SOCKET_OPENER_SOURCE */
#endif
