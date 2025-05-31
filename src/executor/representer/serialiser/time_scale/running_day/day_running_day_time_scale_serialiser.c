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
 * Serialises the source running day into the destination calendar day.
 *
 * CAUTION! This calculation MAY be used for both, the Julian AND Gregorian calendar.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Julianischem_Kalender#Berechnung_des_laufenden_Tages
 *
 * @param p0 the destination day integer
 * @param p1 the source month integer (which might get corrected and thus become a destination)
 * @param p2 the source running day integer
 */
void serialise_time_scale_running_day_day(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale running day day.");

    // The leap year correction.
    int lc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The month correction.
    int mc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The month comparison result.
    int rm = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The day comparison result.
    int rd = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Calculate leap year correction.
    deserialise_time_scale_correction_leap_year((void*) &lc, p1);
    // Calculate month correction.
    deserialise_time_scale_correction_month((void*) &mc, p1);

    // Calculate day.
    copy_integer(p0, p1);
    calculate_integer_subtract(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_multiply(p0, (void*) NUMBER_30_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_negate(p0, p0);
    calculate_integer_add(p0, p2);
    calculate_integer_subtract(p0, (void*) &lc);
    calculate_integer_subtract(p0, (void*) &mc);

    // Detect wrong month value (month == 13) OR (day < 1).
    // CAUTION! For some values of running day,
    // the formula delivers a too big month value.
    compare_integer_greater((void*) &rm, p1, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL);
    compare_integer_less((void*) &rd, p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if ((rm != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (rd != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

        // Correct wrong month value.
        calculate_integer_subtract(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        // Recalculate day by calling this function recursively.
        serialise_time_scale_running_day_day(p0, p1, p2);
    }
}
