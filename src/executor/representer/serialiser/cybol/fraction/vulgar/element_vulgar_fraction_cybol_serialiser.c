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

#ifndef ELEMENT_VULGAR_FRACTION_CYBOL_SERIALISER_SOURCE
#define ELEMENT_VULGAR_FRACTION_CYBOL_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../executor/accessor/getter/fraction_getter.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the fraction number into an integer item.
 *
 * @param p0 the destination integer item
 * @param p1 the source fraction data
 * @param p2 the source fraction index
 */
void serialise_cybol_fraction_vulgar_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol fraction vulgar element.");

    // The temporary fraction number.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The numerator and denominator value.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Allocate temporary fraction number.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

    // Get temporary fraction number from source fraction data at current index.
    copy_array_forward(t, p1, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    // Get numerator and denominator value.
    get_fraction_element((void*) &n, t, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &d, t, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    //
    // Deallocate temporary fraction number.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &t, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

    // Append numerator and denominator value to destination.
    modify_item(p0, (void*) &n, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    modify_item(p0, (void*) &d, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}

/* ELEMENT_VULGAR_FRACTION_CYBOL_SERIALISER_SOURCE */
#endif
