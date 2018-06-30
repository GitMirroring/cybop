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

#ifndef SERIALISE_SENDER_SOURCE
#define SERIALISE_SENDER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../executor/representer/serialiser.c"
#include "../../../logger/logger.c"

/**
 * Serialises source into destination.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count (pointer reference)
 * @param p2 the buffer item
 * @param p3 the source name data
 * @param p4 the source name count
 * @param p5 the source channel data
 * @param p6 the source encoding data
 * @param p7 the source language data
 * @param p8 the source language properties data
 * @param p9 the source language properties count
 * @param p10 the source format data
 * @param p11 the source type data
 * @param p12 the source model data
 * @param p13 the source model count
 * @param p14 the source properties data
 * @param p15 the source properties count
 * @param p16 the clear flag
 * @param p17 the newline flag
 * @param p18 the knowledge memory part (pointer reference)
 * @param p19 the stack memory item
 * @param p20 the internal memory data
 */
void send_serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20) {

    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send serialise.");

        // Serialise message.
        serialise(p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20);

        // Get item data, count.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward(p1, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

//?? fwprintf(stdout, L"TEST: send serialise *c: %i \n", *((int*) c));
//?? fwprintf(stdout, L"TEST: send serialise d: %i \n", d);
//?? fwprintf(stdout, L"TEST: send serialise d as char*: %s \n", (char*) d);

    } else {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serialise. The language is null.");
    }
}

/* SERIALISE_SENDER_SOURCE */
#endif
