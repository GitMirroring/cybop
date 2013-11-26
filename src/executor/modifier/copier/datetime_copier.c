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

#ifndef DATETIME_COPIER_SOURCE
#define DATETIME_COPIER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../executor/accessor/getter/datetime_getter.c"
#include "../../../executor/modifier/copier/double_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Copies the datetime.
 * 
 * CAUTION! The datetime IS a pointer reference,
 * since its elements are accessed via pointers.
 *
 * @param p0 the destination (pointer reference)
 * @param p1 the source (pointer reference)
 */
void copy_datetime(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy datetime.");

    // The destination julian day, julian second.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source julian day, julian second.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ss = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination julian day, julian second.
    get_datetime_element((void*) &dd, (void*) p0, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &ds, (void*) p0, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);
    // Get source julian day, julian second.
    get_datetime_element((void*) &sd, (void*) p1, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &ss, (void*) p1, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    // Copy source- to destination values.
    copy_integer(dd, sd);
    copy_double(ds, ss);
}

/* DATETIME_COPIER_SOURCE */
#endif
