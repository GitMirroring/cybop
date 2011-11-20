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

#ifndef TYPE_CYBOL_DECODER_SOURCE
#define TYPE_CYBOL_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cybol/compare_cybol_type.c"
#include "../../../../constant/type/cybol/datetime_cybol_type.c"
#include "../../../../constant/type/cybol/logicvalue_cybol_type.c"
#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the cybol type into a cyboi type.
 *
 * @param p0 the destination data
 * @param p1 the source data
 * @param p2 the source count
 */
void decode_cybol_type(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode cybol type.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // ======================================================================
    //
    // State.
    //
    // ======================================================================

    //
    // Date time.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) HH_MM_SS_DATETIME_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) HH_MM_SS_DATETIME_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DATETIME_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DATETIME_STATE_CYBOI_TYPE);
        }
    }

    //
    // Logic value.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) BOOLEAN_STATE_CYBOI_TYPE);
        }
    }

    //
    // Number.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CARTESIAN_COMPLEX_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) CARTESIAN_COMPLEX_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) COMPLEX_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DECIMAL_FRACTION_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) DECIMAL_FRACTION_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DOUBLE_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INTEGER_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) INTEGER_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) POLAR_COMPLEX_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) POLAR_COMPLEX_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) COMPLEX_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) VULGAR_FRACTION_NUMBER_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) VULGAR_FRACTION_NUMBER_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_STATE_CYBOI_TYPE);
        }
    }

    //
    // Path.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ENCAPSULATED_KNOWLEDGE_PATH_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ENCAPSULATED_KNOWLEDGE_PATH_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ENCAPSULATED_KNOWLEDGE_PATH_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) KNOWLEDGE_PATH_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) KNOWLEDGE_PATH_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) KNOWLEDGE_PATH_STATE_CYBOI_TYPE);
        }
    }

    //
    // Text.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ASCII_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ASCII_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CHARACTER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOL_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) CYBOL_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PART_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PLAIN_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) PLAIN_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) TYPE_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) TYPE_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) XDT_TEXT_STATE_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) XDT_TEXT_STATE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PART_STATE_CYBOI_TYPE);
        }
    }

    // ======================================================================
    //
    // Logic.
    //
    // ======================================================================

    //
    // Calculate.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ABSOLUTE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ABSOLUTE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ADD_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ADD_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ADD_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DIVIDE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) DIVIDE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DIVIDE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) MULTIPLY_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NEGATE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) NEGATE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NEGATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) REDUCE_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) REDUCE_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) REDUCE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) REMAINDER_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) REMAINDER_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) REMAINDER_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SUBTRACT_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Communicate.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) RECEIVE_COMMUNICATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) RECEIVE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SEND_COMMUNICATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SEND_COMMUNICATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SEND_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Compare.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_PART_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) EQUAL_PART_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EQUAL_PART_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_PREFIX_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) EQUAL_PREFIX_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EQUAL_PREFIX_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) EQUAL_SUFFIX_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EQUAL_SUFFIX_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) GREATER_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) GREATER_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) GREATER_OR_EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SMALLER_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SMALLER_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SMALLER_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SMALLER_OR_EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) UNEQUAL_COMPARE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) UNEQUAL_COMPARE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) UNEQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Convert.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DECODE_CONVERT_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) DECODE_CONVERT_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DECODE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ENCODE_CONVERT_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ENCODE_CONVERT_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ENCODE_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // File.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ARCHIVE_FILE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ARCHIVE_FILE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ARCHIVE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COPY_FILE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) COPY_FILE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) COPY_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) LIST_DIRECTORY_CONTENTS_FILE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) LIST_DIRECTORY_CONTENTS_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Flow.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BRANCH_FLOW_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) BRANCH_FLOW_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) BRANCH_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) LOOP_FLOW_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) LOOP_FLOW_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) LOOP_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SEQUENCE_FLOW_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SEQUENCE_FLOW_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SEQUENCE_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Live.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EXIT_LIVE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) EXIT_LIVE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EXIT_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INTERRUPT_LIVE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) INTERRUPT_LIVE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTERRUPT_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SENSE_LIVE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SENSE_LIVE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SENSE_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Logify.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) AND_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) AND_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) AND_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NAND_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) NAND_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NAND_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NEG_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) NEG_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NEG_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) NOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NOR_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) NOT_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) NOT_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NOT_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) OR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) OR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) OR_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) XNOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) XNOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) XNOR_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) XOR_LOGIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) XOR_LOGIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) XOR_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Maintain.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SHUTDOWN_MAINTAIN_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SHUTDOWN_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) STARTUP_MAINTAIN_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) STARTUP_MAINTAIN_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) STARTUP_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Manipulate.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) GET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) GET_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RESET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) RESET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) RESET_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ROTATE_LEFT_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ROTATE_RIGHT_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SET_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SET_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SET_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SHIFT_LEFT_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SHIFT_RIGHT_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Memorise.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CREATE_MEMORISE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) CREATE_MEMORISE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CREATE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DESTROY_MEMORISE_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) DESTROY_MEMORISE_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DESTROY_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Modify.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) APPEND_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) APPEND_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPEND_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BUILD_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) BUILD_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) BUILD_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COUNT_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) COUNT_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) COUNT_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GET_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) GET_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) GET_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INSERT_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) INSERT_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INSERT_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) OVERWRITE_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) REMOVE_MODIFY_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) REMOVE_MODIFY_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) REMOVE_LOGIC_CYBOI_TYPE);
        }
    }

    //
    // Run.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) RUN_RUN_LOGIC_CYBOL_TYPE, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) RUN_RUN_LOGIC_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) RUN_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode cybol type. The type is unknown.");
    }
}

/* TYPE_CYBOL_DECODER_SOURCE */
#endif
