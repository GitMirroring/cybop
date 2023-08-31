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

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Detects a sign character.
 *
 * Returns TRUE if a sign character is found.
 *
 * The position pointer is moved only if the MOVE flag is set.
 *
 * The detected signs are:
 * - plus with symbol +
 * - minus with symbol -
 *
 * @param p0 the destination sign flag
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the move flag
 * @param p4 the move count
 */
void select_sign(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select sign.");
    //?? fwprintf(stdout, L"Debug: Select sign. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select sign. count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination sign flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Adjust move count.
            calculate_integer_add(p4, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

            // Set destination sign flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }
}
