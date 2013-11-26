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

#ifndef ELEMENTS_QYYYY_DATETIME_XDT_DESERIALISER_SOURCE
#define ELEMENTS_QYYYY_DATETIME_XDT_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/representer/deserialiser/xdt/datetime/qyyyy/quarter_qyyyy_datetime_xdt_deserialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the qyyyy elements wide character data into a datetime model.
 *
 * @param p0 the destination datetime
 * @param p1 the source data
 */
void deserialise_xdt_datetime_qyyyy_elements(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt datetime qyyyy elements.");

    // The year/month/day/hour/minute/second.
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int min = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The quarter.
    int q = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The year/quarter source.
    void* ys = p1;
    void* qs = p1;

    // Adjust year/quarter source.
    // CAUTION! Process numbers in this order: q/y.
    // It should also work the other way around, but to
    // be sure, the source is read from left to right.
    move_position((void*) &qs, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    move_position((void*) &ys, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Deserialise year/quarter source.
    // CAUTION! Process numbers in this order: q/y.
    // It should also work the other way around, but to
    // be sure, the source is read from left to right.
    deserialise_cybol_integer_value_primitive((void*) &q, qs, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
    deserialise_cybol_integer_value_primitive((void*) &y, ys, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Correct month.
    deserialise_xdt_datetime_qyyyy_quarter((void*) &m, (void*) &d, (void*) &q);

    // Deserialise year/month/day/hour/minute/second.
    deserialise_time_scale_gregorian_calendar(p0, (void*) &y, (void*) &m, (void*) &d, (void*) &h, (void*) &min, (void*) &s);
}

/* ELEMENTS_QYYYY_DATETIME_XDT_DESERIALISER_SOURCE */
#endif
