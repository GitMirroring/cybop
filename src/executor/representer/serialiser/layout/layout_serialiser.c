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
#include "logger.h"

/**
 * Serialises layout properties into graphical user interface (gui) coordinates.
 *
 * @param p0 the model data
 * @param p1 the model count
 * @param p2 the position x
 * @param p3 the position y
 * @param p4 the size width
 * @param p5 the size height
 * @param p6 the window flag
 * @param p7 the layout properties data
 * @param p8 the layout properties count
 * @param p9 the knowledge memory part (pointer reference)
 * @param p10 the stack memory item
 * @param p11 the internal memory data
 * @param p12 the layout data
 * @param p13 the layout count
 */
void serialise_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout.");

    //?? fwprintf(stdout, L"Debug: serialise layout: %ls\n", (wchar_t*) p12);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p12, (void*) ABSOLUTE_LAYOUT_CYBOL_MODEL, p13, (void*) ABSOLUTE_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_layout_absolute_size(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p12, (void*) BORDER_LAYOUT_CYBOL_MODEL, p13, (void*) BORDER_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_layout_border_size(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p12, (void*) BOX_LAYOUT_CYBOL_MODEL, p13, (void*) BOX_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? Layout in a row or column WITHOUT breaking them.
            //?? If a row break is desired, then use flow layout.

            fwprintf(stdout, L"Debug: Serialise layout BOX.");

            //?? serialise_layout_box_size(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p12, (void*) FLOW_LAYOUT_CYBOL_MODEL, p13, (void*) FLOW_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_layout_flow_size(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p12, (void*) GRID_LAYOUT_CYBOL_MODEL, p13, (void*) GRID_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Possibly add window flag p6 as argument, if necessary.
            serialise_layout_grid_size(p0, p1, p2, p3, p4, p5, p7, p8, p9, p10, p11, p12, p13);
        }
    }
}
