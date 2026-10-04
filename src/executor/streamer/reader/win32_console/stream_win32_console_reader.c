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

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Reads data stream via win32 console.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source root window data
 * @param p3 the source root window count
 * @param p4 the knowledge memory part
 * @param p5 the internal memory data
 * @param p6 the format
 * @param p7 the language
 */
void read_win32_console_stream(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read win32 console stream.");

    // The input record data.
    // CAUTION! It can be an array of INPUT_RECORD
    // structures that receives the input buffer data.
    INPUT_RECORD rd;
    // The input record count (number of records read).
    DWORD rc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The input record size.
    // CAUTION! The size HAS TO HAVE a value of one.
    // The reason is that each input needs to be processed
    // and deserialised, in order to identify the command
    // corresponding e.g. to the button pressed by key or mouse.
    // Afterwards, that command gets processed in cyboi's
    // MAIN LOOP, before the next input may be received.
    // One advantage of this kind of relying on the main loop
    // is the possibility of real-time processing.
    DWORD rs = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! A loop is NOT used here, since the
    // main thread's signal/event/message loop
    // repeatedly calls this function when necessary.
    //

    // Read message.
    read_win32_console_message((void*) &rd, (void*) &rc, (void*) &rs, p5);

    // Get event type.
    WORD t = rd.EventType;

    // Process message.
    read_win32_console_process(p5, (void*) &rd, (void*) &t);

    // Deserialise event into a meaningful command.
//??    deserialise(p0, p1, p2, p3, p4, p5, td, tc, (void*) &m, (void*) &px, (void*) &py, p6, p7);
//    deserialise_tui(p0, (void*) &bk, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
}
