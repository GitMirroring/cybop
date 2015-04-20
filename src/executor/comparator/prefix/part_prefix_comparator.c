/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_PREFIX_COMPARATOR_SOURCE
#define PART_PREFIX_COMPARATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/prefix/item_prefix_comparator.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Compares if the right array is a prefix of the left part.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the right array count
 * @param p6 the left part element index
 */
void compare_prefix_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare prefix part element.");

    // The left part element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get left part element.
    copy_array_forward((void*) &e, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    // Compare if the right array is a prefix of the left part model item.
    compare_prefix_item_element(p0, e, p2, p3, p4, p5, (void*) DATA_ITEM_STATE_CYBOI_NAME);
}

/**
 * Compares if the right- is a prefix of the left part.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part
 * @param p2 the right part
 * @param p3 the operation type
 * @param p4 the operand type
 */
void compare_prefix_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare prefix part.");

    // The left model.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right model.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get left model.
    copy_array_forward((void*) &lm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right model.
    copy_array_forward((void*) &rm, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Compare if the right- is a prefix of the left part model item.
    compare_prefix_item(p0, lm, rm, p3, p4);
}

/* PART_PREFIX_COMPARATOR_SOURCE */
#endif
