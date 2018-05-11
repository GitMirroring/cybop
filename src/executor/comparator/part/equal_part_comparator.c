/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EQUAL_PART_COMPARATOR_SOURCE
#define EQUAL_PART_COMPARATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/*??
#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/part/equal_part_comparator.c"
#include "../../../executor/comparator/item_comparator.c"
*/

/**
 * Compares the left- with the right part for equality.
 *
 * It considers the following meta elements: name, type, model, properties.
 *
 * This is DEEP COMPARISON, i.e. all child nodes will be compared as well.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the count
 * @param p6 the left index
 * @param p7 the right index
 */
void compare_part_equal(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** r = (void**) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** l = (void**) p1;

            // CAUTION! Do NOT call the logger here.
            // It might use functions that cause circular references.
            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare part equal.");

            // The left part name, type, model, properties item.
            void* ln = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lt = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* lp = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The right part name, type, model, properties item.
            void* rn = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* rt = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* rp = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The right part type data.
            void* rtd = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The name, type, model, properties comparison results.
            int nr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            int tr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            int mr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            int pr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // Get left name, type, model, properties item.
            copy_array_forward((void*) &ln, *l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lt, *l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lm, *l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &lp, *l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
            // Get right part name, type, model, properties item.
            copy_array_forward((void*) &rn, *r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &rt, *r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &rm, *r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            copy_array_forward((void*) &rp, *r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
            // Get right part item data.
            copy_array_forward((void*) &rtd, rt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            // Compare left- with right part type item.
//??            compare_item_equal((void*) &tr, lt, rt, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            if (tr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The left and right type are identical.
                // This is a prerequisite to compare the part models below.
                // When using wrong type for either left or right part model,
                // then severe memory access errors might occur.
                //

                // Compare left- with right part items.
                // CAUTION! Do NOT use the basic function "compare_item" here,
                // since it does NOT compare the item counts.
                //?? TODO: Manually compare item counts?
/*?? TODO:
                compare_item_equal((void*) &nr, ln, rn, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
                compare_item_equal((void*) &mr, lm, rm, p3, rtd);
                compare_item_equal((void*) &pr, lp, rp, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
*/

                if ((nr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (tr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (mr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (pr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

                    // Set result to FALSE if at least one comparison of
                    // name, type, model, properties delivered false.
                    copy_integer(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                } else {

                    copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                }
            }

        } else {

            // CAUTION! Do NOT call the logger here.
            // It might use functions that cause circular references.
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare part equal. The left part is null.");
        }

    } else {

        // CAUTION! Do NOT call the logger here.
        // It might use functions that cause circular references.
        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare part equal. The right part is null.");
    }
}

//
// Recursively call a comparison function, which in turn
// may call this comparison function and so forth.
// This is necessary when processing knowledge tree hierarchies.
//

/*??
void compare_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare part.");

    // The left model.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right model.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get left model.
    copy_array_forward((void*) &lm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right model.
    copy_array_forward((void*) &rm, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Compare all elements of the left- with those of the right part model item.
    compare_item(p0, lm, rm, p3, p4, p5, p6, p7);
}
*/

/* EQUAL_PART_COMPARATOR_SOURCE */
#endif
