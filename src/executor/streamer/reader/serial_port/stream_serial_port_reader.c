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

#ifndef STREAM_SERIAL_PORT_READER_SOURCE
#define STREAM_SERIAL_PORT_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../executor/streamer/reader/serial_port/read_serial_port_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads data stream from serial port.
 *
 * @param p0 the destination item
 * @param p1 the source file descriptor data
 * @param p2 the minimum number of bytes to be received in one call of the read function
 * @param p3 the maximum number of bytes to be received in one call of the read function
 */
void read_serial_port_stream(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read serial port.");

    // The loop break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The character count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        read_serial_port_read(p0, p1, p2, p3, (void*) &c, (void*) &b);
    }
}

/* STREAM_SERIAL_PORT_READER_SOURCE */
#endif
