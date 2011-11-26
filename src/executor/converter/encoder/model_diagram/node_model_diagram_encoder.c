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

#ifndef NODE_MODEL_DIAGRAM_ENCODER_SOURCE
#define NODE_MODEL_DIAGRAM_ENCODER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/converter/encoder/model_diagram/indentation_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/model_diagram/line_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/model_diagram/part_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/model_diagram/type_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/cybol/integer/integer_cybol_encoder.c"
#include "../../../../executor/converter/encoder/cybol/double/double_cybol_encoder.c"
#include "../../../../executor/modifier/inserter/array_inserter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the model diagram node.
 *
 * @param p0 the destination model diagram item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source type data
 * @param p4 the source type count
 * @param p5 the source model data
 * @param p6 the source model count
 * @param p7 the source properties data
 * @param p8 the source properties count
 * @param p9 the properties flag
 * @param p10 the tree level
 */
void encode_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Encode model diagram node.");

    // Append indentation.
    encode_model_diagram_indentation(p0, p9, p10);

    // Append part name.
    append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Append line.
    encode_model_diagram_line(p0);

    // Append part type.
    encode_type(p0, p3);

    //
    // Append part model.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_model_diagram_part(p0, p5, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p10);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) ENCAPSULATED_PATH_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_model_diagram_line(p0);
            append_item_element(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_model_diagram_line(p0);
            encode_cybol_double(p0, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_model_diagram_line(p0);
            encode_cybol_integer(p0, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) KNOWLEDGE_PATH_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_model_diagram_line(p0);
            append_item_element(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            encode_model_diagram_line(p0);
            append_item_element(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    // Append part properties.
    encode_model_diagram_part(p0, p7, p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p10);
}

/* NODE_MODEL_DIAGRAM_ENCODER_SOURCE */
#endif
