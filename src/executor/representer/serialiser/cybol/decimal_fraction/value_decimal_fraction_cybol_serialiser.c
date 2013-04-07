/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Falk Müller <falk89@web.de>
 */

#ifndef VALUE_DECIMAL_FRACTION_CYBOL_SERIALISER_SOURCE
#define VALUE_DECIMAL_FRACTION_CYBOL_SERIALISER_SOURCE

#ifdef WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../logger/logger.c"

/**
 * Serialises the doube value into wide character data.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source index
 */
void serialise_cybol_fraction_decimal_value(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol fraction decimal value.");

    // The value.
    double v = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get value from vector at index.
    copy_array_forward((void*) &v, p1, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

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
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &td, (void*) &ts, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Transform source value to destination string.
    // A null wide character is written to mark the end of the string.
    // The return value is the number of characters generated
    // for the given input, excluding the trailing null.
    // If not all output fits into the provided buffer,
    // a negative value is returned.

#ifdef CYGWIN_ENVIRONMENT
    tc = wsprintfW(td, L"%f", v);
/* CYGWIN_ENVIRONMENT */
#else
    tc = swprintf(td, ts, L"%f", v);
/* CYGWIN_ENVIRONMENT */
#endif

    if (tc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // The value was converted successfully.

        append_item_element(p0, td, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &tc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        // The value returned by the conversion function is negative,
        // which means that the value was NOT converted successfully.

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise cybol fraction decimal value.");

        // CAUTION! A more flexible approach would be to stepwise enlarge
        // the destination array, until the provided source value matches.
        // In order to do this, call this function itself recursively.
        // This is done every time again, until the value
        // gets finally converted successfully.
        // The only argument that grows then is the destination size.
    }

    // Deallocate temporary array.
    deallocate_array((void*) &td, (void*) &tc, (void*) &ts, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* VALUE_DECIMAL_FRACTION_CYBOL_SERIALISER_SOURCE */
#endif
