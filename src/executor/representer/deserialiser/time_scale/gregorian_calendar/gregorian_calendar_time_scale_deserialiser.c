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

#ifndef GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE
#define GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../../../executor/accessor/getter/datetime_getter.c"
#include "../../../../../executor/representer/deserialiser/time_scale/gregorian_calendar/julian_day_gregorian_calendar_time_scale_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/time_scale/gregorian_calendar/julian_second_gregorian_calendar_time_scale_deserialiser.c"
#include "../../../../../executor/representer/deserialiser/time_scale/gregorian_calendar/normalise_gregorian_calendar_time_scale_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the gregorian calendar date into a datetime.
 *
 * @param p0 the destination datetime
 * @param p1 the source year integer
 * @param p2 the source month integer
 * @param p3 the source day integer
 * @param p4 the source hour integer
 * @param p5 the source minute integer
 * @param p6 the source second double
 */
void deserialise_time_scale_gregorian_calendar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale gregorian calendar.");

    // The destination julian day, julian second.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination julian day, julian second.
    get_datetime_element((void*) &d, (void*) &p0, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &s, (void*) &p0, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    // Deserialise source gregorian calendar date into datetime.
    deserialise_time_scale_gregorian_calendar_julian_day(d, p1, p2, p3);
    deserialise_time_scale_gregorian_calendar_julian_second(s, p4, p5, p6);
    deserialise_time_scale_gregorian_calendar_normalise(d, s);
}

/* GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE */
#endif
