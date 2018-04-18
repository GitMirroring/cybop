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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_BUBBLE_SORTER_SOURCE
#define PART_BUBBLE_SORTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../logger/logger.c"

/*
 * Compares the given operands of a part.
 *
 * The comparison criterion is a path to some value belonging to a part.
 * For example, the title of a song in a list of songs to be sorted.
 *
 * @param p0 the result
 * @param p1 the left operand
 * @param p2 the right operand
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the comparison criterion
 */
void sort_bubble_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble part.");

    // The left part.
    // CAUTION! Initialise with given left operand.
    void* lp = p1;
    // The right part.
    // CAUTION! Initialise with given right operand.
    void* rp = p2;

    // The left part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The left part model item data, count.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right part model item data, count.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // A comparison criterion EXISTS.
        // Therefore, determine left- and right part using criterion as path.

        //?? TODO

        // Get left part.
//??        get_part_name((void*) &lp, p1, p?? [CRITERION-PATH_as_argument], p?? [CRITERION-PATH_as_argument_COUNT], p1, p2, p3, p4);
        // Get right part.
//??        get_part_name((void*) &rp, p1, p?? [CRITERION-PATH_as_argument], p?? [CRITERION-PATH_as_argument_COUNT], p1, p2, p3, p4);
    }

fwprintf(stdout, L"TEST sort bubble part p1: %i \n", p1);
fwprintf(stdout, L"TEST sort bubble part lp: %i \n", lp);
fwprintf(stdout, L"TEST sort bubble part pre lm: %i \n", lm);

    // Get left part model item.
    copy_array_forward((void*) &lm, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right part model item.
    copy_array_forward((void*) &rm, rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST sort bubble part post lm: %i \n", lm);
fwprintf(stdout, L"TEST sort bubble part post rm: %i \n", rm);
fwprintf(stdout, L"TEST sort bubble part pre lmd: %i \n", lmd);

    // Get left part model item data.
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get right part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST sort bubble part post lmd: %i \n", lmd);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Apply lexicographic comparison "checker", which always delivers just one return value.

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Apply lexicographic comparison "checker", which always delivers just one return value.

            //?? TODO
        }
    }

fwprintf(stdout, L"TEST sort bubble part: %i \n", 8);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Use standard comparison for all other cases.
        //

        // Apply standard comparison with only ONE return value,
        // i.e. NOT a return value vector.
        compare(p0, p1, p2, p3, p4);
    }
fwprintf(stdout, L"TEST sort bubble part: %i \n", 9);

}

/* PART_BUBBLE_SORTER_SOURCE */
#endif
