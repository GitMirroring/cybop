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
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/model/time_scale/duration_time_scale_model.c"
#include "../../../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../accessor/getter/datetime_getter.c"
#include "../../../../../calculator/basic/double/multiply_double_calculator.c"
#include "../../../../../calculator/basic/double/divide_double_calculator.c"
#include "../../../../../calculator/basic/integer/add_integer_calculator.c"
#include "../../../../../calculator/basic/integer/divide_integer_calculator.c"
#include "../../../../../caster/basic/double/integer_double_caster.c"
#include "../../../../../caster/basic/integer/double_integer_caster.c"
#include "../../../../../comparator/basic/double/smaller_double_comparator.c"
#include "../../../../../modifier/copier/double_copier.c"
#include "../../../../../modifier/copier/integer_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Normalises the datetime's seconds.
 *
 * @param p0 the julian day
 * @param p1 the julian second
 */
void deserialise_time_scale_gregorian_calendar_normalise(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale gregorian calendar normalise.");

    // The days over (as double and integer).
    double od = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    int oi = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The julian second left- and right side for comparison.
    double sl = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double sr = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Calculate days over.
    copy_double((void*) &od, p1);
    calculate_double_divide((void*) &od, (void*) DAY_SOLAR_DURATION_STATE_CYBOI_MODEL);
    cast_integer_double((void*) &oi, (void*) &od);

    compare_double_smaller((void*) &r, p1, (void*) NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_subtract((void*) &oi, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

    calculate_integer_add(p0, (void*) &oi);
    cast_double_integer((void*) &od, (void*) &oi);
    calculate_double_multiply((void*) &od, (void*) DAY_SOLAR_DURATION_STATE_CYBOI_MODEL);
    calculate_double_subtract(p1, (void*) &od);

    // Calculate left side of comparison.
    copy_double((void*) &sl, p1);
    calculate_double_subtract((void*) &sl, (void*) DAY_SOLAR_DURATION_STATE_CYBOI_MODEL);
    calculate_double_absolute((void*) &sl, (void*) &sl);
    // Calculate right side of comparison.
    copy_double((void*) &sr, (void*) NUMBER_10_0_DOUBLE_STATE_CYBOI_MODEL);
    calculate_double_multiply((void*) &sr, (void*) DAY_SOLAR_DURATION_STATE_CYBOI_MODEL);
    calculate_double_multiply((void*) &sr, (void*) EPSILON_DOUBLE_ASTRONOMY_TIME_SCALE_STATE_CYBOI_MODEL);
    // Reset comparison result.
    copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Compare left and right side.
    compare_double_smaller((void*) &r, (void*) &sl, (void*) &sr);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        copy_double(p1, (void*) NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL);
        calculate_integer_add(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/**
 * Checks whether or not the given date (year/month/day)
 * lies AFTER the Gregorian calendar reform.
 *
 * Optional representation:
 * result = (year > 1582) || ((year == 1582) && ((month > 10) || ((month == 10) && (day >= 15))));
 *
 * @param p0 the destination boolean
 * @param p1 the source year
 * @param p2 the source month
 * @param p3 the source day
 */
void deserialise_time_scale_gregorian_calendar_julian_day_check_reform(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale gregorian calendar julian day check reform.");

    // The year/month/day comparison result.
    int y = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int m = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int d = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater((void*) &y, p1, (void*) YEAR_GREGORIAN_CALENDAR_DATETIME_STATE_CYBOI_MODEL);

    if (y != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The year is greater than 1582.
        copy_boolean(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        compare_integer_equal((void*) &y, p1, (void*) YEAR_GREGORIAN_CALENDAR_DATETIME_STATE_CYBOI_MODEL);

        if (y != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_greater((void*) &m, p2, (void*) MONTH_GREGORIAN_CALENDAR_DATETIME_STATE_CYBOI_MODEL);

            if (m != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The year is 1582 and the month is greater than 10.
                copy_boolean(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            } else {

                compare_integer_equal((void*) &m, p2, (void*) MONTH_GREGORIAN_CALENDAR_DATETIME_STATE_CYBOI_MODEL);

                if (m != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    compare_integer_greater_or_equal((void*) &d, p3, (void*) DAY_GREGORIAN_CALENDAR_DATETIME_STATE_CYBOI_MODEL);

                    if (d != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        // The year is 1582 and the month is 10 and the day is greater or equal to 15.
                        copy_boolean(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }
                }
            }
        }
    }
}

/**
 * Deserialises the year/month/day into a julian day.
 *
 * @param p0 the destination julian day double
 * @param p1 the source year integer
 * @param p2 the source month integer
 * @param p3 the source day integer
 */
void deserialise_time_scale_gregorian_calendar_julian_day(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale gregorian calendar julian day.");

    // The flag indicating whether or not the given date (year/month/day)
    // lies AFTER the Gregorian calendar reform.
    int reform = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_smaller((void*) &r, p2, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_subtract(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        calculate_integer_add(p2, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL);
    }

    deserialise_time_scale_gregorian_calendar_julian_day_check_reform((void*) reform, p1, p2, p3);

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
    cast_double_integer(p0, p1);
    calculate_double_multiply(p0, (void*) 365.25);

    // Reset comparison result.
    copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    compare_integer_smaller((void*) &r, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_double_subtract(p0, (void*) 0.75);
    }

    cast_integer_double((void*) &c, p0);

    copy_integer((void*) &d, p2);
    calculate_integer_add((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    cast_double_integer((void*) &dd, (void*) &d);
    calculate_integer_multiply((void*) &dd, (void*) 30.6001);
    cast_integer_double((void*) &d, (void*) &dd);

    copy_integer(p0, p3);
    calculate_integer_add(p0, (void*) &c);
    calculate_integer_add(p0, (void*) &d);
    calculate_integer_add(p0, (void*) 1720994);

    if (reform != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_add(p0, (void*) &b);
    }
}

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
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The julian second as integer.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise hour/minute/second part.
    copy_integer((void*) &h, p1);
    copy_integer((void*) &m, p2);
    copy_integer((void*) &s, p3);

    // Calculate hour/minute/second part.
    calculate_double_multiply((void*) &h, HOUR_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_double_multiply((void*) &m, MINUTE_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_double_multiply((void*) &s, SECOND_SOLAR_DURATION_TIME_SCALE_MODEL);

    // Calculate destination julian second.
    copy_integer((void*) &i, (void*) DAY_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_integer_divide((void*) &i, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_add((void*) &i, (void*) &h);
    calculate_integer_add((void*) &i, (void*) &m);
    calculate_integer_add((void*) &i, (void*) &s);

    // Copy result to destination julian second.
    cast_double_integer(p0, (void*) &i);
}

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
    deserialise_time_scale_gregorian_calendar_julian_second(s, hour, minute, second);
    deserialise_time_scale_gregorian_calendar_normalise(d, s);
}

/* GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE */
#endif
