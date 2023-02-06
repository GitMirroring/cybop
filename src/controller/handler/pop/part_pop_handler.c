/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PART_POP_HANDLER_SOURCE
#define PART_POP_HANDLER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../controller/handler/pop/model_pop_handler.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Retrieves next part.
 *
 * @param p0 the stack memory item
 * @param p1 the stack memory data
 * @param p2 the stack memory index
 */
void handle_pop_part(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle pop part.");

    //
    // Declaration
    //

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
/*??
    // The part name, format, type, model item.
    void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name item data, count.
    void* pnd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pnc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part format item data.
    void* pfd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part type item data.
    void* ptd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part model item data, count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
*/

    //
    // Retrieval
    //

    // Get part.
    copy_array_forward((void*) &p, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);
/*??
    // Get part name, format, type, model item.
    copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pf, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get part name item data, count.
    copy_array_forward((void*) &pnd, pn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pnc, pn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get part format item data.
    copy_array_forward((void*) &pfd, pf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get part type item data.
    copy_array_forward((void*) &ptd, pt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get part model item data, count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
*/

    //
    // Deallocation
    //

    // Deallocate part.
    handle_pop_model((void*) &p);

    //
    // Removal
    //

    //
    // Remove from stack memory (POP).
    //
    // Solution 1: Read properties again
    //
    // CAUTION! The properties might have been changed within
    // the logic executed within the "handle" function above.
    // Therefore, they should NOT be accessed a second time here,
    // in order to remove temporary values from stack memory,
    // since the number and type of properties might have changed,
    // which would otherwise lead to SEVERE MEMORY ERRORS.
    //
    // Solution 2: Add empty marker element to stack
    //
    // - INEFFICIENT since added for each function call
    // - added even for logic not using temporary values on stack
    // - consumes additional time and memory
    //
    // Solution 3: Remember number of values added
    //
    // - seems to be the easiest solution
    // - the exact same number of values that was added to stack
    //   (signal properties count) is removed from it again here
    // - the former (mc_old) stack memory item count is used as index for removal
    //
    // Therefore, solution 3 is applied here.
    //
    // CAUTION! Set the adjust flag to TRUE since otherwise,
    // the destination item will hold a wrong "count" number
    // leading to unpredictable errors in further processing.
    //
    //?? fwprintf(stdout, L"Debug: Handle pop model. mc_old pre: %i\n", mc_old);
    modify_item(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p2, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);
    //?? fwprintf(stdout, L"Debug: Handle pop model. mc_old post: %i\n", mc_old);
}

/* PART_POP_HANDLER_SOURCE */
#endif
