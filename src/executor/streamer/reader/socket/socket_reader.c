/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SOCKET_READER_SOURCE
#define SOCKET_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/sensor/socket/socket_sensor.c"
#include "../../../../executor/streamer/reader/socket/buffer_socket_reader.c"
#include "../../../../logger/logger.c"

//
// CAUTION! Considering byte order conversion from/to network byte order
// is NOT necessary here, since the message data already have been
// serialised properly into single characters before.
//

/**
 * Reads data via socket.
 *
 * @param p0 the destination item
 * @param p1 the source socket
 */
void read_socket(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read socket.");

    //
    // The buffer data, count, size.
    //
    // CAUTION! Its size has to be GREATER than zero.
    // Otherwise, there will be no place for the data to be read.
    // A peek into the apacha http server showed values like 512 or 2048.
    // So, the value of 1024 used here is probably acceptable.
    //
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int bs = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;
    //
    // The extended count, size.
    //
    // It is necessary for peeking ahead.
    //
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int es = bs + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Allocate buffer data.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &bd, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Loop until all bytes have been read.
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"TEST: read socket loop ec: %i \n", ec);

        //
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
        // The function "read_socket_buffer" would be
        // called again in order to process the data.
        //
        // 2b No further data
        //
        // If the function "read_socket_buffer" was called again,
        // it WOULD BLOCK processing, since no more data are available.
        //
        // Therefore, the function "sense_socket" is called for PEEKING AHEAD for new data,
        // without actually reading or removing them from the input queue.
        // However, also this function WOULD BLOCK if there were no further data available.
        // This can be avoided if reading at least ONE BYTE MORE than
        // used later in the function "read_socket_buffer".
        //
        // The efficiency disadvantage is that all data are read TWICE,
        // once within "sense" and another time within "read".
        //
        sense_socket((void*) &ec, p1, (void*) &es);

        // Read data into buffer with given size.
        read_socket_buffer(bd, (void*) &bc, (void*) &bs, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        fwprintf(stdout, L"TEST: Read socket. bc: %i\n", bc);

        if (bc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"TEST: Read socket. bc > 0. bc: %i\n", bc);
            fwprintf(stdout, L"TEST: Read socket. bc > 0. bd: %s\n", (char*) bd);

            // Append buffer to destination data.
            modify_item(p0, bd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &bc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        } else {

            fwprintf(stdout, L"TEST: Read socket. break\n");

            break;
        }

/*??
        if (ec > bs) {

            //?? fwprintf(stdout, L"TEST: read socket ec > bs: %i \n", ec);

            // There are further data available on the socket.
            // Therefore, another loop cycle will be entered.

            // Reset extended count.
            ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            //
            // Reset buffer count.
            //
            // CAUTION! It is NOT necessary to reset the buffer data variable.
            // It points to the first element/begin of the data array
            // and elements will get overwritten starting from there.
            //
            bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        } else {

            //?? fwprintf(stdout, L"TEST: read socket ec <= bs: %i \n", ec);

            //
            // The buffer was filled partly or completely
            // and its size was sufficient.
            // However, NO MORE DATA are available.
            // The loop may therefore be left.
            //

            break;
        }
*/
    }

    //
    // Deallocate buffer data.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &bd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* SOCKET_READER_SOURCE */
#endif
