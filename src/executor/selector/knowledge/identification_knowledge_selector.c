/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

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

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_unequal((void*) &r, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        //?? fwprintf(stdout, L"Debug: select knowledge identification r: %i\n", r);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The index flag IS set.
            // Treat part name data as INDEX.
            //

            //
            // CAUTION! The stack memory argument p4 is NOT needed here,
            // since it is forbidden to access arbitrary stack variables via index.
            // Otherwise, the whole stack order might get ignored, which is NOT wanted.
            //
            // The argument p2 is used as source index related to the source whole part.
            // The part name count p3 is NOT needed, since there is only ONE integer pointer.
            //
            // CAUTION! Do NOT use the "copy_array_forward" function,
            // since it is low-level and does not check array boundaries!
            //
            get_part(p0, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2, p5);

        } else {

            //
            // The index flag is NOT set.
            // Treat part name data as NAME.
            //

            select_knowledge_memory(p0, *s, p2, p3, p4, p5);
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select knowledge identification. The source whole part is null.");
    }
}
