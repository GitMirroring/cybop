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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Adds control button length and prefix length.
 *
 * @param p0 the destination message length
 * @param p1 the source character data position (pointer reference)
 * @param p2 the source character count remaining
 */
void select_ansi_escape_code_length_add(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select ansi escape code length add.");
    //?? fwprintf(stdout, L"Debug: Select ansi escape code length add. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select ansi escape code length add. count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Detect command length.
    select_ansi_escape_code_length_command(p0, p1, p2);

    compare_integer_greater_or_equal((void*) &r, p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A command was detected.
        //
        // CAUTION! The initial message length is minus one -1 and
        // is used by calling functions to filter out empty messages.
        // In order to avoid errors, the prefix length is added ONLY if
        // a command length was already assigned (greater or equal to zero).
        //

        // Add prefix count.
        calculate_integer_add(p0, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT);
    }
}
