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

#ifndef DDMMYYYY_DATETIME_XDT_SERIALISER_SOURCE
#define DDMMYYYY_DATETIME_XDT_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/modifier/appender/item_appender.c"
#include "../../../../../../executor/representer/serialiser/cybol/integer/value_integer_cybol_serialiser.c"
#include "../../../../../../executor/representer/serialiser/xdt/datetime/ddmmyyyy/ddmmyyyy_datetime_xdt_serialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the source datetime into the destination ddmmyyyy wide character data.
 *
 * @param p0 the destination item
 * @param p1 the source datetime
 */
void serialise_xdt_datetime_ddmmyyyy(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xdt datetime ddmmyyyy.");

    // The year/month/day/hour/minute/second.
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int min = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Serialise datetime.
    serialise_time_scale_gregorian_calendar((void*) &y, (void*) &m, (void*) &d, (void*) &h, (void*) &min, (void*) &s, p1);

    // Serialise year/month/day/hour/minute/second.
    serialise_cybol_integer_value(p0, (void*) &d, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    serialise_cybol_integer_value(p0, (void*) &m, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    serialise_cybol_integer_value(p0, (void*) &y, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
}

/* DDMMYYYY_DATETIME_XDT_SERIALISER_SOURCE */
#endif
