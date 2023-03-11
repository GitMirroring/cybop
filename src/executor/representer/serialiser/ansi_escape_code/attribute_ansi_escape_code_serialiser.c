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

#ifndef ATTRIBUTE_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define ATTRIBUTE_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/serialiser/ansi_escape_code/character_ansi_escape_code_serialiser.c"
#include "logger.h"

/**
 * Serialises the attribute into an ansi escape code sequence.
 *
 * Example:
 * printf("\033[1mbold \033[0mswitched off.")
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the source attribute character data
 * @param p2 the source attribute character count
 * @param p3 the prefix flag
 */
void serialise_ansi_escape_code_attribute(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code attribute.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The prefix flag was set to "true",
        // i.e. the prefix HAS been added previously.
        // Therefore, add the attribute separator here instead.
        //

        serialise_ansi_escape_code_character(p0, (void*) ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL, (void*) ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL_COUNT);

    } else {

        //
        // The prefix has NOT been added yet.
        // Therefore, add it here.
        //

        serialise_ansi_escape_code_character(p0, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT);

        // Set prefix flag.
        copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    // Append source attribute character to destination.
    serialise_ansi_escape_code_character(p0, p1, p2);
}

/* ATTRIBUTE_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
