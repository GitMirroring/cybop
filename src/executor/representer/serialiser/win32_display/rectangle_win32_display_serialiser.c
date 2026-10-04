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

#include <windows.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Serialises the rectangle into win32 display.
 *
 * @param p0 the win32 device context
 * @param p1 the position x
 * @param p2 the position y
 * @param p3 the size width
 * @param p4 the size height
 */
void serialise_win32_display_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* h = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* w = (int*) p3;

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* y = (int*) p2;

                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* x = (int*) p1;

                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        // The handle to the device context.
                        //
                        // CAUTION! The device context type is defined as:
                        // typedef HANDLE HDC;
                        // typedef PVOID HANDLE;
                        // typedef void* PVOID;
                        //
                        // The HDC type is: void*
                        // Therefore, cast parametre value AS IS
                        // to handle (WITHOUT dereferencing).
                        HDC hdc = (HDC) p0;

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 display rectangle.");

                        // The x-coordinate, in logical coordinates, of the upper-left corner of the rectangle.
                        int x1 = *x;
                        // The y-coordinate, in logical coordinates, of the upper-left corner of the rectangle.
                        int y1 = *y;
                        // The x-coordinate, in logical coordinates, of the lower-right corner of the rectangle.
                        int x2 = *x + *w;
                        // The y-coordinate, in logical coordinates, of the lower-right corner of the rectangle.
                        int y2 = *y + *h;

                        // Draw rectangle.
                        BOOL b = Rectangle(hdc, x1, y1, x2, y2);

                        // If the return value is zero, then an error occured.
                        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            // Get the calling thread's last-error code.
                            DWORD e = GetLastError();

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display rectangle. A windows system error occured.");
                            log_error((void*) &e);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display rectangle. The device context is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display rectangle. The position x is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display rectangle. The position y is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display rectangle. The width is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display rectangle. The height is null.");
    }
}
