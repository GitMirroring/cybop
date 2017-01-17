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

#ifndef BEGIN_PART_KNOWLEDGE_SELECTOR_SOURCE
#define BEGIN_PART_KNOWLEDGE_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/knowledge/separator_knowledge_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/representer/deserialiser/knowledge/part_knowledge_deserialiser.c"
#include "../../../../executor/representer/deserialiser/knowledge/reference_knowledge_deserialiser.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

//
// CAUTION! This comment is valid for all "select" functions below.
//
// The comparison result HAS TO BE ZERO (r == 0),
// if a detection is to be taking place!
//
// Many "detect" functions are called in a sequence, below.
// If the result of one detection function was positive (r == 1), then that
// function increments the current position and decrements the remaining count.
// In this case, further detection functions following afterwards might detect
// further characters and CHANGE the current position and remaining count,
// and so forth, which would have the effect of "JUMPING" over some characters
// and produce WRONG RESULTS!
//
// Therefore, the checks for (r == 0) below avoid another detection,
// if the result already has a value unequal zero.
//
// CAUTION! If a detection was successful, then the current position and remaining count
// were already adapted within the corresponding "detect" function (as called below),
// so that they now point to the first character FOLLOWING the detected character sequence.
// Any "decode" function called afterwards can rely on this and start processing right away.
//

/**
 * Selects the knowledge part begin.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the knowledge memory part
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 * @param p7 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for stack variables
 */
void select_knowledge_part_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p2;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge part begin.");

        //
        // CAUTION! The order of comparisons IS IMPORTANT.
        //
        // Memory root characters have to be tested first,
        // with simple COMPARISON functions, NOT detection.
        // The reason is that the count/length matters here.
        //
        // Only afterwards, further comparisons may be done
        // using the function "detect_array",
        // which moves the data position pointer automatically.
        //
        // The order of these remaining comparisons does NOT matter
        // and was chosen in a way to favour speed,
        // that is characters often used are standing on top.
        //
        // The only exception are pure names without prefix,
        // which are taken as last option, if nothing else applies.
        //

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_all_array((void*) &r, *d, (void*) KNOWLEDGE_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) KNOWLEDGE_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Copy knowledge memory part from internal memory to destination.
                copy_array_forward(p0, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

                // Set knowledge path count remaining to zero,
                // so that the calling endless loop gets exited.
                copy_integer(p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_all_array((void*) &r, *d, (void*) SIGNAL_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) SIGNAL_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Copy knowledge memory part from internal memory to destination.
                copy_array_forward(p0, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

                // Set knowledge path count remaining to zero,
                // so that the calling endless loop gets exited.
                copy_integer(p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_all_array((void*) &r, *d, (void*) STACK_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) STACK_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Copy knowledge memory part from internal memory to destination.
                copy_array_forward(p0, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) STACK_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

                // Set knowledge path count remaining to zero,
                // so that the calling endless loop gets exited.
                copy_integer(p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            detect_array((void*) &r, p2, p3, (void*) STACK_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) STACK_MEMORY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The "#" indicates that a stack variable name begins.

                deserialise_knowledge_part(p0, p1, p2, p3, p4, p5, p6, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            detect_array((void*) &r, p2, p3, (void*) MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The "." indicates that a sub part's model begins.

                deserialise_knowledge_part(p0, p1, p2, p3, p4, p5, p6, (void*) MODEL_PART_STATE_CYBOI_NAME);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            detect_array((void*) &r, p2, p3, (void*) PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The ":" indicates that a sub part's property begins.

                deserialise_knowledge_part(p0, p1, p2, p3, p4, p5, p6, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            detect_array((void*) &r, p2, p3, (void*) BEGIN_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                deserialise_knowledge_part_index(p0, p1, p2, p3, p4, p5, p6, p7);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            detect_array((void*) &r, p2, p3, (void*) BEGIN_PATH_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_PATH_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The "(" indicates that a nested path containing a name begins.

                deserialise_knowledge_part_path(p0, p1, p2, p3, p4, p5, p6, p7);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            detect_array((void*) &r, p2, p3, (void*) REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The "*" indicates that a reference begins.

                deserialise_knowledge_reference(p0, p1, p2, p3, p4, p5, p6, p7);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // A special prefix character was NOT found.
            // Therefore, the following characters are supposed to represent a name.
            // If there are no further characters, then the source whole part
            // itself will get copied to become the destination part.

            deserialise_knowledge_part_name(p0, p1, p2, p3, p4, p5, p6, p7);
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select knowledge part begin. The knowledge path data position is null.");
    }
}

/* BEGIN_PART_KNOWLEDGE_SELECTOR_SOURCE */
#endif
