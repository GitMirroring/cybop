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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef VERIFICATION_NUMERAL_DESERIALISER_SOURCE
#define VERIFICATION_NUMERAL_DESERIALISER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Verifies if the detected type and the one retrieved from the
 * destination number format are identical.
 *
 * CAUTION! Comparing the formats is not useful, since they may differ
 * even though the type is identical. For example, colour values are
 * given as rgb integer vector but have a different format.
 *
 * @param p0 the comparison result
 * @param p1 the detected type
 * @param p2 the destination number format
 */
void deserialise_numeral_verification(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral verification.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral verification. detected type p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral verification. detected type *p1: %i\n", *((int*) p1));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral verification. destination number format p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral verification. destination number format *p2: %i\n", *((int*) p2));

    // The type item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type item data.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate type item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    // Deserialise destination number format into type item.
    deserialise_cybol_type(t, p2);

    //
    // Get type item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"Debug: Deserialise numeral verification. destination number type td: %i\n", td);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral verification. destination number type *td: %i\n", *((int*) td));

    // Compare types.
    compare_integer_equal(p0, p1, td);

    //
    // Deallocate type item.
    //
    // CAUTION! This has to be done AFTER having deallocated
    // the number above, since the type is needed for it.
    //
    deallocate_item((void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/* VERIFICATION_NUMERAL_DESERIALISER_SOURCE */
#endif
