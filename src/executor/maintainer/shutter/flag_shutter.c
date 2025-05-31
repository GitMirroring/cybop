/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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

#include "client.h"
#include "constant.h"
#include "logger.h"
#include "server.h"

/**
 * Executes client close lifecycle OR service shutdown lifecycle, depending on the given identification name.
 *
 * @param p0 the client identification (e.g. file descriptor, socket number, window id) OR port (service identification)
 * @param p1 the client entry (pointer reference) OR server entry (pointer reference)
 * @param p2 the channel
 * @param p3 the list item
 * @param p4 the list index
 * @param p5 the internal memory data
 * @param p6 the server flag
 */
void shutdown_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown flag.");
    //?? fwprintf(stdout, L"Debug: Shutdown flag. identification name p6: %i\n", p6);
    //?? fwprintf(stdout, L"Debug: Shutdown flag. identification name *p6: %i\n", *((int*) p6));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! Do NOT use "equal" comparison, since client has to be the DEFAULT.
    compare_integer_unequal((void*) &r, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a standalone client entry
        // OR
        // a client stub entry of a server's client list.
        //

        // Execute client close lifecycle.
        close_lifecycle(p0, p1, p2, p3, p4);

    } else {

        //
        // This is a server entry.
        //

        // Execute service shutdown lifecycle.
        shutdown_lifecycle(p5, p0, p2, p1, p3, p4);
    }
}
