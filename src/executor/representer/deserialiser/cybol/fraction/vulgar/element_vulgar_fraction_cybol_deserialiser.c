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

#ifndef ELEMENT_VULGAR_FRACTION_CYBOL_DESERIALISER_SOURCE
#define ELEMENT_VULGAR_FRACTION_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../executor/accessor/setter/fraction_setter.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the integer data into a fraction item.
 *
 * @param p0 the destination fraction item
 * @param p1 the source integer data
 * @param p2 the source integer numerator index
 * @param p3 the source integer denominator index
 */
void deserialise_cybol_fraction_vulgar_element(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol fraction vulgar element.");

    // The numerator and denominator value.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The temporary fraction.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get numerator and denominator value from source integer data at current indices.
    copy_array_forward((void*) &n, p1, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);
    copy_array_forward((void*) &d, p1, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);

    // Allocate temporary fraction.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

    // Set numerator and denominator value.
    set_fraction_element(t, (void*) &n, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    set_fraction_element(t, (void*) &d, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // Append temporary fraction to destination.
    append_item_element(p0, t, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Deallocate temporary fraction.
    deallocate_array((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);
}

/* ELEMENT_VULGAR_FRACTION_CYBOL_DESERIALISER_SOURCE */
#endif
