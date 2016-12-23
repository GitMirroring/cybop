/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STACK_KNOWLEDGE_DESERIALISER_SOURCE
#define STACK_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/accessor/name_getter/item_name_getter.c"
#include "../../../../executor/modifier/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Gets a knowledge part from stack memory.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the knowledge path data position (pointer reference)
 * @param p2 the knowledge path count remaining
 * @param p3 the stack memory item
 */
void deserialise_knowledge_stack(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge stack.");

    // The stack variable name data.
    // CAUTION! Since it is handed over as reference to here,
    // it has to be changed into a simple pointer.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Initialise name string data.
    copy_pointer((void*) &n, p1);

    // Get part with name from stack memory.
    get_name_item_element(p0, p3, n, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
}

/* STACK_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
