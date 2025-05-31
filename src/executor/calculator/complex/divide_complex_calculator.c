/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Adds the source fraction to the destination fraction.
 *
 * @param p0 the destination fraction
 * @param p1 the source fraction
 */
void calculate_complex_divide(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate complex add.");

    // The destination real and imaginary.
    double dr = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double di = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The source real and imaginary.
    double sr = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double si = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get destination real and imaginary.
    get_complex_element((void*) &dr, (void*) p0, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &di, (void*) p0, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
    // Get source real and imaginary.
    get_complex_element((void*) &sr, (void*) p1, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &si, (void*) p1, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    // The temporary destination real value.
    double tdr = dr;

    // Calculate real value.
    dr = ((tdr * sr) + (di * si)) / ((sr * sr) + (si * si));
    // Calculate imaginary value.
    di = ((si * tdr) - (di * sr)) / ((sr * sr) + (si * si));

    // Set destination real and imaginary
    // (just copies the values inside).
    set_complex_element((void*) p0, (void*) &dr, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    set_complex_element((void*) p0, (void*) &di, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
}
