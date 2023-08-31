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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises source into destination.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count (pointer reference)
 * @param p2 the buffer item
 * @param p3 the source model data
 * @param p4 the source model count
 * @param p5 the source properties data
 * @param p6 the source properties count
 * @param p7 the language properties (constraints) data
 * @param p8 the language properties (constraints) count
 * @param p9 the knowledge memory part (pointer reference)
 * @param p10 the stack memory item
 * @param p11 the internal memory data
 * @param p12 the destination device identification item, currently only needed for gui window id
 * @param p13 the format
 * @param p14 the language
 */
void send_serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    // Filter out null value for better performance.
    if (p14 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send serialise.");
        //?? fwprintf(stdout, L"Debug: Send serialise. language p14: %i\n", p14);
        //?? fwprintf(stdout, L"Debug: Send serialise. language *p14: %i\n", *((int*) p14));

        // Serialise message.
        serialise(p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);

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

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serialise. The language is null.");
        //?? fwprintf(stdout, L"Warning: Could not send serialise. The language is null. language p14: %i\n", p14);
        //?? fwprintf(stdout, L"Warning: Could not send serialise. The language is null. language *p14: %i\n", *((int*) p14));
    }
}
