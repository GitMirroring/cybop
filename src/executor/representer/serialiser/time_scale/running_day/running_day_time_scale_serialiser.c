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

#include "communication.h"
#include "logger.h"

/**
 * Serialises the source running day into the destination calendar month and day.
 *
 * CAUTION! This calculation MAY be used for both, the Julian AND Gregorian calendar.
 *
 * http://de.wikipedia.org/wiki/Umrechnung_zwischen_Julianischem_Datum_und_Julianischem_Kalender#Berechnung_des_laufenden_Tages
 *
 * @param p0 the destination month integer
 * @param p1 the destination day integer
 * @param p2 the source running day integer
 */
void serialise_time_scale_running_day(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise time scale running day.");

    // Calculate month.
    serialise_time_scale_running_day_month(p0, p2);
    // Calculate day.
    serialise_time_scale_running_day_day(p1, p0, p2);
}
