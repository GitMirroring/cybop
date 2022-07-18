/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ALLOCATOR_NUMERAL_DESERIALISER_SOURCE
#define ALLOCATOR_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/numeral/numeral_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Allocates a number part.
 *
 * @param p0 the destination number item (pointer reference)
 * @param p1 the destination number part (pointer reference)
 * @param p2 the number part name data
 * @param p3 the number part name count
 * @param p4 the number part format
 * @param p5 the number part type
 */
void deserialise_numeral_allocator(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** p = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral allocator.");
        fwprintf(stdout, L"Debug: Deserialise numeral allocator. name data p2: %ls\n", (wchar_t*) p2);
        fwprintf(stdout, L"Debug: Deserialise numeral allocator. name count p3: %i\n", p3);
        fwprintf(stdout, L"Debug: Deserialise numeral allocator. name count *p3: %i\n", *((int*) p3));
        fwprintf(stdout, L"Debug: Deserialise numeral allocator. format p4: %i\n", p4);
        fwprintf(stdout, L"Debug: Deserialise numeral allocator. format *p4: %i\n", *((int*) p4));
        fwprintf(stdout, L"Debug: Deserialise numeral allocator. type p5: %i\n", p5);
        fwprintf(stdout, L"Debug: Deserialise numeral allocator. type *p5: %i\n", *((int*) p5));

        //
        // Allocate number part.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_part(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p5);

        //
        // Fill number part.
        //
        // CAUTION! Do NOT forget to assign the format and type.
        //
        modify_part(*p, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
        modify_part(*p, p4, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        modify_part(*p, p5, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

        // Get number part model item.
        copy_array_forward(p0, *p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise numeral number. The destination number part is null.");
        fwprintf(stdout, L"Error: Could not deserialise numeral number. The destination number part is null. p1: %i\n", p1);
    }
}

/* ALLOCATOR_NUMERAL_DESERIALISER_SOURCE */
#endif
