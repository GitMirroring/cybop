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

#ifndef SOW_SOURCE
#define SOW_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/randomisation/sow_randomisation_logic_cybol_name.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/randomiser/sower.c"
#include "../../logger/logger.c"

/**
 * Sows a seed for a new series of pseudo-random numbers.
 *
 * Expected parametres:
 * - seed (required): the source seed to be established for a new series of pseudo-random numbers
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the stack memory item
 */
void apply_sow(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply sow.");

    // The source seed part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source seed part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source seed part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source seed part.
    get_part_name((void*) &s, p0, (void*) SEED_SOW_RANDOMISATION_LOGIC_CYBOL_NAME, (void*) SEED_SOW_RANDOMISATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3);
    // Get source seed part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source seed part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Sow seed for new series of pseudo-random numbers.
    sow(smd);
}

/* SOW_SOURCE */
#endif
