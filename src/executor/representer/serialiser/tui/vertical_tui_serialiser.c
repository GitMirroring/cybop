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

#ifndef VERTICAL_TUI_SERIALISER_SOURCE
#define VERTICAL_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Determines the vertical position of the given y coordinate.
 *
 * @param p0 the destination top vertical position flag
 * @param p1 the destination middle vertical position flag
 * @param p2 the destination bottom vertical position flag
 * @param p3 the source y coordinate
 * @param p4 the top border index
 * @param p5 the bottom border index
 */
void serialise_tui_vertical(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui vertical.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, p4);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is the top.
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
            // This is the bottom.
            //

            copy_integer(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is the middle.
        //

        copy_integer(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        copy_integer(p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* VERTICAL_TUI_SERIALISER_SOURCE */
#endif
