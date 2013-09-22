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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_RECEIVER_SOURCE
#define X_WINDOW_SYSTEM_RECEIVER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/communicator/receiver/x_window_system/event_x_window_system_receiver.c"
#include "../../../../executor/communicator/receiver/x_window_system/process_x_window_system_receiver.c"
#include "../../../../executor/representer/deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Receives x window system input.
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
void receive_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive x window system.");

    // The event.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The event type string data, count.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse button or keycode of the physical key on the keyboard.
    // Possible types are: xcb_button_t, uint8_t, xcb_keycode_t
    int bk = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The identification of the window where event occured.
    // This is needed if the application uses more
    // than just one window, e.g. dialogue windows.
    // In this case, the application registers
    // for events on all of these several windows.
    // The actual type is: xcb_window_t
    int win = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mouse position (x, y).
    int px = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int py = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The button- or key mask.
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mouse button identification.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The origo (x, y) of the area that needs to be redrawn.
    int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The size (width, height) of the area that needs to be redrawn.
    int w = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! A loop is NOT used here, since the
    // main thread's signal/event/message loop
    // repeatedly calls this function when necessary.
    //

    // Get event from internal memory.
    // CAUTION! This has to be done FIRST,
    // before trying to receive an event via
    // "receive_x_window_system_event" below.
    // The reason is that file "wait_checker.c"
    // polls for events in the main thread and
    // stores a found event in internal memory.
    // So, that one has to be processed first here.
    copy_array_forward((void*) &e, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EVENT_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Reset event in internal memory.
    // CAUTION! This IS important since otherwise,
    // the same old event would be processed again and again.
    copy_array_forward(p5, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EVENT_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    if (e == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Receive event.
        // CAUTION! This should actually NEVER be called.
        // See comment above.
fwprintf(stdout, L"TEST receive x window system SHOULD NEVER BE CALLED: %i\n", e);
        receive_x_window_system_event((void*) &e, p5);
    }

    // Process event.
    receive_x_window_system_process((void*) &td, (void*) &tc, (void*) &bk, (void*) &win, (void*) &px, (void*) &py, (void*) &m, (void*) &b, (void*) &x, (void*) &y, (void*) &w, (void*) &h, e);

    // Deserialise event into a meaningful command.
    //?? TODO: Comment in or delete later.
    //?? However, "gui" is probably ALWAYS used as language in conjunction with the x window system.
    deserialise(p0, p1, p2, p3, p4, p5, td, tc, (void*) &m, (void*) &px, (void*) &py, p6, p7);
//??    deserialise_gui(p0, p1, p2, p3, p4, p5, td, tc, (void*) &m, (void*) &px, (void*) &py, p6, p7);
}

/* X_WINDOW_SYSTEM_RECEIVER_SOURCE */
#endif
