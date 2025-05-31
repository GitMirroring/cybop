/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <windows.h>

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Serialises the terminal background colour into a win32 console colour.
 *
 * @param p0 the destination data
 * @param p1 the source data
 */
void serialise_win32_console_background(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        WORD* d = (WORD*) p0;

        // CAUTION! The "logify_integer_or" function is NOT used below,
        // as it would require too many conversions causing bad performance.
        // The reason is that "int" parametres are expected,
        // while the destination data is of type "WORD" (16 bit) and
        // the win32 constants are of type "uint32" (unsigned).
        // Also, making a reference of a constant like for example
        // "&BACKGROUND_BLUE" leads to the following error:
        // "lvalue required as unary ‘&’ operand".
        // Therefore, attribute values are OR-combined and
        // assigned directly (i.e. without function call) below.

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console background.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p1, (void*) BLACK_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Do NOTHING here. The default colour is "black".
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p1, (void*) BLUE_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                *d = *d | BACKGROUND_BLUE;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p1, (void*) CYAN_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                *d = *d | BACKGROUND_GREEN | BACKGROUND_BLUE;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p1, (void*) GREEN_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                *d = *d | BACKGROUND_GREEN;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p1, (void*) MAGENTA_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                *d = *d | BACKGROUND_RED | BACKGROUND_BLUE;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p1, (void*) RED_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                *d = *d | BACKGROUND_RED;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p1, (void*) WHITE_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                *d = *d | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p1, (void*) YELLOW_TERMINAL_COLOUR_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                *d = *d | BACKGROUND_RED | BACKGROUND_GREEN;
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console background. The destination data is null.");
    }
}
