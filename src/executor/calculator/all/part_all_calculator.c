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
 * @version $RCSfile: compound_accessor.c,v $ $Revision: 1.64 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_ALL_CALCULATOR_SOURCE
#define PART_ALL_CALCULATOR_SOURCE

#include "../../../constant/type/cybol/number_cybol_type.c"
#include "../../../constant/type/cybol/path_cybol_type.c"
#include "../../../constant/type/memory/memory_type.c"
#include "../../../constant/type/memory/memory_type.c"
#include "../../../constant/model/log/message_log_model.c"
#include "../../../constant/model/memory/integer_memory_model.c"
#include "../../../constant/model/memory/pointer_memory_model.c"
#include "../../../constant/name/cybol/separator_cybol_name.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../executor/comparator/all/item_all_comparator.c"
#include "../../../executor/converter/decoder/wide_character_type_decoder.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Calculates all elements of the left part with those of the right array.
 *
 * @param p0 the result (left unchanged in case of an error)
 * @param p1 the left part
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the right array count
 * @param p6 the left part element index
 */
void calculate_all_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Calculate all part element.");

    // The left part element.
    void* e = *NULL_POINTER_MEMORY_MODEL;

    // Get left part element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p6);

    // Calculate all elements of the right array with those of the left part model item.
    calculate_all_item_element(p0, e, p2, p3, p4, p5, (void*) DATA_ITEM_MEMORY_NAME);
}

/**
 * Calculates all elements of the left- with those of the right part.
 *
 * @param p0 the result (left unchanged in case of an error)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation type
 * @param p4 the operand type
 */
void calculate_all_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Calculate all part.");

    // The left model.
    void* lm = *NULL_POINTER_MEMORY_MODEL;
    // The right model.
    void* rm = *NULL_POINTER_MEMORY_MODEL;

    // Get left model.
    copy_array_forward((void*) &lm, p1, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    // Get right model.
    copy_array_forward((void*) &rm, p2, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Calculate all elements of the right- with those of the left part model item.
    calculate_all_item(p0, lm, rm, p3, p4);
}

/**
 * Calculates all elements of the left- with those of the right part.
 *
 * ONLY the actual model is calculated using the given operation type.
 * This function does NOT change the meta elements: name, type, details.
 *
 * This function is only called when calculating two parts
 * including their parts etc. (deep calculation).
 *
 * @param p0 the result (left unchanged in case of an error)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation type
 */
void calculate_all_part_model(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_MEMORY_MODEL) {

        void** rp = (void**) p2;

        if (p1 != *NULL_POINTER_MEMORY_MODEL) {

            void** lp = (void**) p1;

            log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Calculate all part model.");

            // The left part name, type, model, details.
            void* ln = *NULL_POINTER_MEMORY_MODEL;
            void* la = *NULL_POINTER_MEMORY_MODEL;
            void* lm = *NULL_POINTER_MEMORY_MODEL;
            // The right part name, type, model, details.
            void* rn = *NULL_POINTER_MEMORY_MODEL;
            void* ra = *NULL_POINTER_MEMORY_MODEL;
            void* rm = *NULL_POINTER_MEMORY_MODEL;
            // The right part type data.
            void* rad = *NULL_POINTER_MEMORY_MODEL;
            // The name, type comparison results.
            int nr = *FALSE_BOOLEAN_MEMORY_MODEL;
            int ar = *FALSE_BOOLEAN_MEMORY_MODEL;

            // Get left name, type, model, details.
            copy_array_forward((void*) &ln, *lp, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
            copy_array_forward((void*) &la, *lp, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
            copy_array_forward((void*) &lm, *lp, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            // Get right part name, type, model, details.
            copy_array_forward((void*) &rn, *rp, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
            copy_array_forward((void*) &ra, *rp, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
            copy_array_forward((void*) &rm, *rp, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            // Get right part type data.
            copy_array_forward((void*) &rad, ra, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);

            // Compare left- with right part model item.
            // CAUTION! Do NOT use the basic function "compare_item" here,
            // since it does not compare the item counts.
            compare_all_item((void*) &nr, ln, rn, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE);
            compare_all_item((void*) &ar, la, ra, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) INTEGER_MEMORY_TYPE);

            if ((nr == *FALSE_BOOLEAN_MEMORY_MODEL)
                && (ar == *FALSE_BOOLEAN_MEMORY_MODEL)) {

                // Calculate result model only if comparisons of
                // name and type delivered true.
                calculate_all_item((void*) &mr, lm, rm, p3, (void*) &rad);
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not calculate all part all. The left part is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not calculate all part all. The right part is null.");
    }
}

/* PART_ALL_CALCULATOR_SOURCE */
#endif
