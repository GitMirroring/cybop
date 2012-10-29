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

#ifndef ELEMENT_FIELD_XDT_DESERIALISER_SOURCE
#define ELEMENT_FIELD_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/basic/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/representer/deserialiser/cybol/integer/value_integer_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises an xdt field element.
 *
 * It may be one of the following:
 * - size: 3 Byte
 * - dependency hierarchy: 1 Byte
 * - identification: 4 Byte
 *
 * The corresponding length in Byte is handed over as parametre.
 *
 * @param p0 the destination integer data
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the element count
 */
void deserialise_xdt_field_element(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** sd = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field element.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // CAUTION! This comparison ensures that array boundaries are not crossed.
        compare_integer_greater_or_equal((void*) &r, p2, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary item.
            void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary item data.
            void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate temporary item.
            allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            // Decode xdt field element.
            deserialise_cybol_integer_value(i, *sd, p3, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

            // Get temporary item data.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &id, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            // Copy temporary value to destination.
            copy_integer(p0, id);

            // Deallocate temporary item.
            deallocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            // Move position.
            move_position(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field element. The source data is null.");
    }
}

/* ELEMENT_FIELD_XDT_DESERIALISER_SOURCE */
#endif
