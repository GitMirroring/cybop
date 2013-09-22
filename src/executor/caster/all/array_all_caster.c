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

#ifndef ARRAY_ALL_CASTER_SOURCE
#define ARRAY_ALL_CASTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/caster/basic/array_caster.c"
#include "../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../logger/logger.c"

/**
 * Casts all elements of the source- to the destination array.
 *
 * @param p0 the destination data
 * @param p1 the source data
 * @param p2 the source type
 * @param p3 the operation type
 * @param p4 the destination count
 * @param p5 the source count
 */
void cast_all_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cast all array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! The sizes do NOT have to be identical,
    // since they just represent allocated memory.
    // Only the count (actual number of elements) is of interest.

    // Compare if integer vectors have the same length.
    compare_integer_equal((void*) &r, p4, p5);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! Both, the destination- or the source array count may be
        // handed over alternatively as count parametre, since they are equal.
        cast_array(p0, p1, p2, p3, p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast all array. The destination array count is not equal to the source array count.");
    }
}

/* ARRAY_ALL_CASTER_SOURCE */
#endif
