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

#ifndef RECTANGLE_XCB_SERIALISER_SOURCE
#define RECTANGLE_XCB_SERIALISER_SOURCE

#include <xcb/xcb.h>

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "logger.h"

/**
 * Serialises the rectangle into xcb.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the position x
 * @param p5 the position y
 * @param p6 the size width
 * @param p7 the size height
 */
void serialise_xcb_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* h = (int*) p7;

        if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* w = (int*) p6;

            if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* y = (int*) p5;

                if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* x = (int*) p4;

                    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int* gc = (int*) p3;

                        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            int* d = (int*) p2;

                            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                xcb_connection_t* c = (xcb_connection_t*) p0;

                                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xcb rectangle.");

                                // The xcb graphic context type value.
                                xcb_gcontext_t gct = *gc;
                                // The xcb drawable window type value.
                                xcb_drawable_t dt = *d;

                                //
                                // The rectangle count (number of given rectangles).
                                //
                                // CAUTION! Only ONE rectangle may be processed in cyboi,
                                // since it was decided that rectangles have to be
                                // specified by one cybol part, one for each rectangle.
                                // Therefore, the rectangle count is set to 1.
                                //
                                int rc = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                                // The rectangle data.
                                xcb_rectangle_t rd;

/*??
                                fwprintf(stdout, L"Debug: Serialise xcb rectangle. *x: %i\n", *x);
                                fwprintf(stdout, L"Debug: Serialise xcb rectangle. *y: %i\n", *y);
                                fwprintf(stdout, L"Debug: Serialise xcb rectangle. *w: %i\n", *w);
                                fwprintf(stdout, L"Debug: Serialise xcb rectangle. *h: %i\n", *h);
*/

                                // Initialise rectangle.
                                //?? TODO: Is a reference possible? Example:
                                //?? copy_integer((void*) &(rd.x), p4);
                                rd.x = *x;
                                rd.y = *y;
                                rd.width = *w;
                                rd.height = *h;

                                // Draw rectangle.
                                xcb_poly_fill_rectangle(c, dt, gct, rc, &rd);
                                //?? xcb_poly_rectangle(c, dt, gct, rc, &rd);

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb rectangle. The connexion is null.");
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb rectangle. The window is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb rectangle. The graphic context is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb rectangle. The position x is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb rectangle. The position y is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb rectangle. The width is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb rectangle. The height is null.");
    }
}

/* RECTANGLE_XCB_SERIALISER_SOURCE */
#endif
