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
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Serialises a part into text user interface (tui).
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the source model data
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the sign flag
 * @param p7 the number base
 * @param p8 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p9 the decimal separator data
 * @param p10 the decimal separator count
 * @param p11 the decimal places
 * @param p12 the scientific notation flag
 * @param p13 the newline flag
 * @param p14 the clear flag
 * @param p15 the positioning flag
 * @param p16 the knowledge memory part (pointer reference)
 * @param p17 the stack memory item
 * @param p18 the internal memory data
 * @param p19 the tree level
 * @param p20 the original attributes
 * @param p21 the format
 */
void serialise_tui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p21, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_tui_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20);
        }
    }

    //
    // Other formats
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        serialise_tui_primitive(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p21);
    }
}
