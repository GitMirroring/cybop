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

#ifndef MANAGER_SOURCE
#define MANAGER_SOURCE

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/state_cyboi_model.c"
#include "../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../controller/initiator.c"
#include "../executor/copier/array_copier.c"
#include "../executor/memoriser/allocator/internal_memory_allocator.c"
#include "../executor/memoriser/deallocator/internal_memory_deallocator.c"
#include "../logger/logger.c"

/**
 * Manages the system.
 *
 * A system lifecycle consists of the three phases:
 * - startup
 * - running
 * - shutdown
 *
 * @param p0 the run filename item
 */
void manage(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manage.");
    //?? fwprintf(stdout, L"Information: Manage. p0: %i\n", p0);

    //
    // Declaration
    //

    // The internal memory data.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocation
    //

    // Allocate internal memory.
    allocate_internal_memory((void*) &i);

    //
    // Initiation
    //

    // Get signal (event) memory from internal memory.
    copy_array_forward((void*) &s, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    //
    // Get signal (event) memory part model item.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Initiate system with initial signal.
    initiate(sm, p0, i, (void*) &i);

    //
    // Deallocation
    //

    // Deallocate internal memory.
    deallocate_internal_memory((void*) &i);
}

/* MANAGER_SOURCE */
#endif
