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

#ifndef MESSAGE_SOCKET_RECEIVER_SOURCE
#define MESSAGE_SOCKET_RECEIVER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/communicator/receiver/socket/buffer_socket_receiver.c"
#include "../../../../executor/lifeguard/sensor/socket/socket_sensor.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../logger/logger.c"

/**
 * Receives message via socket.
 *
 * @param p0 the destination item
 * @param p1 the source socket
 */
void receive_socket_message(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive socket message.");

    // The buffer data, count, size.
    // CAUTION! Its size has to be GREATER than zero.
    // Otherwise, there will be no place for the data to be received.
    // A peek into the apacha http server showed values like 512 or 2048.
    // So, the value of 1024 used here is probably acceptable.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int bs = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;
    // The extended count, size.
    // It is necessary for peeking ahead.
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int es = bs + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Allocate buffer data.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &bd, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Loop until all bytes have been received.
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST: receive socket message loop ec: %i \n", ec);

        // Sense further data available on socket.
        //
        // CAUTION! This function call IS NECESSARY in order
        // to avoid an endless loop in some rare cases.
        // There are two possible cases:
        //
        // 1 bc < bs
        //
        // The buffer was filled PARTLY and the loop may be left.
        //
        // 2 bc == bs (bc > bs is not possible)
        //
        // The buffer was filled COMPLETELY.
        // However, it is UNCLEAR, whether or not further data are available.
        //
        // 2a Further data available
        //
        // The function "receive_socket_buffer" would be
        // called again in order to process the data.
        //
        // 2b No further data
        //
        // If the function "receive_socket_buffer" was called again,
        // it WOULD BLOCK processing, since no more data are available.
        //
        // Therefore, the function "sense_socket" is called for PEEKING AHEAD for new data,
        // without actually reading or removing them from the input queue.
        // However, also this function WOULD BLOCK if there were no further data available.
        // This can be avoided if reading at least ONE BYTE MORE than
        // used later in the function "receive_socket_buffer".
        //
        // The efficiency disadvantage is that all data are read TWICE,
        // once within "sense" and another time within "receive".
        //
        sense_socket((void*) &ec, p1, (void*) &es);

        // Receive data into buffer with given size.
        receive_socket_buffer(bd, (void*) &bc, (void*) &bs, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

fwprintf(stdout, L"TEST: receive socket message result bc: %i \n", bc);

        if (bc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST: receive socket message bc > 0: %i \n", bc);

            // Append buffer to destination data.
            append_item_element(p0, bd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &bc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }

        if (ec > bs) {

fwprintf(stdout, L"TEST: receive socket message ec > bs: %i \n", ec);

            // There are further data available on the socket.
            // Therefore, another loop cycle will be entered.

            // Reset extended count.
            ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Reset buffer count.
            // CAUTION! It is NOT necessary to reset the buffer data variable.
            // It points to the first element/begin of the data array
            // and elements will get overwritten starting from there.
            bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        } else {

fwprintf(stdout, L"TEST: receive socket message ec <= bs: %i \n", ec);

            // The buffer completely or not, which is not relevant.
            // However, its size was sufficient.
            // No more data are available.
            // The loop may be left.

            // Exit loop, since no more data are to be received.
            break;
        }
    }

    // Deallocate buffer data.
    deallocate_array((void*) &bd, (void*) &bc, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* MESSAGE_SOCKET_RECEIVER_SOURCE */
#endif
