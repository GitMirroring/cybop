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

#ifndef COMPARATOR_SOURCE
#define COMPARATOR_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cybol/logic/selection_compare_logic_cybol_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../executor/comparator/all/part_all_comparator.c"
#include "../../executor/comparator/prefix/part_prefix_comparator.c"
#include "../../executor/comparator/subsequence/part_subsequence_comparator.c"
#include "../../executor/comparator/suffix/part_suffix_comparator.c"
#include "../../logger/logger.c"

/**
 * Compares the part with the element.
 *
 * @param p0 the result
 * @param p1 the left part
 * @param p2 the right data
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the right array count
 * @param p6 the left part element index
 * @param p7 the selection data
 * @param p8 the selection count
 */
void compare_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare element.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) ALL_SELECTION_COMPARE_LOGIC_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) ALL_SELECTION_COMPARE_LOGIC_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_all_part_element(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) PREFIX_SELECTION_COMPARE_LOGIC_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) PREFIX_SELECTION_COMPARE_LOGIC_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_prefix_part_element(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) SUFFIX_SELECTION_COMPARE_LOGIC_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) SUFFIX_SELECTION_COMPARE_LOGIC_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_suffix_part_element(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) SUBSEQUENCE_SELECTION_COMPARE_LOGIC_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) SUBSEQUENCE_SELECTION_COMPARE_LOGIC_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_subsequence_part_element(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare element. The selection is unknown.");
    }
}

/**
 * Compares two parts.
 *
 * @param p0 the result
 * @param p1 the left operand part
 * @param p2 the right operand part
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the selection data
 * @param p6 the selection count
 */
void compare(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) ALL_SELECTION_COMPARE_LOGIC_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) ALL_SELECTION_COMPARE_LOGIC_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_all_part(p0, p1, p2, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) PREFIX_SELECTION_COMPARE_LOGIC_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) PREFIX_SELECTION_COMPARE_LOGIC_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_prefix_part(p0, p1, p2, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) SUFFIX_SELECTION_COMPARE_LOGIC_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) SUFFIX_SELECTION_COMPARE_LOGIC_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_suffix_part(p0, p1, p2, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) SUBSEQUENCE_SELECTION_COMPARE_LOGIC_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) SUBSEQUENCE_SELECTION_COMPARE_LOGIC_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_subsequence_part(p0, p1, p2, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare. The selection is unknown.");
    }
}

/* COMPARATOR_SOURCE */
#endif
