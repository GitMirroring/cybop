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

#ifndef INDICATE_SOURCE
#define INDICATE_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/modification/indicate_modification_operation_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/indicator/part_indicator.c"
#include "../../executor/modifier/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Indicates whether or not the part is empty (i.e. its element count is zero)
 * or data exist within (i.e. its element count is greater than zero).
 *
 * The kind of comparison depends upon the given operation type.
 * Possible values are: empty, exists
 *
 * Expected parametres:
 * - result (required): the result flag
 *   (set to true upon successful comparison; left untouched otherwise)
 * - part (required): the part
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the operation type
 */
void apply_indicate(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply indicate.");

    // The result part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result part.
    get_part_knowledge((void*) &r, p0, (void*) RESULT_INDICATE_OPERATION_CYBOL_NAME, (void*) RESULT_INDICATE_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get part part.
    get_part_knowledge((void*) &p, p0, (void*) PART_INDICATE_OPERATION_CYBOL_NAME, (void*) PART_INDICATE_OPERATION_CYBOL_NAME_COUNT, p1, p2);

    // Get result part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get result part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Indicate fill level of part.
    indicate_part(rmd, p, p3);
}

/* INDICATE_SOURCE */
#endif
