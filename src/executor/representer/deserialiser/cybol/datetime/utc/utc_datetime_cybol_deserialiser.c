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

#ifndef UTC_DATETIME_CYBOL_DESERIALISER_SOURCE
#define UTC_DATETIME_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../logger/logger.c"
#include "../../../../../../variable/type_size/integral_type_size.c"
#include "../../../../../../variable/reallocation_factor.c"

/**
 * Deserialises the utc date wide character data into a datetime model.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_datetime_utc(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol datetime utc.");

/*??
    // Calendar Date ---> Julian Date
    public int julianDay(int year, int month, int day) {

        boolean reform;
        int a, b = 0, c, d;
        double x1;
        int xj;

        if (month < 3) {

            year--;
            month += 12;
        }

        reform = (year == 1582) && ((month == 10) && (day >= 15) || (month > 10)) || (year > 1582);

        if (reform) {

            a = year / 100;
            c = a / 4;
            b = 2 - a + c;
        }

        x1 = 365.25 * year;

        if (year < 0) {

            x1 -= 0.75;
        }

        c = (int) (x1);
        d = (int) (30.6001 * (month + 1));
        xj = c + d + day + 1720994;

        if (reform) {

            xj = xj + b;
        }

        return xj;
    }

    public void normalize(JulianTime dt) {

        int dayover = (int) (dt.julianSecond / *SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL);

        if (dt.julianSecond < 0.0) {

            dayover--;
        }

        dt.julianDay = dt.julianDay + dayover;
        dt.julianSecond = dt.julianSecond - (dayover * *SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL);

        if (Math.abs(dt.julianSecond - *SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL) < (10.0 * *SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL * *EPSILON_DOUBLE_DATETIME_STATE_CYBOI_MODEL)) {

            dt.julianSecond = 0.0;
            (dt.julianDay)++;
        }
    }

    public void setDmyHms(int day, int month, int year, int hour, int minute, double second) {

        julianDay = julianDay(year, month, day);
        julianSecond = hour * 3600.0 + minute * 60.0 + second;
        julianSecond = julianSecond + (*SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL / 2);

        normalize();
    }
*/
}

/* UTC_DATETIME_CYBOL_DESERIALISER_SOURCE */
#endif
