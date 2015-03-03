/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BODY_HTTP_RESPONSE_SERIALISER_SOURCE
#define BODY_HTTP_RESPONSE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/converter/encoder.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/modifier/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the http response body.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count (pointer reference)
 * @param p2 the buffer item
 * @param p3 the source model data
 * @param p4 the source model count
 * @param p5 the source properties data
 * @param p6 the source properties count
 * @param p7 the knowledge memory part
 */
void serialise_http_response_body(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise http response body.");

    // The encoding part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item data.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get encoding part.
    get_part_knowledge((void*) &e, p5, (void*) ENCODING_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) ENCODING_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p6, p7);
    // Get encoding part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get encoding part model item data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    if (emd != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The item data, count.
        void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Encode body wide character array into multibyte character item.
        encode(p2, p3, p4, emd);

        // Get item data, count.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &d, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &c, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Assign destination data, count.
        copy_pointer(p0, (void*) &d);
        copy_pointer(p1, (void*) &c);
    }
}

/* BODY_HTTP_RESPONSE_SERIALISER_SOURCE */
#endif
