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
 * Processes a win32 console mouse event.
 *
 * @param p0 the internal memory data
 * @param p1 the event record
 * @param p2 the event type
 */
void read_win32_console_process_mouse(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read win32 console process mouse.");

    // The mouse position (x, y).
    int px = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int py = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mouse button identification.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The button- or key mask.
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get event record.
//    MOUSE_EVENT_RECORD r = (*id).Event.MouseEvent;

    // Get mouse coordinates.
//    COORD c = r.dwMousePosition;
//    *px = c.X;
//    *py = c.Y;

    // Get mouse button state.
//    *b = r.dwButtonState;

    // Get control key state (button or key mask).
//    *m = r.dwControlKeyState;

    // Get event flags.
    //?? *TODO = r.dwEventFlags;
}
