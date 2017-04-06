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

#ifndef TUI_SERIALISER_SOURCE
#define TUI_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/cybol/cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/tui/part_tui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises a part into text user interface (tui).
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the source model data
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 * @param p9 the clear flag
 * @param p10 the newline flag
 * @param p11 the tree level
 * @param p12 the cli flag
 * @param p13 the original attributes
 * @param p14 the format
 */
void serialise_tui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_tui_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }
    }

    //
    // Other formats
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Leave processing of other formats to cybol serialiser.
        serialise_cybol(p0, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p14, *NULL_POINTER_STATE_CYBOI_MODEL, p2, p3, p4, p5);
    }
}

/* TUI_SERIALISER_SOURCE */
#endif
