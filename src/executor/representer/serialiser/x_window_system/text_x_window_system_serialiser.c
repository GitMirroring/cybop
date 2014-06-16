/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE
#define TEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the x window system text.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the source model data of type "char"
 * @param p5 the source model count
 * @param p6 the position x
 * @param p7 the position y
 */
void serialise_x_window_system_text(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* y = (int*) p7;

        if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* x = (int*) p6;

            if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* mc = (int*) p5;

                if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        xcb_gcontext_t* gc = (xcb_gcontext_t*) p3;

                        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            xcb_drawable_t* d = (xcb_drawable_t*) p2;

                            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                xcb_connection_t* c = (xcb_connection_t*) p0;

                                // Draw text.
//??                                xcb_image_text_8(c, strlen("TEST"), *d, *gc, *x, *y, "TEST");
                                xcb_image_text_8(c, *mc, *d, *gc, *x, *y, p4);

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system text. The connexion is null.");
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system text. The window is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system text. The graphic context is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system text. The model data is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system text. The model count is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system text. The position x is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system text. The position y is null.");
    }
}

/* TEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE */
#endif
