/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SERVER_XCB_STARTER_SOURCE
#define SERVER_XCB_STARTER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the x window system server.
 *
 * @param p0 the input/output entry
 */
void startup_xcb_server(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup xcb server.");

    fwprintf(stdout, L"Test: Startup xcb server. p0: %i\n", p0);

    //
    // Allocate and open connexion.
    //
    // CAUTION! Do NOT allocate the connexion manually here.
    // The xcb_connection_t is a structure containing
    // all data needed to communicate with an x server.
    //
    void* c = (void*) xcb_connect(*NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Get setup.
        const xcb_setup_t* setup = xcb_get_setup((xcb_connection_t*) c);

        if (setup != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get screen iterator.
            xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);

            //
            // Get first screen.
            //
            // CAUTION! Do NOT allocate the screen manually here.
            // It gets allocated through the connexion above.
            //
            void* s = (void*) iter.data;

            // The xcb screen type value.
            xcb_screen_t* st = (xcb_screen_t*) s;

            // Get root window of the screen.
            int r = (*st).root;

            // Allocate xid for default graphic context.
            int gc = (int) xcb_generate_id((xcb_connection_t*) c);

            //
            // The graphic context value mask.
            //
            // CAUTION! It is possible to set several attributes
            // at the same time by OR'ing these values in valuemask.
            //
            // The values that a mask could take are given
            // by the "xcb_gc_t" enumeration:
            //
            // enum xcb_gc_t {
            //     XCB_GC_FUNCTION = 1,
            //     XCB_GC_PLANE_MASK = 2,
            //     XCB_GC_FOREGROUND = 4,
            //     XCB_GC_BACKGROUND = 8,
            //     XCB_GC_LINE_WIDTH = 16,
            //     XCB_GC_LINE_STYLE = 32,
            //     XCB_GC_CAP_STYLE = 64,
            //     XCB_GC_JOIN_STYLE = 128,
            //     XCB_GC_FILL_STYLE = 256,
            //     XCB_GC_FILL_RULE = 512,
            //     XCB_GC_TILE = 1024,
            //     XCB_GC_STIPPLE = 2048,
            //     XCB_GC_TILE_STIPPLE_ORIGIN_X = 4096,
            //     XCB_GC_TILE_STIPPLE_ORIGIN_Y = 8192,
            //     XCB_GC_FONT = 16384,
            //     XCB_GC_SUBWINDOW_MODE = 32768,
            //     XCB_GC_GRAPHICS_EXPOSURES = 65536,
            //     XCB_GC_CLIP_ORIGIN_X = 131072,
            //     XCB_GC_CLIP_ORIGIN_Y = 262144,
            //     XCB_GC_CLIP_MASK = 524288,
            //     XCB_GC_DASH_OFFSET = 1048576,
            //     XCB_GC_DASH_LIST = 2097152,
            //     XCB_GC_ARC_MODE = 4194304
            // }
            //
            // CAUTION! Be careful when setting the values,
            // as they HAVE TO FOLLOW THE ORDER of the enumeration.
            // https://www.x.org/releases/X11R7.6/doc/libxcb/tutorial/
            //
            uint32_t gcm = XCB_GC_FOREGROUND | XCB_GC_BACKGROUND;

            //
            // The graphic context values.
            //
            // CAUTION! They have to be IN THE SAME ORDER
            // as given in the value mask above.
            //
            uint32_t gcv[2];

            //
            // Initialise graphic context values with
            // black and white pixels of the screen.
            //
            // CAUTION! The index has to be in the
            // SAME ORDER as given in the mask above.
            //
            gcv[0] = (*st).black_pixel;
            gcv[1] = (*st).white_pixel;

            //
            // Create graphic context.
            //
            // It is used to store general drawing parameters,
            // e.g. colour, line width, font.
            //
            // Relation between graphic context and drawable:
            // 1:n One graphic context can be used with all "like" drawables
            //     of the same screen root window and the same bit depth.
            // n:1 Many graphic contexts can be assigned to one drawable,
            //     e.g. to draw in multiple styles.
            //
            // An x11 graphic context does not contain the memory buffer.
            // Both the drawable and the graphic context are passed in
            // to all the drawing operations.
            //
            // In some drawing libraries, the context references a
            // current drawable (target surface), which may be changed.
            // OpenGL also has a "current target" kind of concept.
            //
            // https://stackoverflow.com/questions/6818468/what-exactly-is-a-graphic-context
            //
            // CAUTION! Only ONE graphic context is used in cyboi,
            // since its styles get updated as needed in the serialiser,
            // with each new send gui function call.
            //
            // In order to be able to use a font, one has to create a
            // graphic context that will contain the information about
            // the color of the foreground and the background used
            // when a text is drawn in a drawable.
            //
            // Parametres:
            // - the screen root window drawable is used inside to get the bit depth
            // - the last parametre has to be a pointer, and it already IS one, since it is an array
            //
            xcb_create_gc((xcb_connection_t*) c, (xcb_gcontext_t) gc, (xcb_drawable_t) r, gcm, gcv);

            //
            // Store various values in input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            // CAUTION! Hand over values as pointer REFERENCE.
            //

            // Store connexion in input/output entry.
            set_io_entry_element(p0, (void*) &c, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
            // Store screen in input/output entry.
            set_io_entry_element(p0, (void*) &s, (void*) SCREEN_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
            // Store default graphic context in input/output entry.
            set_io_entry_element(p0, (void*) &gc, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup xcb server. The setup is null.");
            fwprintf(stdout, L"Error: Could not startup xcb server. The setup is null. setup: %i\n", setup);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup xcb server. The connexion is null.");
        fwprintf(stdout, L"Error: Could not startup xcb server. The connexion is null. c: %i\n", c);
    }
}

/* SERVER_XCB_STARTER_SOURCE */
#endif
