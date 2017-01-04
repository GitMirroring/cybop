/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LAYOUT_SERIALISER_SOURCE
#define LAYOUT_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cybol/layout/layout_cybol_model.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/representer/serialiser/layout/absolute/size_absolute_layout_serialiser.c"
/*??
#include "../../../../executor/representer/serialiser/layout/border/size_border_layout_serialiser.c"
#include "../../../../executor/representer/serialiser/layout/box/size_box_layout_serialiser.c"
#include "../../../../executor/representer/serialiser/layout/flow/size_flow_layout_serialiser.c"
*/
#include "../../../../executor/representer/serialiser/layout/grid/size_grid_layout_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises layout properties into graphical user interface (gui) coordinates.
 *
 * @param p0 the model data
 * @param p1 the model count
 * @param p2 the position x
 * @param p3 the position y
 * @param p4 the size width
 * @param p5 the size height
 * @param p6 the layout properties data
 * @param p7 the layout properties count
 * @param p8 the knowledge memory part
 * @param p9 the stack memory item
 * @param p10 the internal memory data
 * @param p11 the layout data
 * @param p12 the layout count
 */
void serialise_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout.");

fwprintf(stdout, L"TEST serialise layout: %ls\n", (wchar_t*) p11);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p11, (void*) ABSOLUTE_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p12, (void*) ABSOLUTE_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_layout_absolute_size(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p11, (void*) BORDER_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p12, (void*) BORDER_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_layout_border_size(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p11, (void*) BOX_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p12, (void*) BOX_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? Layout in a row or column WITHOUT breaking them.
            //?? If a row break is desired, then use flow layout.

//??            serialise_layout_box_size(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p11, (void*) FLOW_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p12, (void*) FLOW_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_layout_flow_size(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p11, (void*) GRID_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p12, (void*) GRID_LAYOUT_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_layout_grid_size(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }
}

/* LAYOUT_SERIALISER_SOURCE */
#endif
