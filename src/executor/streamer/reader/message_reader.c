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

#ifndef MESSAGE_READER_SOURCE
#define MESSAGE_READER_SOURCE

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
 * Reads a message in certain steps.
 *
 * @param p0 the destination item
 * @param p1 the source data (identification e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p2 the source count
 * @param p3 the message fragment data
 * @param p4 the message fragment size
 * @param p5 the destination mutex
 * @param p6 the interrupt pipe write file descriptor
 * @param p7 the interrupt mutex
 * @param p8 the handler (pointer reference)
 * @param p9 the closer (pointer reference)
 * @param p10 the thread exit flag
 * @param p11 the language (protocol)
 * @param p12 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p13 the channel
 * @param p14 the loop break flag
 */
void read_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read message.");
    //?? fwprintf(stdout, L"Debug: Read message. p13: %i\n", p13);
    //?? fwprintf(stdout, L"Debug: Read message. *p13: %i\n", *((int*) p13));

    // The eof-or-close flag.
    int ec = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The complete flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Receive next message fragment.
    read_fragment(p0, p1, p2, p3, p4, p5, (void*) &ec, p13);

    // Check for completeness by evaluating length prefix or end suffix.
    read_completeness((void*) &f, p12, p0, p11, (void*) &ec, p13);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The message is complete, that is all data
        // belonging to it have been received.
        //

        // Inform system about completion of the read process.
        read_completion(p14, p6, p7, p8, p9, p1, p10, p12, (void*) &ec);
    }
}

/* MESSAGE_READER_SOURCE */
#endif
