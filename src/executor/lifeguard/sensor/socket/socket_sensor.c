/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_SENSOR_SOURCE
#define SOCKET_SENSOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../executor/streamer/reader/socket/buffer_socket_reader.c"
#include "../../../../logger/logger.c"

/**
 * Senses data available on the given server socket.
 *
 * @param p0 the destination buffer count
 * @param p1 the source socket
 * @param p2 the source buffer size
 */
void sense_socket(void* p0, void* p1, void* p2) {

    // CAUTION! DO NOT log this function call!
    // The function runs in an endless loop
    // that would produce huge log files.
    // log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket.");

//?? fwprintf(stdout, L"TEST: sense socket *p1: %i \n", *((int*) p1));

    // The buffer data, count, size.
    // CAUTION! Its size has to be GREATER than zero.
    // Otherwise, there will be no place for the data to be received.
    // A peek into the apache http server showed values like 512 or 2048.
    // So, the value of 1024 used here is probably acceptable.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int bs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise buffer size.
    copy_integer((void*) &bs, p2);

    // Allocate buffer data.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &bd, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // The socket options.
    // CAUTION! Look at the data but do NOT remove it from the input queue.
    int o = MSG_PEEK;

//?? fwprintf(stdout, L"TEST sense socket bs: %i\n", bs);

    // Read data until buffer is filled.
    read_socket_buffer(bd, (void*) &bc, (void*) &bs, p1, (void*) &o);

    if (bc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST: sense socket success bc: %i \n", bc);

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket success.");

        // Copy destination buffer count.
        copy_integer(p0, (void*) &bc);
    }

    // Deallocate buffer data.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &bd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* SOCKET_SENSOR_SOURCE */
#endif
