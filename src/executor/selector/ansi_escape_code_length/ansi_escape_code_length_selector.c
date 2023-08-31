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
#include "communication.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the ansi escape code length begin.
 *
 * @param p0 the destination message length
 * @param p1 the source character data position (pointer reference)
 * @param p2 the source character count remaining
 */
void select_ansi_escape_code_length(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select ansi escape code length.");
    //?? fwprintf(stdout, L"Debug: Select ansi escape code length. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select ansi escape code length. count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

/*??
        void** test = (void**) p1;
        fwprintf(stdout, L"Debug: Select ansi escape code length. data position p1 + 0: %i\n", *test + 0);
        fwprintf(stdout, L"Debug: Select ansi escape code length. data position p1 + 1: %i\n", *test + 1);
        fwprintf(stdout, L"Debug: Select ansi escape code length. data position p1 + 2: %i\n", *test + 2);
        fwprintf(stdout, L"Debug: Select ansi escape code length. data position p1 + 0: %i\n", *((char*) (*test + 0)));
        fwprintf(stdout, L"Debug: Select ansi escape code length. data position p1 + 1: %i\n", *((char*) (*test + 1)));
        fwprintf(stdout, L"Debug: Select ansi escape code length. data position p1 + 2: %i\n", *((char*) (*test + 2)));
*/

        // ESC[
        detect((void*) &r, p1, p2, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Add control button length and prefix length.
            select_ansi_escape_code_length_add(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // An ansi escape code prefix was NOT found.
        //

        // Handle other characters.
        select_ansi_escape_code_length_character(p0, p1, p2);
    }
}
