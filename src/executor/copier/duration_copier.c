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

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Copies the duration.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_duration(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy duration.");

    // The source value, start, end.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate source value, start, end.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &v, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
    allocate_array((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
    allocate_array((void*) &e, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);

    // Get source value, start, end.
    get_duration_element(v, p1, (void*) VALUE_DURATION_STATE_CYBOI_NAME);
    get_duration_element(s, p1, (void*) START_DURATION_STATE_CYBOI_NAME);
    get_duration_element(e, p1, (void*) END_DURATION_STATE_CYBOI_NAME);

    // Copy source value, start, end to destination.
    set_duration_element(p0, v, (void*) VALUE_DURATION_STATE_CYBOI_NAME);
    set_duration_element(p0, s, (void*) START_DURATION_STATE_CYBOI_NAME);
    set_duration_element(p0, e, (void*) END_DURATION_STATE_CYBOI_NAME);

    //
    // Deallocate source value, start, end.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &v, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
    deallocate_array((void*) &s, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
    deallocate_array((void*) &e, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
}
