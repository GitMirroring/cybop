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

#ifndef JULIAN_DATE_DESERIALISER_SOURCE
#define JULIAN_DATE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/datetime_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../../executor/accessor/getter/datetime_getter.c"
#include "../../../../executor/calculator/basic/double/floor_double_calculator.c"
#include "../../../../executor/calculator/basic/double/multiply_double_calculator.c"
#include "../../../../executor/calculator/basic/double/subtract_double_calculator.c"
#include "../../../../executor/caster/basic/integer/double_integer_caster.c"
#include "../../../../executor/modifier/copier/double_copier.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the julian date (jd) double into a datetime.
 *
 * @param p0 the destination data
 * @param p1 the source data
 */
void deserialise_julian_date(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise julian date.");

    // The destination julian day, julian second.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination julian day as double.
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get destination julian day, julian second.
    get_datetime_element((void*) &d, (void*) &p0, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &s, (void*) &p0, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    // Extract integer part of source julian date data,
    // by rounding downwards to the nearest integer.
    // The result, however, is of type "double".
    //
    // Example:
    // floor (1.5) is 1.0 and floor (-1.5) is -2.0
    calculate_double_floor((void*) &dd, p1);

    // Cast julian day into an integer number.
    cast_integer_double(d, (void*) &dd);

    // Initialise julian second with source julian date.
    copy_double(s, p1);
    // Extract fractional part of source, by
    // subtracting the julian day integer part.
    calculate_double_subtract(s, (void*) &dd);
    // Normalise fractional part of source
    // to duration of day in solar seconds.
    calculate_double_multiply(s, (void*) SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL);
}

/* JULIAN_DATE_DESERIALISER_SOURCE */
#endif
