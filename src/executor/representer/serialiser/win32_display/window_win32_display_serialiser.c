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
 * @version CYBOP 0.27.0 2023-08-31
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
 * Serialises the window into win32 display.
 *
 * @param p0 the win32 device context
 * @param p1 the source position x
 * @param p2 the source position y
 * @param p3 the source size width
 * @param p4 the source size height
 */
void serialise_win32_display_window(void* p0, void* p1, void* p2, void* p3, void* p4) {

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
                        HDC h = (HDC) p0;

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 display window.");

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display window. The device context is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display window. The source position x is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display window. The source position y is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display window. The source size width is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display window. The source size height is null.");
    }
}
