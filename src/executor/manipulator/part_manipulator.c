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

#ifndef PART_MANIPULATOR_SOURCE
#define PART_MANIPULATOR_SOURCE

//
// Library interface
//

#include "constant.h"
#include "logger.h"

//
// Executable interface
//

#include "../../executor/manipulator/item_manipulator.c"

/**
 * Manipulates the part bit at the given position.
 *
 * @param p0 the value part
 * @param p1 the bit position
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the count
 * @param p5 the value index
 */
void manipulate_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate part.");

    // The model.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get model.
    copy_array_forward((void*) &m, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    manipulate_item(m, p1, p2, p3, p4, p5);
}

/* PART_MANIPULATOR_SOURCE */
#endif
