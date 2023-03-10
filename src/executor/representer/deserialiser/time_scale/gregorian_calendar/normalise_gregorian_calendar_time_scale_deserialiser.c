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

#ifndef NORMALISE_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE
#define NORMALISE_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/calculator/double/absolute_double_calculator.c"
#include "../../../../../executor/calculator/double/divide_double_calculator.c"
#include "../../../../../executor/calculator/double/multiply_double_calculator.c"
#include "../../../../../executor/calculator/double/subtract_double_calculator.c"
#include "../../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../../../executor/caster/double/integer_double_caster.c"
#include "../../../../../executor/caster/integer/double_integer_caster.c"
#include "../../../../../executor/comparator/double/less_double_comparator.c"
#include "../../../../../executor/copier/double_copier.c"
#include "../../../../../executor/copier/integer_copier.c"
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
    calculate_double_divide((void*) &od, (void*) DAY_SOLAR_DURATION_TIME_SCALE_MODEL);
    cast_integer_double((void*) &oi, (void*) &od);

    compare_double_less((void*) &r, p1, (void*) NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_subtract((void*) &oi, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

    calculate_integer_add(p0, (void*) &oi);
    cast_double_integer((void*) &od, (void*) &oi);
    calculate_double_multiply((void*) &od, (void*) DAY_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_double_subtract(p1, (void*) &od);

    // Calculate left side of comparison.
    copy_double((void*) &sl, p1);
    calculate_double_subtract((void*) &sl, (void*) DAY_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_double_absolute((void*) &sl, (void*) &sl);
    // Calculate right side of comparison.
    copy_double((void*) &sr, (void*) NUMBER_10_0_DOUBLE_STATE_CYBOI_MODEL);
    calculate_double_multiply((void*) &sr, (void*) DAY_SOLAR_DURATION_TIME_SCALE_MODEL);
    calculate_double_multiply((void*) &sr, (void*) EPSILON_DOUBLE_ASTRONOMY_TIME_SCALE_MODEL);
    // Reset comparison result.
    copy_integer((void*) &r, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Compare left and right side.
    compare_double_less((void*) &r, (void*) &sl, (void*) &sr);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        copy_double(p1, (void*) NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL);
        calculate_integer_add(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* NORMALISE_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE */
#endif
