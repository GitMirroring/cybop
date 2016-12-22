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

#ifndef ELEMENT_CARTESIAN_COMPLEX_CYBOL_DESERIALISER_SOURCE
#define ELEMENT_CARTESIAN_COMPLEX_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../executor/accessor/setter/complex_setter.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the double number into a complex item.
 *
 * @param p0 the destination complex item
 * @param p1 the source double data
 * @param p2 the source double real index
 * @param p3 the source double imaginary index
 */
void deserialise_cybol_complex_cartesian_element(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol complex cartesian element.");

    // The real and imaginary value.
    double r = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double i = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The temporary complex.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get real and imaginary value from source double data at current indices.
    copy_array_forward((void*) &r, p1, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);
    copy_array_forward((void*) &i, p1, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);

    // Allocate temporary complex.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

    // Set real and imaginary value.
    set_complex_element(t, (void*) &r, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    set_complex_element(t, (void*) &i, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    // Append temporary complex to destination.
    append_item_element(p0, t, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Deallocate temporary complex.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &t, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);
}

/* ELEMENT_CARTESIAN_COMPLEX_CYBOL_DESERIALISER_SOURCE */
#endif
