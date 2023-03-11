/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COMPLEX_COPIER_SOURCE
#define COMPLEX_COPIER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/accessor/getter/complex_getter.c"
#include "../../executor/accessor/setter/complex_setter.c"
#include "logger.h"

/**
 * Copies the complex.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_complex(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy complex.");

    // The source real, imaginary.
    double r = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double i = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get source real, imaginary.
    get_complex_element((void*) &r, p1, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &i, p1, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    // Copy source real, imaginary to destination.
    set_complex_element(p0, (void*) &r, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    set_complex_element(p0, (void*) &i, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
}

/* COMPLEX_COPIER_SOURCE */
#endif
