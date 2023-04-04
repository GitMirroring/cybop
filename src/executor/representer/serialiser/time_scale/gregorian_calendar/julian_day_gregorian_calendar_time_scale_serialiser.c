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

#ifndef JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE
#define JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the source julian day into the destination year/month/day.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Gregorianischem_Kalender
 *
 * @param p0 the destination year integer
 * @param p1 the destination month integer
 * @param p2 the destination day integer
 * @param p3 the source julian day integer
 */
void serialise_time_scale_gregorian_calendar_julian_day(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale gregorian calendar julian day.");

    // The full 400-year-cycles since the first year.
    int n400 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The number of full 100-year-cycles of the last 400-year-cycle.
    int n100 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The number of full 4-year-cycles of the last 100-year-cycle.
    int n4 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The number of full years in the last, incomplete 4-year-cycle.
    int n1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The number of full 100-year-cycles in the last, incomplete 400-year-cycle.
    int r400 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The number of full 4-year-cycles in the last, incomplete 100-year-cycle.
    int r100 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The number of full years in the last, incomplete 4-year-cycle.
    int r4 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The running day.
    int rd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The running year.
    int ry = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The overall 400-year-cycles.
    int o400 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The overall 100-year-cycles.
    int o100 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The overall 4-year-cycles.
    int o4 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The overall years.
    int o1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise with source julian day.
    copy_integer((void*) &n400, p3);
    copy_integer((void*) &r400, p3);

    // Subtract JD0.
    calculate_integer_subtract((void*) &n400, (void*) DAY_0_JULIAN_DATE_TIME_SCALE_MODEL);
    calculate_integer_subtract((void*) &r400, (void*) DAY_0_JULIAN_DATE_TIME_SCALE_MODEL);

    // Divide by 400-year-cycle.
    calculate_integer_divide((void*) &n400, (void*) CYCLE_400_DAY_CALENDAR_TIME_SCALE_MODEL);
    // Determine remainder of division by 400-year-cycle.
    calculate_integer_modulo((void*) &r400, (void*) CYCLE_400_DAY_CALENDAR_TIME_SCALE_MODEL);

    // Initialise with 400-year-cycle remainder.
    copy_integer((void*) &n100, (void*) &r400);
    copy_integer((void*) &r100, (void*) &r400);

    // Divide by 100-year-cycle.
    calculate_integer_divide((void*) &n100, (void*) CYCLE_100_DAY_CALENDAR_TIME_SCALE_MODEL);
    // Determine remainder of division by 100-year-cycle.
    calculate_integer_modulo((void*) &r100, (void*) CYCLE_100_DAY_CALENDAR_TIME_SCALE_MODEL);

    // Correct values.
    serialise_time_scale_gregorian_calendar_correction((void*) &n100, (void*) &r100, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) CYCLE_100_DAY_CALENDAR_TIME_SCALE_MODEL);

    // Initialise with 100-year-cycle remainder.
    copy_integer((void*) &n4, (void*) &r100);
    copy_integer((void*) &r4, (void*) &r100);

    // Divide by 4-year-cycle.
    calculate_integer_divide((void*) &n4, (void*) CYCLE_4_DAY_CALENDAR_TIME_SCALE_MODEL);
    // Determine remainder of division by 4-year-cycle.
    calculate_integer_modulo((void*) &r4, (void*) CYCLE_4_DAY_CALENDAR_TIME_SCALE_MODEL);

    // Initialise with 4-year-cycle remainder.
    copy_integer((void*) &n1, (void*) &r4);
    copy_integer((void*) &rd, (void*) &r4);

    // Divide by 1-year-cycle.
    calculate_integer_divide((void*) &n1, (void*) CYCLE_1_DAY_CALENDAR_TIME_SCALE_MODEL);
    // Determine remainder of division by 1-year-cycle.
    calculate_integer_modulo((void*) &rd, (void*) CYCLE_1_DAY_CALENDAR_TIME_SCALE_MODEL);

    // Correct values.
    serialise_time_scale_gregorian_calendar_correction((void*) &n1, (void*) &rd, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) CYCLE_1_DAY_CALENDAR_TIME_SCALE_MODEL);

    // Initialise full cycles.
    copy_integer((void*) &o400, (void*) &n400);
    copy_integer((void*) &o100, (void*) &n100);
    copy_integer((void*) &o4, (void*) &n4);
    copy_integer((void*) &o1, (void*) &n1);

    // Calculate full cycles.
    calculate_integer_multiply((void*) &o400, (void*) CYCLE_400_YEAR_CALENDAR_TIME_SCALE_MODEL);
    calculate_integer_multiply((void*) &o100, (void*) CYCLE_100_YEAR_CALENDAR_TIME_SCALE_MODEL);
    calculate_integer_multiply((void*) &o4, (void*) CYCLE_4_YEAR_CALENDAR_TIME_SCALE_MODEL);
    calculate_integer_multiply((void*) &o1, (void*) CYCLE_1_YEAR_CALENDAR_TIME_SCALE_MODEL);

    // Calculate running year.
    calculate_integer_add((void*) &ry, (void*) &o400);
    calculate_integer_add((void*) &ry, (void*) &o100);
    calculate_integer_add((void*) &ry, (void*) &o4);
    calculate_integer_add((void*) &ry, (void*) &o1);

    // Initialise year.
    copy_integer(p0, (void*) &ry);

    // Calculate year.
    calculate_integer_add(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Calculate month and day from running day.
    serialise_time_scale_running_day(p1, p2, (void*) &rd);
}

/* JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE */
#endif
