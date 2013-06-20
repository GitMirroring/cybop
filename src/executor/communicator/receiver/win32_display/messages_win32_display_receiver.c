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

#ifndef MESSAGES_WIN32_DISPLAY_RECEIVER_SOURCE
#define MESSAGES_WIN32_DISPLAY_RECEIVER_SOURCE

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
#include "../../../../executor/communicator/receiver/win32_display/message_win32_display_receiver.c"
#include "../../../../executor/communicator/receiver/win32_display/process_win32_display_receiver.c"
#include "../../../../logger/logger.c"

/**
 * Receives win32 display messages.
 *
 * @param p0 the internal memory data
 * @param p1 the event type data (pointer reference)
 * @param p2 the event type count (pointer reference)
 * @param p3 the mouse button or key code
 * @param p4 the window identification
 * @param p5 the mouse position x coordinate
 * @param p6 the mouse position y coordinate
 * @param p7 the button- or key mask
 * @param p8 the mouse button identification
 * @param p9 the expose area x coordinate
 * @param p10 the expose area y coordinate
 * @param p11 the expose area width
 * @param p12 the expose area height
 */
void receive_win32_display_messages(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive win32 display messages.");

    // The message.
    MSG m;
    // The loop break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        //
        // CAUTION! Process event (message) first,
        // before trying to retrieve the next one.
        //
        // The reason is that an initial event (message)
        // was probably already retrieved in file "wait_checker.c".
        // It HAS TO BE processed before getting a next.
        //
        // If no more events are available, the break
        // flag is set, so that the loop may be left
        // before trying to process an empty event.
        //

        receive_win32_display_process(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, (void*) &b, (void*) &m);
        receive_win32_display_message((void*) &b, (void*) &m);
    }
}

/* MESSAGES_WIN32_DISPLAY_RECEIVER_SOURCE */
#endif
