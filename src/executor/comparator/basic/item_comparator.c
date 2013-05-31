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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ITEM_COMPARATOR_SOURCE
#define ITEM_COMPARATOR_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../logger/logger.c"

/**
 * Compares left- with right item.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left item
 * @param p2 the right item
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the count
 * @param p6 the left index
 * @param p7 the right index
 */
void compare_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare item.");

    // CAUTION! The sizes do NOT have to be identical,
    // since they just represent allocated memory.
    // For comparison, only the count (actual number of elements)
    // is of interest.

    // The left data.
    void* ld = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right data.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get left data.
    copy_array_forward((void*) &ld, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get right data.
    copy_array_forward((void*) &rd, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    compare_array(p0, ld, rd, p3, p4, p5, p6, p7);
}

/* ITEM_COMPARATOR_SOURCE */
#endif
