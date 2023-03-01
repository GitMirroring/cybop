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

#ifndef NULL_NUMERAL_DESERIALISER_SOURCE
#define NULL_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/numeral/allocation_numeral_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the source wide character numeral sequence into a number item.
 *
 * @param p0 the temporary number (pointer reference)
 * @param p1 the destination number part (pointer reference)
 * @param p2 the number part name data
 * @param p3 the number part name count
 * @param p4 the format
 * @param p5 the type
 */
void deserialise_numeral_null(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral null.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral null. type p4: %i\n", p4);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral null. type *p4: %i\n", *((int*) p4));

    // Allocate a new number part.
    deserialise_numeral_allocation(p1, p2, p3, p4, p5);

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The destination number part (pointer reference).
        void** p = (void**) p1;

        // The destination number part model item.
        void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The destination number part model item data.
        void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;

        //?? fwprintf(stdout, L"Debug: Deserialise numeral null. test pre pmd: %i\n", pmd);

        // Get destination number part model item.
        copy_array_forward((void*) &pm, *p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        // Get destination number part model item data.
        copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        //?? fwprintf(stdout, L"Debug: Deserialise numeral null. test post pmd: %i\n", pmd);

        // Assign part model item data as temporary number.
        copy_pointer(p0, (void*) &pmd);

        //
        // CAUTION Do NOT append the part to some destination here,
        // since this is done in other deserialisers' files such as:
        //
        // - CYBOL: "standard_cybol_deserialiser.c"
        // - JSON: "number_json_deserialiser.c", "string_json_deserialiser.c"
        //

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise numeral null. The allocated part is null.");
        fwprintf(stdout, L"Error: Could not deserialise numeral null. The allocated part is null. p1: %i\n", p1);
    }
}

/* NULL_NUMERAL_DESERIALISER_SOURCE */
#endif
