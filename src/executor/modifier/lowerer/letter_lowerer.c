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

#ifndef LETTER_LOWERER_SOURCE
#define LETTER_LOWERER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "logger.h"

/**
 * Converts the character into a lower case letter.
 *
 * The character remains untouched if it is not a letter.
 *
 * @param p0 the destination wide character item
 * @param p1 the wide character
 */
void lower_letter(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Lower letter.");
    fwprintf(stdout, L"Debug: Lower letter. source count p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Lower letter. source count *p1: %i\n", *((int*) p1));

    //
    //?? TODO:
    // Do NOT map characters 1:1 since "ß", for example,
    // gets mapped to TWO capital letters "SS".
    //

/*??
    if (letter == xy) {

        // Append converted source wide character to destination item.
        modify_item(p0, (void*) TODO_UNICODE_LETTER, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TODO_UNICODE_LETTER_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    }

    ... compare for other letters ...
*/
}

/* LETTER_LOWERER_SOURCE */
#endif
