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

#ifndef RECTANGLE_GUI_SERIALISER_SOURCE
#define RECTANGLE_GUI_SERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the rectangle into gui.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the position x
 * @param p5 the position y
 * @param p6 the width
 * @param p7 the height
 */
void serialise_gui_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* h = (int*) p7;

        if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* w = (int*) p6;

            if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* y = (int*) p5;

                if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* x = (int*) p4;

                    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        xcb_gcontext_t* gc = (xcb_gcontext_t*) p3;

                        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            xcb_drawable_t* d = (xcb_drawable_t*) p2;

                            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                xcb_screen_t* s = (xcb_screen_t*) p1;

                                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    xcb_connection_t* c = (xcb_connection_t*) p0;

                                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui rectangle.");

                                    // Get screen's default colour map.
                                    xcb_colormap_t cm = (*s).default_colormap;

/*??
fwprintf(stdout, L"TEST serialise gui rectangle h: %i\n", *((int*) h));
fwprintf(stdout, L"TEST serialise gui rectangle w: %i\n", *((int*) w));
fwprintf(stdout, L"TEST serialise gui rectangle y: %i\n", *((int*) y));
fwprintf(stdout, L"TEST serialise gui rectangle x: %i\n", *((int*) x));
fwprintf(stdout, L"TEST serialise gui rectangle c: %i\n", c);
fwprintf(stdout, L"TEST serialise gui rectangle *c: %i\n", *((uint32_t*) c));
fwprintf(stdout, L"TEST serialise gui rectangle s: %i\n", s);
fwprintf(stdout, L"TEST serialise gui rectangle *s: %i\n", *((uint32_t*) s));
fwprintf(stdout, L"TEST serialise gui rectangle d: %i\n", d);
fwprintf(stdout, L"TEST serialise gui rectangle *d: %i\n", *((uint32_t*) d));
fwprintf(stdout, L"TEST serialise gui rectangle gc: %i\n", gc);
fwprintf(stdout, L"TEST serialise gui rectangle *gc: %i\n", *((uint32_t*) gc));
*/

                                    /*??
                                    DELETE LATER:
                                    XCB_GC_FUNCTION
                                    XCB_GC_PLANE_MASK
                                    XCB_GC_FOREGROUND
                                    XCB_GC_BACKGROUND
                                    XCB_GC_LINE_WIDTH
                                    XCB_GC_LINE_STYLE
                                    XCB_GC_CAP_STYLE
                                    XCB_GC_JOIN_STYLE
                                    XCB_GC_FILL_STYLE
                                    XCB_GC_FILL_RULE
                                    XCB_GC_TILE
                                    XCB_GC_STIPPLE
                                    XCB_GC_TILE_STIPPLE_ORIGIN_X
                                    XCB_GC_TILE_STIPPLE_ORIGIN_Y
                                    XCB_GC_FONT
                                    XCB_GC_SUBWINDOW_MODE
                                    XCB_GC_GRAPHICS_EXPOSURES
                                    XCB_GC_CLIP_ORIGIN_X
                                    XCB_GC_CLIP_ORIGIN_Y
                                    XCB_GC_CLIP_MASK
                                    XCB_GC_DASH_OFFSET
                                    XCB_GC_DASH_LIST
                                    XCB_GC_ARC_MODE
                                    */

                                    // The colour cookie.
                                    xcb_alloc_color_cookie_t cc = xcb_alloc_color(c, cm, 65535, 0, 0);
                                    // The colour reply.
                                    xcb_alloc_color_reply_t* cr = xcb_alloc_color_reply(c, cc, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);
                                    // The value mask.
                                    // CAUTION! It is possible to set several attributes
                                    // at the same time by OR'ing these values in valuemask.
//??                                    uint32_t m = XCB_GC_BACKGROUND | XCB_GC_FOREGROUND; //?? | XCB_GC_FONT;
                                    uint32_t m = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
                                    // The values.
                                    // CAUTION! They have to be IN THE SAME ORDER
                                    // as given in the value mask above.
                                    uint32_t v[2];
                                    // The rectangle.
                                    xcb_rectangle_t r;

                                    // Initialise values.
                                    // CAUTION! Initialise values BEFORE using them
                                    // in function calls further below.
                                    // Otherwise, drawings will not be displayed.
//??                                    v[0] = (*s).black_pixel;
                                    v[0] = (*cr).pixel;
                                    v[1] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                                    /*?? DELETE LATER. Just another example:
                                    v[0] = s->white_pixel;
                                    v[1] = s->black_pixel;
//??                                    v[2] = font;
                                    */

                                    // Initialise rectangle.
                                    r.x = *x;
                                    r.y = *y;
                                    r.width = *w;
                                    r.height = *h;

                                    // Change graphic context.
                                    xcb_change_gc(c, *gc, m, v);

                                    // Draw rectangle.
                                    xcb_poly_rectangle(c, *d, *gc, *NUMBER_1_INTEGER_STATE_CYBOI_MODEL, &r);

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The connexion is null.");
                                }

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The screen is null.");
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The window is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The graphic context is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The position x is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The position y is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The width is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui rectangle. The height is null.");
    }
}

/* RECTANGLE_GUI_SERIALISER_SOURCE */
#endif
