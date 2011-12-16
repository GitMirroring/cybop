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

#ifndef MODEL_MODEL_DIAGRAM_SERIALISER_SOURCE
#define MODEL_MODEL_DIAGRAM_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cybol/logic/calculate_logic_cybol_type.c"
#include "../../../../constant/type/cybol/state/logicvalue_state_cybol_type.c"
#include "../../../../constant/type/model_diagram/model_diagram_type.c"
#include "../../../../executor/representer/serialiser/cybol/double/double_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/complex_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/fraction_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/line_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/part_model_diagram_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the cyboi model into a model diagram model.
 *
 * @param p0 the destination model diagram item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the tree level
 * @param p4 the source type
 */
void serialise_model_diagram_model(void* p0, void* p1, void* p2, void* p3, void* p4) {

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

        compare_integer_equal((void*) &r, p4, (void*) DATETIME_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_model_diagram_part(p0, p1, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_model_diagram_line(p0);
            serialise_cybol_double(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_model_diagram_line(p0);
            serialise_cybol_double(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_model_diagram_line(p0);
            serialise_cybol_integer(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_model_diagram_line(p0);
            serialise_cybol_integer(p0, p1, p2);
        }
    }

    //
    // path
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ENCAPSULATED_PATH_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_model_diagram_line(p0);
            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) KNOWLEDGE_PATH_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_model_diagram_line(p0);
            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    //
    // pointer
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) POINTER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) POINTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) POINTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) PLAIN_TEXT_STATE_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PLAIN_TEXT_STATE_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_model_diagram_line(p0);
            append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    //
    // ========== Logic types. ==========
    //

    //
    // calculate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ADD_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) ADD_CALCULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ADD_CALCULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) DIVIDE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DIVIDE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) NEGATE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) NEGATE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NEGATE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) REDUCE_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) REDUCE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REDUCE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) REMAINDER_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) REMAINDER_CALCULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REMAINDER_CALCULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // communicate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SEND_COMMUNICATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SEND_COMMUNICATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SEND_COMMUNICATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // compare
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) EQUAL_PART_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) EQUAL_PART_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EQUAL_PART_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) EQUAL_PREFIX_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) EQUAL_PREFIX_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EQUAL_PREFIX_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) GREATER_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) GREATER_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GREATER_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SMALLER_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SMALLER_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALLER_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) UNEQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) UNEQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // convert
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DECODE_CONVERT_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) DECODE_CONVERT_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DECODE_CONVERT_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ENCODE_CONVERT_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) ENCODE_CONVERT_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ENCODE_CONVERT_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // file
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ARCHIVE_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) ARCHIVE_FILE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ARCHIVE_FILE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) COPY_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) COPY_FILE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) COPY_FILE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // flow
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) BRANCH_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) BRANCH_FLOW_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BRANCH_FLOW_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) LOOP_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) LOOP_FLOW_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LOOP_FLOW_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SEQUENCE_FLOW_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SEQUENCE_FLOW_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SEQUENCE_FLOW_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // live
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) EXIT_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) EXIT_LIVE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EXIT_LIVE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) INTERRUPT_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) INTERRUPT_LIVE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTERRUPT_LIVE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SENSE_LIVE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SENSE_LIVE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SENSE_LIVE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // logify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) AND_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) AND_LOGIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) AND_LOGIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) NAND_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) NAND_LOGIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NAND_LOGIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) NEG_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) NEG_LOGIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NEG_LOGIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) NOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) NOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) NOT_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) NOT_LOGIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NOT_LOGIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) OR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) OR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) OR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) XNOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) XNOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) XNOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) XOR_LOGIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) XOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) XOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // maintain
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) STARTUP_MAINTAIN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) STARTUP_MAINTAIN_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) STARTUP_MAINTAIN_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // manipulate
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) GET_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) GET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) RESET_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) RESET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RESET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SET_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // memorise
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CREATE_MEMORISE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) CREATE_MEMORISE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CREATE_MEMORISE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DESTROY_MEMORISE_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) DESTROY_MEMORISE_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DESTROY_MEMORISE_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // modify
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) APPEND_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) APPEND_MODIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) APPEND_MODIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) BUILD_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) BUILD_MODIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BUILD_MODIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) COUNT_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) COUNT_MODIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) COUNT_MODIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) GET_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) GET_MODIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GET_MODIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) INSERT_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) INSERT_MODIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INSERT_MODIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) REMOVE_MODIFY_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) REMOVE_MODIFY_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REMOVE_MODIFY_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //
    // run
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) RUN_LOGIC_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            append_item_element(p0, (void*) RUN_LOGIC_CYBOL_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RUN_LOGIC_CYBOL_TYPE_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise type. The type is unknown.");
    }
}

/* MODEL_MODEL_DIAGRAM_SERIALISER_SOURCE */
#endif
