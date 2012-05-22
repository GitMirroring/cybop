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

#ifndef FRACTION_DEALLOCATOR_SOURCE
#define FRACTION_DEALLOCATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the fraction.
 *
 * @param p0 the fraction (pointer reference)
 * @param p1 the fraction size
 */
void deallocate_fraction(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** f = (void**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate fraction.");

/*??
        // The numerator and denominator.
        void** n = NULL_POINTER_STATE_CYBOI_MODEL;
        void** d = NULL_POINTER_STATE_CYBOI_MODEL;

        // Retrieve numerator and denominator.
        retrieve((void*) &n, p0, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        retrieve((void*) &d, p0, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        // Deallocate numerator and denominator.
        deallocate((void*) &n, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        deallocate((void*) &d, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        // Deallocate fraction.
        deallocate(p0, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
*/

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate fraction. The fraction is null.");
    }
}

/* FRACTION_DEALLOCATOR_SOURCE */
#endif
