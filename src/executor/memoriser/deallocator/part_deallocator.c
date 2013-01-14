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

#ifndef PART_DEALLOCATOR_SOURCE
#define PART_DEALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../executor/referencer/referencer.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void reference(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Deallocates the part.
 *
 * @param p0 the part (pointer reference)
 * @param p1 the size
 * @param p2 the type
 */
void deallocate_part(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** part = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate part.");

        // The references, name, channel, encoding, language, format, type, model, properties.
        void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The data, count.
        void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get references, name, channel, encoding, language, format, type, model, properties.
        copy_array_forward((void*) &r, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) REFERENCES_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &n, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &c, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &e, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENCODING_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &l, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &f, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &t, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &m, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &p, *part, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
        // Get data, count.
        copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Verify that reference data is zero.
        // CAUTION! Otherwise, do NOT deallocate this part.
        if (rd == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Decrement reference count of child parts for rubbish (garbage) collection.
            reference(md, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT, mc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, td);

            // Deallocate references, name, type, model, properties.
            deallocate_item((void*) &r, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            deallocate_item((void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &e, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &m, p1, p2);
            deallocate_item((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

            // Deallocate part.
            deallocate_array(p0, (void*) PART_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate part. It is still referenced by other parts.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate part. The part is null.");
    }
}

/* PART_DEALLOCATOR_SOURCE */
#endif
