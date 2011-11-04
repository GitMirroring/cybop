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
 * @version $RCSfile: model_diagram_converter.c,v $ $Revision: 1.29 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NODE_MODEL_DIAGRAM_ENCODER_SOURCE
#define NODE_MODEL_DIAGRAM_ENCODER_SOURCE

#include "../../../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../../../constant/abstraction/memory/memory_abstraction.c"
#include "../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/converter/encoder/model_diagram/compound_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/model_diagram/indentation_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/model_diagram/line_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../../../executor/converter/encoder/double_vector_encoder.c"
#include "../../../../executor/modifier/inserter/array_inserter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the model diagram node.
 *
 * @param p0 the destination model diagram item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source abstraction data
 * @param p4 the source abstraction count
 * @param p5 the source model data
 * @param p6 the source model count
 * @param p7 the source details data
 * @param p8 the source details count
 * @param p9 the details flag
 * @param p10 the tree level
 */
void encode_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram node.");

    // Add indentation.
    encode_model_diagram_indentation(p0, p1, p2, p11, p12);

    // Add part name to destination array.
    overwrite_array(p0, p3, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p4, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);

    // Add line.
    encode_model_diagram_line(p0, p1, p2);

    // Add part abstraction to destination array.
    overwrite_array(p0, p5, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) PART_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) PART_MEMORY_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Add part model to destination array.
            encode_model_diagram_part(p0, p1, p2, p7, p8, p11, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            encode_model_diagram_line(p0, p1, p2);
            overwrite_array(p0, p7, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p8, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) FRACTION_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) FRACTION_MEMORY_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            encode_model_diagram_line(p0, p1, p2);
            encode_double_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) INTEGER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) INTEGER_MEMORY_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            encode_model_diagram_line(p0, p1, p2);
            encode_integer_vector(p0, p1, p2, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) KNOWLEDGE_PATH_MEMORY_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            encode_model_diagram_line(p0, p1, p2);
            overwrite_array(p0, p7, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p8, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) OPERATION_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) OPERATION_MEMORY_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            encode_model_diagram_line(p0, p1, p2);
            overwrite_array(p0, p7, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p8, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_all_array((void*) &r, p5, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) EQUAL_PRIMITIVE_OPERATION_ABSTRACTION, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p6, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            encode_model_diagram_line(p0, p1, p2);
            overwrite_array(p0, p7, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p8, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
        }
    }

    // CAUTION! Do NOT move this test to the beginning of the function!
    // Otherwise, a model will not be processed, if the details happen to be null.
    if (p10 != *NULL_POINTER_MEMORY_MODEL) {

        // Add part details to destination array.
        encode_model_diagram_part(p0, p1, p2, p9, p10, p11, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not encode model diagram node. The details count is null.");
    }
}

/* NODE_MODEL_DIAGRAM_ENCODER_SOURCE */
#endif
