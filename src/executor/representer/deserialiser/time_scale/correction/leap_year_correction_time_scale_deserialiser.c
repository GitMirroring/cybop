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

#ifndef LEAP_YEAR_CORRECTION_TIME_SCALE_DESERIALISER_SOURCE
#define LEAP_YEAR_CORRECTION_TIME_SCALE_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "logger.h"

/**
 * Deserialises the source calendar month into the destination leap year correction.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Julianischem_Kalender#Berechnung_des_laufenden_Tages
 *
 * @param p0 the destination leap year correction integer
 * @param p1 the source month integer
 */
void deserialise_time_scale_correction_leap_year(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale correction leap year.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater((void*) &r, p1, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        copy_integer(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    } else {

        copy_integer(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* LEAP_YEAR_CORRECTION_TIME_SCALE_DESERIALISER_SOURCE */
#endif
