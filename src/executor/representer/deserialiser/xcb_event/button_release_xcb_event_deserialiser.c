/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <xcb/xcb.h>
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the button release xcb event.
 *
 * @param p0 the destination properties item
 * @param p1 the source event
 */
void deserialise_xcb_event_button_release(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_button_release_event_t* e = (xcb_button_release_event_t*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise button release xcb event.");
        //?? fwprintf(stdout, L"Debug: Deserialise button release xcb event. p1: %i\n", p1);

        // Get window identification.
        int w = (int) (*e).event;
        // Get mouse coordinates.
        int x = (int) (*e).event_x;
        int y = (int) (*e).event_y;
        // Get mouse button or keycode.
        int b = (int) (*e).detail;
        // Get button mask.
        int mask = (int) (*e).state;

        // Allocate event name part and append it to the destination properties item.
        append_part(p0, (void*) EVENT_EVENT_GUI_STATE_CYBOL_NAME, (void*) EVENT_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BUTTON_RELEASE_EVENT_XCB_CYBOL_MODEL, (void*) BUTTON_RELEASE_EVENT_XCB_CYBOL_MODEL_COUNT);
        // Allocate window identification part and append it to the destination properties item.
        append_part(p0, (void*) WINDOW_EVENT_GUI_STATE_CYBOL_NAME, (void*) WINDOW_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &w, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        // Allocate x mouse coordinate part and append it to the destination properties item.
        append_part(p0, (void*) X_EVENT_GUI_STATE_CYBOL_NAME, (void*) X_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &x, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        // Allocate y mouse coordinate part and append it to the destination properties item.
        append_part(p0, (void*) Y_EVENT_GUI_STATE_CYBOL_NAME, (void*) Y_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &y, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        // Allocate mouse button or keycode part and append it to the destination properties item.
        append_part(p0, (void*) BUTTON_EVENT_GUI_STATE_CYBOL_NAME, (void*) BUTTON_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &b, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        // Allocate button mask part and append it to the destination properties item.
        append_part(p0, (void*) MASK_EVENT_GUI_STATE_CYBOL_NAME, (void*) MASK_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &mask, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb event button release. The source event is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb event button release. The source event is null. p1: %i\n", p1);
    }
}
