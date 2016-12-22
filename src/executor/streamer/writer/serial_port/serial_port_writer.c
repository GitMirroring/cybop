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

#ifndef SERIAL_PORT_WRITER_SOURCE
#define SERIAL_PORT_WRITER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/streamer/writer/serial_port/stream_serial_port_writer.c"
#include "../../../../logger/logger.c"

/**
 * Writes the source to the serial port.
 *
 * @param p0 the source data
 * @param p1 the source count
 * @param p2 the internal memory
 */
void write_serial_port(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write serial port.");

    // The file descriptor item.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The file descriptor item data.
    void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get file descriptor item.
    // It should have been created in the "maintain/startup"
    // operation with channel "serial-port" before.
    copy_array_forward((void*) &f, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_DESCRIPTOR_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get file descriptor item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    write_serial_port_stream(fd, p0, p1);
}

/* SERIAL_PORT_WRITER_SOURCE */
#endif
