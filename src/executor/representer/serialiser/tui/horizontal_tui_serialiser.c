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
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Determines the horizontal position of the given y coordinate.
 *
 * @param p0 the destination left horizontal position flag
 * @param p1 the destination centre horizontal position flag
 * @param p2 the destination right horizontal position flag
 * @param p3 the source x coordinate
 * @param p4 the left border index
 * @param p5 the right border index
 */
void serialise_tui_horizontal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui horizontal.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, p4);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is the left side.
            //

            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, p5);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is the right side.
            //

            copy_integer(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is the centre.
        //

        copy_integer(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        copy_integer(p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}
