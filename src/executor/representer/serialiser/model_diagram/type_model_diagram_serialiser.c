/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TYPE_MODEL_DIAGRAM_SERIALISER_SOURCE
#define TYPE_MODEL_DIAGRAM_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cybol/logic/calculate_logic_cybol_type.c"
#include "../../../../constant/type/cybol/state/logicvalue_state_cybol_type.c"
#include "../../../../constant/type/model_diagram/model_diagram_type.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the cyboi type into a model diagram type.
 *
 * @param p0 the destination model diagram item
 * @param p1 the source type
 */
void serialise_model_diagram_type(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise model diagram type.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // ========== State types. ==========
    //

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DATETIME_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) PART_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PART_MODEL_DIAGRAM_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // path
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ENCAPSULATED_PATH_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) KNOWLEDGE_PATH_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // pointer
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) POINTER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) POINTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) POINTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // ========== Logic types. ==========
    //

    //
    // calculate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ADD_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NEGATE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) REDUCE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) REMAINDER_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // communicate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SEND_COMMUNICATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // compare
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) EQUAL_PART_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) EQUAL_PREFIX_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GREATER_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SMALLER_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // convert
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DECODE_CONVERT_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ENCODE_CONVERT_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // file
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ARCHIVE_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) COPY_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // flow
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) BRANCH_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) LOOP_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SEQUENCE_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // live
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) EXIT_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) INTERRUPT_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SENSE_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // logify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) AND_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NAND_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NEG_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NOT_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) OR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) XNOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) XOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // maintain
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) STARTUP_MAINTAIN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // manipulate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GET_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) RESET_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SET_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // memorise
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CREATE_MEMORISE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DESTROY_MEMORISE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // modify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) APPEND_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) BUILD_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) COUNT_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GET_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) INSERT_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) REMOVE_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // run
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) RUN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, (void*) TODO_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TODO_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise type. The type is unknown.");
    }
}

/* TYPE_MODEL_DIAGRAM_SERIALISER_SOURCE */
#endif
