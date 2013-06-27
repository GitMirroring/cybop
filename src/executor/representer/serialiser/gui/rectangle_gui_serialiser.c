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

#ifndef RECTANGLE_GUI_SERIALISER_SOURCE
#define RECTANGLE_GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the rectangle into gui.
 *
 * @param p0 the position x
 * @param p1 the size x
 * @param p2 the position y
 * @param p3 the size y
 */
void serialise_gui_rectangle(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui rectangle.");

/*??
    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_connection_t* c = (xcb_connection_t*) p0;

        // Use xcb type.
        xcb_window_t window = *w;
        // Use xcb type.
//??        xcb_gcontext_t gcontext = *gc;

        //
        // Adjust value mask.
        //
        // The valuemask parameter could take any combination
        // of these masks from the xcbgct enumeration:
        //
        // XCB_GC_FUNCTION
        // XCB_GC_PLANE_MASK
        // XCB_GC_FOREGROUND
        // XCB_GC_BACKGROUND
        // XCB_GC_LINE_WIDTH
        // XCB_GC_LINE_STYLE
        // XCB_GC_CAP_STYLE
        // XCB_GC_JOIN_STYLE
        // XCB_GC_FILL_STYLE
        // XCB_GC_FILL_RULE
        // XCB_GC_TILE
        // XCB_GC_STIPPLE
        // XCB_GC_TILE_STIPPLE_ORIGIN_X
        // XCB_GC_TILE_STIPPLE_ORIGIN_Y
        // XCB_GC_FONT
        // XCB_GC_SUBWINDOW_MODE
        // XCB_GC_GRAPHICS_EXPOSURES
        // XCB_GC_CLIP_ORIGIN_X
        // XCB_GC_CLIP_ORIGIN_Y
        // XCB_GC_CLIP_MASK
        // XCB_GC_DASH_OFFSET
        // XCB_GC_DASH_LIST
        // XCB_GC_ARC_MODE
        //
        // CAUTION! It is possible to set several attributes
        // at the same time by OR'ing these values in valuemask.
        //
        // Example:
        // Set the attributes of a font and the color
        // which will be used to display a string.
        //
        uint32_t mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;

        // Adjust value mask values.
        //
        // CAUTION! The valuelist has to be an array which
        // lists the value for the respective attributes.
        // These values must be in the same order
        // as masks listed above.
        uint32_t values[] = { s->black_pixel, 0 };

        // TEST: Create black (foreground) graphic context.
        xcb_gcontext_t foreground = xcb_generate_id(c);
        xcb_create_gc(c, foreground, window, mask, values);

        xcb_rectangle_t rectangles[] = {
            { 10, 50, 40, 20 },
            { 80, 50, 10, 40 }};

        xcb_poly_rectangle(c, window, foreground, 2, rectangles);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The connexion is null.");
    }
*/
}

/* RECTANGLE_GUI_SERIALISER_SOURCE */
#endif
