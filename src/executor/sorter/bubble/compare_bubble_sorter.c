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

#ifndef COMPARE_BUBBLE_SORTER_SOURCE
#define COMPARE_BUBBLE_SORTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/checker/array_checker.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/comparator.c"
#include "../../../logger/logger.c"

/*
 * Compares the given operands.
 *
 * If their type is string (wide or ascii), then a checker
 * function is called for lexicographic comparison.
 * For all other types, standard comparison is used.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left model data
 * @param p2 the right model data
 * @param p3 the left model count
 * @param p4 the right model count
 * @param p5 the operation type
 * @param p6 the string operation type
 * @param p7 the operand type
 */
void sort_bubble_compare(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble compare.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Apply lexicographic comparison "checker",
            // which always delivers just one return value.
            //
            // CAUTION! Do NOT use the given operation type here,
            // since it represents a comparison logic.
            // Instead, use the given string comparison ("check") logic.
            check_array(p0, p1, p2, p3, p4, p6, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Apply lexicographic comparison "checker",
            // which always delivers just one return value.
            //
            // CAUTION! Do NOT use the given operation type here,
            // since it represents a comparison logic.
            // Instead, use the given string comparison ("check") logic.
            check_array(p0, p1, p2, p3, p4, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
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
        compare(p0, p1, p2, p5, p7);
    }
}

/* COMPARE_BUBBLE_SORTER_SOURCE */
#endif
