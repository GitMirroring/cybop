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

#ifndef FRACTION_COPIER_SOURCE
#define FRACTION_COPIER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/accessor/getter/fraction_getter.c"
#include "../../executor/accessor/setter/fraction_setter.c"
#include "logger.h"

/**
 * Copies the fraction.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_fraction(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy fraction.");

    // The source numerator, denominator.
    int sn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int sd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get source numerator, denominator.
    get_fraction_element((void*) &sn, p1, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &sd, p1, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // Copy source numerator, denominator to destination.
    set_fraction_element(p0, (void*) &sn, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    set_fraction_element(p0, (void*) &sd, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
}

/* FRACTION_COPIER_SOURCE */
#endif
