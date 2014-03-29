/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CARTESIAN_COMPLEX_CYBOL_SERIALISER_SOURCE
#define CARTESIAN_COMPLEX_CYBOL_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/representer/serialiser/cybol/complex/cartesian/vector_cartesian_complex_cybol_serialiser.c"
#include "../../../../../../executor/representer/serialiser/cybol/fraction/decimal/decimal_fraction_cybol_serialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the complex number given in cartesian coordinates
 * into comma-separated wide character data.
 *
 * @param p0 the destination wide character item
 * @param p1 the source complex number data
 * @param p2 the source complex number count
 */
void serialise_cybol_complex_cartesian(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol complex cartesian.");

    // The temporary double item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary double item data, count.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate temporary double item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE);

    // Serialise complex data.
    serialise_cybol_complex_cartesian_vector(t, p1, p2);

    // Get temporary double item data, count.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tc, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Serialise source data.
    // (One or more complex numbers represent
    // two or more double numbers, respectively).
    serialise_cybol_fraction_decimal(p0, td, tc);

    // Deallocate temporary double item.
    deallocate_item((void*) &t, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE);
}

/* CARTESIAN_COMPLEX_CYBOL_SERIALISER_SOURCE */
#endif
