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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef EXISTENCE_NUMERAL_DESERIALISER_SOURCE
#define EXISTENCE_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Tests if a number part exists and allocates it if not.
 *
 * @param p0 the destination number item (pointer reference)
 * @param p1 the destination number part (pointer reference)
 * @param p2 the number part name data
 * @param p3 the number part name count
 * @param p4 the number part format
 * @param p5 the number part type
 */
void deserialise_numeral_existence(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral existence.");
    fwprintf(stdout, L"Debug: Deserialise numeral existence. type p5: %i\n", p5);
    fwprintf(stdout, L"Debug: Deserialise numeral existence. type *p5: %i\n", *((int*) p5));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_pointer_equal((void*) &r, p0, NULL_POINTER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A destination number item does NOT exist.
        //

        // Allocate a new number part.
        deserialise_numeral_allocator(p0, p1, p2, p3, p4, p5);
    }
}

/* EXISTENCE_NUMERAL_DESERIALISER_SOURCE */
#endif
