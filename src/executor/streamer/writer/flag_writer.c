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

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Writes data in synchronous (direct) or asynchronous (indirect) mode.
 *
 * @param p0 the destination device identification item, e.g. file descriptor (a file, serial port, terminal, socket) OR window id OR knowledge tree element (for inline channel)
 * @param p1 the source buffer item
 * @param p2 the source buffer type
 * @param p3 the source part (pointer reference), e.g. a signal
 * @param p4 the source buffer mutex
 * @param p5 the client entry
 * @param p6 the internal memory (needed for signal only)
 * @param p7 the channel
 * @param p8 the output writer handler (pointer reference)
 * @param p9 the asynchronicity flag
 */
void write_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write flag.");
    //?? fwprintf(stdout, L"Debug: Write flag. p0: %i\n", p0);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! Do NOT use "equal" comparison, since synchronous mode has to be the DEFAULT.
    compare_integer_unequal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is SYNCHRONOUS mode.
        //

        // Write directly into device.
        write_loop(p0, p1, p2, p3, p4, p5, p6, p7);

    } else {

        //
        // This is ASYNCHRONOUS mode.
        //

        // Store data in client entry.
        write_entry(p5, p8, p3);

        // Invoke write function within a new thread.
        write_thread(p5);
    }
}
