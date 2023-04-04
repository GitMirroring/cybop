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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef OUTPUT_WIN32_CONSOLE_INITIALISER_SOURCE
#define OUTPUT_WIN32_CONSOLE_INITIALISER_SOURCE

//
// System interface
//

#include <windows.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Initialises the win32 console output mode.
 *
 * @param p0 the console mode
 */
void initialise_win32_console_output(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DWORD* m = (DWORD*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise win32 console output.");

        //
        // Configure output events.
        //
        // The mode can be one or more of the following values:
        // ENABLE_PROCESSED_OUTPUT 0x0001
        // ENABLE_WRAP_AT_EOL_OUTPUT 0x0002
        // ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
        // DISABLE_NEWLINE_AUTO_RETURN 0x0008
        // ENABLE_LVB_GRID_WORLDWIDE 0x0010
        //
        // CAUTION! When a screen buffer is created,
        // BOTH output modes are enabled by default.
        //
        *m = ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT;

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise win32 console output. The console mode is null.");
    }
}

/* OUTPUT_WIN32_CONSOLE_INITIALISER_SOURCE */
#endif
