/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MESSAGE_READER_SOURCE
#define MESSAGE_READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/streamer/reader/completeness_reader.c"
#include "../../../executor/streamer/reader/completion_reader.c"
#include "../../../executor/streamer/reader/fragment_reader.c"
#include "../../../logger/logger.c"

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
 * @param p7 the interrupt handlers item
 * @param p8 the interrupt mutex
 * @param p9 the handler (pointer reference)
 * @param p10 the closer (pointer reference)
 * @param p11 the thread exit flag
 * @param p12 the language (protocol)
 * @param p13 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p14 the channel
 * @param p15 the loop break flag
 */
void read_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read message.");
    fwprintf(stdout, L"Debug: Read message. p14: %i\n", p14);
    fwprintf(stdout, L"Debug: Read message. *p14: %i\n", *((int*) p14));

    // The eof-or-close flag.
    int ec = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The complete flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Receive next message fragment.
    read_fragment(p0, p1, p2, p3, p4, p5, (void*) &ec, p14);

    // Check for completeness by evaluating length prefix or end suffix.
    read_completeness((void*) &f, p13, p0, p12, (void*) &ec, p14);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The message is complete, that is all data
        // belonging to it have been received.
        //

        //
        // CAUTION! The complete flag does NOT have to be reset here,
        // since it is a local variable on stack and gets freed
        // automatically when this function is left now.
        //

        // Inform system about completion of the read process.
        read_completion(p15, p6, p7, p8, p9, p10, p11, p13, (void*) &ec);
    }
}

/* MESSAGE_READER_SOURCE */
#endif
