/*
 * Copyright (C) 1999-2014. Christian Heller.
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
#include "../../../../../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../executor/representer/serialiser/time_scale/gregorian_calendar/gregorian_calendar_time_scale_serialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the datetime into utc date wide character data.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_cybol_datetime_utc(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol datetime utc.");

    // The year/month/day/hour/minute/second.
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int min = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Serialise datetime.
    serialise_time_scale_gregorian_calendar((void*) &y, (void*) &m, (void*) &d, (void*) &h, (void*) &min, (void*) &s, p1);

    //?? TODO: Replace the following using ISO format!
    //?? The following lines are just for testing.

    // Serialise year/month/day/hour/minute/second.
    serialise_cybol_integer_value(p0, (void*) &d, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    serialise_cybol_integer_value(p0, (void*) &m, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    serialise_cybol_integer_value(p0, (void*) &y, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
}

/* UTC_DATETIME_CYBOL_SERIALISER_SOURCE */
#endif
