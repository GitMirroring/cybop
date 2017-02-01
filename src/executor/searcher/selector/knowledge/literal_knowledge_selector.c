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

#ifndef LITERAL_KNOWLEDGE_SELECTOR_SOURCE
#define LITERAL_KNOWLEDGE_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../../executor/representer/deserialiser/knowledge/index_knowledge_deserialiser.c"
#include "../../../../executor/searcher/selector/knowledge/memory_knowledge_selector.c"
#include "../../../../logger/logger.c"

/**
 * Selects the index treatment (path or literal).
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the part name data
 * @param p3 the part name count
 * @param p4 the stack memory item
 * @param p5 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for stack variables
 */
void select_knowledge_literal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge literal.");

//?? fwprintf(stdout, L"TEST select knowledge literal *p6: %i\n", *((int*) p6));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??        compare_integer_unequal((void*) &r, p6, *FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The index literal flag IS set.
            // Treat part name data as integer value.

            deserialise_knowledge_index(p0, p1, p2, p3, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The index literal flag is NOT set.
        // Treat part name data as string.

        select_knowledge_memory(p0, p1, p2, p3, p4, p5);
    }
}

/* LITERAL_KNOWLEDGE_SELECTOR_SOURCE */
#endif
