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

#ifndef DATETIME_COPIER_SOURCE
#define DATETIME_COPIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../executor/accessor/getter/datetime_getter.c"
#include "../../executor/accessor/setter/datetime_setter.c"
#include "../../logger/logger.c"

/**
 * Copies the datetime.
 *
 * @param p0 the destination datetime
 * @param p1 the source datetime
 */
void copy_datetime(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy datetime.");

    // The source julian day, julian second.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double s = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get source julian day, julian second.
    get_datetime_element((void*) &d, p1, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &s, p1, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    // Copy source julian day, julian second to destination.
    set_datetime_element(p0, (void*) &d, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    set_datetime_element(p0, (void*) &s, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);
}

/* DATETIME_COPIER_SOURCE */
#endif
