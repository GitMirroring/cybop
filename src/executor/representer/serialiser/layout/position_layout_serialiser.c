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

#ifndef POSITION_LAYOUT_SERIALISER_SOURCE
#define POSITION_LAYOUT_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/checker/operation_checker.c"
#include "../../../../executor/representer/serialiser/layout/absolute/position_absolute_layout_serialiser.c"
#include "../../../../executor/representer/serialiser/layout/grid/position_grid_layout_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises layout position.
 *
 * @param p0 the destination element (child) position x
 * @param p1 the destination element (child) position y
 * @param p2 the source element (child) width
 * @param p3 the source element (child) height
 * @param p4 the source position x
 * @param p5 the source position y
 * @param p6 the element (child) index
 * @param p7 the layout data
 * @param p8 the layout count
 */
void serialise_layout_position(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout position.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p7, (void*) ABSOLUTE_LAYOUT_CYBOL_MODEL, p8, (void*) ABSOLUTE_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_layout_absolute_position(p0, p1, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p7, (void*) BORDER_LAYOUT_CYBOL_MODEL, p8, (void*) BORDER_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_layout_border_position(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p7, (void*) BOX_LAYOUT_CYBOL_MODEL, p8, (void*) BOX_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Debug: Serialise layout position BOX.");

            //?? Layout in a row or column WITHOUT breaking them.
            //?? If a row break is desired, then use flow layout.

            //?? serialise_layout_box_position(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p7, (void*) FLOW_LAYOUT_CYBOL_MODEL, p8, (void*) FLOW_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_layout_flow_position(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p7, (void*) GRID_LAYOUT_CYBOL_MODEL, p8, (void*) GRID_LAYOUT_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_layout_grid_position(p0, p1, p2, p3, p4, p5, p6);
        }
    }
}

/* POSITION_LAYOUT_SERIALISER_SOURCE */
#endif
