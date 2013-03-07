/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SERIAL_PORT_SENDER_SOURCE
#define FILE_SERIAL_PORT_SENDER_SOURCE

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/sender/serial_port/stream_serial_port_sender.c"
#include "../../../../logger/logger.c"

/**
 * Sends the source to the serial port file.
 *
 * @param p0 the source data
 * @param p1 the source count
 * @param p2 the internal memory
 */
void send_serial_port_file(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send serial port file.");

    // The serial port output file descriptor.
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get serial port file descriptor.
    // It should have been created in the "maintain/startup"
    // operation with channel "serial-port" before.
    copy_array_forward((void*) &sp, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_DESCRIPTOR_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    send_serial_port_stream(sp, p0, p1);
}

/* FILE_SERIAL_PORT_SENDER_SOURCE */
#endif
