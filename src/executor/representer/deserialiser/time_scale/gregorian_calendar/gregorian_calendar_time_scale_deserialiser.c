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

#ifndef GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE
#define GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the source gregorian calendar date into the destination datetime.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Gregorianischem_Kalender
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
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    //
    // Deserialise source gregorian calendar date into datetime.
    //
    // An alternative algorith may be found here:
    // http://www.astro-toolbox.com/
    //
    // It was implemented in the file:
    // "ALTERNATIVE_julian_day_gregorian_calendar_time_scale_deserialiser.c"
    //
    deserialise_time_scale_gregorian_calendar_julian_day((void*) &d, p1, p2, p3);
    deserialise_time_scale_gregorian_calendar_julian_second((void*) &s, p4, p5, p6);

    //?? fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar d: %i\n", d);
    //?? fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar s: %f\n", s);

    //?? TODO: Normalisation has not been tested in detail yet!
    deserialise_time_scale_gregorian_calendar_normalise((void*) &d, (void*) &s);

    //?? fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar normalised d: %i\n", d);
    //?? fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar normalised s: %f\n", s);

    // Set destination julian day, julian second.
    set_datetime_element(p0, (void*) &d, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    set_datetime_element(p0, (void*) &s, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);
}

/* GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE */
#endif
