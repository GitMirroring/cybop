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

#ifndef ROOT_KNOWLEDGE_SELECTOR_SOURCE
#define ROOT_KNOWLEDGE_SELECTOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/checker/operation_checker.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/selector/knowledge/begin_knowledge_selector.c"
#include "logger.h"

/**
 * Selects the knowledge memory root node.
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
void select_knowledge_root(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p2;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge root.");
        //?? fwprintf(stdout, L"Debug: Select knowledge root. *p3: %i\n", *((int*) p3));
        //?? fwprintf(stdout, L"Debug: Select knowledge root. *p2: %ls\n", (wchar_t*) *d);

        //
        // Select the correct memory.
        //
        // CAUTION! This is to filter out the special case
        // that ONLY a memory root is given, that is
        // the path consists of one character only.
        // The STANDARD CASE, however, is to call the function
        // "select_knowledge_begin" at the end of this file.
        //
        // CAUTION! The ORDER of the following comparisons is IMPORTANT!
        //
        // Memory root characters have to be tested FIRST, i.e.:
        // . knowledge memory
        // | signal memory
        // # stack memory
        //
        // Use the function "check_operation", NOT detection.
        // It does a lexicographical comparison considering
        // the count/length of both operands.
        //
        // Only afterwards, further comparisons may be done in file
        // "begin_knowledge_selector.c", using the function "detect_array",
        // which moves the data position pointer automatically.
        //

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_operation((void*) &r, *d, (void*) KNOWLEDGE_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, p3, (void*) KNOWLEDGE_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Copy knowledge memory part from internal memory to destination.
                copy_array_forward(p0, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_operation((void*) &r, *d, (void*) SIGNAL_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, p3, (void*) SIGNAL_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Copy signal memory part from internal memory to destination.
                copy_array_forward(p0, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_operation((void*) &r, *d, (void*) STACK_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, p3, (void*) STACK_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Copy stack memory part from internal memory to destination.
                copy_array_forward(p0, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) STACK_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // No knowledge memory root . or | or # was given.
            // Therefore, now process the knowledge path
            // by searching for special prefixes and delimiters.
            //

            select_knowledge_begin(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select knowledge root. The knowledge path data position is null.");
    }
}

/* ROOT_KNOWLEDGE_SELECTOR_SOURCE */
#endif
