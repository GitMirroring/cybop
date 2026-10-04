/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "logger.h"

/**
 * Serialises the datetime model into international atomic time (tai).
 *
 * TAI is an integer number indicating SI-seconds.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_datetime_tai(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise datetime tai.");

/*??
    // The conversion difference datetime.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source julian day, julian second.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate conversion difference datetime.
    allocate_datetime((void*) &d);

    // Get source julian day, julian second.
    get_datetime_element((void*) &dd, (void*) &p1, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &ds, (void*) &p1, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    // Initialise source julian day, julian second.
    copy_integer((void*) &dd, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    //?? TODO: EopData pd; pd.tai_utc; see "AstroToolbox/data/tai_utc.txt"
    copy_double((void*) &ds, ??TODO: pd.tai_utc);

    //
    // Normalise conversion difference datetime.
    //
    // CAUTION! DO CALL "normalise" after having set
    // the values for julian day and julian second!
    //
    normalize(d);

    // Subtract conversion difference datetime from source.
    DESTjulianDay = SOURCEjulianDay - d.julianDay;
    DESTjulianSecond = SOURCEjulianSecond - d.julianSecond;
    normalize(DEST);

    // Deallocate conversion difference datetime.
    deallocate_datetime((void*) &d);
*/
}
