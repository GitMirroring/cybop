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

#ifndef MONTH_RUNNING_DAY_TIME_SCALE_SERIALISER_SOURCE
#define MONTH_RUNNING_DAY_TIME_SCALE_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../../executor/calculator/integer/divide_integer_calculator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Serialises the source calendar month and day into the destination running day.
 *
 * CAUTION! This calculation MAY be used for both, the Julian AND Gregorian calendar.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Julianischem_Kalender#Berechnung_des_laufenden_Tages
 *
 * @param p0 the destination month integer
 * @param p1 the source running day integer
 */
void serialise_time_scale_running_day_month(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale running day month.");

    // Calculate month.
    copy_integer(p0, p1);
    calculate_integer_add(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_divide(p0, (void*) NUMBER_31_INTEGER_STATE_CYBOI_MODEL);
}

/* MONTH_RUNNING_DAY_TIME_SCALE_SERIALISER_SOURCE */
#endif
