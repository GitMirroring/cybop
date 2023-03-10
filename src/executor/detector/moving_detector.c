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

#ifndef MOVING_DETECTOR_SOURCE
#define MOVING_DETECTOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../executor/mover/mover.c"
#include "../../logger/logger.c"

/**
 * Moves the current position and remaining count, depending on the move flag.
 *
 * @param p0 the source data position (pointer reference)
 * @param p1 the source count remaining
 * @param p2 the type
 * @param p3 the count
 * @param p4 the move flag
 */
void detect_moving(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detect moving.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        move(p0, p1, p2, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* MOVING_DETECTOR_SOURCE */
#endif
