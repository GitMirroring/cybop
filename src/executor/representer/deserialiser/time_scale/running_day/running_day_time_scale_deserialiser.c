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

#ifndef RUNNING_DAY_TIME_SCALE_DESERIALISER_SOURCE
#define RUNNING_DAY_TIME_SCALE_DESERIALISER_SOURCE

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the source calendar month and day into the destination running day.
 *
 * CAUTION! This calculation MAY be used for both, the Julian AND Gregorian calendar.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Julianischem_Kalender#Berechnung_des_laufenden_Tages
 *
 * @param p0 the destination running day integer
 * @param p1 the source year integer
 * @param p2 the source month integer
 * @param p3 the source day integer
 */
void deserialise_time_scale_running_day(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale running day.");

    // The leap year flag.
    int lf = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The leap year correction.
    int lc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The month correction.
    int mc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The running day.
    int rd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Determine if year is a leap year.
    deserialise_time_scale_correction_leap_year_detection((void*) &lf, p1);

    if (lf != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! If this block is NOT processed,
        // i.e. if this is NOT a leap year,
        // then the leap year correction value
        // keeps its initial value zero from above,
        // so that the addition below has NO effect.

        // Calculate leap year correction.
        deserialise_time_scale_correction_leap_year((void*) &lc, p2);
    }

    // Calculate month correction.
    deserialise_time_scale_correction_month((void*) &mc, p2);

    // Calculate running day.
    copy_integer((void*) &rd, p2);
    calculate_integer_subtract((void*) &rd, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_multiply((void*) &rd, (void*) NUMBER_30_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_add((void*) &rd, (void*) &lc);
    calculate_integer_add((void*) &rd, (void*) &mc);
    calculate_integer_add((void*) &rd, p3);

    // Copy running day to destination.
    copy_integer(p0, (void*) &rd);
}

/* RUNNING_DAY_TIME_SCALE_DESERIALISER_SOURCE */
#endif
