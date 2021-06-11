/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SOCKET_SENSOR_SOURCE
#define SOCKET_SENSOR_SOURCE

#include <sys/ioctl.h> // FIONREAD

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../executor/streamer/reader/device/device_reader.c"
#include "../../../logger/logger.c"

/**
 * Senses data available on the given server socket.
 *
 * @param p0 the data available flag
 * @param p1 the source socket
 */
void sense_socket(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket.");

    //?? fwprintf(stdout, L"Test: Sense socket. *p1: %i\n", *((int*) p1));

    // The number of data available on socket.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The command (device-dependent request code).
    int c = FIONREAD;

    // Read the number of data available on socket.
    read_device((void*) &n, p1, (void*) &c);

    if (n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket successful.");
        //?? fwprintf(stdout, L"Test: Sense socket successful. n: %i\n", n);

        // Set data available flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

/*?? DELETE later, since deprecated!

    //
    // The buffer data, count, size.
    //
    // CAUTION! Its size has to be GREATER than zero since otherwise,
    // there will be no place for the data to be received.
    // For peeking ahead, a size of just ONE is sufficient to detect data.
    //
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int bs = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Initialise buffer size.
    //?? copy_integer((void*) &bs, p2);

    //
    // Allocate buffer data.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &bd, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // The socket options.
    //
    // CAUTION! Look at the data but do NOT
    // remove it from the input queue.
    //
    int o = MSG_PEEK;

    //?? fwprintf(stdout, L"TEST sense socket bs: %i\n", bs);

    // Read data until buffer is filled.
    read_socket_buffer(bd, (void*) &bc, (void*) &bs, p1, (void*) &o);

    //?? fwprintf(stdout, L"TEST sense socket bc: %i\n", bc);

    if (bc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket success.");
        //?? fwprintf(stdout, L"Test: sense socket success bc: %i\n", bc);

        // Copy destination buffer count.
        copy_integer(p0, (void*) &bc);
    }

    //
    // Deallocate buffer data.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &bd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &bs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
*/
}

/* SOCKET_SENSOR_SOURCE */
#endif
