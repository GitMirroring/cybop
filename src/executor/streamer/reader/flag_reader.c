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

#ifndef FLAG_READER_SOURCE
#define FLAG_READER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/streamer/reader/buffer_reader.c"
#include "../../../executor/streamer/reader/device_reader.c"
#include "logger.h"

/**
 * Reads data via the given channel into the destination.
 *
 * @param p0 the destination item
 * @param p1 the source data (identification e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p2 the source count
 * @param p3 the destination mutex
 * @param p4 the client entry
 * @param p5 the language (protocol)
 * @param p6 the channel
 * @param p7 the asynchronicity flag
 */
void read_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read flag.");
    //?? fwprintf(stdout, L"Debug: Read flag. p0: %i\n", p0);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! Do NOT use "equal" comparison, since synchronous mode has to be the DEFAULT.
    compare_integer_unequal((void*) &r, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is SYNCHRONOUS mode.
        //

        // Read directly from device.
        read_device(p0, p1, p2, p3, p4, p5, p6);

    } else {

        //
        // This is ASYNCHRONOUS mode.
        //

        //
        // Read indirectly from buffer.
        //
        // The data have been read and stored in the buffer
        // in a separate sensing thread before.
        //
        read_buffer(p0, p4, p5, p6);
    }
}

/* FLAG_READER_SOURCE */
#endif
