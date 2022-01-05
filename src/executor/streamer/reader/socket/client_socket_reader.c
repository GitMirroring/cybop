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

#ifndef CLIENT_SOCKET_READER_SOURCE
#define CLIENT_SOCKET_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../executor/streamer/reader/socket/message_client_socket_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads as client from server socket.
 *
 * @param p0 the destination item to store message data in
 * @param p1 the source server socket number to read from
 * @param p2 the language (protocol)
 */
void read_socket_client(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read socket client.");
    fwprintf(stdout, L"Debug: Read socket client. p1: %i\n", p1);

    //
    // The local character buffer data, count.
    //
    // CAUTION! Do NOT declare these variables inside
    // the called function, for two reasons:
    //
    // 1 It is more EFFICIENT not to have to reserve
    //   the buffer on stack with each loop cycle.
    //
    // 2 The buffer does NOT have to be emptied, since only
    //   the number of data received is processed further.
    //
    // Purpose of this local buffer:
    //
    // Received data are to be stored in the buffer item.
    // However, this buffer item CANNOT be used directly
    // for reading data, since read calls are BLOCKING.
    // Since the main thread needs to have access to
    // the buffer as well, a mutex has to be used.
    //
    // It could thus happen that the mutex is set,
    // in order to protect access to the buffer item,
    // while the sensing child thread waits for input.
    // In this case, the main thread would be blocked
    // while waiting for the mutex to be reset.
    //
    // Therefore, this additional LOCAL BUFFER needs to be used
    // for reading data in a blocking manner. The data received
    // are then copied to the actual destination buffer item,
    // whilst the mutex is set only for a short time.
    //
    // One more argument for this local buffer:
    //
    // The characters received have to be converted to wide characters,
    // so that this additional local buffer is needed anyway.
    //
    // Size of this local buffer:
    //
    // 1 It has to be GREATER than zero, so that there is place
    //   for the data to be read.
    //
    // 2 A peek into the APACHE http server showed values like 512 or 2048.
    //   So, the value of 1024 used here is probably acceptable.
    //
    char cd[*NUMBER_1024_INTEGER_STATE_CYBOI_MODEL];
    int cc = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;
    //
    // The message length.
    //
    // CAUTION! It serves just as a value-holder across many loop cycles,
    // so that a "message length" header found in the data
    // (e.g. "Content-Length: " in http) can be compared with
    // the actual number of bytes that have been read, in each loop cycle.
    //
    // Since it gets compared inside, it should be initialised
    // with a value < 0, e.g. with -1.
    //
    int ml = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"Debug: Read socket client. cc: %i\n", cc);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        read_socket_client_message(p0, p1, cd, (void*) &cc, p2, (void*) &ml, (void*) &b);
    }
}

/* CLIENT_SOCKET_READER_SOURCE */
#endif
