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

#ifndef GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE
#define GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/datetime_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../logger/logger.c"

/**
 * Serialises the datetime into a gregorian calendar date.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_time_scale_gregorian_calendar(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale gregorian calendar.");

/*??
    // Julian Date ---> Calendar Date
    private void civildate() {

        double f, x, jdt;
        int alfa, a, b, c, d, e, z;

        //?? TODO: Replace "Java::julianDate()" call with:
        //?? cyboi::serialise_julian_date(double dest, datetime src)
        jdt = julianDate() + 0.5;
        z = (int) Math.floor(jdt);

        f = jdt - z;
        f = f * 24.0;

        if (z < 2299161) {

            a = z;

        } else {

            alfa = (int) Math.floor(((z - 1867216.25) / 36524.25));
            a = z + 1 + alfa - alfa / 4;
        }

        b = a + 1524;
        c = (int) Math.floor((b - 122.1) / 365.25);
        d = (int) Math.floor((365.25 * c));
        e = (int) Math.floor(((b - d) / 30.6001));

        this.day = (int) (b - d - (int) Math.floor((30.6001 * e)));

        if (e < 14) {

            this.month = (int) (e - 1);

        } else {

            this.month = (int) (e - 13);
        }

        if (month < 3) {

            this.year = c - 4715;

        } else {

            this.year = c - 4716;
        }

        x = f;
        this.hour = (int) Math.floor(x);
        x = x - hour;
        x = x * 60.0;

        this.minute = (int) Math.floor(x);
        x = x - minute;
        this.second = x * 60.0;
    }
*/
}

/* GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE */
#endif
