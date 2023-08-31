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
 * Deserialises the expose xcb event.
 *
 * Expose events are sensed when a window needs to be repainted,
 * e.g. when being displayed after having been covered by another window before.
 *
 * @param p0 the destination properties item
 * @param p1 the source event
 */
void deserialise_xcb_event_expose(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_expose_event_t* e = (xcb_expose_event_t*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise expose xcb event.");
        //?? fwprintf(stdout, L"Debug: Deserialise expose xcb event. p1: %i\n", p1);
        //?? fwprintf(stdout, L"Debug: Deserialise expose xcb event. (*e).count: %i\n", (*e).count);

        //
        // CAUTION! Consider only the LAST in a row of multiple expose
        // events, in order to avoid flickering of the display.
        //
        if ((*e).count == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Get window identification.
            int wi = (int) (*e).window;
            // Get expose area position.
            int x = (int) (*e).x;
            int y = (int) (*e).y;
            // Get expose area size.
            int w = (int) (*e).width;
            int h = (int) (*e).height;

            // Allocate event name part and append it to the destination properties item.
            append_part(p0, (void*) EVENT_EVENT_GUI_STATE_CYBOL_NAME, (void*) EVENT_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EXPOSE_EVENT_XCB_CYBOL_MODEL, (void*) EXPOSE_EVENT_XCB_CYBOL_MODEL_COUNT);
            // Allocate window identification part and append it to the destination properties item.
            append_part(p0, (void*) WINDOW_EVENT_GUI_STATE_CYBOL_NAME, (void*) WINDOW_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &wi, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            // Allocate x expose area position part and append it to the destination properties item.
            append_part(p0, (void*) EXPOSED_X_EVENT_GUI_STATE_CYBOL_NAME, (void*) EXPOSED_X_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &x, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            // Allocate y expose area position part and append it to the destination properties item.
            append_part(p0, (void*) EXPOSED_Y_EVENT_GUI_STATE_CYBOL_NAME, (void*) EXPOSED_Y_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &y, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            // Allocate x expose area size part and append it to the destination properties item.
            append_part(p0, (void*) EXPOSED_WIDTH_EVENT_GUI_STATE_CYBOL_NAME, (void*) EXPOSED_WIDTH_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &w, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
            // Allocate y expose area size part and append it to the destination properties item.
            append_part(p0, (void*) EXPOSED_HEIGHT_EVENT_GUI_STATE_CYBOL_NAME, (void*) EXPOSED_HEIGHT_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &h, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb event expose. The source event is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb event expose. The source event is null. p1: %i\n", p1);
    }
}
