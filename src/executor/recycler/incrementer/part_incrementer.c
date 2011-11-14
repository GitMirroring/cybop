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

#ifndef PART_INCREMENTER_SOURCE
#define PART_INCREMENTER_SOURCE

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
 * Increments the reference count of the given part.
 *
 * @param p0 the part
 */
void increment_part(void* p0) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Increment part.");

    // The references.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The references data.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get references.
    copy_array_forward((void*) &r, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) REFERENCES_PART_STATE_CYBOI_NAME);
    // Get references data.
    copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Increment references counter.
    calculate_integer_add(rd, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
}

/* PART_INCREMENTER_SOURCE */
#endif
