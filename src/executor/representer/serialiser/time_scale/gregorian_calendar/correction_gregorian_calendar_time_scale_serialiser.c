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

#ifndef CORRECTION_GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE
#define CORRECTION_GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "logger.h"

/**
 * Corrects the given cycle and element.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Gregorianischem_Kalender
 *
 * @param p0 the source cycle (which may become a destination, if to be corrected)
 * @param p1 the source element (which may become a destination, if to be corrected)
 * @param p2 the first correction value
 * @param p3 the second correction value
 */
void serialise_time_scale_gregorian_calendar_correction(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale gregorian calendar correction.");

    // The cycle comparison result.
    int rc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The element comparison result.
    int re = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Compare if this is the LAST element within the cycle.
    compare_integer_equal((void*) &rc, p0, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);
    compare_integer_equal((void*) &re, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if ((rc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) && (re != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

        // Correct values.
        copy_integer(p0, p2);
        copy_integer(p1, p3);
    }
}

/* CORRECTION_GREGORIAN_CALENDAR_TIME_SCALE_SERIALISER_SOURCE */
#endif
