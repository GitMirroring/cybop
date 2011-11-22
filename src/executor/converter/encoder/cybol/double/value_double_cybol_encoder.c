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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VALUE_DOUBLE_CYBOL_ENCODER_SOURCE
#define VALUE_DOUBLE_CYBOL_ENCODER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../logger/logger.c"

/**
 * Encodes the double value into a wide character value.
 *
 * @param p0 the destination item
 * @param p1 the source double data
 * @param p2 the source double index
 */
void encode_cybol_double_value(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Encode cybol double value.");

    // The value.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get value from vector at index.
    copy_array_forward((void*) &v, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    //
    // The temporary array.
    //
    // The longest possible real value defined in the
    // C programming language currently seems to be:
    //
    // long double
    //
    // Minimum allowed range: 1×10^−37..1×10^37
    // Typical allowed range: 1×10^−308..1×10^308 or 1×10^−4932..1×10^4932 (x87 FPU systems)
    // Typical size [Byte]: 8 or 12
    // Typical size [Bit]: 64 or 96
    //
    // The range 1×10^4932 contains 4932 digits.
    // It therefore is sufficient to provide an array of size 8192.
    //
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    int tc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ts = *NUMBER_8192_INTEGER_STATE_CYBOI_MODEL;

    // Allocate temporary array.
    allocate_array((void*) &td, (void*) &ts, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Transform source value to destination string.
    // A null wide character is written to mark the end of the string.
    // The return value is the number of characters generated
    // for the given input, excluding the trailing null.
    // If not all output fits into the provided buffer,
    // a negative value is returned.
#ifdef CYGWIN_ENVIRONMENT
    int tc = wsprintfW(td, L"%d", *((long double*) v));
/* CYGWIN_ENVIRONMENT */
#else
    int tc = swprintf(td, ts, L"%d", *((long double*) v));
/* CYGWIN_ENVIRONMENT */
#endif

    if (tc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // The value was converted successfully.

        append_item_element(p0, td, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &tc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        // The value returned by the conversion function is negative,
        // which means that the value was NOT converted successfully.

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not encode cybol double value.");

        // CAUTION! A more flexible approach would be to stepwise enlarge
        // the destination array, until the provided source value matches.
        // In order to do this, call this function itself recursively.
        // This is done every time again, until the value
        // gets finally converted successfully.
        // The only argument that grows then is the destination size.
    }

    // Deallocate temporary array.
    deallocate_array((void*) &td, (void*) &ts, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* VALUE_DOUBLE_CYBOL_ENCODER_SOURCE */
#endif
