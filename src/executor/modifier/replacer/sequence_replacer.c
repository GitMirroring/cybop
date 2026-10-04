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
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Replaces the searchterm sequence with the replacement sequence.
 * Appends the unchanged source data otherwise.
 *
 * @param p0 the destination wide character item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the searchterm data
 * @param p4 the searchterm count
 * @param p5 the replacement data
 * @param p6 the replacement count
 */
void replace_sequence(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** sd = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Replace sequence.");
        fwprintf(stdout, L"Debug: Replace sequence. source count remaining p2: %i\n", p2);
        fwprintf(stdout, L"Debug: Replace sequence. source count remaining *p2: %i\n", *((int*) p2));

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        //
        // searchterm sequence
        //

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            detect((void*) &r, p1, p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Append replacement sequence to destination item.
                modify_item(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
            }
        }

        //
        // other
        //

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append source data to destination item.
            modify_item(p0, *sd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            //
            // Increment the current position by one.
            //
            // CAUTION! Move position only AFTER having copied the source character
            // above since otherwise, it gets skipped and is lost.
            //
            move(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not replace sequence. The source data position is null.");
        fwprintf(stdout, L"Error: Could not replace sequence. The source data position is null. source data position p1: %i\n", p1);
    }
}
