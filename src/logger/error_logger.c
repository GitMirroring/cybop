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

#include <stddef.h> // wchar_t
#include <stdio.h> // stdout, fwprintf
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h" // log_message_terminated
#include "mapper.h"

/**
 * Prints the message belonging to the given error number.
 *
 * @param p0 the errno value
 */
void log_error(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* e = (int*) p0;

        // The message.
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Map errno value to message string.
        map_errno_to_message((void*) &m, p0);

        // Write message to log file.
        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, m);

        // Cast message to correct type.
        wchar_t* mt = (wchar_t*) m;

        // Print message.
        fwprintf(stdout, mt);
        // Print space.
        fwprintf(stdout, L" ");
        // Print errno.
        fwprintf(stdout, L"Errno: %i\n", *e);

#if defined(__linux__) || defined(__unix__)
        // empty
#elif defined(__APPLE__) && defined(__MACH__)
        // empty
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
        log_windows_system_error(p0);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

    } else {

        fwprintf(stdout, L"Error: Could not log error. The errno value is null. p0: %i\n", p0);
    }
}
