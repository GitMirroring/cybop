/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TJD_DATETIME_CYBOL_SERIALISER_SOURCE
#define TJD_DATETIME_CYBOL_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/time_scale/julian_date_time_scale_model.c"
#include "../../../../../../executor/representer/serialiser/cybol/datetime/jd/basic_jd_datetime_cybol_serialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the datetime into truncated julian date (tjd) wide character data.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_cybol_datetime_tjd(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol datetime tjd.");

    serialise_cybol_datetime_jd_basic(p0, p1, p2, (void*) TRUNCATED_JULIAN_DATE_TIME_SCALE_MODEL);
}

/* TJD_DATETIME_CYBOL_SERIALISER_SOURCE */
#endif
