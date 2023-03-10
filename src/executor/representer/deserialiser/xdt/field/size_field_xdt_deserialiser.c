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

#ifndef SIZE_FIELD_XDT_DESERIALISER_SOURCE
#define SIZE_FIELD_XDT_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../../executor/mover/mover.c"
#include "../../../../../executor/representer/deserialiser/numeral/integer_numeral_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises xdt field size.
 *
 * @param p0 the destination field size data
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the element count
 */
void deserialise_xdt_field_size(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** sd = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field size.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Ensure that array boundaries are not crossed.
        compare_integer_greater_or_equal((void*) &r, p2, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_numeral_integer(p0, *sd, p3, (void*) DECIMAL_BASE_NUMERAL_MODEL);

            // Move position.
            move(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field size. The source data position is null.");
        fwprintf(stdout, L"Error: Could not deserialise xdt field size. The source data position is null. p1: %i\n", p1);
    }
}

/* SIZE_FIELD_XDT_DESERIALISER_SOURCE */
#endif
