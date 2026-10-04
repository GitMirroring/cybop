/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the xcb text.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the position x
 * @param p7 the position y
 * @param p8 the size width
 * @param p9 the size height
 */
void serialise_xcb_text(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p9 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* h = (int*) p9;

        if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* w = (int*) p8;

            if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* y = (int*) p7;

                if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* x = (int*) p6;

                    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int* gc = (int*) p3;

                        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            int* d = (int*) p2;

                            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                xcb_connection_t* c = (xcb_connection_t*) p0;

                                // The text item.
                                void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
                                // The text item data, count.
                                void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
                                void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;

                                // Allocate text item.
                                // CAUTION! Due to memory allocation handling, the size MUST NOT
                                // be negative or zero, but have at least a value of ONE.
                                allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                                // Encode model wide character data into multibyte character item.
                                encode_utf_8(t, p4, p5);

                                // Get text item data, count.
                                // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                                // Inside the structure, arrays may have been reallocated,
                                // with elements pointing to different memory areas now.
                                copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                                copy_array_forward((void*) &tc, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

                                if (tc != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    // The text item count as integer.
                                    int* tci = (int*) tc;
                                    // The xcb graphic context type value.
                                    xcb_gcontext_t gct = *gc;
                                    // The xcb drawable window type value.
                                    xcb_drawable_t dt = *d;
                                    //
                                    // The centred x, y.
                                    //
                                    // TODO: This is only a rough estimation of the centre.
                                    // In the future, the text width and font height
                                    // will have to be considered as well.
                                    //
                                    // int cx = *x + (*w / 2);
                                    int cx = *x;
                                    // int cy = *y + (*h / 2);
                                    int cy = *y + 10;

/*??
                                    fwprintf(stdout, L"Debug: Serialise xcb text. *x: %i\n", *x);
                                    fwprintf(stdout, L"Debug: Serialise xcb text. *y: %i\n", *y);
                                    fwprintf(stdout, L"Debug: Serialise xcb text. *w: %i\n", *w);
                                    fwprintf(stdout, L"Debug: Serialise xcb text. *h: %i\n", *h);
*/

                                    // Draw text.
                                    xcb_image_text_8(c, *tci, dt, gct, cx, cy, td);

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb text. The text item count is null.");
                                }

                                // Deallocate text item.
                                deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb text. The connexion is null.");
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb text. The window is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb text. The graphic context is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb text. The position x is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb text. The position y is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb text. The size width is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb text. The size height is null.");
    }
}
