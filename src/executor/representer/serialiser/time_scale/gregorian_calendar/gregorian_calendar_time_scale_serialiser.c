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

#ifndef GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE
#define GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the datetime into a gregorian calendar date.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Gregorianischem_Kalender
 *
 * @param p0 the destination year integer
 * @param p1 the destination month integer
 * @param p2 the destination day integer
 * @param p3 the destination hour integer
 * @param p4 the destination minute integer
 * @param p5 the destination second double
 * @param p6 the source datetime
 */
void serialise_time_scale_gregorian_calendar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale gregorian calendar.");

    // The destination julian day, julian second.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get destination julian day, julian second.
    get_datetime_element((void*) &d, p6, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &s, p6, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    // Serialise source datetime into gregorian calendar date.
    //
    // An alternative algorith may be found here:
    // http://www.astro-toolbox.com/
    //
    // It was implemented in the file:
    // "ALTERNATIVE_julian_day_gregorian_calendar_time_scale_serialiser.c"
    serialise_time_scale_gregorian_calendar_julian_day(p0, p1, p2, (void*) &d);
    serialise_time_scale_gregorian_calendar_julian_second(p3, p4, p5, (void*) &s);
}

/* GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE */
#endif
