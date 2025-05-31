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

#include <stddef.h> // wchar_t
#include <stdio.h> // FILE
#include <wchar.h> // fputws, fwprintf

/**
 * Writes a terminated log message to the given output stream.
 *
 * CAUTION! The "write" function is not used here, because it expects
 * a multibyte character sequence.
 * The log message, however, is handed over with a null termination wide character,
 * so that it may be passed on to either of the "fputws" or "fwprintf" function.
 * Since it seems simpler and presumably is faster, the decision here fell on the "fputws" function.
 *
 * @param p0 the log output stream
 * @param p1 the log message
 */
void log_write(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* m = (wchar_t*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            FILE* s = (FILE*) p0;

            fputws(m, s);

        } else {

            //
            // CAUTION! Do NOT call the logger here. It cannot log itself.
            // This is commented out, in order to avoid annoying messages.
            //
            // fputws(L"Error: Could not log write. The log output stream is null.\n", stdout);
            //
            fwprintf(stdout, L"Error: Could not log write. The log output stream is null. p0: %i\n", p0);
        }

    } else {

        //
        // CAUTION! Do NOT call the logger here. It cannot log itself.
        //
        //?? fputws(L"Error: Could not write log. The log message is null.\n", stdout);
        //
        fwprintf(stdout, L"Error: Could not log write. The log message is null. p1: %i\n", p1);
    }
}
