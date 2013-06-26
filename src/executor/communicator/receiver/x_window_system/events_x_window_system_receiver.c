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

#ifndef EVENTS_X_WINDOW_SYSTEM_RECEIVER_SOURCE
#define EVENTS_X_WINDOW_SYSTEM_RECEIVER_SOURCE

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
#include "../../../../executor/communicator/receiver/x_window_system/event_x_window_system_receiver.c"
#include "../../../../executor/communicator/receiver/x_window_system/process_x_window_system_receiver.c"
#include "../../../../logger/logger.c"

/**
 * Receives x window system events.
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
void receive_x_window_system_events(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* mt = *NULL_POINTER_STATE_CYBOI_MODEL;
    xcb_generic_event_t* e = (xcb_generic_event_t*) p0;

    // Get connexion.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get mutex.
    copy_array_forward((void*) &mt, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive x window system events.");

    // The event.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The loop break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Get next event.
        receive_x_window_system_event((void*) &e, (void*) &b);

        // Process event.
        // If no more events are available, the break
        // flag is set, so that the loop may be left.
        receive_x_window_system_process(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, e, (void*) &b);
    }
}

/* EVENTS_X_WINDOW_SYSTEM_RECEIVER_SOURCE */
#endif
