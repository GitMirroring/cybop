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

#ifndef DURATION_COPIER_SOURCE
#define DURATION_COPIER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/duration_state_cyboi_name.c"
#include "../../../executor/accessor/getter/duration_getter.c"
#include "../../../executor/modifier/copier/datetime_copier.c"
#include "../../../logger/logger.c"

/**
 * Copies the duration.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_duration(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy duration.");

    // The destination value, start, end.
    void* dv = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* de = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source value, start, end.
    void* sv = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ss = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination value, start, end.
    get_duration_element((void*) &dv, (void*) p0, (void*) VALUE_DURATION_STATE_CYBOI_NAME);
    get_duration_element((void*) &ds, (void*) p0, (void*) START_DURATION_STATE_CYBOI_NAME);
    get_duration_element((void*) &de, (void*) p0, (void*) END_DURATION_STATE_CYBOI_NAME);
    // Get source value, start, end.
    get_duration_element((void*) &sv, (void*) p1, (void*) VALUE_DURATION_STATE_CYBOI_NAME);
    get_duration_element((void*) &ss, (void*) p1, (void*) START_DURATION_STATE_CYBOI_NAME);
    get_duration_element((void*) &se, (void*) p1, (void*) END_DURATION_STATE_CYBOI_NAME);

    // Copy source- to destination values.
    copy_datetime(dv, sv);
    copy_datetime(ds, ss);
    copy_datetime(de, se);
}

/* DURATION_COPIER_SOURCE */
#endif
