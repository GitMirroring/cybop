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

#ifndef PART_ALL_CALCULATOR_SOURCE
#define PART_ALL_CALCULATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/all/item_all_calculator.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Calculates all elements of the result part with those of the operand array.
 *
 * @param p0 the result part, which contains the operands BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the operand array count
 * @param p5 the result part element index
 */
void calculate_all_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate all part element.");

    // The result part element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result part element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p5);

    // Calculate all elements of the operand array with those of the result part model item.
    calculate_all_item_element(e, p1, p2, p3, p4, (void*) DATA_ITEM_STATE_CYBOI_NAME);
}

/**
 * Calculates all elements of the result- with those of the operand part.
 *
 * @param p0 the result part, which contains the operands BEFORE the operation
 * @param p1 the operand part
 * @param p2 the operation type
 * @param p3 the operand type
 */
void calculate_all_part(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate all part.");

    // The result model.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand model.
    void* om = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get result model.
    copy_array_forward((void*) &rm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get operand model.
    copy_array_forward((void*) &om, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Calculate all elements of the operand- with those of the result part model item.
    calculate_all_item(rm, om, p2, p3);
}

/**
 * Calculates all elements of the result- with those of the operand part.
 *
 * ONLY the actual model is calculated using the given operation type.
 * This function does NOT change the meta elements: name, type, properties.
 *
 * This function is only called when calculating two parts
 * including their parts etc. (deep calculation).
 *
 * @param p0 the result part, which contains the operands BEFORE the operation
 * @param p1 the operand part
 * @param p2 the operation type
 */
/*?? TODO: not sure if this function is needed at all?
void calculate_all_part_all(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** rp = (void**) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** lp = (void**) p1;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate all part model.");

            // The left part name, type, model, properties.
            void* ln = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* la = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The right part name, type, model, properties.
            void* rn = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* ra = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The right part type data.
            void* rad = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The name, type comparison results.
            int nr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            int ar = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // Get left name, type, model, properties.
            copy_array_forward((void*) &ln, *lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &la, *lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lm, *lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            // Get right part name, type, model, properties.
            copy_array_forward((void*) &rn, *rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &ra, *rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &rm, *rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            // Get right part type data.
            copy_array_forward((void*) &rad, ra, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            // Compare left- with right part model item.
            // CAUTION! Do NOT use the basic function "compare_item" here,
            // since it does not compare the item counts.
            compare_all_item((void*) &nr, ln, rn, (void*) EQUAL_COMPARE_LOGIC_FORMAT_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            compare_all_item((void*) &ar, la, ra, (void*) EQUAL_COMPARE_LOGIC_FORMAT_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            if ((nr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
                && (ar == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

                // Calculate result model only if comparisons of
                // name and type delivered true.
                calculate_all_item((void*) &mr, lm, rm, p3, (void*) &rad);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate all part all. The left part is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate all part all. The right part is null.");
    }
}
*/

/* PART_ALL_CALCULATOR_SOURCE */
#endif
