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

#ifndef COLOUR_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define COLOUR_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../../executor/representer/serialiser/ansi_escape_code/attribute_ansi_escape_code_serialiser.c"
#include "logger.h"

/**
 * Serialises the colour into an ansi escape code sequence.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the source colour data
 * @param p2 the source colour count
 * @param p3 the prefix flag
 */
void serialise_ansi_escape_code_colour(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code colour.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // If the source count is greater than zero,
    // then a colour was successfully assigned before.
    // Testing the colour data may therefore be omitted here.
    //
    compare_integer_greater((void*) &r, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        serialise_ansi_escape_code_attribute(p0, p1, p2, p3);
    }
}

/* COLOUR_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
