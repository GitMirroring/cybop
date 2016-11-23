/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BRANCH_SOURCE
#define BRANCH_SOURCE

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/flow/branch_flow_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

/**
 * Branches the programme flow, depending on the criterion flag.
 *
 * Expected parametres:
 * - criterion (required): the flag specifying which of the two models to execute
 * - true (optional): the logic knowledge model to be executed if the condition is true
 * - false (optional): the logic knowledge model to be executed if the condition is false
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the signal memory item
 * @param p6 the shutdown flag
 */
void apply_branch(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply branch.");

    // The criterion part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The true part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The false part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The criterion part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The criterion part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get criterion part.
    get_part_name((void*) &c, p0, (void*) CRITERION_BRANCH_FLOW_LOGIC_CYBOL_NAME, (void*) CRITERION_BRANCH_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);
    // Get true part.
    get_part_name((void*) &t, p0, (void*) TRUE_BRANCH_FLOW_LOGIC_CYBOL_NAME, (void*) TRUE_BRANCH_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);
    // Get false part.
    get_part_name((void*) &f, p0, (void*) FALSE_BRANCH_FLOW_LOGIC_CYBOL_NAME, (void*) FALSE_BRANCH_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);

    // Get criterion part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get criterion part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The direct execution flag.
    // CAUTION! The flag has to be set to true, because otherwise,
    // a new signal would be placed in signal memory and only
    // be processed with a delay.
    // But this is not desirable here, since the branch
    // is expected to be executed directly.
    // Further, follow-up signals may rely on its full execution.
    int x = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, cmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

/*??
fwprintf(stdout, L"TEST branch cmd: %i\n", cmd);
fwprintf(stdout, L"TEST branch *cmd: %i\n", *((int*) cmd));
*/

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST branch true: %i\n", r);

        // The criterion is true. Handle true model.
        handle(t, p4, p2, p3, p5, (void*) &x, p6);

    } else {

//?? fwprintf(stdout, L"TEST branch false: %i\n", r);

        // The criterion is false. Handle false model.
        handle(f, p4, p2, p3, p5, (void*) &x, p6);
    }
//?? fwprintf(stdout, L"TEST branch END: %i\n", r);
}

/* BRANCH_SOURCE */
#endif
