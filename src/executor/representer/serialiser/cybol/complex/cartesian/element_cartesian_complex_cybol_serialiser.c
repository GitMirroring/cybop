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

#ifndef ELEMENT_CARTESIAN_COMPLEX_CYBOL_SERIALISER_SOURCE
#define ELEMENT_CARTESIAN_COMPLEX_CYBOL_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../executor/accessor/getter/complex_getter.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the complex number into a double item.
 *
 * @param p0 the destination double item
 * @param p1 the source complex data
 * @param p2 the source complex index
 */
void serialise_cybol_complex_cartesian_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol complex cartesian element.");

    // The temporary complex number.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The real and imaginary value.
    double r = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double i = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    //
    // Allocate temporary complex number.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

    // Get temporary complex number from source complex data at current index.
    copy_array_forward(t, p1, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    // Get real and imaginary value.
    get_complex_element((void*) &r, t, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &i, t, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    //
    // Deallocate temporary complex number.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &t, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

    // Append real and imaginary value to destination.
    modify_item(p0, (void*) &r, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    modify_item(p0, (void*) &i, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}

/* ELEMENT_CARTESIAN_COMPLEX_CYBOL_SERIALISER_SOURCE */
#endif
