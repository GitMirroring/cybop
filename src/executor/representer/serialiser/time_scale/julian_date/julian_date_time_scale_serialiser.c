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
 * @version CYBOP 0.27.0 2023-08-31
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
 * Serialises the source datetime into the destination julian date (jd) double.
 *
 * @param p0 the destination double
 * @param p1 the source datetime
 */
void serialise_time_scale_julian_date(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale julian date.");

    // The source julian day, julian second.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The source julian day as double.
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get source julian day, julian second.
    get_datetime_element((void*) &d, p1, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &s, p1, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    //
    // Julian date.
    //

    // Cast julian day into a double number.
    cast_double_integer((void*) &dd, (void*) &d);

    // Initialise destination julian date.
    copy_double(p0, (void*) &s);
    // Denormalise fractional part
    // from duration of day in solar seconds.
    calculate_double_divide(p0, (void*) DAY_SOLAR_DURATION_TIME_SCALE_MODEL);
    // Add source julian day integer part.
    calculate_double_add(p0, (void*) &dd);
}
