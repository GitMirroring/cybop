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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Senses input data via endless loop.
 *
 * @param p0 the destination item (client internal input buffer)
 * @param p1 the source device identification (e.g. file descriptor of a file, serial port, client socket, window id)
 * @param p2 the destination mutex (only relevant, if destination is the internal buffer, which is shared with the sensing thread)
 * @param p3 the language (protocol)
 * @param p4 the internal memory
 * @param p5 the channel
 * @param p6 the server flag
 * @param p7 the port
 * @param p8 the asynchronicity flag
 * @param p9 the sense thread exit flag
 */
void sense_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense loop.");
    //?? fwprintf(stdout, L"Debug: Sense loop. language p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Sense loop. language *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The sense thread exit flag was set in the main thread.
            // Therefore, leave this endless loop now.
            // This child thread gets exited when this
            // and its calling functions return.
            //

            break;
        }

        read_data(p0, p1, *NULL_POINTER_STATE_CYBOI_MODEL, p2, p3, p4, p5, p6, p7, p8);

        //
        // CAUTION! Do NOT call function "read_deallocation" here.
        //
        // This is currently ONLY relevant for channel DISPLAY where
        // the x window system (accessed via xcb api) allocates events
        // that have to get deallocated by CYBOI after having been processed.
        //
        // However, the event does NOT have to get destroyed here,
        // since it gets copied and stored in the input BUFFER of
        // the client entry by the sense thread, in order to be
        // processed LATER by the main thread.
        //
    }
}
