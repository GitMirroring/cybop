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

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/accessor/getter/complex_getter.c"
#include "../../../../executor/accessor/setter/complex_setter.c"
#include "../../../../executor/calculator/basic/double/add_double_calculator.c"
#include "../../../../logger/logger.c"

/**
 * Adds the source complex number to the destination complex number.
 *
 * @param p0 the destination complex number
 * @param p1 the source complex number
 */
void calculate_complex_add(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate complex add.");

    // The destination real and imaginary.
    double dr = *NUMBER_0_7_DOUBLE_STATE_CYBOI_MODEL;
    double di = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The source real and imaginary.
    double sr = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double si = *NUMBER_0_8_DOUBLE_STATE_CYBOI_MODEL;

    // Get destination real and imaginary.
    get_complex_element((void*) &dr, (void*) p0, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &di, (void*) p0, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
    // Get source real and imaginary.
    get_complex_element((void*) &sr, (void*) p1, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &si, (void*) p1, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

fwprintf(stdout, L"pre dr: %f\n", dr);
fwprintf(stdout, L"pre di: %f\n", di);
fwprintf(stdout, L"pre sr: %f\n", sr);
fwprintf(stdout, L"pre si: %f\n", si);

    // Add real value.
    calculate_double_add((void*) &dr, (void*) &sr);

    // Add imaginary value.
    calculate_double_add((void*) &di, (void*) &si);

fwprintf(stdout, L"post dr: %f\n", dr);
fwprintf(stdout, L"post di: %f\n", di);

    // Set destination real and imaginary
    // (just copies the values inside).
    set_complex_element((void*) p0, (void*) &dr, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    set_complex_element((void*) p0, (void*) &di, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
}

/* ADD_COMPLEX_CALCULATOR_SOURCE */
#endif
