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

#ifndef UTC_DATETIME_CYBOL_SERIALISER_SOURCE
#define UTC_DATETIME_CYBOL_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/datetime_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/memoriser/allocator/datetime_allocator.c"
#include "../../../../../../executor/memoriser/deallocator/datetime_deallocator.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the datetime model into utc.
 *
 * UTC is ...
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_cybol_datetime_utc(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol datetime utc.");

    // The conversion difference datetime.
    void* dt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The julian day.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The julian second.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate conversion difference datetime.
    allocate_datetime((void*) &dt);

    // Get julian day, julian second.
    copy_array_forward((void*) &d, dt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    copy_array_forward((void*) &s, dt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

/*??
    // Initialise julian day, julian second.
    overwrite_array(d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    //?? TODO: EopData pd; pd.tai_utc
    overwrite_array(s, ??TODO: pd.tai_utc, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // CAUTION! DO CALL "normalise" after having set
    // the values for julian day and julian second!
    normalize(dt);

    // Subtract conversion difference datetime from source.
    DESTjulianDay = SOURCEjulianDay - dt.julianDay;
    DESTjulianSecond = SOURCEjulianSecond - dt.julianSecond;
    normalize(DEST);
*/

    // Deallocate conversion difference datetime.
    deallocate_datetime((void*) &d);

//?? ----------

/*??
    public void normalize() {

        int dayover = (int) (julianSecond / *SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL);

        if (julianSecond < 0.0) {

            dayover--;
        }

        julianDay = julianDay + dayover;

        julianSecond = julianSecond - (dayover * *SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL);

        if (Math.abs(julianSecond - *SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL) < (10.0 * *SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL * *EPSILON_DOUBLE_DATETIME_STATE_CYBOI_MODEL)) {

            julianSecond = 0.0;
            julianDay++;
        }
    }
*/
}

/* UTC_DATETIME_CYBOL_SERIALISER_SOURCE */
#endif
