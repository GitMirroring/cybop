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

#ifndef WIN32_DISPLAY_RECEIVER_SOURCE
#define WIN32_DISPLAY_RECEIVER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/communicator/receiver/win32_display/messages_win32_display_receiver.c"
#include "../../../../executor/representer/deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Receives win32 display input.
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
void receive_win32_display(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive win32 display.");

    // The buffer item (array, queue) of e.g. 100 elements.
    // It is needed to avoid endless display input, so that
    // the system has the chance to process events in between.
//??    void* buf = *NULL_POINTER_STATE_CYBOI_MODEL;
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

fwprintf(stdout, L"TEST receive win32 display: %i\n", p5);

    // Receive messages.
    receive_win32_display_messages(p5, (void*) &td, (void*) &tc, (void*) &bk, (void*) &win, (void*) &px, (void*) &py, (void*) &m, (void*) &b, (void*) &x, (void*) &y, (void*) &w, (void*) &h);

    // Deserialise event into a meaningful command.
//??    deserialise(p0, p1, p2, p3, p4, p5, td, tc, (void*) &m, (void*) &px, (void*) &py, p6, p7);
}

/* WIN32_DISPLAY_RECEIVER_SOURCE */
#endif
