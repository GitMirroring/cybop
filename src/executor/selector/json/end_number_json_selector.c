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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef END_NUMBER_JSON_SELECTOR_SOURCE
#define END_NUMBER_JSON_SELECTOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "../../../executor/mover/mover.c"
#include "../../../executor/selector/whitespace/whitespace_selector.c"
#include "../../../logger/logger.c"

/**
 * Selects the json number end.
 *
 * @param p0 the source data position (pointer reference)
 * @param p1 the source count remaining
 * @param p2 the number count
 * @param p3 the break flag
 */
void select_json_number_end(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select json number end.");
    //?? fwprintf(stdout, L"Debug: Select json number end. count remaining p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Select json number end. count remaining *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // ,
        detect((void*) &r, p0, p1, (void*) SEPARATION_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SEPARATION_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // }
        detect((void*) &r, p0, p1, (void*) END_OBJECT_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_OBJECT_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // ]
        detect((void*) &r, p0, p1, (void*) END_ARRAY_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_ARRAY_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Detect whitespace character.
        select_whitespace((void*) &r, p0, p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The step.
        int step = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        // Move the current position.
        move(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &step, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Adjust number count.
        calculate_integer_add(p2, (void*) &step);
    }
}

/* END_NUMBER_JSON_SELECTOR_SOURCE */
#endif
