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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef JULIAN_DATE_TIME_SCALE_DESERIALISER_SOURCE
#define JULIAN_DATE_TIME_SCALE_DESERIALISER_SOURCE

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the source julian date (jd) double into the destination datetime.
 *
 * @param p0 the destination datetime
 * @param p1 the source double
 */
void deserialise_time_scale_julian_date(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale julian date.");

    // The destination julian day, julian second.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The destination julian day as double.
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    //
    // Julian day.
    //

    // Extract integer part of source julian date data,
    // by rounding downwards to the nearest integer.
    // The result, however, is of type "double".
    //
    // Example:
    // floor (1.5) is 1.0 and floor (-1.5) is -2.0
    calculate_double_floor((void*) &dd, p1);

    // Cast julian day into an integer number.
    cast_integer_double((void*) &d, (void*) &dd);

    //
    // Julian second.
    //

    // Initialise julian second with source julian date.
    copy_double((void*) &s, p1);
    // Extract fractional part of source, by
    // subtracting the julian day integer part.
    calculate_double_subtract((void*) &s, (void*) &dd);
    // Normalise fractional part of source
    // to duration of day in solar seconds.
    calculate_double_multiply((void*) &s, (void*) DAY_SOLAR_DURATION_TIME_SCALE_MODEL);

    // Set destination julian day, julian second.
    set_datetime_element(p0, (void*) &d, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    set_datetime_element(p0, (void*) &s, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);
}

/* JULIAN_DATE_TIME_SCALE_DESERIALISER_SOURCE */
#endif
