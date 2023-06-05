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
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the rows into tui.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the horizontal border character
 * @param p3 the vertical border character
 * @param p4 the left top border character
 * @param p5 the right top border character
 * @param p6 the left bottom border character
 * @param p7 the right bottom border character
 * @param p8 the position x
 * @param p9 the size x
 * @param p10 the position y
 * @param p11 the size y
 */
void serialise_tui_rows(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui rows.");

    // The loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The loop variable.
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The top border index.
    int ti = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The bottom border index.
    int bi = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The top, middle, bottom vertical position flags.
    int tp = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int mp = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int bp = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise loop count.
    copy_integer((void*) &c, p10);
    calculate_integer_add((void*) &c, p11);
    // Initialise loop variable.
    copy_integer((void*) &y, p10);
    // Initialise top border index.
    copy_integer((void*) &ti, (void*) &y);
    // Initialise bottom border index.
    copy_integer((void*) &bi, (void*) &c);
    calculate_integer_subtract((void*) &bi, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &y, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Determine vertical position of y coordinate.
        serialise_tui_vertical((void*) &tp, (void*) &mp, (void*) &bp, (void*) &y, (void*) &ti, (void*) &bi);
        serialise_tui_row(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, (void*) &y, (void*) &tp, (void*) &mp, (void*) &bp);

        // Increment loop variable.
        y++;
    }
}
