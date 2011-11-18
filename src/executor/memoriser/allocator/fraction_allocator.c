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

#ifndef FRACTION_ALLOCATOR_SOURCE
#define FRACTION_ALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/name/cyboi/state/fraction_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Allocates the fraction.
 *
 * @param p0 the fraction (pointer reference)
 * @param p1 the fraction size (This value is ignored.)
 */
void allocate_fraction(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** f = (void**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate fraction.");

        // Allocate fraction.
        allocate_array(p0, (void*) FRACTION_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        // The numerator and denominator.
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* d = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate numerator and denominator.
        allocate_array((void*) &n, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_STATE_CYBOI_TYPE);
        allocate_array((void*) &d, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_STATE_CYBOI_TYPE);

/*?? TODO!
        // Initialise numerator and denominator.
        overwrite_array(n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) INTEGER_STATE_CYBOI_TYPE_COUNT);
        overwrite_array(d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) INTEGER_STATE_CYBOI_TYPE_COUNT);

        // Replace numerator and denominator.
        overwrite_array(*f, n, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_CYBOI_TYPE_COUNT);
        overwrite_array(*f, d, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_CYBOI_TYPE_COUNT);
*/

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate fraction. The fraction is null.");
    }
}

/* FRACTION_ALLOCATOR_SOURCE */
#endif
