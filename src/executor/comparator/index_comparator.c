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

#ifndef INDEX_COMPARATOR_SOURCE
#define INDEX_COMPARATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/comparator/offset_array_comparator.c"
#include "../../executor/verifier/double_index_count_verifier.c"
#include "../../logger/logger.c"

/**
 * Tests if the indices plus count are inside the array boundaries.
 *
 * @param p0 the result array (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the count
 * @param p6 the left index
 * @param p7 the right index
 * @param p8 the left count
 * @param p9 the right count
 */
void compare_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare index.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! An extra comparison of left- and right count is NOT necessary,
    // since the function "verify_double_index_count" called below tests if
    // left- and right index PLUS count are smaller than the left- and right count.
    //
    // If so, then this also means that the given count which determines the
    // number of elements to be compared is used EQUALLY for the left- AND right side
    // and hence does NOT have to be compared here.
    //

    verify_double_index_count((void*) &r, p5, p6, p7, p8, p9);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_array_offset(p0, p1, p2, p3, p4, p5, p6, p7);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare index. The indices plus count are outside the array boundaries.");
        fwprintf(stdout, L"Error: Could not compare index. The indices plus count are outside the array boundaries.\n");
        fwprintf(stdout, L"Hint: Count p5: %i\n", p5);
        fwprintf(stdout, L"Hint: Count *p5: %i\n", *((int*) p5));
        fwprintf(stdout, L"Hint: Left index p6: %i\n", p6);
        fwprintf(stdout, L"Hint: Left index *p6: %i\n", *((int*) p6));
        fwprintf(stdout, L"Hint: Right index p7: %i\n", p7);
        fwprintf(stdout, L"Hint: Right index *p7: %i\n", *((int*) p7));
        fwprintf(stdout, L"Hint: Left count p8: %i\n", p8);
        fwprintf(stdout, L"Hint: Left count *p8: %i\n", *((int*) p8));
        fwprintf(stdout, L"Hint: Right count p9: %i\n", p9);
        fwprintf(stdout, L"Hint: Right count *p9: %i\n", *((int*) p9));
    }
}

/* INDEX_COMPARATOR_SOURCE */
#endif
