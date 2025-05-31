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

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Writes source to destination.
 *
 * @param p0 the destination device identification item, e.g. file descriptor (a file, serial port, terminal, socket) OR window id OR knowledge tree element (for inline channel)
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source part (pointer reference), e.g. a signal
 * @param p4 the internal memory
 * @param p5 the channel
 * @param p6 the server flag
 * @param p7 the port
 * @param p8 the output writer handler (pointer reference)
 * @param p9 the asynchronicity flag
 */
void send_write(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    // Filter out null value for better performance.
    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send write.");
        //?? fwprintf(stdout, L"Debug: Send write. channel p5: %i\n", p5);
        //?? fwprintf(stdout, L"Debug: Send write. channel *p5: %i\n", *((int*) p5));

        // Write message.
        write_data(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serialise. The channel is null.");
        fwprintf(stdout, L"Warning: Could not send write. The channel is null. channel p5: %i\n", p5);
        fwprintf(stdout, L"Warning: Could not send write. The channel is null. channel *p5: %i\n", *((int*) p5));
    }
}
