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

#ifndef IDENTIFICATION_KNOWLEDGE_SELECTOR_SOURCE
#define IDENTIFICATION_KNOWLEDGE_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/part_getter.c"
#include "../../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../../executor/searcher/selector/knowledge/memory_knowledge_selector.c"
#include "../../../../logger/logger.c"

/**
 * Selects the knowledge identification (name or index).
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
 * @param p6 the index flag (true if index; false otherwise, i.e. name)
 */
void select_knowledge_identification(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** s = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge identification.");

//?? fwprintf(stdout, L"TEST select knowledge identification *p6: %i\n", *((int*) p6));

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &r, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The index flag IS set.
                // Treat part name data as index.

                // CAUTION! The stack memory argument p4 is NOT needed here,
                // since it is forbidden to access arbitrary stack variables via index.
                // Otherwise, the whole stack order might get ignored,
                // which is not wanted.
                //
                // CAUTION! Do NOT use the "copy_array_forward" function,
                // since it is low-level and does not check array boundaries!
                get_part_metadata(p0, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2, p5);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The index flag is NOT set.
            // Treat part name data as name.

            select_knowledge_memory(p0, *s, p2, p3, p4, p5);
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select knowledge identification. The source whole part is null.");
    }
}

/* IDENTIFICATION_KNOWLEDGE_SELECTOR_SOURCE */
#endif
