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

#ifndef POSITION_GRID_LAYOUT_SERIALISER_SOURCE
#define POSITION_GRID_LAYOUT_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "logger.h"

/**
 * Serialises grid layout position.
 *
 * @param p0 the destination element (child) position x
 * @param p1 the destination element (child) position y
 * @param p2 the source element (child) width
 * @param p3 the source element (child) height
 * @param p4 the source position x
 * @param p5 the source position y
 * @param p6 the element (child) index
 */
void serialise_layout_grid_position(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout grid position.");

    // Initialise destination position.
    // CAUTION! This is necessary for
    // the multiplication below.
    copy_integer(p0, p2);
    copy_integer(p1, p3);

    // Multiply with element (child) index.
    calculate_integer_multiply(p0, p6);
    calculate_integer_multiply(p1, p6);

    // Add parent position.
    calculate_integer_add(p0, p4);
    calculate_integer_add(p1, p5);
}

/* POSITION_GRID_LAYOUT_SERIALISER_SOURCE */
#endif
