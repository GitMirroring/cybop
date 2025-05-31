/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Moves the current position and remaining count, depending on the move flag.
 *
 * @param p0 the comparison result
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the data
 * @param p4 the type
 * @param p5 the count
 * @param p6 the move flag
 */
void detect_comparison(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** p = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detect comparison.");
        //?? fwprintf(stdout, L"Debug: Detect comparison. count p5: %i\n", p5);
        //?? fwprintf(stdout, L"Debug: Detect comparison. count *p5: %i\n", *((int*) p5));

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        //
        // CAUTION! The remaining count may NOT be handed over as position count,
        // since it might be greater than the array count and would thus differ.
        // Therefore, hand over the given count p5 as parametre TWICE.
        //
        check_operation((void*) &r, *p, p3, p5, p5, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, p4);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Copy comparison result.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Move current position and remaining count.
            detect_moving(p1, p2, p4, p5, p6);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not detect comparison. The source data position is null.");
    }
}
