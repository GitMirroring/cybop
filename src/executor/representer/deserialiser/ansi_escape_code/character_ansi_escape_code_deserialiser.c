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

#ifndef CHARACTER_ANSI_ESCAPE_CODE_DESERIALISER_SOURCE
#define CHARACTER_ANSI_ESCAPE_CODE_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/representer/serialiser/ascii/ascii_serialiser.c"
#include "logger.h"

/**
 * Deserialises the ansi escape code character data into a command.
 *
 * @param p0 the destination wide character item
 * @param p1 the source character data position (pointer reference)
 * @param p2 the source character count remaining
 */
void deserialise_ansi_escape_code_character(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise ansi escape code character.");
        //?? fwprintf(stdout, L"Debug: Deserialise ansi escape code character. count remaining p2: %i\n", p2);
        //?? fwprintf(stdout, L"Debug: Deserialise ansi escape code character. count remaining *p2: %i\n", *((int*) p2));

        // Decode multibyte character array into wide character item.
        serialise_ascii(p0, *d, p2);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise ansi escape code character. The source data position is null.");
    }
}

/* CHARACTER_ANSI_ESCAPE_CODE_DESERIALISER_SOURCE */
#endif
