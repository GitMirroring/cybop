/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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
 * Selects the character reference end.
 *
 * @param p0 the break flag
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the character reference count
 */
void select_character_reference_end(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select character reference end.");
    //?? fwprintf(stdout, L"Debug: Select character reference end. source count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select character reference end. source count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) END_CHARACTER_REFERENCE_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_CHARACTER_REFERENCE_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The character reference end was found.
            //
            // CAUTION! The current position and remaining count were already
            // changed in the called function, to be processed further.
            //
            // The character reference count is left as it is.
            //

            // Set break flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The step.
        int step = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        // Move the current position.
        move(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &step, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Adjust character reference count.
        calculate_integer_add(p3, (void*) &step);
    }
}
