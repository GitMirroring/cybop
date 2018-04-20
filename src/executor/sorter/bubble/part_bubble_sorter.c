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
 * For example, the title of a song (in a list of songs to be sorted).
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left operand
 * @param p2 the right operand
 * @param p3 the operation type
 * @param p4 the comparison criterion
 */
void sort_bubble_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble part.");

    // The left part.
    // CAUTION! Initialise with given left operand.
    // CAUTION! Use as pointer reference, since this is a compound part.
    void** lp = (void**) p1;
    // The right part.
    // CAUTION! Initialise with given right operand.
    // CAUTION! Use as pointer reference, since this is a compound part.
    void** rp = (void**) p2;

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

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // A comparison criterion EXISTS.
        // Therefore, determine left- and right part using criterion as path.

        // Get left part.
//??        get_part_name((void*) &lp, p1, p?? [CRITERION-PATH_as_argument], p?? [CRITERION-PATH_as_argument_COUNT], p1, p2, p3, TODO??(type));
        // Get right part.
//??        get_part_name((void*) &rp, p1, p?? [CRITERION-PATH_as_argument], p?? [CRITERION-PATH_as_argument_COUNT], p1, p2, p3, TODO??(type));
    }

    // Get left part type, model item.
    copy_array_forward((void*) &lt, *lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lm, *lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get right part type, model item.
    copy_array_forward((void*) &rt, *rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rm, *rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get left part type, model item data, count.
    copy_array_forward((void*) &ltd, lt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmc, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get right part type, model item data, count.
    copy_array_forward((void*) &rtd, rt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rmc, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST sort bubble part ltd: %i \n", ltd);
fwprintf(stdout, L"TEST sort bubble part *ltd: %i \n", *((int*) ltd));

    // The comparison result.
    int rTODO = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &rTODO, ltd, rtd);

    if (rTODO != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, ltd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Apply lexicographic comparison "checker",
                // which always delivers just one return value.
                //
                // CAUTION! Do NOT use the tiven operation type p3 here,
                // since it represents a comparison (but NOT check) logic.
                // Instead, use the GREATER_CHECK_LOGIC_CYBOI_FORMAT.
                check_array_ascii(p0, lmd, rmd, lmc, rmc, (void*) GREATER_CHECK_LOGIC_CYBOI_FORMAT);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, ltd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Apply lexicographic comparison "checker",
                // which always delivers just one return value.
                //
                // CAUTION! Do NOT use the tiven operation type p3 here,
                // since it represents a comparison (but NOT check) logic.
                // Instead, use the GREATER_CHECK_LOGIC_CYBOI_FORMAT.
                check_array(p0, lmd, rmd, lmc, rmc, (void*) GREATER_CHECK_LOGIC_CYBOI_FORMAT);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Use standard comparison for all other cases.
            //

            // Apply standard comparison with only ONE return value,
            // i.e. NOT a return value vector.
            //
            //?? TODO: Use DEEP compare flag here if implemented one day in the future.
            compare(p0, lmd, rmd, p3, ltd);
        }

    } else {

        fwprintf(stdout, L"Error: Could not sort bubble part. The left and right part have different types.");
        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sort bubble part. The left and right part have different types.");
    }
}

/* PART_BUBBLE_SORTER_SOURCE */
#endif
