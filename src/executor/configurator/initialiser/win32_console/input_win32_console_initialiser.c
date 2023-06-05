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
 * Initialises the win32 console input mode.
 *
 * @param p0 the console mode
 */
void initialise_win32_console_input(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DWORD* m = (DWORD*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise win32 console input.");

        //
        // Configure input events.
        //
        // The mode can be one or more of the following values:
        //
        // ENABLE_ECHO_INPUT 0x0004
        // ENABLE_EXTENDED_FLAGS 0x0080
        // ENABLE_INSERT_MODE 0x0020
        // ENABLE_LINE_INPUT 0x0002
        // ENABLE_MOUSE_INPUT 0x0010
        // ENABLE_PROCESSED_INPUT 0x0001
        // ENABLE_QUICK_EDIT_MODE 0x0040
        // ENABLE_WINDOW_INPUT 0x0008
        // ENABLE_VIRTUAL_TERMINAL_INPUT 0x0200
        //
        // The same values sorted by identification:
        //
        // ENABLE_PROCESSED_INPUT 0x0001
        // ENABLE_LINE_INPUT 0x0002
        // ENABLE_ECHO_INPUT 0x0004
        // ENABLE_WINDOW_INPUT 0x0008
        // ENABLE_MOUSE_INPUT 0x0010
        // ENABLE_INSERT_MODE 0x0020
        // ENABLE_QUICK_EDIT_MODE 0x0040
        // ENABLE_EXTENDED_FLAGS 0x0080
        // ENABLE_VIRTUAL_TERMINAL_INPUT 0x0200
        //
        // CAUTION! When a console is created, all input modes
        // EXCEPT ENABLE_WINDOW_INPUT are enabled by default.
        //
        *m = ENABLE_ECHO_INPUT | ENABLE_EXTENDED_FLAGS | ENABLE_INSERT_MODE | ENABLE_LINE_INPUT | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT | ENABLE_QUICK_EDIT_MODE | ENABLE_WINDOW_INPUT;

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise win32 console input. The console mode is null.");
    }
}
