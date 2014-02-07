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

#ifndef ADD_COMPLEX_CALCULATOR_SOURCE
#define ADD_COMPLEX_CALCULATOR_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Adds the source fraction to the destination fraction.
 *
 * @param p0 the destination fraction
 * @param p1 the source fraction
 */
void calculate_complex_add(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate fraction add.");

    // The destination real and imaginary.
    void* dr = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source real and imaginary.
    void* sr = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary source numerator value.
    // CAUTION! The original *sn should NOT be altered, since a
    // source should always be left untouched (read-only).
    int tsn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get destination real and imaginary.
    copy_array_forward((void*) &dr, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    copy_array_forward((void*) &di, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
    // Get source real and imaginary.
    copy_array_forward((void*) &sr, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    copy_array_forward((void*) &si, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
    // Copy temporary source numerator value.
    copy_integer((void*) &tsn, sn);

    fwprintf(stdout, L"pre i: %d\n", *((double*) dn));
    fwprintf(stdout, L"pre o: %d\n", *((double*) dd));
    //fwprintf(stdout, L"pre t: %i\n", *((int*) tmd));
    
    
    // Add real-parts
//    calculate_double_add(dr, sr);

	//Add imaginary-parts
//	  calculate_double_add(di,si);

}

/* ADD_COMPLEX_CALCULATOR_SOURCE */
#endif
