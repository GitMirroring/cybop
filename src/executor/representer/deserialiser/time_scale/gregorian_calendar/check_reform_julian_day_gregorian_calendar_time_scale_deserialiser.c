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

#ifndef CHECK_REFORM_JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE
#define CHECK_REFORM_JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "logger.h"

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

    compare_integer_greater((void*) &y, p1, (void*) YEAR_GREGORIAN_CALENDAR_TIME_SCALE_MODEL);

    if (y != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The year is greater than 1582.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        compare_integer_equal((void*) &y, p1, (void*) YEAR_GREGORIAN_CALENDAR_TIME_SCALE_MODEL);

        if (y != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_greater((void*) &m, p2, (void*) MONTH_GREGORIAN_CALENDAR_TIME_SCALE_MODEL);

            if (m != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The year is 1582 and the month is greater than 10.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            } else {

                compare_integer_equal((void*) &m, p2, (void*) MONTH_GREGORIAN_CALENDAR_TIME_SCALE_MODEL);

                if (m != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    compare_integer_greater_or_equal((void*) &d, p3, (void*) DAY_GREGORIAN_CALENDAR_TIME_SCALE_MODEL);

                    if (d != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        // The year is 1582 and the month is 10 and the day is greater or equal to 15.
                        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }
                }
            }
        }
    }
}

/* CHECK_REFORM_JULIAN_DAY_GREGORIAN_CALENDAR_TIME_SCALE_DESERIALISER_SOURCE */
#endif
