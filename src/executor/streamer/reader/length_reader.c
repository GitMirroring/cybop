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
 * @version CYBOP 0.27.0 2023-08-31
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
#include "knowledge.h"
#include "logger.h"

//
// Message Boundaries:
//
// TCP is a stream protocol with no message boundaries.
// This means that multiple sends can be received in one recv call,
// or one send can be received in multiple recv calls.
// Therefore, one needs to DELIMIT messages in the stream.
//
// Two common ways of delimiting messages in a stream:
//
// 1 Begin messages with a (fixed-size) header prefix
// 2 End messages with a suffix
//
// https://stackoverflow.com/questions/59269755/missing-one-pixel-row-while-transfering-image-with-tcp-socket/59271376
//

/**
 * Checks the data length to find out if the message is complete,
 * that is if all data belonging to it have been received.
 *
 * @param p0 the complete flag
 * @param p1 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p2 the message item
 * @param p3 the language (protocol)
 */
void read_length(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read length.");
    //?? fwprintf(stdout, L"Debug: Read length. message length p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Read length. message length *p1: %i\n", *((int*) p1));

    // The buffer item data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Get buffer item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    // CAUTION! The buffer data and count HAVE TO be determined here
    // in EACH loop cycle ANEW, since the arrays inside might have
    // got reallocated and changed!
    //
    copy_array_forward((void*) &bd, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bc, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // CAUTION! The length was initialised with -1.
    // Use >= operator and not only > since an otherwise EMPTY message
    // with length 0 might contain a termination suffix such as crlf anyway.
    //
    // CAUTION! The length has to be checked BEFORE comparing the buffer count
    // since otherwise, the buffer count would always be greater than the length.
    // Even the initial buffer count of 0 would be greater than
    // the initial message length of -1.
    //
    compare_integer_greater_or_equal((void*) &r, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The message length was ALREADY DETECTED as prefix
        // within the message in a PREVIOUS loop cycle.
        //

        // Check if expected number of characters has been received.
        read_count(p0, p1, bc);

    } else {

        //
        // The message length was NOT detected as prefix within the message
        // before. Therefore, parse the message and SEARCH for either a
        // PREFIX message length or SUFFIX sequence marking the end of the message.
        //
        // Examples:
        // - prefix: http has a "Content-Length:" header entry
        // - suffix: some binary protocols have a crlf termination
        //

        deserialise_message_length(p1, bd, bc, p3);

        //?? fwprintf(stdout, L"Debug: Read length. post deserialise message length p1: %i\n", p1);
        //?? fwprintf(stdout, L"Debug: Read length. post deserialise message length *p1: %i\n", *((int*) p1));

        //
        // CAUTION! The length was initialised with -1.
        // Use >= operator and not only > since an otherwise EMPTY message
        // with length 0 might contain a termination suffix such as crlf anyway.
        //
        // CAUTION! The length has to be checked BEFORE comparing the buffer count
        // since otherwise, the buffer count would always be greater than the length.
        // Even the initial buffer count of 0 would be greater than
        // the initial message length of -1.
        //
        // CAUTION! Check buffer count a SECOND TIME here (already checked once above)
        // since it may happen that the message fragment just read before contains
        // the message length and is ALREADY COMPLETE, so that a next fragment
        // does NOT have to be read.
        //
        // If the buffer count was not checked here and only in the next loop cycle
        // then the thread would BLOCK due to the next message fragment "read" call
        // (at least if no other separate message is following).
        //
        compare_integer_greater_or_equal((void*) &r, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The message length WAS DETECTED as prefix within the message.
            //

            // Check if expected number of characters has been received.
            read_count(p0, p1, bc);
        }
    }
}
