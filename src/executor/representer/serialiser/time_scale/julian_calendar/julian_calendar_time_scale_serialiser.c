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

#ifndef JULIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE
#define JULIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/accessor/setter/datetime_setter.c"
/*??
#include "../../../../../executor/representer/deserialiser/time_scale/julian_calendar/julian_day_julian_calendar_time_scale_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/time_scale/julian_calendar/julian_second_julian_calendar_time_scale_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/time_scale/julian_calendar/normalise_julian_calendar_time_scale_deserialiser.c"
*/
#include "../../../../../logger/logger.c"

/**
 * Serialises the source datetime into the destination julian calendar date.
 *
 * @param p0 the source year integer
 * @param p1 the source month integer
 * @param p2 the source day integer
 * @param p3 the source hour integer
 * @param p4 the source minute integer
 * @param p5 the source second double
 * @param p6 the destination datetime
 */
void serialise_time_scale_julian_calendar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale julian calendar.");

/*??
    // The destination julian day, julian second.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Deserialise source julian calendar date into datetime.
    deserialise_time_scale_julian_calendar_julian_day((void*) &d, p1, p2, p3);
    deserialise_time_scale_julian_calendar_julian_second((void*) &s, p4, p5, p6);
    deserialise_time_scale_julian_calendar_normalise((void*) &d, (void*) &s);

    fwprintf(stdout, L"Debug: deserialise time scale julian calendar d: %i\n", d);

    // Set destination julian day, julian second.
    set_datetime_element(p0, (void*) &d, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    set_datetime_element(p0, (void*) &s, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);
*/
}

/* JULIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE */
#endif
