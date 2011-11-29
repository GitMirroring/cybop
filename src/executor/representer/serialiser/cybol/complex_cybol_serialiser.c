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

#ifndef COMPLEX_SERIALISER_SOURCE
#define COMPLEX_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the complex model and creates a byte stream from it.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_complex(void* p0, void* p1, void* p2) {

/*??
    //??    log_message((void*) &INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) &"Finalise complex.");

    // Initialise elements.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get elements.
    get_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &IMAGINARY_INDEX, (void*) &i);
    get_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &REAL_INDEX, (void*) &r);

    // Remove elements.
    remove_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &COMPLEX_STATE_CYBOI_MODEL_COUNT, (void*) &IMAGINARY_INDEX);
    remove_array_element(p0, (void*) &DOUBLE_ARRAY, (void*) &COMPLEX_STATE_CYBOI_MODEL_COUNT, (void*) &REAL_INDEX);

    //??    fwprintf(p1, %d, (void*) &(t->real));
    //??    fwprintf(p1, %d, (void*) &(t->imaginary));
*/
}

/* COMPLEX_SERIALISER_SOURCE */
#endif
