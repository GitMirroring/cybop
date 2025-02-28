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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Converts the character into an uppercase letter.
 *
 * The character remains untouched if it is not a letter.
 *
 * @param p0 the destination item
 * @param p1 the letter
 */
void uppercase_letter(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Uppercase letter.");
    fwprintf(stdout, L"Debug: Uppercase letter. source count p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Uppercase letter. source count *p1: %i\n", *((int*) p1));

    //
    // CAUTION! With the letter being of type "wide character",
    // most alphabets can be handled using UNICODE tables.
    //
    // However, for letters of type "character", only the LATIN
    // alphabet with ASCII characters can be handled correctly.
    //
    // The letters of other alphabets may be encoded most differently
    // outside unicode and cause too much effort to be handled here.
    //
    // The cyboi interpreter internally works with wide characters only,
    // so that most alphabets can be considered. Only in rare cases
    // a conversion of ascii characters is necessary, for example when
    // deserialising a special data format with ancient ascii commands.
    //

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

    //
    //?? TODO: Do NOT forget to consider ascii character letters
    // of the LATIN alphabet. See comment avove!
    //
}
