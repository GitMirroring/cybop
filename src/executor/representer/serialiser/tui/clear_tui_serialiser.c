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
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Clears the terminal screen.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the clear flag
 * @param p3 the tree level
 */
void serialise_tui_clear(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui clear.");

    // The root tree level comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The clear flag comparison result.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is the ROOT tree level,
        // which means that this is the INITIAL
        // (and not a recursive) call of this function.
        //

        compare_integer_unequal((void*) &c, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The clear flag IS set.
            //

            // Clear terminal.
#if defined(__linux__) || defined(__unix__)
            serialise_ansi_escape_code_clear(p0);
#elif defined(__APPLE__) && defined(__MACH__)
            serialise_ansi_escape_code_clear(p0);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            serialise_win32_console_clear(p1);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }
}
