/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Deserialises the hour/minute/second into a julian second.
 *
 * @param p0 the destination julian second
 * @param p1 the source hour
 * @param p2 the source minute
 * @param p3 the source second
 */
void deserialise_time_scale_gregorian_calendar_julian_second(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale gregorian calendar julian second.");

    // The hour/minute/second part.
    double h = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double m = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Initialise hour/minute/second part.
    cast_double_integer((void*) &h, p1);
    cast_double_integer((void*) &m, p2);
    copy_double((void*) &s, p3);

    // Calculate hour/minute/second part.
    calculate_double_multiply((void*) &h, (void*) HOUR_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_double_multiply((void*) &m, (void*) MINUTE_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_double_multiply((void*) &s, (void*) SECOND_SOLAR_DURATION_TIME_SCALE_MODEL);

    // Calculate destination julian second.
    cast_double_integer(p0, (void*) DAY_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_double_divide(p0, (void*) NUMBER_2_0_DOUBLE_STATE_CYBOI_MODEL);
    calculate_double_add(p0, (void*) &h);
    calculate_double_add(p0, (void*) &m);
    calculate_double_add(p0, (void*) &s);
}
