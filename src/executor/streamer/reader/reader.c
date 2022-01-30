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

#ifndef READER_SOURCE
#define READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"
--
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/feeler/sensor/loop_sensor.c"

/**
 * Reads data via the given channel into the destination.
 *
 * CAUTION! Do NOT rename this function to "read",
 * since that name is already used by low-level glibc
 * functionality in header file unistd.h.
 * Function: ssize_t read (int filedes, void *buffer, size_t size)
 *
--
DEVICE READER:
 * @param p0 the destination item
 * @param p1 the source data (mostly a client identification file descriptor for a file, serial port, terminal, socket OR input text for inline channel)
 * @param p2 the source count
 * @param p3 the destination mutex
 * @param p4 the client entry
 * @param p5 the server identification (server base + service port)
 * @param p6 the client identification
 * @param p7 the language (protocol)
 * @param p8 the channel
 * @param p9 the asynchronous mode
--
BUFFER_READER:
 * @param p0 the destination item
 * @param p1 the client entry
 * @param p2 the language (protocol)
 * @param p3 the channel
 */
void read_data(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read data.");
    fwprintf(stdout, L"Debug: Read data. p0: %i\n", p0);

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client device identification.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from internal memory.
    get_internal_memory_channel((void*) &se, p1, p2, p3);

    if (se != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Get client identification from client entry.
        copy_array_forward((void*) &cid, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);

        get_server_entry();

        get_client_entry();
        find_client_list_name();

        if (asynchronous == false) {

            //
            // This is SYNCHRONOUS mode.
            //

            // Read directly from device.
            read_device(px);

        } else {

            //
            // This is ASYNCHRONOUS mode.
            //

            //
            // Read indirectly from buffer.
            //
            // The data have been read and stored in the buffer
            // in a separate sensing thread before.
            //
            read_buffer(destination-item, client-entry, language, channel);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read data. The server entry is null.");
        fwprintf(stdout, L"Error: Could not read data. The server entry is null. se: %i\n", se);
    }
}

/* READER_SOURCE */
#endif
