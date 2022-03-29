/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONFIGURE_NOTIFY_XCB_EVENT_DESERIALISER_SOURCE
#define CONFIGURE_NOTIFY_XCB_EVENT_DESERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cybol/xcb/event_xcb_cybol_model.c"
#include "../../../../constant/name/cybol/state/gui/event_gui_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/appender/item/part_item_appender.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the configure notify xcb event.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source event
 */
void deserialise_xcb_event_configure_notify(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_configure_notify_event_t* e = (xcb_configure_notify_event_t*) p2;

        //
        // CAUTION! Comment out if necessary since this is called very often.
        //
        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise configure notify xcb event.");
        fwprintf(stdout, L"Debug: Deserialise configure notify xcb event. p2: %i\n", p2);

        // Overwrite configure notify xcb event name.
        modify_item(p0, (void*) CONFIGURE_NOTIFY_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) CONFIGURE_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        //?? TODO: The "static" keyword does probably NOT work for
        // storing the original window size, since the variables
        // have to be initialised with a constant expression that
        // can be evaluated at COMPILE time. But the window size
        // gets determined only at RUNTIME.
        //
        // --> possibly store window size in "client entry".
        //

        //
        // The original window size.
        //
        // CAUTION! The keyword "static" is IMPORTANT!
        // Using it, the variables are declared and initialised only the FIRST TIME
        // this code is executed, in order to store the original window size.
        // Later, original and new window size may be compared.
        //
        // CAUTION! The variables HAVE TO be initialised with
        //
        // The C language requires the initialiser for a static object
        // to be a constant expression. Since initialisation of static
        // objects occurs before main begins, there's no place for any
        // run-time evaluation to happen.
        //
        // The "const" keyword does NOT mean "constant". A constant expression
        // is one that can be, and in some cases must be, evaluated at compile time.
        // In the c programming language, "const" means "read-only".
        //
        // https://stackoverflow.com/questions/21592494/initializer-element-is-not-constant-error-for-no-reason-in-linux-gcc-compilin
        //
        static uint16_t ow = 0;
        static uint16_t oh = 0;

        // Get original window size.
        ow = (*e).width;
        oh = (*e).height;

        // Get current window size.
        uint16_t ew = (*e).width;
        uint16_t eh = (*e).height;

        // Resize window.
        if (((ew > 0) && (ow != ew)) || ((eh > 0) && (oh != eh)) ) {

            // Assign new width and height.
            ow = ew;
            oh = eh;
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb event configure notify. The source event is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb event configure notify. The source event is null. p2: %i\n", p2);
    }
}

/* CONFIGURE_NOTIFY_XCB_EVENT_DESERIALISER_SOURCE */
#endif
