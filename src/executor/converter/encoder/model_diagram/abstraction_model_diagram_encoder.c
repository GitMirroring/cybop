/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: type_converter.c,v $ $Revision: 1.17 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TYPE_MODEL_DIAGRAM_ENCODER_SOURCE
#define TYPE_MODEL_DIAGRAM_ENCODER_SOURCE

#include "../../../../constant/type/model_diagram/model_diagram_type.c"
#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/type/operation/operation_type.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the cyboi type into a model diagram type.
 *
 * @param p0 the destination model diagram item
 * @param p1 the source type
 */
void encode_model_diagram_type(void* p0, void* p1) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram type.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) BOOLEAN_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) BOOLEAN_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) BOOLEAN_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CHARACTER_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) ENCAPSULATED_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) INTEGER_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) INTEGER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) INTEGER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) KNOWLEDGE_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) KNOWLEDGE_PATH_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) KNOWLEDGE_PATH_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) PART_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) PART_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PART_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) WIDE_CHARACTER_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) WIDE_CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) WIDE_CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

/*??
    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) EQUAL_COMPARE_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GREATER_COMPARE_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) GREATER_OR_EQUAL_COMPARE_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) PREFIX_EQUAL_COMPARE_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            overwrite_array(p0, p1, p2, (void*) PREFIX_EQUAL_OPERATION_TYPE, (void*) PREFIX_EQUAL_OPERATION_TYPE_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SMALLER_COMPARE_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            overwrite_array(p0, p1, p2, (void*) SMALLER_OPERATION_TYPE, (void*) SMALLER_OPERATION_TYPE_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SMALLER_OR_EQUAL_COMPARE_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            overwrite_array(p0, p1, p2, (void*) SMALLER_OR_EQUAL_OPERATION_TYPE, (void*) SMALLER_OR_EQUAL_OPERATION_TYPE_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SUFFIX_EQUAL_COMPARE_TYPE);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            append_item_element(p0, (void*) CHARACTER_MODEL_DIAGRAM_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CHARACTER_MODEL_DIAGRAM_TYPE_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
            overwrite_array(p0, p1, p2, (void*) SUFFIX_EQUAL_OPERATION_TYPE, (void*) SUFFIX_EQUAL_OPERATION_TYPE_COUNT, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE_COUNT);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not encode type. The type is unknown.");
    }
}

/* TYPE_MODEL_DIAGRAM_ENCODER_SOURCE */
#endif
