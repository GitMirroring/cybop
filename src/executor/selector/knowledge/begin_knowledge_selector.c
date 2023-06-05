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
 * @version CYBOP 0.26.0 2023-04-04
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

#include "algorithm.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the knowledge begin.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 * @param p7 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts on heap
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties on heap
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for variables on stack
 *           - *NULL_POINTER_STATE_CYBOI_MODEL if none of the above applies
 * @param p8 the knowledge path end flag
 */
void select_knowledge_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge begin.");
    //?? fwprintf(stdout, L"Debug: select knowledge begin *p3: %i\n", *((int*) p3));
    //?? fwprintf(stdout, L"Debug: select knowledge begin *p2: %ls\n", (wchar_t*) *((void**) p2));

    //
    // The order of comparisons does NOT matter
    // and was chosen in a way to favour speed,
    // that is characters often used are standing on top.
    //
    // The only exception are pure names without prefix,
    // which are taken as LAST option, if nothing else applies.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) STACK_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) STACK_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The "#" indicates that a STACK variable name begins.
            //

            deserialise_knowledge_part(p0, p1, p2, p3, p4, p5, p6, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The "." indicates that a sub part's MODEL begins.
            //

            deserialise_knowledge_part(p0, p1, p2, p3, p4, p5, p6, (void*) MODEL_PART_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The ":" indicates that a sub part's PROPERTY begins.
            //

            deserialise_knowledge_part(p0, p1, p2, p3, p4, p5, p6, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) BEGIN_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The "[" indicates that a nested path containing an INDEX begins.
            //

            // CAUTION! Hand over TRUE as last parametre to indicate that an INDEX is being processed.
            deserialise_knowledge_identification(p0, p1, p2, p3, p4, p5, p6, p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) BEGIN_NAME_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_NAME_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The "(" indicates that a nested path containing a NAME begins.
            //

            // CAUTION! Hand over FALSE as last parametre to indicate that a NAME is being processed.
            deserialise_knowledge_identification(p0, p1, p2, p3, p4, p5, p6, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) BEGIN_REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The "{" indicates that a REFERENCE begins.
            //

            deserialise_knowledge_reference(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A special prefix character was NOT found.
        //
        // Therefore, the following characters are supposed to represent a NAME.
        // If there are no further characters, then the source WHOLE part
        // ITSELF will get copied to become the destination part.
        //

        deserialise_knowledge_name(p0, p1, p2, p3, p5, p7, p8);
    }
}
