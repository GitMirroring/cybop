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

#ifndef DESTROY_SOURCE
#define DESTROY_SOURCE

#include "../../constant/type/cybol/text_cybol_type.c"
#include "../../constant/type/memory/memory_type.c"
#include "../../constant/type/operation/primitive_operation_type.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/boolean_memory_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../constant/name/cybol/operation/memory/destroy_memory_operation_cybol_name.c"
#include "../../executor/accessor/getter/compound_getter.c"
#include "../../executor/accessor/remover/compound_remover.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../logger/logger.c"

/**
 * Destroys a part and removes it from the knowledge model.
 *
 * Primitive models need a different creation than compound models.
 *
 * Expected parametres:
 * - part (required): the part to be destroyed
 *
 * @param p0 the parametres array (signal/ operation part properties with pointers referencing parts)
 * @param p1 the parametres array count
 * @param p2 the knowledge memory part
 */
void apply_destroy(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Apply destroy.");

    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The part type.
    void* pa = *NULL_POINTER_MEMORY_MODEL;
    // The part type data.
    void* pad = *NULL_POINTER_MEMORY_MODEL;

    // Get part.
    get_name_array((void*) &p, p0, (void*) PART_DESTROY_OPERATION_CYBOL_NAME, (void*) PART_DESTROY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get part type.
    copy_array_forward((void*) &pa, p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
    // Get part type data.
    copy_array_forward((void*) &pad, pa, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

    // Deallocate part.
    deallocate_part((void*) &p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, pad);
}

/* DESTROY_SOURCE */
#endif
