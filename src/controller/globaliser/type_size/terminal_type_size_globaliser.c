/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#if defined(__linux__) || defined(__unix__)
    #include <termios.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <termios.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <windows.h> // DWORD
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "variable.h"

/**
 * Initialises terminal type size global variables.
 */
void globalise_type_size_terminal() {

#if defined(__linux__) || defined(__unix__)
    *UNIX_TERMINAL_MODE_TYPE_SIZE = sizeof (struct termios);
#elif defined(__APPLE__) && defined(__MACH__)
    *UNIX_TERMINAL_MODE_TYPE_SIZE = sizeof (struct termios);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    *WIN32_CONSOLE_MODE_TYPE_SIZE = *DOUBLE_WORD_INTEGRAL_TYPE_SIZE;
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}
