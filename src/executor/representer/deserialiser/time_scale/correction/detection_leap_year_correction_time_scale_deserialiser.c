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

#ifndef DETECTION_LEAP_YEAR_CORRECTION_TIME_SCALE_DESERIALISER_SOURCE
#define DETECTION_LEAP_YEAR_CORRECTION_TIME_SCALE_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/calculator/integer/modulo_integer_calculator.c"
#include "../../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "../../../../../logger/logger.c"

/**
 * Detects whether or not the source year is a leap year and sets the destination flag accordingly.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Julianischem_Kalender
 *
 * @param p0 the destination leap year flag
 * @param p1 the source year integer
 */
void deserialise_time_scale_correction_leap_year_detection(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise time scale correction leap year detection.");

    // The remainder.
    int rem = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise remainder.
    copy_integer((void*) &rem, p1);

    // Calculate remainder.
    calculate_integer_modulo((void*) &rem, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

    // Find out if before or after the Common/Christian/Current era (BCE).
    // CAUTION! The year 1 is assumed to be the first year of BCE.
    compare_integer_greater_or_equal((void*) &r, p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The year DOES belong to the Common/Christian/Current era (BCE),
        // i.e. it lies WITHIN BCE.

        compare_integer_equal(p0, (void*) &rem, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    } else {

        // The year does NOT belong to the Common/Christian/Current era (BCE),
        // i.e. it lies BEFORE BCE.

        compare_integer_equal(p0, (void*) &rem, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* DETECTION_LEAP_YEAR_CORRECTION_TIME_SCALE_DESERIALISER_SOURCE */
#endif
