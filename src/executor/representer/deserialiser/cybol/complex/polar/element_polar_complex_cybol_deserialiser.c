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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_POLAR_COMPLEX_CYBOL_DESERIALISER_SOURCE
#define ELEMENT_POLAR_COMPLEX_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../executor/accessor/getter/complex_getter.c"
#include "../../../../../../executor/accessor/setter/complex_setter.c"
#include "../../../../../../executor/representer/deserialiser/cybol/complex/polar/coordinates_polar_complex_cybol_deserialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the complex number in polar coordinates
 * into a complex item in cartesian coordinates.
 *
 * @param p0 the destination complex item
 * @param p1 the source complex data
 * @param p2 the source complex index
 */
void deserialise_cybol_complex_polar_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol complex polar element.");

    // The temporary destination complex number.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary source complex number.
    void* ts = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The absolute value and argument.
    double v = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double a = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The real and imaginary value.
    double r = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double i = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Allocate temporary destination complex number.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &td, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);
    // Allocate temporary source complex number.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &ts, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

    // Get temporary source complex number from source complex data at current index.
    copy_array_forward(ts, p1, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    // Get absolute value and argument.
    //
    // CAUTION! The type structure used here for polar coordinates
    // is IDENTICAL to that of cartesian coordinates.
    // Therefore, the following name constants may be used:
    // - REAL_COMPLEX_STATE_CYBOI_NAME
    // - IMAGINARY_COMPLEX_STATE_CYBOI_NAME
    //
    // The following constants do NOT exist,
    // in order to avoid redundancy:
    // - ABSOLUTE_VALUE_COMPLEX_STATE_CYBOI_NAME
    // - ARGUMENT_COMPLEX_STATE_CYBOI_NAME
    get_complex_element((void*) &v, ts, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &a, ts, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    // Transform polar coordinates into cartesian coordinates.
    deserialise_cybol_complex_polar_coordinates((void*) &r, (void*) &i, (void*) &v, (void*) &a);

    // Set real and imaginary value.
    set_complex_element(td, (void*) &r, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    set_complex_element(td, (void*) &i, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    // Append complex to destination.
    append_item_element(p0, td, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Deallocate temporary destination complex number.
    deallocate_array((void*) &td, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);
    // Deallocate temporary source complex number.
    deallocate_array((void*) &ts, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);
}

/* ELEMENT_POLAR_COMPLEX_CYBOL_DESERIALISER_SOURCE */
#endif
