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

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "algorithm.h"
#include "client.h"
#include "constant.h"
#include "logger.h"

/**
 * Closes the client with the given identification on the given channel.
 *
 * CAUTION! Do NOT rename this function to "close",
 * as that name is already used by low-level functionality:
 * /usr/include/unistd.h:353:12
 * extern int close (int __fd);
 *
 * @param p0 the client identification (e.g. file descriptor, socket number, window id)
 * @param p1 the port
 * @param p2 the channel
 * @param p3 the server flag
 * @param p4 the internal memory
 */
void close_client(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close client.");
    //?? fwprintf(stdout, L"Information: Close client. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Information: Close client. *p0: %i\n", *((int*) p0));

    //
    // Declaration
    //

    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list item.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list index.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get client entry belonging to given source device.
    find_entry((void*) &ce, p4, p2, p3, p1, p0);
    // Get input output entry from client entry.
    copy_array_forward((void*) &io, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_OUTPUT_BACKLINK_CLIENT_STATE_CYBOI_NAME);
    // Get suitable client list item.
    find_mode((void*) &cl, io, p3, p1);
    // Get client list index within client list by client device identification.
    find_list_index((void*) &i, cl, p0, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);

    // Execute client close lifecycle.
    close_lifecycle(p0, (void*) &ce, p2, cl, (void*) &i);
}
