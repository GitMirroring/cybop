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

#ifndef POSITION_ABSOLUTE_LAYOUT_SERIALISER_SOURCE
#define POSITION_ABSOLUTE_LAYOUT_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../../logger/logger.c"

/**
 * Serialises absolute layout position.
 *
 * @param p0 the destination element (child) position x
 * @param p1 the destination element (child) position y
 * @param p2 the source position x
 * @param p3 the source position y
 */
void serialise_layout_absolute_position(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout absolute position.");

    // Add whole position.
    calculate_integer_add(p0, p2);
    calculate_integer_add(p1, p3);
}

/* POSITION_ABSOLUTE_LAYOUT_SERIALISER_SOURCE */
#endif
