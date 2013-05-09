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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESTROY_SOURCE
#define DESTROY_SOURCE

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/memory/destroy_memory_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/memoriser/deallocator/part_deallocator.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Destroys a part and removes it from the knowledge model.
 *
 * Primitive models need a different creation than compound models.
 *
 * Expected parametres:
 * - model (required): the part to be destroyed
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_destroy(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply destroy.");

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part type item.
    void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part type item data.
    void* ptd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part.
    get_part_knowledge((void*) &p, p0, (void*) MODEL_DESTROY_MEMORY_LOGIC_CYBOL_NAME, (void*) MODEL_DESTROY_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get part type item.
    copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Get part type item data.
    copy_array_forward((void*) &ptd, pt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Deallocate part.
    // CAUTION! The reference counters of those parts referenced by this part
    // get decremented and, if zero, the (child) parts deallocated automatically inside.
    // Calling a special "destructor" here is therefore NOT necessary
    // (as opposed to the "creator" called by the "apply_create" function).
    deallocate_part((void*) &p);
}

/* DESTROY_SOURCE */
#endif
