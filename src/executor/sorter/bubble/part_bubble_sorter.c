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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PART_BUBBLE_SORTER_SOURCE
#define PART_BUBBLE_SORTER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/checker/operation_checker.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/sorter/bubble/criterion_bubble_sorter.c"
#include "../../../logger/logger.c"

/*
 * Compares the given operands of a part.
 *
 * The comparison criterion is a path to some value belonging to a part.
 * For example, the title of a song (in a list of songs to be sorted).
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left part (pointer reference)
 * @param p2 the right part (pointer reference)
 * @param p3 the operation type
 * @param p4 the criterion data (pointer reference)
 * @param p5 the criterion count
 * @param p6 the criterion type
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 */
void sort_bubble_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble part.");
    //?? fwprintf(stdout, L"Debug: Sort bubble part. criterion type p6: %i\n", p6);
    //?? fwprintf(stdout, L"Debug: Sort bubble part. criterion type *p6: %i\n", *((int*) p6));

    // The left part.
    void* lp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right part.
    void* rp = *NULL_POINTER_STATE_CYBOI_MODEL;

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A comparison criterion EXISTS.
        //
        // Therefore, determine left- and right part
        // as child elements of the given parts,
        // using the criterion as path.
        //

        sort_bubble_criterion((void*) &lp, (void*) &rp, p1, p2, p4, p5, p6, p7, p8, p9);

    } else {

        //
        // A comparison criterion does NOT exist.
        //
        // Therefore, assign left- and right part themselves.
        //

        copy_pointer((void*) &lp, p1);
        copy_pointer((void*) &rp, p2);
    }

    // The left part type, model item.
    void* lt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right part type, model item.
    void* rt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The left part type, model item data, count.
    void* ltd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right part type, model item data, count.
    void* rtd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get left part type, model item.
    copy_array_forward((void*) &lt, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lm, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right part type, model item.
    copy_array_forward((void*) &rt, rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rm, rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get left part type, model item data, count.
    copy_array_forward((void*) &ltd, lt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmc, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get right part type, model item data, count.
    copy_array_forward((void*) &rtd, rt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rmc, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, ltd, rtd);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation(p0, lmd, rmd, lmc, rmc, p3, ltd);

    } else {

        //
        // CAUTION! Comment out this log message since in some cases, it is
        // standard behaviour that a part does not exist so that the sort
        // criterion (left part or right part or both) cannot be found either.
        // In such cases, their types naturally differ as well.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sort bubble part. The left and right part have different types.");
        // fwprintf(stdout, L"Error: Could not sort bubble part. The left and right part have different types. ltd: %i, rtd: %i\n", ltd, rtd);
        // fwprintf(stdout, L"Error: Could not sort bubble part. The left and right part have different types. *ltd: %i, *rtd: %i\n", *((int*) ltd), *((int*) rtd));
        //
    }
}

/* PART_BUBBLE_SORTER_SOURCE */
#endif
