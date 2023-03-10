/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SOW_SOURCE
#define SOW_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/randomiser/sower.c"
#include "../../logger/logger.c"

/**
 * Sows a seed for a new series of pseudo-random numbers.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_sow(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply sow.");

    //
    // Declaration
    //

    // The source seed part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source seed part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source seed part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get source seed part.
    get_part_name((void*) &s, p0, (void*) SEED_SOW_RANDOMISATION_LOGIC_CYBOL_NAME, (void*) SEED_SOW_RANDOMISATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source seed part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source seed part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // Sow seed for new series of pseudo-random numbers.
    sow(smd);
}

/* SOW_SOURCE */
#endif
