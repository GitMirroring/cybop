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

#ifndef JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE
#define JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/calculator/double/multiply_double_calculator.c"
#include "../../../../../executor/calculator/double/subtract_double_calculator.c"
#include "../../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../../executor/calculator/integer/divide_integer_calculator.c"
#include "../../../../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../../../executor/caster/double/integer_double_caster.c"
#include "../../../../../executor/caster/integer/double_integer_caster.c"
#include "../../../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "../../../../../executor/representer/deserialiser/time_scale/gregorian_calendar/check_reform_julian_day_gregorian_calendar_time_scale_deserialiser.c"
#include "logger.h"

/**
 * Deserialises the source year/month/day into the destination julian day.
 *
 * http://www.astro-toolbox.com/
 *
 * @param p0 the destination julian day integer
 * @param p1 the source year integer
 * @param p2 the source month integer
 * @param p3 the source day integer
 */
void deserialise_time_scale_gregorian_calendar_julian_day(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale gregorian calendar julian day.");

    //
    // The flag indicating whether or not the given date (year/month/day)
    // lies AFTER the Gregorian calendar reform.
    //
    int reform = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double cd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The constants.
    double X_CONSTANT = 0.75;
    double Y_CONSTANT = 30.6001;
    int Z_CONSTANT = 1720994;

    compare_integer_less((void*) &r, p2, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_subtract(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        calculate_integer_add(p2, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL);
    }

    deserialise_time_scale_gregorian_calendar_julian_day_check_reform((void*) &reform, p1, p2, p3);

    if (reform != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        copy_integer((void*) &a, p1);
        calculate_integer_divide((void*) &a, (void*) NUMBER_100_INTEGER_STATE_CYBOI_MODEL);

        copy_integer((void*) &c, (void*) &a);
        calculate_integer_divide((void*) &c, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

        copy_integer((void*) &b, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
        calculate_integer_subtract((void*) &b, (void*) &a);
        calculate_integer_add((void*) &b, (void*) &c);
    }

    // Initialise destination julian day.
    cast_double_integer((void*) &cd, p1);
    calculate_double_multiply((void*) &cd, (void*) YEAR_JULIAN_DURATION_TIME_SCALE_MODEL);

    // Reset comparison result.
    copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    compare_integer_less((void*) &r, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_double_subtract((void*) &cd, (void*) &X_CONSTANT);
    }

    cast_integer_double((void*) &c, (void*) &cd);

    copy_integer((void*) &d, p2);
    calculate_integer_add((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    cast_double_integer((void*) &dd, (void*) &d);
    calculate_double_multiply((void*) &dd, (void*) &Y_CONSTANT);
    cast_integer_double((void*) &d, (void*) &dd);

    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day a: %i\n", a);
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day c: %i\n", c);
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day b: %i\n", b);

    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day *p0: %i\n", *((int*) p0));
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day *p3: %i\n", *((int*) p3));
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day c: %i\n", c);
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day d: %i\n", d);
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day Z_CONSTANT: %i\n", Z_CONSTANT);

    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day *p0 0: %i\n", *((int*) p0));
    copy_integer(p0, p3);
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day *p0 1: %i\n", *((int*) p0));
    calculate_integer_add(p0, (void*) &c);
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day *p0 2: %i\n", *((int*) p0));
    calculate_integer_add(p0, (void*) &d);
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day *p0 3: %i\n", *((int*) p0));
    calculate_integer_add(p0, (void*) &Z_CONSTANT);
    fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day *p0 4: %i\n", *((int*) p0));

    if (reform != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_add(p0, (void*) &b);
        fwprintf(stdout, L"Debug: deserialise time scale gregorian calendar julian day *p0 5: %i\n", *((int*) p0));
    }
}

/* JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE */
#endif
