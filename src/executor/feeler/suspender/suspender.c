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

#ifndef SUSPENDER_SOURCE
#define SUSPENDER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/feeler/suspender/thread_suspender.c"
#include "../../../executor/finder/entry_finder.c"
#include "../../../logger/logger.c"

/**
 * Suspends the data input sensing on the given channel.
 *
 * @param p0 the internal memory
 * @param p1 the channel
 * @param p2 the server flag
 * @param p3 the port
 * @param p4 the client identification (e.g. file descriptor, socket number, window id)
 */
void suspend(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Suspend.");
    //?? fwprintf(stdout, L"Information: Suspend. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Information: Suspend. *p2: %i\n", *((int*) p2));

    //
    // Declaration
    //

    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get client entry belonging to given source device.
    find_entry((void*) &ce, p0, p1, p2, p3, p4);

    if (ce != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Suspend client by exiting enable thread.
        suspend_thread(ce);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not suspend. A client entry with the given identification does not exist.");
        fwprintf(stdout, L"Warning: Could not suspend. A client entry with the given identification does not exist. p4: %i\n", p4);
        fwprintf(stdout, L"Warning: Could not suspend. A client entry with the given identification does not exist. *p4: %i\n", *((int*) p4));
    }
}

/* SUSPENDER_SOURCE */
#endif
