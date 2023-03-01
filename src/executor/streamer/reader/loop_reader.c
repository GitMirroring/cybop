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

#ifndef LOOP_READER_SOURCE
#define LOOP_READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/streamer/reader/message_reader.c"
#include "../../../logger/logger.c"

/**
 * Reads data via an endless loop.
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
 */
void read_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read loop.");
    //?? fwprintf(stdout, L"Debug: Read loop. p0: %i\n", p0);

    // The loop break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If data are read in synchronous mode,
        // then there is NO thread and the thread exit flag NULL.
        // However, a null value is just IGNORED inside this
        // comparison and leaves the resulting break flag untouched.
        //
        compare_integer_unequal((void*) &b, p10, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The break flag has been set.
            //
            // This can happen in two ways:
            // - synchronous mode: directly
            // - asynchronous mode: via thread exit flag (see comparison above)
            //

            break;
        }

        read_message(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, (void*) &b);
    }
}

/* LOOP_READER_SOURCE */
#endif
