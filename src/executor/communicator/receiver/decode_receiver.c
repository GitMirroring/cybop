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

#ifndef DECODE_RECEIVER_SOURCE
#define DECODE_RECEIVER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/converter/decoder/decoder.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../logger/logger.c"

/**
 * Decode source into destination.
 *
 * @param p0 the destination item data (pointer reference)
 * @param p1 the destination item count (pointer reference)
 * @param p2 the buffer item
 * @param p3 the source data
 * @param p4 the source count
 * @param p5 the encoding
 */
void receive_decode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    // Filter out null value for better performance.
    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive decode.");
        //?? fwprintf(stdout, L"Debug: Receive decode. encoding p5: %i\n", p5);
        //?? fwprintf(stdout, L"Debug: Receive decode. encoding *p5: %i\n", *((int*) p5));

        // Decode message.
        decode(p2, p3, p4, p5);

        //
        // Get item data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward(p1, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        //?? fwprintf(stdout, L"Debug: receive decode *c: %i\n", *((int*) c));
        //?? fwprintf(stdout, L"Debug: receive decode d: %s\n", d);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive decode. The encoding is null.");
        //?? fwprintf(stdout, L"Warning: Could not receive decode. The encoding is null. encoding p5: %i\n", p5);
        //?? fwprintf(stdout, L"Warning: Could not receive decode. The encoding is null. encoding *p5: %i\n", *((int*) p5));
    }
}

/* DECODE_RECEIVER_SOURCE */
#endif
