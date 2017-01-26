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

#ifndef READ_RECEIVER_SOURCE
#define READ_RECEIVER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../executor/streamer/reader.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/modifier/copier/pointer_copier.c"
#include "../../../logger/logger.c"

/**
 * Reads from source into destination.
 *
 * @param p0 the destination item data (pointer reference)
 * @param p1 the destination item count (pointer reference)
 * @param p2 the buffer item
 * @param p3 the source model data (e.g. a filename or socket number)
 * @param p4 the source model count
 * @param p5 the source properties data
 * @param p6 the source properties count
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 * @param p10 the blocking flag
 * @param p11 the minimum number of bytes to be received in one call of the read function
 * @param p12 the maximum number of bytes to be received in one call of the read function
 * @param p13 the channel
 */
void receive_read(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    if (p13 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive read.");

//?? fwprintf(stdout, L"TEST: receive read *p4: %i \n", *((int*) p4));
//?? fwprintf(stdout, L"TEST: receive read p3: %ls \n", p3);

        // Read message from device.
        read_data(p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);

        // Get item data, count.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward(p1, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive read. The channel is null.");
    }
}

/* READ_RECEIVER_SOURCE */
#endif
