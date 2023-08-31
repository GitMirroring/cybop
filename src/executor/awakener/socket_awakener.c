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

#include <sys/ioctl.h> // ioctl
#include <errno.h> // errno
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Let the system send an input to itself over socket.
 *
 * @param p0 the input/output entry
 */
void awake_socket(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awake socket.");
    fwprintf(stdout, L"Debug: Awake socket. p0: %i\n", p0);

    //
    //?? TODO: The function "awake" is NOT necessary for client STUB socket on server side
    // since zero is returned automatically by "read" if the connexion has been closed,
    // so that the thread can exit and client entry deallocated.
    //

    // The server socket.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server socket from input/output entry.
    //?? copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

    //
    // For socket handling, there are TWO kinds of threads:
    // - accept: ONE thread for sensing new client requests
    // - read: MANY threads for sensing data on existing client sockets
    //
    // Both kinds of threads have to be exited:
    // - at first the accept thread, so that no new client requests are accepted anymore
    // - afterwards all the single data sensing threads for each existing client socket
    //

    //
    // Step 1: accept
    //
    // Connect to this system's server socket itself,
    // so that this client request can be ACCEPTED by the thread function
    // and the accept thread be exited.
    //
    //?? TODO: connect();
    //?? open_socket(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);

    //
    // Step 2: read
    //
    // Write data to sensing thread of each existing client,
    // so that it can be detected by the SENSING thread function
    // and ALL the sensing threads be exited.
    //
    // If not possible, then sadly use operating system signal SIGUSR1.
    //
    //?? TODO: Loop through client list.

    // Write data to client socket's local read buffer.
    //?? TODO: How to write data NOT to remote client socket but rather to local READ BUFFER?
    //?? ioctl();
}
