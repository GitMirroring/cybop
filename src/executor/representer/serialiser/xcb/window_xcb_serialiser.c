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
 * Serialises the window into xcb.
 *
 * @param p0 the connexion
 * @param p1 the window
 * @param p2 the source position x
 * @param p3 the source position y
 * @param p4 the source size width
 * @param p5 the source size height
 * @param p6 the title data
 * @param p7 the title count
 * @param p8 the icon title data
 * @param p9 the icon title count
 */
void serialise_xcb_window(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* h = (int*) p5;

        if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* w = (int*) p4;

            if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* y = (int*) p3;

                if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* x = (int*) p2;

                    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int* d = (int*) p1;

                        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            xcb_connection_t* c = (xcb_connection_t*) p0;

                            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xcb window.");

                            //?? TODO:
                            // http://xcb.freedesktop.org/manual/group__XCB____API.html

                            // The title model data terminated item.
                            void* tmdt = *NULL_POINTER_STATE_CYBOI_MODEL;
                            // The icon title model data terminated item.
                            void* itmdt = *NULL_POINTER_STATE_CYBOI_MODEL;
                            // The title model data terminated item data.
                            void* tmdtd = *NULL_POINTER_STATE_CYBOI_MODEL;
                            // The icon title model data terminated item data.
                            void* itmdtd = *NULL_POINTER_STATE_CYBOI_MODEL;
                            // The value mask.
                            // CAUTION! It is possible to set several attributes
                            // at the same time by OR'ing these values in valuemask.
                            uint32_t mask = XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y | XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT;
                            // The values.
                            // CAUTION! They have to be IN THE SAME ORDER
                            // as given in the value mask above.
                            uint32_t values[4];

                            // Allocate title model data terminated item.
                            // CAUTION! Due to memory allocation handling, the size MUST NOT
                            // be negative or zero, but have at least a value of ONE.
                            allocate_item((void*) &tmdt, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
                            // Allocate icon title model data terminated item.
                            // CAUTION! Due to memory allocation handling, the size MUST NOT
                            // be negative or zero, but have at least a value of ONE.
                            allocate_item((void*) &itmdt, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                            // Encode title model data terminated wide character- into multibyte character data.
                            encode_utf_8(tmdt, p6, p7);
                            // Encode icon title model data terminated wide character- into multibyte character data.
                            encode_utf_8(itmdt, p8, p9);

/*??
                            fwprintf(stdout, L"Debug: Serialise xcb window. *x: %i\n", *x);
                            fwprintf(stdout, L"Debug: Serialise xcb window. *y: %i\n", *y);
                            fwprintf(stdout, L"Debug: Serialise xcb window. *w: %i\n", *w);
                            fwprintf(stdout, L"Debug: Serialise xcb window. *h: %i\n", *h);
*/

                            // Initialise values.
                            // CAUTION! Initialise values BEFORE using them
                            // in function calls further below.
                            // Otherwise, the window configuration will fail.
                            values[0] = *x;
                            values[1] = *y;
                            values[2] = *w;
                            values[3] = *h;

                            // Add null termination character to title model data terminated.
                            modify_item(tmdt, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
                            // Add null termination character to icon title model data terminated.
                            modify_item(itmdt, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                            // Get title model data terminated item data.
                            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                            // Inside the structure, arrays may have been reallocated,
                            // with elements pointing to different memory areas now.
                            copy_array_forward((void*) &tmdtd, tmdt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                            // Get icon title model data terminated item data.
                            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                            // Inside the structure, arrays may have been reallocated,
                            // with elements pointing to different memory areas now.
                            copy_array_forward((void*) &itmdtd, itmdt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

                            // The xcb drawable window type value.
                            xcb_drawable_t dt = *d;

                            // Set title.
                            // CAUTION! The sixth parametre specifies
                            // the format of the property (8, 16, 32).
                            // However, number 32 (= 4 byte) for
                            // specifying "wchar_t" data did NOT work.
                            // Therefore, "char" data with string
                            // termination character are used now.
                            xcb_change_property(c, XCB_PROP_MODE_REPLACE, dt, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, *NUMBER_8_INTEGER_STATE_CYBOI_MODEL, strlen(tmdtd), tmdtd);
                            // Set icon title.
                            xcb_change_property(c, XCB_PROP_MODE_REPLACE, dt, XCB_ATOM_WM_ICON_NAME, XCB_ATOM_STRING, *NUMBER_8_INTEGER_STATE_CYBOI_MODEL, strlen(itmdtd), itmdtd);
                            // Set icon
                            //?? TODO
                            //?? xcb_change_property(c, XCB_PROP_MODE_REPLACE, dt, XCB_ATOM_WM_ICON, XCB_ATOM_CARDINAL, *NUMBER_32_INTEGER_STATE_CYBOI_MODEL, *imci, imd);
                            // Configure window position and size.
                            xcb_configure_window(c, dt, mask, values);

                            // Deallocate title model data terminated item.
                            deallocate_item((void*) &tmdt, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
                            // Deallocate icon title model data terminated item.
                            deallocate_item((void*) &itmdt, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb window. The connexion is null.");
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb window. The window is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb window. The source position x is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb window. The source position y is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb window. The source size width is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb window. The source size height is null.");
    }
}
