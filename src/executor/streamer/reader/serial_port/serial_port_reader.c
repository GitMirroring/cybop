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

#ifndef SERIAL_PORT_READER_SOURCE
#define SERIAL_PORT_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/streamer/reader/serial_port/stream_serial_port_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads the destination from serial port.
 *
 * @param p0 the destination item
 * @param p1 the minimum number of bytes to be received in one call of the read function
 * @param p2 the maximum number of bytes to be received in one call of the read function
 * @param p3 the internal memory data
 */
void read_serial_port(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read serial port.");

    // The file descriptor item.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The file descriptor item data.
    void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get file descriptor item.
    copy_array_forward((void*) &f, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_DESCRIPTOR_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get mutex.
    copy_array_forward((void*) &m, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get file descriptor item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    read_serial_port_stream(p0, fd, m, p1, p2);
}

/* SERIAL_PORT_READER_SOURCE */
#endif
