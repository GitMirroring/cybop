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

#ifndef OFFSET_ADDER_SOURCE
#define OFFSET_ADDER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../executor/calculator/pointer/add_pointer_calculator.c"
#include "../../mapper/type_to_size_mapper.c"

/**
 * Adds an offset to the given pointer.
 *
 * @param p0 the pointer (pointer reference)
 * @param p1 the type
 * @param p2 the index
 */
void add_offset(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT call the logger here.
    // It uses functions causing circular references.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add offset.");
    //

    // The offset memory area.
    int o = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Determine type size.
    map_type_to_size((void*) &o, p1);

    //
    // Calculate offset.
    //
    // CAUTION! The integer type is needed here, since o
    // is only the offset integer value and not a pointer.
    //
    calculate_integer_multiply((void*) &o, p2);

    //
    // Add offset to pointer.
    //
    // CAUTION! The pointer type is needed here, since p0
    // is a pointer to which the offset is added.
    //
    calculate_pointer_add(p0, (void*) &o);
}

/* OFFSET_ADDER_SOURCE */
#endif
