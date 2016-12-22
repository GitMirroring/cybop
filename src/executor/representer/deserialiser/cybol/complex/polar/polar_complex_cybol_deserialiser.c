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

#ifndef POLAR_COMPLEX_CYBOL_DESERIALISER_SOURCE
#define POLAR_COMPLEX_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../executor/representer/deserialiser/cybol/complex/cartesian/cartesian_complex_cybol_deserialiser.c"
#include "../../../../../../executor/representer/deserialiser/cybol/complex/polar/vector_polar_complex_cybol_deserialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the source wide character data given in polar coordinates
 * into a destination complex item in cartesian coordinates.
 *
 * @param p0 the destination complex item
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 */
void deserialise_cybol_complex_polar(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol complex polar.");

    // The temporary complex item in polar coordinates.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary complex item data, count.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate temporary complex item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

    // Deserialise source data.
    // CAUTION! This function for cartesian coordinates
    // CAN BE USED for polar coordinates as well,
    // since all it does is converting from double values.
    deserialise_cybol_complex_cartesian(t, p1, p2);

    // Get temporary complex item data, count.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tc, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Deserialise complex data given in polar coordinates
    // into complex data in cartesian coordinates.
    deserialise_cybol_complex_polar_vector(p0, td, tc);

    // Deallocate temporary double item.
    deallocate_item((void*) &t, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);
}

/* POLAR_COMPLEX_CYBOL_DESERIALISER_SOURCE */
#endif
