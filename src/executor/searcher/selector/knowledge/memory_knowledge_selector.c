/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MEMORY_KNOWLEDGE_SELECTOR_SOURCE
#define MEMORY_KNOWLEDGE_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../executor/accessor/name_getter/item_name_getter.c"
#include "../../../../executor/accessor/name_getter/part_name_getter.c"
#include "../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Get destination part with the given name from source whole part
 * using the memory identified by the source whole part element index.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part
 * @param p2 the part name data
 * @param p3 the part name count
 * @param p4 the stack memory item
 * @param p5 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for stack variables
 */
void select_knowledge_memory(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge memory.");

//?? fwprintf(stdout, L"TEST select knowledge memory *p5: %i\n", *((int*) p5));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get part with name from stack memory.
            // CAUTION! The last argument is true to indicate last-in-first-out (lifo) retrieval.
            get_name_item_element(p0, p4, p2, p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) MODEL_PART_STATE_CYBOI_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get part with name from source whole part model OR properties,
            // depending on the source whole part element index p5.
            get_name_part_element(p0, p1, p2, p3, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get part with name from source whole part model OR properties,
            // depending on the source whole part element index p5.
            get_name_part_element(p0, p1, p2, p3, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select knowledge memory. The source whole part element index is unknown.");

fwprintf(stdout, L"WARNING: Could not select knowledge memory. The source whole part element index is unknown. p2: %ls\n", (wchar_t*) p2);
fwprintf(stdout, L"WARNING: Could not select knowledge memory. The source whole part element index is unknown. *p3: %i\n", *((int*) p3));

fwprintf(stdout, L"WARNING: Could not select knowledge memory. The source whole part element index is unknown. p5: %p\n", p5);
    }
}

/* MEMORY_KNOWLEDGE_SELECTOR_SOURCE */
#endif
