/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_WRITER_SOURCE
#define SOCKET_WRITER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/calculator/basic/integer/subtract_integer_calculator.c"
#include "../../../../executor/calculator/basic/pointer/add_pointer_calculator.c"
#include "../../../../executor/streamer/writer/socket/buffer_socket_writer.c"
#include "../../../../executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

//
// CAUTION! Considering byte order conversion from/to network byte order
// is NOT necessary here, since the message data already have been
// serialised properly into single characters before.
//

/**
 * Writes a message via socket.
 *
 * @param p0 the destination socket
 * @param p1 the source data (pointer reference)
 * @param p2 the source count
 */
void write_socket(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write socket.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The data position and count remaining to start the transfer at.
    void* pos = *NULL_POINTER_STATE_CYBOI_MODEL;
    int rem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The number of bytes transferred.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise data position and count remaining to start the transfer at.
    // CAUTION! Testing the parametre for null is NOT necessary since the
    // copy function does not change its result if the source is null.
    copy_pointer((void*) &pos, p1);
    copy_integer((void*) &rem, p2);

    // CAUTION! The write operation does not necessarily
    // handle all the bytes handed over to it, because
    // its major focus is handling the network buffers.
    // In general, it returns when the associated
    // network buffers have been filled.
    // It then returns the number of handled bytes.
    //
    // The "send" operation therefore has to be
    // CALLED AGAIN AND AGAIN, in a loop, until
    // the complete message has been transmitted!
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, (void*) &rem, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        write_socket_buffer(p0, pos, (void*) &rem, (void*) &n);

        if (n <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // CAUTION! This test IS NECESSARY in order
            // to avoid an endless loop if no data could be
            // transmitted, for whatever reason.
            break;
        }

        // Increment byte array index.
        calculate_pointer_add((void*) &pos, (void*) &n);
        // Decrement byte array count.
        calculate_integer_subtract((void*) &rem, (void*) &n);
        // Reset number of bytes transferred.
        copy_integer((void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* SOCKET_WRITER_SOURCE */
#endif
