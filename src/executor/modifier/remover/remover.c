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

#ifndef REMOVER_SOURCE
#define REMOVER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../executor/modifier/remover/inside_remover.c"
#include "logger.h"

/**
 * Removes the given number of elements from the array, starting from the index.
 *
 * CAUTION! Do NOT rename this function to "remove", since that name is
 * already used by low-level glibc functionality in header file "stdio.h".
 * Function: int remove (const char *filename)
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the type
 * @param p2 the count
 * @param p3 the destination index
 * @param p4 the destination array count
 * @param p5 the destination array size
 * @param p6 the adjust count flag
 */
void remove_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Remove.");
    //?? fwprintf(stdout, L"Debug: Remove. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Remove. *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &r, p3, p4);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            remove_inside(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove. The array is empty.");
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not remove. The destination index is outside the array boundaries.");
    }
}

/* REMOVER_SOURCE */
#endif
