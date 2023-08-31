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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Serialises the source julian date into the destination weekday.
 *
 * CAUTION! This calculation MAY be used for both, the Julian AND Gregorian calendar.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Gregorianischem_Kalender
 *
 * The calculated number corresponds to the following weekdays:
 *
 * 0 = Sunday
 * 1 = Monday
 * 2 = Tuesday
 * 3 = Wednesday
 * 4 = Thursday
 * 5 = Friday
 * 6 = Saturday
 *
 * CAUTION! It is NOT the task of cyboi to translate strings into any language.
 * This has to be done in cybol, e.g. by special localisation libraries.
 *
 * @param p0 the destination weekday integer
 * @param p1 the source datetime
 */
void serialise_time_scale_weekday(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale weekday.");

    // The julian date.
    double d = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Serialise datetime into julian date.
    serialise_time_scale_julian_date((void*) &d, p1);

    // Add day correction.
    calculate_double_add((void*) &d, (void*) DAY_CORRECTION_WEEK_TIME_SCALE_MODEL);

    // Convert julian date double into weekday integer.
    cast_integer_double(p0, (void*) &d);

    // Divide by day count in order to determine modulo.
    calculate_integer_modulo(p0, (void*) DAY_COUNT_WEEK_TIME_SCALE_MODEL);
}
