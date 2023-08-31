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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Processes a win32 console message.
 *
 * @param p0 the internal memory data
 * @param p1 the event record
 * @param p2 the event type
 */
void read_win32_console_process(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        WORD* t = (WORD*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read win32 console process.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // CAUTION! The comparison CANNOT be done like:
        // compare_integer_equal((void*) &r, p1, (void*) &FOCUS_EVENT);
        //
        // The reason is that "FOCUS_EVENT" etc. are NOT variables,
        // so that a reference may NOT be formed using the "&" operator.
        //
        // Therefore, integer values are compared DIRECTLY here.

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            r = (*t == FOCUS_EVENT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // CAUTION! These events are used internally
                // by win32 and are recommended to be ignored.
                // http://msdn.microsoft.com/en-us/windows/desktop/ms683149(v=vs.85)
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            r = (*t == KEY_EVENT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                read_win32_console_process_key(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            r = (*t == MENU_EVENT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // CAUTION! These events are used internally
                // by win32 and are recommended to be ignored.
                // http://msdn.microsoft.com/en-us/windows/desktop/ms684213(v=vs.85)
                //
                // CAUTION! Furthermore, this event type is NOT useful in cyboi.
                // The reason is that menu items and corresponding
                // action commands are identified via knowledge tree.
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            r = (*t == MOUSE_EVENT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                read_win32_console_process_mouse(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            r = (*t == WINDOW_BUFFER_SIZE_EVENT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                read_win32_console_process_window_buffer_size(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 console process. The event type is unknown.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 console process. The event type is null.");
    }
}
