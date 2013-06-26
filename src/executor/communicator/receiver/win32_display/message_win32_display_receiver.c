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

#ifndef MESSAGE_WIN32_DISPLAY_RECEIVER_SOURCE
#define MESSAGE_WIN32_DISPLAY_RECEIVER_SOURCE

#include <windowsx.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cybol/state/gui/event_gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/keyboard/keyboard_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/mouse/mouse_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Receives a win32 display message.
 *
 * @param p0 the message
 * @param p1 the loop break flag
 */
void receive_win32_display_message(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        MSG* m = (MSG*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive win32 display message.");

        // The window.
        //
        // CAUTION! It is initialised with NULL,
        // so that not only the main window's messages,
        // but all messages of the thread are received.
        //
        // This is important if using a dialogue window
        // besides the main window, for example.
        // CYBOI will then have to find out internally,
        // to which window a message belongs.
        // It thus has to keep a list of existing windows
        // in a container structure stored in internal memory.
        HWND w = (HWND) *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Get message from application's message queue.
        //
        // Using "PeekMessage", one can choose between "PM_NOREMOVE" and
        // "PM_REMOVE", to be handed over as last argument.
        //
        // CAUTION! DO REMOVE the message from the queue with flag PM_REMOVE here!
        // It was detected in file "wait_checker.c" and may be removed and processed now.
        //
        // IF a message is available, the return value is NONZERO (TRUE).
        // If NO messages are available, the return value is ZERO (FALSE).
        // The loop sleeps if no messages are available.
        //
        BOOL b = PeekMessage(m, w, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, PM_REMOVE);

        if (b == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // No messages are available.

            // Set loop break flag.
            copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 display message. The message is null.");
    }
}

/* MESSAGE_WIN32_DISPLAY_RECEIVER_SOURCE */
#endif
