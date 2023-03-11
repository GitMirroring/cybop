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

#ifndef CHARACTER_ANSI_ESCAPE_CODE_LENGTH_SELECTOR_SOURCE
#define CHARACTER_ANSI_ESCAPE_CODE_LENGTH_SELECTOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "logger.h"

/**
 * Selects the ansi escape code length character.
 *
 * @param p0 the destination message length
 * @param p1 the source character data position (pointer reference)
 * @param p2 the source character count remaining
 */
void select_ansi_escape_code_length_character(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select ansi escape code length character.");
    //?? fwprintf(stdout, L"Debug: Select ansi escape code length character. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select ansi escape code length character. count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Newline
    //
    // It differs between platforms (operating systems).
    //
    // CAUTION! The ORDER of the following comparisons is IMPORTANT!
    //
    // If changed, sequences might not be detected correctly.
    // The windows newline <cr> + <lf> detection has to be FIRST.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) WINDOWS_ASCII_NEWLINE_TEXT_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) WINDOWS_ASCII_NEWLINE_TEXT_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) WINDOWS_ASCII_NEWLINE_TEXT_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) MACINTOSH_ASCII_NEWLINE_TEXT_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MACINTOSH_ASCII_NEWLINE_TEXT_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) MACINTOSH_ASCII_NEWLINE_TEXT_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) UNIX_ASCII_NEWLINE_TEXT_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) UNIX_ASCII_NEWLINE_TEXT_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) UNIX_ASCII_NEWLINE_TEXT_MODEL_COUNT);
        }
    }

    //
    // Escape
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) ESCAPE_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        }
    }

    //
    // Other
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // None of the control characters above matched.
        //

        // Add standard character size.
        copy_integer(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    }
}

/* CHARACTER_ANSI_ESCAPE_CODE_LENGTH_SELECTOR_SOURCE */
#endif
