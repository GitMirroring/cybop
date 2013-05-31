/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DISPLAY_STARTER_SOURCE
#define DISPLAY_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef WIN32
    #include "../../../../executor/maintainer/starter/win32_display/win32_display_starter.c"
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/maintainer/starter/x_window_system/x_window_system_starter.c"
#endif
#ifdef DARWIN
    //#include "../../../../executor/maintainer/starter/darwin_display/darwin_display_starter.c"
#endif

/**
 * Starts up the display.
 *
 * @param p0 the internal memory data
 */
void startup_display(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup display.");

#ifdef WIN32
    startup_win32_display(p0);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    startup_x_window_system(p0);
#endif
#ifdef DARWIN
    startup_darwin_display(p0);
#endif
}

/* DISPLAY_STARTER_SOURCE */
#endif
