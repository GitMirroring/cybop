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

#ifndef DISPLAY_ENABLER_SOURCE
#define DISPLAY_ENABLER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "logger.h"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/activator/enabler/xcb/xcb_enabler.c"
#elif defined(__APPLE__) && defined(__MACH__)
    //?? TODO: Add cocoa support for apple
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/activator/enabler/win32_display/win32_display_enabler.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Enables display event delivery.
 *
 * @param p0 the server entry
 */
void enable_display(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable display.");

#if defined(__linux__) || defined(__unix__)
    enable_xcb(p0);
#elif defined(__APPLE__) && defined(__MACH__)
    //?? TODO: Add cocoa support for apple
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    enable_win32_display(p0);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* DISPLAY_ENABLER_SOURCE */
#endif
