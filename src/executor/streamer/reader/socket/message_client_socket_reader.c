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

#ifndef MESSAGE_CLIENT_SOCKET_READER_SOURCE
#define MESSAGE_CLIENT_SOCKET_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../executor/sensor/socket/completeness_socket_sensor.c"
#include "../../../../executor/streamer/reader/socket/fragment_client_socket_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads client socket message.
 *
 * @param p0 the destination item to store message data in
 * @param p1 the source server socket to read from
 * @param p2 the local character buffer data
 * @param p3 the local character buffer count
 * @param p4 the language (protocol)
 * @param p5 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p6 the break flag
 */
void read_socket_client_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read socket client message.");
    fwprintf(stdout, L"Debug: Read socket client message. p5: %i\n", p5);
    fwprintf(stdout, L"Debug: Read socket client message. *p5: %i\n", *((int*) p5));

    // Receive next message fragment.
    read_socket_client_fragment(p0, p1, p2, p3);

    // Check for length prefix and end suffix.
    sense_socket_completeness(p6, p5, p0, p4);
}

/* MESSAGE_CLIENT_SOCKET_READER_SOURCE */
#endif
