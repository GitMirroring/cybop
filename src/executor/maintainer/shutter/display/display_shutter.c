/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DISPLAY_SHUTTER_SOURCE
#define DISPLAY_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    //#include "../../../../executor/maintainer/shutter/darwin_display/darwin_display_shutter.c"
    //?? Add cocoa support for Apple
#elif WIN32
    #include "../../../../executor/maintainer/shutter/win32_display/win32_display_shutter.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/maintainer/shutter/x_window_system/x_window_system_shutter.c"
#else
    #include "../../../../executor/maintainer/shutter/x_window_system/x_window_system_shutter.c"
#endif

/**
 * Shuts down the display.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_display(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown display.");

#ifdef __APPLE__
    //shutdown_darwin_display(p0);
    //?? Add cocoa support for Apple
#elif WIN32
    shutdown_win32_display(p0);
#elif GNU_LINUX_OPERATING_SYSTEM
    shutdown_x_window_system(p0, p1, p2);
#else
    shutdown_x_window_system(p0, p1, p2);
#endif
}

/* DISPLAY_SHUTTER_SOURCE */
#endif
