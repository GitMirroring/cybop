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

#ifndef PART_ALL_COMPARATOR_SOURCE
#define PART_ALL_COMPARATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/all/item_all_comparator.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Compares all elements of the left part with those of the right array.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the right array count
 * @param p6 the left part element index
 */
void compare_all_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare all part element.");

    // The left part element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get left part element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    // Compare all elements of the right array with those of the left part model item.
    compare_all_item_element(p0, e, p2, p3, p4, p5, (void*) DATA_ITEM_STATE_CYBOI_NAME);
}

/**
 * Compares all elements of the left- with those of the right part.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation type
 * @param p4 the operand type
 */
void compare_all_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare all part.");

    // The left model.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right model.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get left model.
    copy_array_forward((void*) &lm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right model.
    copy_array_forward((void*) &rm, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Compare all elements of the right- with those of the left part model item.
    compare_all_item(p0, lm, rm, p3, p4);
}

/**
 * Compares all elements of the left- with those of the right part.
 *
 * This function compares ALL meta elements: name, type, model, properties.
 *
 * The name, type, properties are ALWAYS compared for EQUALITY!
 * Anything else would not make sense and be pointless.
 * ONLY the actual model is compared using the given operation type.
 *
 * This comparison function is only called when comparing
 * two parts including their parts etc. (deep comparison).
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation type
 */
void compare_all_part_all(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare all part all.");

    // The left part name, type, model, properties.
    void* ln = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* la = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ld = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right part name, type, model, properties.
    void* rn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ra = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right part elements data, count.
    void* rad = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name, type, model, properties comparison results.
    int nr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int ar = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int mr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int dr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get left name, type, model, properties.
    copy_array_forward((void*) &ln, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &la, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ld, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get right part name, type, model, properties.
    copy_array_forward((void*) &rn, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ra, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rm, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rd, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get right part item data, count.
    copy_array_forward((void*) &rad, ra, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Overwrite left- with right part model item.
    // CAUTION! Do NOT use the basic function "compare_item" here,
    // since it does not compare the item counts.
    compare_all_item((void*) &nr, ln, rn, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
    compare_all_item((void*) &ar, la, ra, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
    compare_all_item((void*) &mr, lm, rm, p3, rad);
    compare_all_item((void*) &dr, ld, rd, (void*) EQUAL_LOGIC_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE);

    if ((nr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
        && (ar == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
        && (mr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
        && (dr == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

        // Set result to TRUE only if all comparisons of
        // name, type, model, properties delivered true.
        copy_integer(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* PART_ALL_COMPARATOR_SOURCE */
#endif
