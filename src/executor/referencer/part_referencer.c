/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_DECREMENTER_SOURCE
#define PART_DECREMENTER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/converter/encoder/model_diagram_encoder.c"
#include "../../../executor/searcher/mover/position_mover.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

/**
 * Decrements the part's reference count.
 *
 * CAUTION! Deallocates the part if its reference count is zero.
 *
 * @param p0 the whole part
 * @param p1 the type
 * @param p2 the index
 */
void decrement_part(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decrement part.");

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part references, type, model.
    void* pr = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part references, type, model data, size.
    void* prd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ptd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pms = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part at index from whole.
    copy_array_forward((void*) &p, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);
    // Get part references, type, model.
    copy_array_forward((void*) &pr, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) REFERENCES_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pt, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get part references, type, model data, size.
    copy_array_forward((void*) &prd, pr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ptd, pt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pms, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    // Decrement references counter.
    calculate_integer_subtract(prd, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_smaller_or_equal((void*) &r, prd, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        deallocate_part((void*) &p, pms, ptd);
    }
}

/* PART_DECREMENTER_SOURCE */
#endif
