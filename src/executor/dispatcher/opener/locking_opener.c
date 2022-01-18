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

#ifndef LOCKING_OPENER_SOURCE
#define LOCKING_OPENER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/locker/locker.c"
#include "../../../executor/locker/unlocker.c"
#include "../../../executor/dispatcher/opener/general_opener.c"
#include "../../../logger/logger.c"

/**
 * Locks client list access.
 *
 * @param p0 the destination client list item
 * @param p1 the client identification (e.g. client socket)
 * @param p2 the client list mutex
 * @param p3 the interrupt pipe (pointer reference)
 * @param p4 the interrupt mutex (pointer reference)
 * @param p5 the input/output identification (pointer reference, input/output base + socket port)
 * @param p6 the language (pointer reference, protocol)
 * @param p7 the channel (pointer reference)
 * @param p8 the serial port file descriptor (pointer reference)
 * @param p9 the terminal file descriptor (pointer reference)
 * @param p10 the xcb connexion (pointer reference)
 * @param p11 the exit flag
 * @param p12 the channel
 */
void open_locking(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open locking.");
    fwprintf(stdout, L"Debug: Open locking. p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Open locking. *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Lock client list mutex.
    //
    // CAUTION! Set this lock BEFORE comparing with the exit flag below
    // since otherwise, a race condition might occur.
    //
    // Example:
    // - the exit flag is not set
    // - the sensing child thread enters the block with r != 0
    // - the main thread receives some shutdown cybol operation
    // - the main thread sets the exit flag only now
    // - the main thread shuts down and deallocates the destination buffer
    // - the sensing child thread decodes characters
    // - the sensing child thread possibly reallocates the (non-existing) destination buffer
    // - this leads to memory errors such as "corrupted double-linked list"
    //
    // The reallocation of a non-existing buffer would lead to the error
    // "realloc(): invalid pointer".
    //
    lock(p2);

    compare_integer_equal((void*) &r, p11, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The exit flag was NOT set in the main thread.
        // Therefore, proceed normally.
        //

        open_general(p0, p1, p3, p4, p5, p6, p7, p8, p9, p10, p12);
    }

    // Unlock client list mutex.
    unlock(p2);
}

/* LOCKING_OPENER_SOURCE */
#endif
