/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Checks two arrays lexicographically.
 *
 * In order to achieve this, different functions have to be handed over,
 * depending on the given operation type (operator).
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left data
 * @param p2 the right data
 * @param p3 the left count
 * @param p4 the right count
 * @param p5 the operation type
 * @param p6 the operand type
 */
void check_insensitiveness(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check insensitiveness.");
    fwprintf(stdout, L"Debug: Check insensitiveness. left count p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Check insensitiveness. left count *p3: %i\n", *((int*) p3));

    // The left lower case item.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right lower case item.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The left lower case item data, count.
    void* ld = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right lower case item data, count.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate left lower case item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p6);
    //
    // Allocate right lower case item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &r, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p6);

    // Convert left lower case item to lower case.
    lower_string(l, p1, p3, p6);
    // Convert right lower case item to lower case.
    lower_string(r, p2, p4, p6);

    //
    // Get left lower case item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &ld, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lc, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    //
    // Get right lower case item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rc, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Compare left with right lower case item.
    check_operation(p0, ld, rd, lc, rc, p5, p6);

    // Deallocate left lower case item.
    deallocate_item((void*) &l, p6);
    // Deallocate right lower case item.
    deallocate_item((void*) &r, p6);
}
