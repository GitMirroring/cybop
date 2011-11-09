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

#ifndef PART_MODEL_DIAGRAM_ENCODER_SOURCE
#define PART_MODEL_DIAGRAM_ENCODER_SOURCE

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
#include "../../../../executor/modifier/inserter/array_inserter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void encode_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);

/**
 * Encodes the model diagram part part.
 *
 * @param p0 the destination model diagram item
 * @param p1 the source model data
 * @param p2 the source model index
 * @param p3 the details flag
 * @param p4 the tree level
 */
void encode_model_diagram_part_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram part part.");

    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The part name, type, model, details.
    void* n = *NULL_POINTER_MEMORY_MODEL;
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* m = *NULL_POINTER_MEMORY_MODEL;
    void* d = *NULL_POINTER_MEMORY_MODEL;
    // The part name, type, model, details data, count.
    void* nd = *NULL_POINTER_MEMORY_MODEL;
    void* nc = *NULL_POINTER_MEMORY_MODEL;
    void* ad = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* md = *NULL_POINTER_MEMORY_MODEL;
    void* mc = *NULL_POINTER_MEMORY_MODEL;
    void* dd = *NULL_POINTER_MEMORY_MODEL;
    void* dc = *NULL_POINTER_MEMORY_MODEL;

    // Get part from source whole at current index.
    copy_array_forward((void*) &p, p1, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p2);
    // Get part name, type, model, details.
    copy_array_forward((void*) &n, p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &a, p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
    copy_array_forward((void*) &m, p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &d, p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);
    // Get part name, type, model, details data, count.
    copy_array_forward((void*) &nd, n, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &nc, n, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &ad, a, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &ac, a, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &dd, d, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // Append line feed character.
    append_item_element(p0, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    // Encode part.
    encode_model_diagram_node(p0, nd, nc, ad, ac, md, mc, dd, dc, p3, p4);
}

/**
 * Encodes the model diagram part.
 *
 * @param p0 the destination model diagram item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the details flag
 * @param p4 the tree level
 */
void encode_model_diagram_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode model diagram part.");

    // The new tree level.
    //
    // It gets initialised with the current tree level incremented by one.
    //
    // CAUTION! Do NOT manipulate the original tree level that was handed over as parameter!
    // Otherwise, it would never be decremented anymore leading to wrong indentation.
    int l = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Initialise new tree level with current tree level.
    copy_integer((void*) &l, p4);
    // Increment new tree level.
    calculate_integer_add((void*) &l, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);

    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

        encode_model_diagram_part_part(p0, p1, (void*) &j, p3, (void*) &l);

        // Increment loop variable.
        j++;
    }
}

/* PART_MODEL_DIAGRAM_ENCODER_SOURCE */
#endif
