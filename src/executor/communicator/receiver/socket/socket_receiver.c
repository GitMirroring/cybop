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

#ifndef SOCKET_RECEIVER_SOURCE
#define SOCKET_RECEIVER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/communicator/receiver/socket/buffer_socket_receiver.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/representer/deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Receives message via socket.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source socket
 * @param p3 the knowledge memory part
 * @param p4 the format
 * @param p5 the language
 */
void receive_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive socket.");

    // The buffer data, count, size.
    // CAUTION! Its size has to be GREATER than zero.
    // Otherwise, there will be no place for the data to be received.
    // A peek into the apacha http server showed values like 512 or 2048.
    // So, the value of 1024 used here is probably acceptable.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int bs = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;
    // The serialised character item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised character item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate buffer data.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &bd, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate serialised character item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Loop until all bytes have been received.
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Receive data until buffer is filled.
        receive_socket_buffer(bd, (void*) &bc, (void*) &bs, socket);

        if (bc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Append buffer to destination data.
            append_item_element(s, bd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &bc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        } else {

            // No more data have been received.
            break;
        }
    }

    // Get serialised character item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Deserialise serialised character array into destination item.
    //
    // CAUTION! Any meta data like an http request's headers
    // are written into the destination item as well.
    deserialise(p0, p1, sd, sc, p3, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p4, p5);

    // Deallocate buffer data.
    deallocate_array((void*) &bd, (void*) &bc, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate serialised character item.
    deallocate_item((void*) &s, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* SOCKET_RECEIVER_SOURCE */
#endif
