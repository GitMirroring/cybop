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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CLIENT_MESSAGE_XCB_EVENT_DESERIALISER_SOURCE
#define CLIENT_MESSAGE_XCB_EVENT_DESERIALISER_SOURCE

#include <xcb/xcb.h>

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/modifier/appender/item/part_item_appender.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the client message xcb event.
 *
 * @param p0 the destination properties item
 * @param p1 the source event
 */
void deserialise_xcb_event_client_message(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_client_message_event_t* e = (xcb_client_message_event_t*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise client message xcb event.");
        //?? fwprintf(stdout, L"Debug: Deserialise client message xcb event. p1: %i\n", p1);

        // Get window identification.
        uint32_t w = (uint32_t) (*e).window;
        //?? fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 0 w: %i\n", w);
        // Get type.
        uint32_t ty = (uint32_t) (*e).type;
        //?? fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 1 ty: %i\n", ty);
        // Get data.
        xcb_client_message_data_t d = (*e).data;
        //?? fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 2 d: %i\n", d);

        // Allocate window identification part and append it to the destination properties item.
        append_item_part(p0, (void*) WINDOW_EVENT_GUI_STATE_CYBOL_NAME, (void*) WINDOW_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) &w, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        //?? fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 3 w: %i\n", w);

        // The delete window cookie.
        void* dwc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Retrieve delete window cookie from input/output entry.
        //?? fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 4 dwc: %i\n", dwc);
        //?? copy_array_forward((void*) &dwc, p02, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DELETE_WINDOW_COOKIE_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        //?? fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 5 dwc: %i\n", dwc);

        // The delete window cookie structure.
        xcb_intern_atom_reply_t* dwcs = (xcb_intern_atom_reply_t*) dwc;
        //?? fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 6 dwcs: %i\n", dwcs);
/*??
        xcb_intern_atom_reply_t test = *dwcs;
        fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 7-8 test\n");
        fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 8 *dwcs: %i\n", *dwcs);
        fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 9 (*dwcs).atom: %i\n", (*dwcs).atom);
        fwprintf(stdout, L"Debug: deserialise xcb XCB_CLIENT_MESSAGE 10 d.data32[0]: %i\n", d.data32[0]);
*/

        // Find out if window is to be closed.
        //?? if (d.data32[0] == (*dwcs).atom) {

            // Allocate event name part and append it to the destination properties item.
            append_item_part(p0, (void*) EVENT_EVENT_GUI_STATE_CYBOL_NAME, (void*) EVENT_EVENT_GUI_STATE_CYBOL_NAME_COUNT, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CLOSE_WINDOW_EVENT_XCB_CYBOL_MODEL, (void*) CLOSE_WINDOW_EVENT_XCB_CYBOL_MODEL_COUNT);
        //?? }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb event client message. The source event is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb event client message. The source event is null. p1: %i\n", p1);
    }
}

/* CLIENT_MESSAGE_XCB_EVENT_DESERIALISER_SOURCE */
#endif
