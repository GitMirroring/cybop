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

#include <xcb/xproto.h>
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Let the system send an input to itself over display.
 *
 * @param p0 the input/output entry
 */
void awake_display(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awake display.");
    fwprintf(stdout, L"Debug: Awake display. p0: %i\n", p0);

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The propagation.
    uint8_t p = (uint8_t) *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get connexion from input/output entry.
    //?? copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Cast connexion to correct type.
    xcb_connection_t* ct = (xcb_connection_t*) c;

    //
    // Allocate an empty event.
    //
    // CAUTION! Every x11 event is 32 bytes long. Therefore, xcb will copy 32 bytes.
    // In order to properly initialize these bytes, 32 bytes get allocated
    // even if only less are needed.
    //
    // Example:
    // https://www.x.org/releases/X11R7.7/doc/man/man3/xcb_send_event.3.xhtml
    //
    xcb_configure_notify_event_t* e = calloc(32, 1);

    //
    // CAUTION! An initialisation of the event is NOT necessary,
    // since it is just to wake up the sensing thread,
    // without any further meaning.
    //

    //
    // Send event to xcb, so that it can be detected by the sensing thread function.
    //
    // Parametres:
    // https://www.x.org/releases/X11R7.7/doc/man/man3/xcb_send_event.3.xhtml
    //
    xcb_send_event(ct, p, XCB_SEND_EVENT_DEST_POINTER_WINDOW, XCB_EVENT_MASK_STRUCTURE_NOTIFY, (char*) e);

    // Flush out event to xcb.
    xcb_flush(ct);
}
