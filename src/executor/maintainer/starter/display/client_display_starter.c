/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CLIENT_DISPLAY_STARTER_SOURCE
#define CLIENT_DISPLAY_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/maintainer/starter/xcb/client_xcb_starter.c"
#elif defined(__APPLE__) && defined(__MACH__)
//??    #include "../../../../executor/maintainer/starter/darwin_display/client_darwin_display_starter.c"
    //?? TODO: Add cocoa support for apple.
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/maintainer/starter/win32_display/client_win32_display_starter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Starts up the display client (creates a window).
 *
 * @param p0 the input/output entry
 * @param p1 the window id
 */
void startup_display_client(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup display client.");

#if defined(__linux__) || defined(__unix__)
    startup_xcb_client(p0, p1);
#elif defined(__APPLE__) && defined(__MACH__)
//??    startup_darwin_display_client(p0);
    // Add cocoa support for apple
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    startup_win32_display_client(p0);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* CLIENT_DISPLAY_STARTER_SOURCE */
#endif
