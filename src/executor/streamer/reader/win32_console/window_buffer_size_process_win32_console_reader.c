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

#include <windows.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Processes a win32 console window buffer size event.
 *
 * @param p0 the internal memory data
 * @param p1 the event record
 * @param p2 the event type
 */
void read_win32_console_process_window_buffer_size(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read win32 console process window buffer size.");

    // The size (width, height) of the area that needs to be redrawn.
    int w = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get event record.
//    WINDOW_BUFFER_SIZE_RECORD r = (*id).Event.WindowBufferSizeEvent;

    // Get new size of console screen buffer,
    // in character cell columns and rows.
//    COORD c = r.dwSize;
//    *w = c.X;
//    *h = c.Y;
}
