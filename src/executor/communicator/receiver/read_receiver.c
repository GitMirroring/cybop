/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef READ_RECEIVER_SOURCE
#define READ_RECEIVER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../executor/streamer/reader/reader.c"
#include "../../../logger/logger.c"

/**
 * Reads from source into destination.
 *
 * @param p0 the destination item data (pointer reference)
 * @param p1 the destination item count (pointer reference)
 * @param p2 the destination item
 * @param p3 the source device identification (e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p4 the source device count
 * @param p5 the language (protocol)
 * @param p6 the internal memory data
 * @param p7 the channel
 * @param p8 the server flag
 * @param p9 the service port
 * @param p10 the asynchronicity flag (true if reading indirectly from buffer; false or null if reading directly from device)
 */
void receive_read(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    // Filter out null value for better performance.
    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive read.");
        // fwprintf(stdout, L"Debug: Receive read. p7: %i\n", p7);
        // fwprintf(stdout, L"Debug: Receive read. *p7: %i\n", *((int*) p7));

        //
        // Read message from device.
        //
        // CAUTION! Hand over NULL as destination mutex, since that is
        // used only when calling this function from a "sense" thread,
        // in order to write data into an internal client buffer.
        //
        read_data(p2, p3, p4, *NULL_POINTER_STATE_CYBOI_MODEL, p5, p6, p7, p8, p9, p10);

        //
        // Get item data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward(p1, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive read. The channel is null.");
        fwprintf(stdout, L"Warning: Could not receive read. The channel is null. channel p7: %i\n", p7);
        fwprintf(stdout, L"Warning: Could not receive read. The channel is null. channel *p7: %i\n", *((int*) p7));
    }
}

/* READ_RECEIVER_SOURCE */
#endif
