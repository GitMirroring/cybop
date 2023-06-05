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
 * @version CYBOP 0.26.0 2023-04-04
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

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Detects and skips the decimal digit characters 0..9.
 *
 * Returns TRUE if a digit character is found.
 *
 * The position pointer is moved only if the MOVE flag is set.
 *
 * The detected digits are:
 * - zero with symbol 0
 * - one with symbol 1
 * - two with symbol 2
 * - three with symbol 3
 * - four with symbol 4
 * - five with symbol 5
 * - six with symbol 6
 * - seven with symbol 7
 * - eight with symbol 8
 * - nine with symbol 9
 *
 * @param p0 the destination digit flag
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the move flag
 * @param p4 the move count
 */
void select_digit_decimal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select digit decimal.");
    //?? fwprintf(stdout, L"Debug: Select digit decimal. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select digit decimal. count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_ONE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_TWO_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_THREE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_FOUR_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_FIVE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_SIX_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_SEVEN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_EIGHT_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) DIGIT_NINE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination digit flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }
}
