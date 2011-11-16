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

#ifndef TYPE_DECODER_SOURCE
#define TYPE_DECODER_SOURCE

#include "../../../../constant/type/cybol/compare_cybol_type.c"
#include "../../../../constant/type/cybol/datetime_cybol_type.c"
#include "../../../../constant/type/cybol/logicvalue_cybol_type.c"
//?? Delete this later. Superfluous since replaced with compare/equal etc.
#include "../../../../constant/type/cybol/operation_cybol_type.c"
#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/operation/operation_type.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the type wide character data into an type integer.
 *
 * @param p0 the destination data
 * @param p1 the source data
 * @param p2 the source count
 */
void decode_type(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode type.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ASCII_TEXT_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ASCII_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CHARACTER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) BOOLEAN_LOGICVALUE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) BOOLEAN_LOGICVALUE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) COMPLEX_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) CYBOL_TEXT_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) CYBOL_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PART_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ENCAPSULATED_KNOWLEDGE_PATH_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) EQUAL_COMPARE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) EQUAL_COMPARE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_COMPARE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) GREATER_COMPARE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) GREATER_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) GREATER_OR_EQUAL_COMPARE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) GREATER_OR_EQUAL_COMPARE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) GREATER_OR_EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) HH_MM_SS_DATETIME_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) HH_MM_SS_DATETIME_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DATETIME_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) INTEGER_NUMBER_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) INTEGER_NUMBER_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INTEGER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) KNOWLEDGE_PATH_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) KNOWLEDGE_PATH_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) KNOWLEDGE_PATH_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PART_EQUAL_COMPARE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) PART_EQUAL_COMPARE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PART_EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    //?? Delete "plain operation" later, as it was replaced with cybol mime types like compare/equal etc.
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PLAIN_OPERATION_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) PLAIN_OPERATION_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) OPERATION_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PLAIN_TEXT_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) PLAIN_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) POLAR_COMPLEX_NUMBER_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) POLAR_COMPLEX_NUMBER_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) COMPLEX_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) PREFIX_EQUAL_COMPARE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) PREFIX_EQUAL_COMPARE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PREFIX_EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SMALLER_COMPARE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SMALLER_COMPARE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SMALLER_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SMALLER_OR_EQUAL_COMPARE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SMALLER_OR_EQUAL_COMPARE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SMALLER_OR_EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) SUFFIX_EQUAL_COMPARE_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) SUFFIX_EQUAL_COMPARE_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) SUFFIX_EQUAL_LOGIC_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) VULGAR_FRACTION_NUMBER_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) VULGAR_FRACTION_NUMBER_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) FRACTION_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) XDT_TEXT_CYBOL_TYPE, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p2, (void*) XDT_TEXT_CYBOL_TYPE_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PART_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode type. The type is unknown.");
    }
}

/* TYPE_DECODER_SOURCE */
#endif
