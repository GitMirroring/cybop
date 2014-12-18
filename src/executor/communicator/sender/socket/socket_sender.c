/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_SENDER_SOURCE
#define SOCKET_SENDER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Sends a message via socket.
 *
 * @param p11 the message type
 * @param p12 the message type count
 * @param p13 the message model
 * @param p14 the message model count
 * @param p15 the message properties
 * @param p16 the message properties count
 * @param p17 the knowledge memory
 * @param p18 the knowledge memory count
 * @param p19 the language
 * @param p20 the language count
 */
void send_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send socket.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The data index to start the transfer at.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The number of bytes transferred.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise data index to start the transfer at.
    copy_pointer((void*) &i, (void*) &p1);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    // CAUTION! The send operation does not necessarily
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

        compare_integer_smaller_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        send_socket_buffer(p0, i, p2, (void*) &n);

        // Increment byte array index.
        calculate_pointer_add((void*) &i, (void*) &n);
        // Decrement byte array count.
        calculate_integer_subtract(p2, (void*) &n);
    }
}

/* SOCKET_SENDER_SOURCE */
#endif
