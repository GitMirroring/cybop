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

#ifndef BASIC_JD_DATETIME_SERIALISER_SOURCE
#define BASIC_JD_DATETIME_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/calculator/double/subtract_double_calculator.c"
#include "../../../../../executor/representer/serialiser/numeral/decimal_fraction_numeral_serialiser.c"
#include "../../../../../executor/representer/serialiser/time_scale/julian_date/julian_date_time_scale_serialiser.c"
#include "logger.h"

/**
 * Serialises the source datetime into destination jd/mjd/tjd wide character data.
 *
 * @param p0 the destination wide character item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the jd/mjd/tjd correction
 */
void serialise_datetime_jd_basic(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise datetime jd basic.");

    // The temporary julian date.
    double d = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Serialise datetime.
    serialise_time_scale_julian_date((void*) &d, p1);

    // Subtract jd/mjd/tjd correction.
    calculate_double_subtract((void*) &d, p3);

    // Assign resulting temporary julian date to destination.
    serialise_numeral_fraction_decimal(p0, (void*) &d, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DECIMAL_BASE_NUMERAL_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
}

/* BASIC_JD_DATETIME_SERIALISER_SOURCE */
#endif
