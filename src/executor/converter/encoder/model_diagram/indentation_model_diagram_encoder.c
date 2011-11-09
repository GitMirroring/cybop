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

#ifndef INDENTATION_MODEL_DIAGRAM_ENCODER_SOURCE
#define INDENTATION_MODEL_DIAGRAM_ENCODER_SOURCE

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../../../executor/converter/encoder/double_vector_encoder.c"
#include "../../../../executor/memoriser/reallocator/array_reallocator.c"
#include "../../../../executor/modifier/inserter/array_inserter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the model diagram indentation branch.
 *
 * @param p0 the destination model diagram item
 * @param p1 the properties flag
 */
void encode_model_diagram_indentation_branch(void* p0, void* p1) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram indentation branch.");

    // The properties flag.
    int d = *FALSE_BOOLEAN_MEMORY_MODEL;

    compare_integer_equal((void*) &d, p1, (void*) FALSE_BOOLEAN_MEMORY_MODEL);

    if (d != *FALSE_BOOLEAN_MEMORY_MODEL) {

        // This is the part MODEL, so that a plus- and minus character are used.

        // Append plus character.
        append_item_element(p0, (void*) PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

        // Append minus character.
        append_item_element(p0, (void*) HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    } else {

        // This is the part PROPERTIES, so that a number sign- and minus character are used.

        // Append plus character.
        append_item_element(p0, (void*) NUMBER_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

        // Append minus character.
        append_item_element(p0, (void*) HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
    }
}

/**
 * Encodes the model diagram indentation line.
 *
 * @param p0 the destination model diagram item
 * @param p1 the properties flag
 * @param p2 the tree level
 * @param p3 the current level
 */
void encode_model_diagram_indentation_line(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram indentation line.");

    // The next tree level.
    int n = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The last indentation flag.
    int l = *FALSE_BOOLEAN_MEMORY_MODEL;

    // Initialise next tree level.
    copy_integer((void*) &n, p3);

    // Increment next tree level.
    n++;

    // Check if the last of many indentations has been reached.
    compare_integer_smaller((void*) &l, (void*) &n, p2);

    if (l != *FALSE_BOOLEAN_MEMORY_MODEL) {

        // This is ONE OF MANY indentations before the actual part appears.
        // Therefore, use a pipe- and space character.

        // Append pipe character.
        append_item_element(p0, (void*) VERTICAL_LINE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

        // Append space character.
        append_item_element(p0, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    } else {

        // This is the LAST indentation. Special characters are used for it.

        encode_model_diagram_indentation_branch(p0, p1);
    }
}

/**
 * Encodes the model diagram indentation.
 *
 * @param p0 the destination model diagram item
 * @param p1 the properties flag
 * @param p2 the tree level
 */
void encode_model_diagram_indentation(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram indentation.");

    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

        encode_model_diagram_indentation_line(p0, p1, p2, (void*) &j);

        // Increment loop variable.
        j++;
    }
}

/* INDENTATION_MODEL_DIAGRAM_ENCODER_SOURCE */
#endif
