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

fwprintf(stdout, L"TEST serialise gui rectangle h: %i\n", *((int*) h));
fwprintf(stdout, L"TEST serialise gui rectangle w: %i\n", *((int*) w));
fwprintf(stdout, L"TEST serialise gui rectangle y: %i\n", *((int*) y));
fwprintf(stdout, L"TEST serialise gui rectangle x: %i\n", *((int*) x));
fwprintf(stdout, L"TEST serialise gui rectangle gc: %i\n", gc);
fwprintf(stdout, L"TEST serialise gui rectangle d: %i\n", d);
fwprintf(stdout, L"TEST serialise gui rectangle s: %i\n", s);
fwprintf(stdout, L"TEST serialise gui rectangle c: %i\n", c);

                                    // Adjust value mask.
                                    //
                                    // CAUTION! It is possible to set several attributes
                                    // at the same time by OR'ing these values in valuemask.
//??                                    uint32_t m = XCB_GC_BACKGROUND | XCB_GC_FOREGROUND; //?? | XCB_GC_FONT;
                                    uint32_t m = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
                                    // Adjust values.
                                    //
                                    // CAUTION! The valuelist has to be an array which
                                    // lists the value for the respective attributes.
                                    // These values must be in the same order
                                    // as given in the mask above.
                                    uint32_t v[2];
                                    // The rectangle.
                                    xcb_rectangle_t r;

                                    // Initialise values.
                                    // CAUTION! Initialise values BEFORE using them
                                    // in function calls further below.
                                    // Otherwise, drawings will not be displayed.
                                    v[0] = s->black_pixel;
                                    v[1] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
/*??
                                    v[0] = s->white_pixel;
                                    v[1] = s->black_pixel;
//??                                    v[2] = font;
*/
                                    // Initialise rectangle.
                                    r.x = *x;
                                    r.y = *y;
                                    r.width = *w;
                                    r.height = *h;

                                    // Create graphic context.
                                    // CAUTION! The "xcb_change_gc" function call
                                    // does not work for some unknown reason.
                                    // xcb_change_gc(c, *gc, m, v);
                                    *gc = xcb_generate_id(c);
                                    xcb_create_gc(c, *gc, *d, m, v);

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
