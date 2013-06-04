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

#ifndef X_WINDOW_SYSTEM_RECEIVER_SOURCE
#define X_WINDOW_SYSTEM_RECEIVER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/communicator/receiver/x_window_system/event_x_window_system_receiver.c"
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

    // The buffer item (array, queue) of e.g. 100 elements.
    // It is needed to avoid endless display input, so that
    // the system has the chance to process events in between.
//??    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The event type string data, count.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse button or keycode of the physical key on the keyboard.
    int bk = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The id of the window where event occured.
    // This is needed if the application uses more
    // than just one window, e.g. dialogue windows.
    // In this case, the application registers
    // for events on all of these several windows.
    xcb_window_t win = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mouse position (x, y).
    int px = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int py = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The button- or key mask.
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The origo (x, y) of the area that needs to be redrawn.
    int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The expansion (width, height) of the area that needs to be redrawn.
    int w = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Buffer events until a null event is reached
    // or until the buffer is full.
//??    receive_x_window_system_buffer();

    // Filter out expose events to avoid flickering.
    // The last expose event is reached when the
    // next event is either null or another kind of event.
//??    receive_x_window_system_filter();

    // Receive event.
    receive_x_window_system_event((void*) &td, (void*) &tc, (void*) &m, (void*) &px, (void*) &py, p5);

//?? fwprintf(stdout, L"TEST receive x window system td: %ls\n", (wchar_t*) td);
//?? fwprintf(stdout, L"TEST receive x window system tc: %i\n", *((int*) tc));

//?? fwprintf(stdout, L"TEST receive x window system p0 pre: %ls\n", (wchar_t*) *((void**) p0));

    // Deserialise event into a meaningful command.
    deserialise(p0, p1, p2, p3, p4, p5, td, tc, (void*) &m, (void*) &px, (void*) &py, p6, p7);

//?? fwprintf(stdout, L"TEST receive x window system p0 post: %ls\n", (wchar_t*) *((void**) p0));
}

/* X_WINDOW_SYSTEM_RECEIVER_SOURCE */
#endif
