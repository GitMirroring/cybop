/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the datetime into a gregorian calendar date.
 *
 * http://www.astro-toolbox.com/
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

    // The constants.
    int A_CONSTANT = 2299161;
    double B_CONSTANT = 24.0;
    double C_CONSTANT = 1867216.25;
    double E_CONSTANT = 122.1;
    int G_CONSTANT = 1524;
    double H_CONSTANT = 30.6001;
    int I_CONSTANT = 4715;
    int J_CONSTANT = 4716;
    double MINUTES_SECONDS_CONSTANT = 60.0;
    // The ?? a.
    int a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The ?? b.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The ?? c and ?? c as double.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double cd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The ?? d and ?? d as double.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The ?? e and ?? e as double.
    int e = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double ed = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The ?? z and ?? z as double.
    int z = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double zd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The temporary julian date.
    double jdt = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The ?? f and x.
    double f = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double x = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double y = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The ?? alfa.
    double alfa_double = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    int alfa = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int alfa_quarter = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Serialise datetime.
    serialise_time_scale_julian_date((void*) &jdt, p6);

    // Adjust begin of the day from noon to midnight.
    calculate_double_add((void*) &jdt, (void*) NUMBER_0_5_DOUBLE_STATE_CYBOI_MODEL);

    // Calculate ?? z.
    calculate_double_floor((void*) &zd, (void*) &jdt);
    cast_integer_double((void*) &z, (void*) &zd);

    // Calculate ?? f.
    copy_double((void*) &f, (void*) &jdt);
    cast_double_integer((void*) &zd, (void*) &z);
    calculate_double_subtract((void*) &f, (void*) &zd);
    calculate_double_multiply((void*) &f, (void*) &B_CONSTANT);

    compare_integer_less((void*) &r, (void*) &z, (void*) &A_CONSTANT);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Calculate ?? a.
        copy_integer((void*) &a, (void*) &z);

    } else {

        // Calculate ?? alfa.
        cast_double_integer((void*) &alfa_double, (void*) &z);
        calculate_double_subtract((void*) &alfa_double, (void*) &C_CONSTANT);
        calculate_double_divide((void*) &alfa_double, (void*) CENTURY_GREGORIAN_DURATION_TIME_SCALE_MODEL);
        calculate_double_floor((void*) &alfa_double, (void*) &alfa_double);
        cast_integer_double((void*) &alfa, (void*) &alfa_double);

        // Calculate ?? alfa quarter.
        copy_integer((void*) &alfa_quarter, (void*) &alfa);
        calculate_integer_divide((void*) &alfa_quarter, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

        // Calculate ?? a.
        copy_integer((void*) &a, (void*) &alfa);
        calculate_integer_add((void*) &a, (void*) &z);
        calculate_integer_add((void*) &a, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        calculate_integer_subtract((void*) &a, (void*) &alfa_quarter);
    }

    // Calculate ?? b.
    copy_integer((void*) &b, (void*) &a);
    calculate_integer_add((void*) &b, (void*) &G_CONSTANT);

    // Calculate ?? c.
    cast_double_integer((void*) &cd, (void*) &b);
    calculate_double_subtract((void*) &cd, (void*) &E_CONSTANT);
    calculate_double_divide((void*) &cd, (void*) YEAR_JULIAN_DURATION_TIME_SCALE_MODEL);
    calculate_double_floor((void*) &cd, (void*) &cd);
    cast_integer_double((void*) &c, (void*) &cd);

    // Calculate ?? d.
    cast_double_integer((void*) &dd, (void*) &c);
    calculate_double_multiply((void*) &dd, (void*) YEAR_JULIAN_DURATION_TIME_SCALE_MODEL);
    calculate_double_floor((void*) &dd, (void*) &dd);
    cast_integer_double((void*) &d, (void*) &dd);

    // Calculate ?? e.
    copy_integer((void*) &e, (void*) &b);
    calculate_integer_subtract((void*) &e, (void*) &d);
    cast_double_integer((void*) &ed, (void*) &e);
    calculate_double_divide((void*) &ed, (void*) &H_CONSTANT);
    calculate_double_floor((void*) &ed, (void*) &ed);
    cast_integer_double((void*) &e, (void*) &ed);

    // Calculate day.
    calculate_double_multiply((void*) &ed, (void*) &H_CONSTANT);
    calculate_double_floor((void*) &ed, (void*) &ed);
    cast_integer_double(p2, (void*) &ed);
    calculate_integer_negate(p2, p2);
    calculate_integer_add(p2, (void*) &b);
    calculate_integer_subtract(p2, (void*) &d);

    // Calculate month.
    copy_integer(p1, (void*) &e);

    // Reset comparison result.
    copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    compare_integer_less((void*) &r, (void*) &e, (void*) NUMBER_14_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_subtract(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    } else {

        calculate_integer_subtract(p1, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL);
    }

    // Calculate year.
    copy_integer(p0, (void*) &c);

    // Reset comparison result.
    copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    compare_integer_less((void*) &r, p1, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_subtract(p0, (void*) &I_CONSTANT);

    } else {

        calculate_integer_subtract(p0, (void*) &J_CONSTANT);
    }

    // Calculate hour.
    // Remember original value of ?? f for calculations below.
    copy_double((void*) &x, (void*) &f);
    calculate_double_floor((void*) &f, (void*) &f);
    cast_integer_double(p3, (void*) &f);

    // Calculate minute.
    cast_double_integer((void*) &y, p3);
    calculate_double_subtract((void*) &x, (void*) &y);
    calculate_double_multiply((void*) &x, (void*) &MINUTES_SECONDS_CONSTANT);
    calculate_double_floor((void*) &f, (void*) &x);
    cast_integer_double(p4, (void*) &f);

    // Calculate second.
    copy_double(p5, (void*) &x);
    cast_double_integer((void*) &y, p4);
    calculate_double_subtract(p5, (void*) &y);
    calculate_double_multiply(p5, (void*) &MINUTES_SECONDS_CONSTANT);
}
