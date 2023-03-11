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

#ifndef ARRAY_FINDER_SOURCE
#define ARRAY_FINDER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../executor/finder/fifo_array_finder.c"
#include "../../executor/finder/lifo_array_finder.c"
#include "logger.h"

/**
 * Finds a part with the given name in the investigated array.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated data (pointer reference) (each element pointing to a part)
 * @param p2 the searched name data
 * @param p3 the searched name count
 * @param p4 the investigated count
 * @param p5 the lifo flag (use last-in-first-out instead of first-in-first-out)
 */
void find_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The lifo flag IS set.

        find_array_lifo(p0, p1, p2, p3, p4);

    } else {

        // The lifo flag is NOT set.

        find_array_fifo(p0, p1, p2, p3, p4);
    }
}

/* ARRAY_FINDER_SOURCE */
#endif
