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

#ifndef TERMINAL_MODE_COPIER_SOURCE
#define TERMINAL_MODE_COPIER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../executor/copier/terminal_mode/unix_terminal_mode_copier.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../executor/copier/terminal_mode/unix_terminal_mode_copier.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../executor/copier/terminal_mode/win32_console_mode_copier.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Copies the terminal mode.
 *
 * @param p0 the destination terminal mode
 * @param p1 the source terminal mode
 */
void copy_terminal_mode(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy terminal mode.");

#if defined(__linux__) || defined(__unix__)
    copy_terminal_mode_unix(p0, p1);
#elif defined(__APPLE__) && defined(__MACH__)
    copy_terminal_mode_unix(p0, p1);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    copy_console_mode_win32(p0, p1);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* TERMINAL_MODE_COPIER_SOURCE */
#endif
