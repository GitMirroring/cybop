/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VALUE_INTEGER_CYBOL_SERIALISER_SOURCE
#define VALUE_INTEGER_CYBOL_SERIALISER_SOURCE

#include <stdio.h>
#include <string.h>
#include <wchar.h>

 
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/representer/serialiser/cybol/integer/base_integer_cybol_serialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Serialises the integer value into wide character data.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source index
 * @param p3 the number base:
 *           0 - tries to automatically identify the correct number base
 *           8 - octal, e.g. 083
 *           10 - decimal, e.g. 1234
 *           16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
 */
void serialise_cybol_integer_value(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol integer value.");

    // The value.
    int v = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get value from vector at index.
    copy_array_forward((void*) &v, p1, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    //
    // The temporary array.
    //
    // The longest possible integer value defined in the
    // C programming language currently seems to be:
    //
    // unsigned long long int
    //
    // Minimum allowed range: 0..+18446744073709551615
    // Typical allowed range: 0..+18446744073709551615
    // Typical size [Byte]: 8
    // Typical size [Bit]: 64
    //
    // The range 18446744073709551615 contains 20 digits.
    // It therefore is sufficient to provide an array of size 256.
    //
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    int tc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ts = *NUMBER_256_INTEGER_STATE_CYBOI_MODEL;

    // Allocate temporary array.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &td, (void*) &ts, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Serialise value according to given number base.
    serialise_cybol_integer_base(td, (void*) &tc, (void*) &ts, (void*) &v, p3);

    if (tc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // The value was converted successfully.

        modify_item(p0, td, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &tc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        // The value returned by the conversion function is negative,
        // which means that the value was NOT converted successfully.

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol integer value.");

        // CAUTION! A more flexible approach would be to stepwise enlarge
        // the destination array, until the provided source value matches.
        // In order to do this, call this function itself recursively.
        // This is done every time again, until the value
        // gets finally converted successfully.
        // The only argument that grows then is the destination size.
    }

    // Deallocate temporary array.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &td, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &ts, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* VALUE_INTEGER_CYBOL_SERIALISER_SOURCE */
#endif
